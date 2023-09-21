// ======================================================================
// \title  Scheduler.hpp
// \author aiden
// \brief  hpp file for Scheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Scheduler_HPP
#define Scheduler_HPP

#include "Ref/Scheduler/SchedulerComponentAc.hpp"
#include "Svc/FileDownlink/FileDownlink.hpp"
#include "Fw/Logger/Logger.hpp"
#include "../libcron/libs/Cron.h"
#include "../libcron/libs/TaskQueue.h"
#include <string>
#include <functional>
namespace Ref {

  class Scheduler :
    public SchedulerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Scheduler
      //!
      Scheduler(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object Scheduler
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Scheduler
      //!
      ~Scheduler();

      std::vector<libcron::Task> get_tasks();


    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for getSchedule
      //!
      void getSchedule_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const nameString &name, /*!< 
      Name of schedule for libcron task
      */
          const scheduleString &schedule, /*!< 
      Schedule in libcron format
      */
          const Ref::ScheduleOp &action 
      );

      //! Handler implementation for tick
      //!
      void tick_handler(
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
      //! Downlinks file containing a list of the current schedules
      void GET_SCHEDULE_LIST_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdStringArg& destFileName /*!< 
          Path to store downlinked schedule list at
          */
      );
      void STOP_SCHEDULE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdStringArg& name 
      );

    };

} // end namespace Ref

#endif
