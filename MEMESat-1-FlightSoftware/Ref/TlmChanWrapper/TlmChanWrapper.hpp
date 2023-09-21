// ======================================================================
// \title  TlmChanWrapper.hpp
// \author michael
// \brief  hpp file for TlmChanWrapper component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TlmChanWrapper_HPP
#define TlmChanWrapper_HPP

#include "Ref/TlmChanWrapper/TlmChanWrapperComponentAc.hpp"

namespace Ref {

  class TlmChanWrapper :
    public TlmChanWrapperComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object TlmChanWrapper
      //!
      TlmChanWrapper(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object TlmChanWrapper
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object TlmChanWrapper
      //!
      ~TlmChanWrapper();

    PRIVATE:
      void preamble() override;
      void parameterUpdated(
        FwPrmIdType id
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

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

      //! Implementation for CHANGE_SCHEDULE command handler
      //! clean up data
      void CHANGE_SCHEDULE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdStringArg& sched, 
          const Ref::ScheduleOp action
      );

    };

} // end namespace Ref

#endif
