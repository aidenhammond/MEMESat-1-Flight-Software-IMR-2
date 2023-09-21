// ======================================================================
// \title  FileRecycler.hpp
// \author aiden
// \brief  cpp file for FileRecycler test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "Tester.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <cstdlib>
#include "Os/FileSystem.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

/**
 * Add unit test for filename > 100 characters
 * Add checks to all possible telemetry (maybe a function that takes a pointer to the object? 'this')
 * Test changing the schedule parameter
*/
namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester() :
#if FW_OBJECT_NAMES == 1
      FileRecyclerGTestBase("Tester", MAX_HISTORY_SIZE),
      component("FileRecycler")
#else
      FileRecyclerGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester()
  {

  }

  void Tester::
    prepend_path(char* filename) {
      // Concatenate the storage directory and the file name
      std::string abspath = std::string(MEMESAT_STORAGE_DIR) + filename;
      // Copy the result back into the original character array
      std::strcpy(filename, abspath.c_str());
    }

  std::tm* Tester::
    get_time() {
      // Get the current time as a time_point
      auto now = std::chrono::system_clock::now();

      // Convert the time_point to a time_t
      std::time_t now_c = std::chrono::system_clock::to_time_t(now);

      // Convert the time_t to a tm struct
      std::tm* now_tm = std::localtime(&now_c);

      return now_tm;
    }

  void Tester::customAssert_file_remove(const char* filename, const char* status , const char* message, int index)
  {
    const EventEntry_FILE_REMOVE& e = this->eventHistory_FILE_REMOVE->at(index);
    std::tm* time = this->get_time();
    ASSERT_EQ(time->tm_year, e.year)
      << "\n"
      << "   Expected the event FILE_REMOVE to have removed a file from this year.\n"
      << "\n"
      << "   Current year:       " << time->tm_year << "\n"
      << "   From FILE_REMOVE:   " << e.year << "\n";
    ASSERT_STREQ(months[time->tm_mon], e.month.toChar())
      << "\n"
      << "   Expected the event FILE_REMOVE to have removed a file from this month.\n"
      << "\n"
      << "   Current month:       " << months[time->tm_mon] << "\n"
      << "   From FILE_REMOVE:   " << e.month << "\n";
    ASSERT_EQ(time->tm_mday, e.day)
      << "\n"
      << "   Expected the event FILE_REMOVE to have removed a file from this year.\n"
      << "\n"
      << "   Current day:        " << time->tm_mday << "\n"
      << "   From FILE_REMOVE:   " << e.day << "\n";
    ASSERT_EQ(time->tm_hour, e.hour)
      << "\n"
      << "   Expected the event FILE_REMOVE to have removed a file from this hour.\n"
      << "\n"
      << "   Current hour:        " << time->tm_hour << "\n"
      << "   From FILE_REMOVE:    " << e.hour << "\n";
    ASSERT_TRUE(time->tm_min == e.minute || time->tm_min == e.minute + 1)
      << "\n"
      << "   Expected the event FILE_REMOVE to have removed a file from this minute.\n"
      << "\n"
      << "   Current minute:        " << time->tm_min << "\n"
      << "   From FILE_REMOVE:    " << e.minute << "\n";
    ASSERT_STREQ(filename, e.name.toChar())
      << "\n"
      << "  File:     " << filename << "\n"
      << "  Value:    Value of argument name at index "
      << index
      << " in history of event FILE_REMOVE\n"
      << "  Expected: " << filename << "\n"
      << "  Actual:   " << e.name.toChar() << "\n";
    ASSERT_STREQ(status, e.status.toChar())
      << "\n"
      << "  File:     " << filename << "\n"
      << "  Value:    Value of argument status at index "
      << index
      << " in history of event FILE_REMOVE\n"
      << "  Expected: " << status << "\n"
      << "  Actual:   " << e.status.toChar() << "\n";
    ASSERT_STREQ(message, e.message.toChar())
      << "\n"
      << "  File:     " << filename << "\n"
      << "  Value:    Value of argument message at index "
      << index
      << " in history of event FILE_REMOVE\n"
      << "  Expected: " << message << "\n"
      << "  Actual:   " << e.message.toChar() << "\n";
  }

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------
  void Tester ::
	testNum() {
    std::cout << "here1" <<std::endl;
     this->testCleanUpData(5, FileRecyclerOp::NUM);
    std::cout << "here2" <<std::endl;
  }
  void Tester ::
  testCleanUpData(U64 count, FileRecyclerOp op)
  {
    const U32 cmdSeq = 10;
    this->sendCmd_CLEAN_UP_DATA(0, cmdSeq, count, op);
    this->component.doDispatch();
    ASSERT_CMD_RESPONSE(0, FileRecyclerComponentBase::OPCODE_CLEAN_UP_DATA, cmdSeq, Fw::CmdResponse::OK);
    ASSERT_EVENTS_COMMAND_RECV_SIZE(1);
    ASSERT_EVENTS_COMMAND_RECV(0, count, op);
  }

  void Tester ::
	testMax() 
  {
    this->testCleanUpData(5, FileRecyclerOp::MAX);
  }

  void Tester::
    testBefore() 
  {
    this->testCleanUpData(1800000000000, FileRecyclerOp::BEFORETIME);
  }

  void Tester::
    testAfter() 
  {
    this->testCleanUpData(1800000000000, FileRecyclerOp::AFTERTIME);
  }


  void Tester::
    testNR_TestEmptyDirectory(Ref::FileRecyclerOp &op) 
  {
    //std::vector<std::pair<time_t, std::string>> result = num_recycler(1, Ref::FileRecyclerOp::NUM);
    std::cout << "Sending command, ASSERT_NO_THROW" << std::endl;
    ASSERT_NO_THROW(this->sendCmd_CLEAN_UP_DATA(0, 10, 1, Ref::FileRecyclerOp::NUM));
    ASSERT_EVENTS_COMMAND_RECV(0, 1, Ref::FileRecyclerOp::NUM);
    std::cout << "Command sent, checking that tlm sent and 0 files removed" << std::endl;
    ASSERT_TLM_NUM_FILES_REMOVED_SIZE(1);
    ASSERT_TLM_NUM_FILES_REMOVED(0, 0);
    std::cout << "Asserting type" << std::endl;
    //ASSERT_TLM_RECYCLER_TYPE(0, Ref::FileRecyclerOp::NUM);
    // Check that the result is empty
    //EXPECT_EQ(result.size(), 0);
  }

  void Tester::
    testNR_TestOneFile(Ref::FileRecyclerOp &op, U32 num_files_removed) 
  {
    std::string filename = std::string(MEMESAT_STORAGE_DIR) + "test.txt";
    Tester::testOneFileHandler(op, num_files_removed, filename)
  }

  void Tester::
    test_TestOneFileLongName(Ref::FileRecyclerOp &op, U32 num_files_removed) 
  {
    // 257 character name
    std::string filename = std::string(MEMESAT_STORAGE_DIR) + "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo.txt";
    Tester::testOneFileHandler(op, num_files_removed, filename)
  }

  void Tester::
    testOneFileHandler(Ref::FileRecyclerOp &op, U32 num_files_removed, std::string filename) 
  {
    // Create a file in the temporary directory
    std::ofstream file(filename.c_str());
    // Make sure that there is one file in the directory
    U32 filecount = 0;
    Os::FileSystem::getFileCount(MEMESAT_STORAGE_DIR, filecount);
    ASSERT_EQ(filecount, 1);
    file << "test long name";
    file.close();
    // Recycle one file
    ASSERT_NO_THROW(this->sendCmd_CLEAN_UP_DATA(0, 10, 1, op));
    ASSERT_EVENTS_COMMAND_RECV(0, 1, op);
    // Check that 1 file was removed
    std::cout << "Checking that " << num_files_removed << " file was removed" << std::endl;
    ASSERT_TLM_NUM_FILES_REMOVED(0, num_files_removed);
    // Check that the result contains the file name
    if (num_files_removed) {
      customAssert_file_remove(filename.c_str(), "Os::FileSystem::Status::OP_OK", "Operation was successful");
      // Check that the file was deleted
      std::ifstream deleted_file(filename.c_str());
      EXPECT_FALSE(deleted_file.good());
    }
    else {
      // Check that the file was not deleted
      std::ifstream not_deleted_file(filename.c_str());
      EXPECT_TRUE(not_deleted_file.good());
      Os::FileSystem::removeFile(filename.c_str());
      std::cout << "Next assert not part of test, just removing unnecessary file" << std::endl;
      // Check that the file was deleted
      std::ifstream deleted_file(filename.c_str());
      EXPECT_FALSE(deleted_file.good());
    }
  }

  

  void Tester::
    testNR_TestTwoFiles(Ref::FileRecyclerOp op, U32 num_files_removed, U32 count)
  {   
      // Ensures that there are no files in the storage directory
      U32 filecount = 2;
      Os::FileSystem::getFileCount(MEMESAT_STORAGE_DIR, filecount);
      ASSERT_TRUE(filecount == 0);
      // Create two files in the storage directory
      std::string file1path = std::string(MEMESAT_STORAGE_DIR) + "test1.txt";
      std::ofstream file1(file1path);
      file1 << "test1";
      file1.close();
      std::string file2path = std::string(MEMESAT_STORAGE_DIR) + "test2.txt";
      std::ofstream file2(file2path);
      file2 << "test2";
      file2.close();
      // Assert that two files now exist
      Os::FileSystem::getFileCount(MEMESAT_STORAGE_DIR, filecount);
      ASSERT_TRUE(filecount == 2);

      // Recycling files
      ASSERT_NO_THROW(this->sendCmd_CLEAN_UP_DATA(0, 10, count, op));

      // Check that the result contains the file names
      std::cout << "Expecting " << num_files_removed << " file(s) to be deleted." << std::endl;
      ASSERT_TLM_NUM_FILES_REMOVED(0, num_files_removed);
      ASSERT_TLM_NUM_FILES_REMOVED_SIZE(1);

      if (op == Ref::FileRecyclerOp::NUM){
        ASSERT_EVENTS_FILE_REMOVE_SIZE(num_files_removed);
        customAssert_file_remove(file1path.c_str(), "Os::FileSystem::Status::OP_OK", "Operation was successful", 0);
        customAssert_file_remove(file2path.c_str(), "Os::FileSystem::Status::OP_OK", "Operation was successful", 1);
      }
      else {
        U32 abs_val = static_cast<U32>(std::abs(static_cast<int>(count)-2));
        ASSERT_EVENTS_FILE_REMOVE_SIZE(abs_val);
        std::ifstream file1(file1path);
        std::ifstream file2(file2path);      
      }
      // Check that the files were deleted
      std::ifstream deleted_file1(file1path);
      std::ifstream deleted_file2(file2path);

      if (num_files_removed >= 2) {
        EXPECT_FALSE(deleted_file1.good());
        EXPECT_FALSE(deleted_file2.good());
      }
      else if (num_files_removed == 1) {
        EXPECT_FALSE(deleted_file1.good());
        EXPECT_TRUE(deleted_file2.good());
      }
      else if (num_files_removed == 0) {
        EXPECT_TRUE(deleted_file1.good());
        EXPECT_TRUE(deleted_file2.good());
      }
      // Remove the files manually
        std::cout << "Removing first file manually: " << Os::FileSystem::removeFile(file1path.c_str()) << std::endl;
        std::cout << "Removing second file manually: " << Os::FileSystem::removeFile(file2path.c_str()) << std::endl;
      
      //EXPECT_EQ(std::string(result[0].second), file1path);
      //EXPECT_EQ(std::string(result[1].second), file2path);
    }



  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_sendSchedule_handler(
        const NATIVE_INT_TYPE portNum,
        const nameString &name,
        const scheduleString &schedule,
        const Ref::ScheduleOp &action
    )
  {
    this->pushFromPortEntry_sendSchedule(name, schedule, action);
  }

  void Tester ::
    from_toFileRecyclerHandler_handler(
        const NATIVE_INT_TYPE portNum,
        U32 count,
        const Ref::FileRecyclerOp &op
    )
  {
    this->pushFromPortEntry_toFileRecyclerHandler(count, op);
  }

  // ----------------------------------------------------------------------
  // Helper methods
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts()
  {

    // cmdIn
    this->connect_to_cmdIn(
        0,
        this->component.get_cmdIn_InputPort(0)
    );

    // fileRecyclerOpIn
    this->connect_to_fileRecyclerOpIn(
        0,
        this->component.get_fileRecyclerOpIn_InputPort(0)
    );

    // scheduledHandler
    this->connect_to_scheduledHandler(
        0,
        this->component.get_scheduledHandler_InputPort(0)
    );

    // cmdRegOut
    this->component.set_cmdRegOut_OutputPort(
        0,
        this->get_from_cmdRegOut(0)
    );

    // cmdResponseOut
    this->component.set_cmdResponseOut_OutputPort(
        0,
        this->get_from_cmdResponseOut(0)
    );

    // eventOut
    this->component.set_eventOut_OutputPort(
        0,
        this->get_from_eventOut(0)
    );

    // prmGetOut
    this->component.set_prmGetOut_OutputPort(
        0,
        this->get_from_prmGetOut(0)
    );

    // prmSetOut
    this->component.set_prmSetOut_OutputPort(
        0,
        this->get_from_prmSetOut(0)
    );

    // sendSchedule
    this->component.set_sendSchedule_OutputPort(
        0,
        this->get_from_sendSchedule(0)
    );

    // textEventOut
    this->component.set_textEventOut_OutputPort(
        0,
        this->get_from_textEventOut(0)
    );

    // timeGetOut
    this->component.set_timeGetOut_OutputPort(
        0,
        this->get_from_timeGetOut(0)
    );

    // tlmOut
    this->component.set_tlmOut_OutputPort(
        0,
        this->get_from_tlmOut(0)
    );

    // toFileRecyclerHandler
    this->component.set_toFileRecyclerHandler_OutputPort(
        0,
        this->get_from_toFileRecyclerHandler(0)
    );




  }

  void Tester ::
    initComponents()
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace Ref
