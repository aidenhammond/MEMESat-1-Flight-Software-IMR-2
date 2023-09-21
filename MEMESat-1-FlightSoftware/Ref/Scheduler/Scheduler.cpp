// ======================================================================
// \title  Scheduler.cpp
// \author aiden
// \brief  cpp file for Scheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Scheduler/Scheduler.hpp>

#include "Fw/Types/BasicTypes.hpp"


#include <thread>

#include <chrono>

#include <iostream>

#include <fstream>

#include <vector>

#include <unordered_map>

namespace Ref {
  /*
   * 'Cron' is a template class. When included in a cpp file,
   * the compiler can figure out the template arguments for the
   * object. However, if it is included in an hpp file, the 
   * compiler is unaware of what the template arguments will be
   * for all implementations of the object. Thus, the Cron object
   * must exist in this cpp file and any actions necessary for
   * testing need to be defined here.
   */
  // can figure above out after run
  libcron::Cron cron;
  

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  Scheduler ::
    Scheduler(
        const char *const compName
    ) : SchedulerComponentBase(compName)
  {

  }

  void Scheduler ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    SchedulerComponentBase::init(queueDepth, instance);
  }

  Scheduler ::
    ~Scheduler()
  {

  }

  static char* schedule_parser(
    char* input
  ) 
  {
    // add regex for cron scheduling according to libcron github page
    // also parsing for "REMOVE/remove" or "ADD/add"
    return (char*)"";
  }
  std::vector<libcron::Task> Scheduler ::
    get_tasks()
  {
    cron.tasks.lock_queue();
    std::vector<libcron::Task> tasks = cron.tasks.get_tasks();
    cron.tasks.release_queue();
    return tasks;
  }

  // ----------------------------------------------------------------------
  // Custom Functions
  // ----------------------------------------------------------------------

  /*
   * This function was made to generate a file to be downlinked which 
   * contains a list of the names of the tasks being run on the 
   * cron objcet
  */
  void schedule_list_to_file()
  {
    // Do we need to handle potential queuing on the mutex?

    // Getting the tasks
    cron.tasks.lock_queue();
    std::vector<libcron::Task> tasks = cron.tasks.get_tasks();
    cron.tasks.release_queue();

    std::ofstream file_of_schedules;
    // MemberTypeFailure exception thrown on fail
    // Check failbit
    // Opens the file
    file_of_schedules.open("schedules.txt", std::ios::trunc);

    // If it is open, loop through the tasks on the cron object,
    // get_name() and shove into file
    if (file_of_schedules.is_open())
    {

        for(auto &task : tasks)
        {

            file_of_schedules << task.get_name() << std::endl;

        }

      file_of_schedules.close();

    }

  }


  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Scheduler ::
    getSchedule_handler(
        const NATIVE_INT_TYPE portNum,
        const nameString &name,
        const scheduleString &schedule,
        const Ref::ScheduleOp &action
    )
  {

    const char* name_str = name.toChar();
    const char* schedule_str = schedule.toChar(); 
    // Make sure that the inputted port is not greater than the actual number of ports
    NATIVE_INT_TYPE actual_number_of_ports = this->getNum_getSchedule_InputPorts();
    if (actual_number_of_ports < portNum) {
        this->log_WARNING_LO_WARN_PORT_NUM_GET_SCHEDULE_HANDLER(portNum);
        return;
    } 
    
    // add character check, ensure correctly format
    if (name_str == NULL || name_str[0] == '\0') {
      this->log_WARNING_LO_NAME_STRING_EMPTY(portNum);
      return;
    }

    // add schedule parsing, use event SCHEDULE_INCORRECT(schedule_str, portNum, name_str, status)
    // only parse if action != STOP

    bool isTask = false; 
    std::vector<libcron::Task> tasks = get_tasks();
    for (auto &task : tasks) {
      if (strcmp(task.get_name().c_str(), name_str)) {
        isTask = true;
      } 
    }
    Ref::ScheduleStatus currentStatus = isTask ? Ref::ScheduleStatus::RUNNING : Ref::ScheduleStatus::STOPPED; 
    // Make a separate event for before run vs after run
    this->log_ACTIVITY_LO_TASK_RUNNING(name_str, currentStatus); 
    try{
      switch(action.e) {
        case ScheduleOp::START:
          if (isTask) {
            cron.remove_schedule(name_str);
            currentStatus = Ref::ScheduleStatus::STOPPED;
          } 
          currentStatus = Ref::ScheduleStatus::RUNNING;
          cron.add_schedule(name_str, schedule_str, [=](auto&) {
            this->runSchedule_out(portNum, currentStatus);
          });
        break;
        case ScheduleOp::STOP:
          cron.remove_schedule(name_str);
          currentStatus = Ref::ScheduleStatus::STOPPED;
          break;
        default:
          currentStatus = Ref::ScheduleStatus::FAILED;
          break;
      }
    }
    catch(...) {
      currentStatus = Ref::ScheduleStatus::FAILED;
    }
    this->log_ACTIVITY_LO_TASK_RUNNING(name_str, currentStatus); 

    // Telemetry specific
    if (portNum == 0) {
      this->tlmWrite_FILE_RECYCLER_PORT_STATUS(currentStatus);
    }
    else if (portNum == 1) {
      this->tlmWrite_TLM_CHAN_PORT_STATUS(currentStatus);
    }
  }

  void Scheduler ::
    tick_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // Ensure that this doesn't throw anything
    cron.tick();
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void Scheduler ::
    GET_SCHEDULE_LIST_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdStringArg& destFileName
    )
  {
    const char* destination_file_name = destFileName.toChar();
    schedule_list_to_file();
    this->DownlinkCurrentSchedules_out(0, "schedules.txt", destination_file_name, 0, 0);
    this->log_DIAGNOSTIC_DOWNLINKED_SCHEDULE(destination_file_name);
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }
  void Scheduler ::
    STOP_SCHEDULE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdStringArg& name
    )
  {
    cron.remove_schedule(name.toChar());
    // Check if stopped
    this->log_ACTIVITY_LO_TASK_RUNNING(name.toChar(), ScheduleStatus::STOPPED);
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  // ----------------------------------------------------------------------
  // Functions for testing
  // ----------------------------------------------------------------------

  
  

} // end namespace Ref
