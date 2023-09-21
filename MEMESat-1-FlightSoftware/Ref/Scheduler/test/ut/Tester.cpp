// ======================================================================
// \title  Scheduler.hpp
// \author aiden
// \brief  cpp file for Scheduler test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "Tester.hpp"
#include "../../../libcron/libs/Cron.h"
#include <thread>
#include "../../../libcron/libs/TaskQueue.h"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester() :
#if FW_OBJECT_NAMES == 1
      SchedulerGTestBase("Tester", MAX_HISTORY_SIZE),
      component("Scheduler")
#else
      SchedulerGTestBase(MAX_HISTORY_SIZE),
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

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------

  void Tester :: 
    testGetScheduleHandler()
  {
    this->init();
    // Test with valid input
    std::cout << "Test with valid input" << std::endl;
    this->invoke_to_getSchedule(0, "FileRecycler", "* * * * *", Ref::ScheduleOp::START);
    ASSERT_from_runSchedule_SIZE(1);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::vector<libcron::Task> tasks = component.get_tasks();
    std::cout << tasks.size() << std::endl;
    //EXPECT_EQ(tasks.size(), 1);
    /*EXPECT_EQ(tasks[0].get_name(), "FileRecycler");

    // Test with invalid port number
    std::cout << "Test with invalid port number" << std::endl;
    this->invoke_to_getSchedule(10, "TlmChanWrapper", "* * * * *", Ref::ScheduleOp::START);
    tasks = component.get_tasks();
    EXPECT_EQ(tasks.size(), 1);

    // Test with empty name string
    std::cout << "Test with empty name string" << std::endl;
    this->invoke_to_getSchedule(0, "", "* * * * *", Ref::ScheduleOp::START);
    tasks = component.get_tasks();
    EXPECT_EQ(tasks.size(), 1);*/
  }

  void Tester :: 
    testPorts() 
  {
    this->connectPorts();
    std::vector<libcron::Task> tasks = component.get_tasks();
    EXPECT_EQ(tasks.size(), 2);
  }
  
  void Tester ::
    toDo()
  {
    //this->clearHistory();
    //this->invoke_to_getSchedule(0, "FileRecycler", "* * * * * ?", Ref::ScheduleOp::START);
    //this->component.doDispatch();
    //ASSERT_EVENTS_SIZE(2);
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  Svc::SendFileResponse Tester ::
    from_DownlinkCurrentSchedules_handler(
        const NATIVE_INT_TYPE portNum,
        const Svc::sourceFileNameString &sourceFileName,
        const Svc::destFileNameString &destFileName,
        U32 offset,
        U32 length
    )
  {
    this->pushFromPortEntry_DownlinkCurrentSchedules(sourceFileName, destFileName, offset, length);
    // TODO: Return a value
  }

  void Tester ::
    from_runSchedule_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::ScheduleStatus &status
    )
  {
    this->pushFromPortEntry_runSchedule(status);
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

    // getSchedule
    for (NATIVE_INT_TYPE i = 0; i < 2; ++i) {
      this->connect_to_getSchedule(
          i,
          this->component.get_getSchedule_InputPort(i)
      );
    }

    // tick
    this->connect_to_tick(
        0,
        this->component.get_tick_InputPort(0)
    );

    // DownlinkCurrentSchedules
    this->component.set_DownlinkCurrentSchedules_OutputPort(
        0,
        this->get_from_DownlinkCurrentSchedules(0)
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

    // runSchedule
    for (NATIVE_INT_TYPE i = 0; i < 2; ++i) {
      this->component.set_runSchedule_OutputPort(
          i,
          this->get_from_runSchedule(i)
      );
    }

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
