// ======================================================================
// \title  FileRecycler.hpp
// \author aiden
// \brief  hpp file for FileRecycler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef FileRecycler_HPP
#define FileRecycler_HPP

#include "Ref/FileRecycler/FileRecyclerComponentAc.hpp"
#include <vector>
#include <utility>
#include <string>
#include <mutex>
#include <Os/Directory.hpp>
#include <Os/FileSystem.hpp>
#include <array>
#include <unistd.h>


#define MEMESAT_STORAGE_DIR_MAX_LEN 256

/**
 * Need to change from compile time to runtime
*/
#ifdef __arm__
  #define MEMESAT_STORAGE_DIR "/storage/images"
#else
  #ifdef __APPLE__ 
    #define MEMESAT_STORAGE_DIR "/Users/aiden/MEMESat-1-FlightSoftware/Ref/storage/"
  #endif
  #ifdef __linux__
    #define MEMESAT_STORAGE_DIR "/storage/images"
  #endif
#endif
constexpr std::array<const char*, 12> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
//constexpr char MEMESAT_STORAGE_DIR[] = "/Users/aiden/MEMESat-1-FlightSoftware/Ref/storage/";

namespace Ref {
  class FileRecycler :
    public FileRecyclerComponentBase
  {

    public:
      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object FileRecycler
      //!
      FileRecycler(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object FileRecycler
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object FileRecycler
      //!
      ~FileRecycler();



    PRIVATE:
      void preamble() override;
      void parameterUpdated(
        FwPrmIdType id
      ) override;
      
    PRIVATE:
      void recycler_call_on_reset_handler();

      template <typename T>
      Ref::FauxOsStatus convertOsStatusToFaux(const T& status);

      void handleStatError(int valueFromStat);

      void logRecyclerOutput (
        std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> return_value /*!< The return value from recycler */
      );

    PRIVATE:
      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for fileRecyclerOpIn
      //!
      void fileRecyclerOpIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 count, /*!< 
      File attribute that determines which files are deleted
      */
          const Ref::FileRecyclerOp &op 
      ) override;

      //! Handler implementation for readyForPowerOff
      //!
      void readyForPowerOff_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool result /*!< 
      Whether or not something was completed successfully
      */
      ) override;

      //! Handler implementation for scheduledHandler
      //!
      void scheduledHandler_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Ref::ScheduleStatus &status
      ) override;
         
    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for CLEAN_UP_DATA command handler
      //! clean up data
      void CLEAN_UP_DATA_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 count, /*!< 
          file attribute that determines which files are deleted
          */
          Ref::FileRecyclerOp op 
      ) override;

      bool shutdown;

      Os::Directory directory;
      //std::vector<std::tuple<time_t, std::string, Os::FileSystem::Status>> num_recycler(U32 count, const Ref::FileRecyclerOp &op);
      std::vector<std::tuple<time_t, std::string, Ref::FauxOsStatus>> recycler(U32 count, const Ref::FileRecyclerOp &op);
      std::mutex directory_mutex;
    };

} // end namespace Ref

#endif
