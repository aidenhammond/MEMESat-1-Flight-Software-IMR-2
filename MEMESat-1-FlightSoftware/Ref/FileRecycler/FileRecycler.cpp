// ======================================================================
// \title  FileRecycler.cpp
// \author aiden
// \brief  cpp file for FileRecycler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <Fw/Types/String.hpp>
#include <queue>
#include <set>
#include <inttypes.h>
#include <fcntl.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <exception>
#include <Ref/FileRecycler/FileRecycler.hpp>

#include "Fw/Types/BasicTypes.hpp"

#if __has_include(<filesystem>)
#include <filesystem>
#else
#include <experimental/filesystem>
#endif

namespace Ref {
  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  FileRecycler ::
    FileRecycler(
        const char *const compName
    ) : FileRecyclerComponentBase(compName)
  {
    this->shutdown = false;
  }

  void FileRecycler ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    FileRecyclerComponentBase::init(queueDepth, instance);
  }

  FileRecycler ::
    ~FileRecycler()
  {

  }
  /*
   *  Runs on start up
  */
  void FileRecycler ::
    preamble()
  {
    Fw::ParamValid valid;
    // Gets the SCHEDULE parameter 
    const Fw::ParamString schedule_param = this->paramGet_SCHEDULE(valid);
    const char* schedule = schedule_param.toChar();
    FW_ASSERT(
      valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
      valid.e
    );

    this->sendSchedule_out(0, "FileRecycler", schedule, ScheduleOp::START);
  }

  void FileRecycler ::
    recycler_call_on_reset_handler()
    {
      this->log_WARNING_LO_RECYCLER_STOPPED_BY_SYS_RESET();
    }

  // ----------------------------------------------------------------------
  // Recycler
  // ----------------------------------------------------------------------

  template <typename T>
  Ref::FauxOsStatus FileRecycler :: 
    convertOsStatusToFaux(const T& status) 
  {
    static_assert(std::is_same_v<T, Os::Directory::Status> || std::is_same_v<T, Os::FileSystem::Status>, 
                  "convertOsStatusToRefStatus only takes in either an Os::Directory::Status or Os::FileSystem::Status");
    
    Ref::FauxOsStatus fauxStatus;

    auto modifyFauxStatus = [&](std::string status, std::string message) {
      fauxStatus.setstatus(status.c_str());
      fauxStatus.setstatus_message(message.c_str());
    };

    if constexpr (std::is_same_v<T, Os::Directory::Status>) {
      switch(status) {
        //  Operation was successful
        case Os::Directory::Status::OP_OK: modifyFauxStatus("Os::Directory::Status::OP_OK", "Operation was successful"); break; 
        //  Directory doesn't exist
        case Os::Directory::Status::DOESNT_EXIST: modifyFauxStatus("Os::Directory::Status::DOESNT_EXIST", "Directory doesn't exist"); break;
        //  No permission to read directory
        case Os::Directory::Status::NO_PERMISSION: modifyFauxStatus("Os::Directory::Status::NO_PERMISSION","No permission to read directory"); break;
        //  Directory hasn't been opened yet
        case Os::Directory::Status::NOT_OPENED: modifyFauxStatus("Os::Directory::Status::NOT_OPENED","Directory hasn't been opened yet"); break; 
        //  Path is not a directory
        case Os::Directory::Status::NOT_DIR: modifyFauxStatus("Os::Directory::Status::NOT_DIR","Path is not a directory"); break;
        //  Directory stream has no more files
        case Os::Directory::Status::NO_MORE_FILES: modifyFauxStatus("Os::Directory::Status::NO_MORE_FILES","Directory stream has no more files"); break; 
        //  A catch-all for other errors. Have to look in implementation-specific code
        default: modifyFauxStatus("Os::Directory::Status::OTHER_ERROR","A catch-all for other errors. Have to look in implementation-specific code"); break;
      }
    }
    else if constexpr (std::is_same_v<T, Os::FileSystem::Status>) {
      switch(status) {
        //!<  Operation was successful
        case Os::FileSystem::Status::OP_OK: modifyFauxStatus("Os::FileSystem::Status::OP_OK","Operation was successful"); break;
        //!<  File already exists
        case Os::FileSystem::Status::ALREADY_EXISTS: modifyFauxStatus("Os::FileSystem::Status::ALREADY_EXISTS","File already exists"); break;
        //!<  No space left
        case Os::FileSystem::Status::NO_SPACE: modifyFauxStatus("Os::FileSystem::Status::NO_SPACE","No space left"); break;
        //!<  No permission to write
        case Os::FileSystem::Status::NO_PERMISSION: modifyFauxStatus("Os::FileSystem::Status::NO_PERMISSION","No permission to write"); break;
        //!<  Path is not a directory
        case Os::FileSystem::Status::NOT_DIR: modifyFauxStatus("Os::FileSystem::Status::NOT_DIR","Path is not a directory"); break;
        //!<  Path is a directory
        case Os::FileSystem::Status::IS_DIR: modifyFauxStatus("Os::FileSystem::Status::IS_DIR","Path is a directory"); break;
        //!<  directory is not empty
        case Os::FileSystem::Status::NOT_EMPTY: modifyFauxStatus("Os::FileSystem::Status::NOT_EMPTY","Directory is not empty"); break;
        //!<  Path is too long, too many sym links, doesn't exist, ect
        case Os::FileSystem::Status::INVALID_PATH: modifyFauxStatus("Os::FileSystem::Status::INVALID_PATH","Path is too long, too many sym links, doesn't exist, ect"); break;
        //!<  Too many files or links
        case Os::FileSystem::Status::FILE_LIMIT: modifyFauxStatus("Os::FileSystem::Status::FILE_LIMIT","Too many files or links"); break;
        //!<  Operand is in use by the system or by a process
        case Os::FileSystem::Status::BUSY: modifyFauxStatus("Os::FileSystem::Status::BUSY","Operand is in use by the system or by a process"); break;
        //!<  Other OS-specific error
        default: modifyFauxStatus("Os::FileSystem::Status::OTHER_ERROR","Other OS-specific error"); break;
      }
    }
    return fauxStatus;
  }

  void
    FileRecycler::handleStatError(int valueFromStat) {
      switch(valueFromStat) {
            case EACCES:
              this->log_WARNING_LO_STAT_ERROR(EACCES,"EACCES","Search permission is denied for one of the directories in the path prefix of path.");
              // Solve with path_resolution
              // https://linux.die.net/man/7/path_resolution
              break;
            case EBADF:
              this->log_WARNING_LO_STAT_ERROR(EBADF, "EBADF", "File descriptor is bad.");
              break;
            case EFAULT:
              this->log_WARNING_LO_STAT_ERROR(EFAULT, "EFAULT", "Bad address.");
              break;
            case ELOOP:
              this->log_WARNING_LO_STAT_ERROR(ELOOP, "ELOOP", "Too many symbolic links encountered while traversing the path.");
              break;
            case ENAMETOOLONG:
              this->log_WARNING_LO_STAT_ERROR(ENAMETOOLONG, "ENAMETOOLONG", "Path is too long");
              break;
            case ENOENT:
              this->log_WARNING_LO_STAT_ERROR(ENOENT, "ENOENT", "A component of path does not exist, or path is an empty string.");
              break;
            case ENOMEM:
              this->log_WARNING_LO_STAT_ERROR(ENOMEM, "ENOMEM", "Out of memory (i.e., kernel memory).");
              break;
            case ENOTDIR:
              this->log_WARNING_LO_STAT_ERROR(ENOTDIR, "ENOTDIR", "A component of the path prefix of path is not a directory.");
              break;
            case EOVERFLOW: 
              this->log_WARNING_LO_STAT_ERROR(EOVERFLOW, "EOVERFLOW", "path or fd refers to a file whose size, inode number, or number of blocks cannot be represented in, respectively, the types off_t, ino_t, or blkcnt_t.");
              break;
            default:
              this->log_WARNING_LO_STAT_ERROR(0, "UNKNOWN", "Default case hit in stat error switch.");
              break;
          }
    }
  
  
  
  std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> 
    FileRecycler::recycler(U32 count, const Ref::FileRecyclerOp &op) 
  {
    std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> deleted_files;
    // if shutting down, send event and don't continue
    if (this->shutdown){
      this->log_WARNING_LO_RECYCLER_STOPPED_BY_SYS_RESET();
      return deleted_files;
    }

    // Open directory
    std::lock_guard<std::mutex> lock(this->directory_mutex);
    Os::Directory::Status status = this->directory.open(MEMESAT_STORAGE_DIR);
    if (status != Os::Directory::Status::OP_OK) {
      // invoke change state port to go to reboot state
      // error opening directory
      // should send status to telemetry
      // Ask state machine to move into abnormal mode?
      // Add this as a check prior to moving into cruise
      this->log_WARNING_HI_CANNOT_OPEN_DIR(MEMESAT_STORAGE_DIR);
      return deleted_files;
    }

    struct stat file_info;
    // Name of the file
    char file[MEMESAT_STORAGE_DIR_MAX_LEN]; // maybe make a string or catch the overflow
    status = this->directory.read(file, MEMESAT_STORAGE_DIR_MAX_LEN);
    std::set<std::pair<time_t, std::string>> files;
    while ((status != Os::Directory::Status::NO_MORE_FILES) &&
            (status != Os::Directory::Status::OTHER_ERROR)) {
      // Absolute path of the file
      char abspath[MEMESAT_STORAGE_DIR_MAX_LEN];
      strcpy(abspath, MEMESAT_STORAGE_DIR);
      strcat(abspath, file);
      int exist = stat(abspath, &file_info);
      if (exist == 0) {
        switch(op.e) {
          case Ref::FileRecyclerOp::BEFORETIME:
            if (file_info.st_mtime < count) {
              Os::FileSystem::Status fsStatus = Os::FileSystem::removeFile(abspath);
              deleted_files.push_back(std::make_tuple(file_info.st_mtime, abspath, convertOsStatusToFaux(fsStatus)));
            }
            break;
          case Ref::FileRecyclerOp::AFTERTIME:
            if (file_info.st_mtime > count) {
              Os::FileSystem::Status fsStatus = Os::FileSystem::removeFile(abspath);
              deleted_files.push_back(std::make_tuple(file_info.st_mtime, abspath, convertOsStatusToFaux(fsStatus)));
            }
            break;
          default:
            if (file_info.st_atime < file_info.st_mtime) {
              // file was accessed before it was modified, use
              // st_atime for age
              files.emplace(file_info.st_atime, abspath);
            }
            else {
              // file was modified before it was accessed, use
              // st_mtime for age
              files.emplace(file_info.st_mtime, abspath);
            }
            break;
        }  
        status = this->directory.read(file, 100);
      }
      // if value returned from stat != 0
      // stat error
      else {
        handleStatError(exist);
      }
    }

    this->directory.close();
    if (status != Os::Directory::Status::NO_MORE_FILES) {
      this->log_WARNING_LO_UNEXPECTED_DIRECTORY_STATUS(convertOsStatusToFaux(status));
    }
    if (op == Ref::FileRecyclerOp::BEFORETIME || op == Ref::FileRecyclerOp::AFTERTIME) {
      return deleted_files;
    }
    // Now that directory is closed, begin deleting files
    Os::FileSystem::Status delete_status;
    // If NUM call, delete 'count' number of files
    // change to a map iterator might allow us to consolidate these if statements
    if (op == Ref::FileRecyclerOp::NUM) {
      U32 deleted_count = 0;
      // this loop can just use a map iterator 
      for (const auto& file : files) {
        if (deleted_count == count) {
          break;
        }
        // Need to handle error
        delete_status = Os::FileSystem::removeFile(file.second.c_str());
        deleted_files.push_back(std::make_tuple(file.first, file.second, convertOsStatusToFaux(delete_status)));
        // Need to handle error
        if (delete_status != Os::FileSystem::OP_OK){
          // To do
          // restart           
        }
        else {
          deleted_count += 1;
        }
      }
    } 
    // else, if MAX call, then remove all files until only 'count' remain
    else if (op == Ref::FileRecyclerOp::MAX && files.size() > count){
      std::set<std::pair<time_t, std::string>>::iterator it;
      auto stop_it = std::prev(files.end(), count);
      // files.end() - count
      for (it = files.begin(); it != stop_it; it++) {
        std::pair<time_t, std::string> file = *it;
        //std::cout << "DELETING FILE " << file.second.c_str() << std::endl;
        // Need to handle error
        delete_status = Os::FileSystem::removeFile(file.second.c_str());
        deleted_files.push_back(std::make_tuple(file.first, file.second, convertOsStatusToFaux(delete_status)));
      }
    }
    return deleted_files;
  };
  
  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  /**
   * Defined as a potential use of returned values from the recycler
   * Kept separate so that recycler doesn't need to access nonstatic member 
   * variables
  */
  void FileRecycler :: 
    logRecyclerOutput (
      std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> return_value
    )
  {
    for (std::tuple<time_t, std::string, Ref::FauxOsStatus> &value : return_value) {
      std::tm* file_time = std::get<0>(value) ? std::gmtime(&std::get<0>(value)) : std::gmtime(0);
      this->log_DIAGNOSTIC_FILE_REMOVE(
          file_time->tm_year,
          (Fw::LogStringArg&) months[file_time->tm_mon],
          file_time->tm_mday,
          file_time->tm_hour,
          file_time->tm_min,
          file_time->tm_sec,
          (Fw::LogStringArg&) (std::get<1>(value)), 
          (Fw::LogStringArg&) std::get<2>(value).getstatus(), 
          (Fw::LogStringArg&) std::get<2>(value).getstatus_message());
    }
  }

  // Port to remove a specified number of files from the storage directory
  // VARIABLE: count - number of files to remove
  void FileRecycler ::
    fileRecyclerOpIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 count,
        const Ref::FileRecyclerOp &op
    )
  {
    // Log the command received and number of files to be removed
    this->log_COMMAND_COMMAND_RECV(count, op);
    // Remove the number of files specified by the command
    std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> ret_value = this->recycler(count, op);
    logRecyclerOutput(ret_value);
    // Log the number of files actually removed
    U32 num_op_ok = std::count_if(ret_value.begin(), ret_value.end(), [](const auto& file) {
		    /**
		     * This is temporary. Please fix.
		     */
		    try {
      			return std::get<2>(file).getstatus() == "OP_OK";
		    }
		    catch(std::exception& err) {
		   	return false; 
		    }

    });
    this->tlmWrite_NUM_FILES_REMOVED(num_op_ok); // iterate through and count the number of files will good delete op
    // Log the type of operation performed
    this->tlmWrite_RECYCLER_TYPE(op);
  }


  void FileRecycler ::
    readyForPowerOff_handler(
        const NATIVE_INT_TYPE portNum,
        bool result
    )
  {
    // The file manager will make sure all file descriptors are closed and reject any attempts to open one
    // mutex lock on opening files // changing files // etc
    // make sure mutex is unlocked on reboot / restart
    std::lock_guard<std::mutex> lock(this->directory_mutex);
    this->directory.close();
    this->shutdown = true;
    result = true;
  }


  // we need a way to restart the schedule if it stops
  void FileRecycler ::
    scheduledHandler_handler(
      const NATIVE_INT_TYPE portNum,
      const Ref::ScheduleStatus &status
    )
  {
    // should this have a higher priority?

    if (status == Ref::ScheduleStatus::FAILED || status == Ref::ScheduleStatus::STOPPED) {
       this->log_WARNING_LO_SCHEDULE_ERROR(status);
       return;
    }
    Fw::ParamValid valid;
    U32 max_files = this->paramGet_MAX_FILES(valid);

    FW_ASSERT(
        valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
        valid.e
      );
    this->toFileRecyclerHandler_out(0, max_files, Ref::FileRecyclerOp::MAX);
    this->log_DIAGNOSTIC_SCHEDULE_RAN();
  }


  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  // Command to remove a specified number of files from the storage directory
  // VARIABLE: count - number of files to remove
  void FileRecycler ::
    CLEAN_UP_DATA_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 count,
        Ref::FileRecyclerOp op
    )
  {
    this->log_COMMAND_COMMAND_RECV(count, op);
    // this->tlmWrite_OP(op);
    std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> ret_value = this->recycler(count, op);
    logRecyclerOutput(ret_value);
    U32 num_op_ok = std::count_if(ret_value.begin(), ret_value.end(), [](const auto& file) {
      return std::get<2>(file).getstatus() == "OP_OK";
    });
    this->tlmWrite_NUM_FILES_REMOVED(num_op_ok);  
    this->tlmWrite_CLEAN_UP_DATA_COMPLETED(Status::COMPLETED);
    this->log_DIAGNOSTIC_CLEAN_UP_DATA_COMPLETED(Status::COMPLETED);
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK); 

  }
  void FileRecycler :: 
    parameterUpdated(
      FwPrmIdType id
    )
  {
    if (id == 1) {
      Fw::ParamValid valid;
      const Fw::ParamString schedule_param = this->paramGet_SCHEDULE(valid);
      const char* schedule = schedule_param.toChar();
      FW_ASSERT(
        valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
        valid.e
      );
      this->sendSchedule_out(0, "FileRecycler", schedule, ScheduleOp::START);
      this->log_DIAGNOSTIC_SCHEDULE_CHANGED_TO(schedule);
    }
  }
} // end namespace Ref

