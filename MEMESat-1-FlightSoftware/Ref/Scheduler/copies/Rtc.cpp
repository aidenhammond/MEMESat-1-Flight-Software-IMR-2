// ======================================================================
// \title  Rtc.cpp
// \author aiden
// \brief  cpp file for Rtc component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Rtc/Rtc.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "../libcron/libs/Cron.h"
#include "../libcron/libs/TaskQueue.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
namespace Ref {
  static libcron::Cron cron;
  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  Rtc ::
    Rtc(
        const char *const compName
    ) : RtcComponentBase(compName)
  {

  }

  void Rtc ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    RtcComponentBase::init(queueDepth, instance);
  }

  Rtc ::
    ~Rtc()
  {

  }

  // ----------------------------------------------------------------------
  // Custom Functions 
  // ----------------------------------------------------------------------
  void schedule_list_to_file()
  {
		cron.tasks.lock_queue();
		std::vector<libcron::Task> tasks = cron.tasks.get_tasks();
    cron.tasks.release_queue();
    std::ofstream file_of_schedules;
    file_of_schedules.open("schedules.txt", std::ios::trunc);
		if (file_of_schedules.is_open()) {
    	for(auto &task : tasks) {
      	file_of_schedules << task.get_name() << std::endl;
    	}
      file_of_schedules.close();
    }
  }
  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Rtc ::
    removeCronSchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        const nameString &name
    )
  {
    cron.remove_schedule(name.toChar());
    // TODO
  }

  void Rtc ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    cron.tick();
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void Rtc ::
    GET_SCHEDULE_LIST_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const destFileNameString& destFileName
    )
  {
    // TODO
    schedule_list_to_file();
    this->schedOut_out(0, "schedule.txt", destFileName.toChar(), 0, 0);
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void Rtc ::
    REMOVE_SCHED_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdStringArg& name
    )
  {
    // TODO
		cron.remove_schedule(name.toChar());
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void Rtc ::
    CHANGE_SCHED_FREQ_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdStringArg& name,
        const Fw::CmdStringArg& new_sched
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }
  void Rtc ::
    ADD_SCHEDULE(
      const std::string name,
      const std::string schedule,
      void (*funct)()
    )
  {
    cron.add_schedule(name, schedule, [=](auto&) {
      funct();
    });
  }
      

} // end namespace Ref
