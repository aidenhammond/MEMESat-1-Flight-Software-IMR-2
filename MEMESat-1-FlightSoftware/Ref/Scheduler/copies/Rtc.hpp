// ======================================================================
// \title  Rtc.hpp
// \author aiden
// \brief  hpp file for Rtc component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Rtc_HPP
#define Rtc_HPP

#include "Ref/Rtc/RtcComponentAc.hpp"
#include "Svc/FileDownlink/FileDownlink.hpp"
#include <string>

namespace Ref {

  class Rtc :
    public RtcComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Rtc
      //!
      Rtc(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object Rtc
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Rtc
      //!
      ~Rtc();

      static void ADD_SCHEDULE(
          const std::string name,
          const std::string schedule,
          void (*funct)()
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for removeCronSchedIn
      //!
      void removeCronSchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const nameString &name /*!< 
      name of the task to remove
      */
      );

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for GET_SCHEDULE_LIST command handler
      //! 
      void GET_SCHEDULE_LIST_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const destFileNameString& destFileName
      );

      //! Implementation for REMOVE_SCHED command handler
      //! 
      void REMOVE_SCHED_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdStringArg& name 
      );

      //! Implementation for CHANGE_SCHED_FREQ command handler
      //! 
      void CHANGE_SCHED_FREQ_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdStringArg& name, 
          const Fw::CmdStringArg& new_sched 
      );



    };

} // end namespace Ref

#endif
