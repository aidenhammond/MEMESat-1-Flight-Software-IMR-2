// ======================================================================
// \title  StateMachine.hpp
// \author michael
// \brief  cpp file for StateMachine test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "Tester.hpp"

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
      StateMachineGTestBase("Tester", MAX_HISTORY_SIZE),
      component("StateMachine")
#else
      StateMachineGTestBase(MAX_HISTORY_SIZE),
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

  void Tester::checkState(){
    State states[3] = {
      State::CRUISE,
      State::SAFE_ANOM,
      State::SAFE_CRIT_PWR
    };

    int targetState = 0;
    const U32 cmdSeq = 10;

    // Test to make sure first state is SAFE_ANOM

    this->invoke_to_Run(0,0);
    this->component.doDispatch();

    // Get the number of telem messages
    ASSERT_TLM_SIZE(1);
    // verify the desired telemetry channel was sent once
    ASSERT_TLM_STATE_SIZE(1);
    // verify the values of the telemetry channel
    ASSERT_TLM_STATE(0, states[1]);
    // verify one event was sent
    ASSERT_EVENTS_SIZE(1);
    // verify the expected event was sent once
    ASSERT_EVENTS_STATE_CHANGE_SIZE(1);
    // verify the expect value of the event
    ASSERT_EVENTS_STATE_CHANGE(0, states[1]);

    this->setMode(states[0]);

    int num;
    for (int i = 0; i < 3; i ++){
      for (int j = 0; j < 3; j++){

         // Find the correct mode for the test
        if (i == 0) {
          if (j == 0) {
            targetState = 0;
          } else if (j == 1) {
            targetState = 1;
          } else if (j == 2) {
            targetState = 2;
          }
        } else if (i == 1){
          if (j == 1 | j == 0) {
            targetState = 1;
          } else if (j == 2) {
            targetState = 2;
          }
        } else if (i == 2){
          if (j == 0 | j == 1){
            targetState = 1;
          } else if (j == 2){
            targetState = 2;
          }
        }

        // Run the change state command
        this->sendCmd_CHANGE_STATE(0,cmdSeq,states[i]);
        this->component.doDispatch();
        this->component.setError(j);

        this->invoke_to_Run(0,0);
        this->component.doDispatch();

        this->clearHistory();

        this->invoke_to_Run(0,0);
        this->component.doDispatch();

        if (targetState != i){
          // Get the number of telem messages
          ASSERT_TLM_SIZE(1);
          // verify the desired telemetry channel was sent once
          ASSERT_TLM_STATE_SIZE(1);
          // verify the values of the telemetry channel
          ASSERT_TLM_STATE(0, states[targetState]);
          // verify one event was sent
          ASSERT_EVENTS_SIZE(1);
          // verify the expected event was sent once
          ASSERT_EVENTS_STATE_CHANGE_SIZE(1);
          // verify the expect value of the event
          ASSERT_EVENTS_STATE_CHANGE(0, states[targetState]);
        }
      }
    }
  }

  void Tester::changeState(){
    State states[3] = {
      State::CRUISE,
      State::SAFE_ANOM,
      State::SAFE_CRIT_PWR
    };

    const U32 cmdSeq = 10;

    // Checks to make sure all states change state command can change states
    for (int i = 0; i < 3; i++){
      setMode(states[i],i);
    }

  }

  int Tester::testInterupt(){

    State states[3] = {
      State::CRUISE,
      State::SAFE_ANOM,
      State::SAFE_CRIT_PWR
    };

    int targetState = 0;
    const U32 cmdSeq = 10;

    // Test to make sure first state is SAFE_ANOM

    this->invoke_to_Run(0,0);
    this->component.doDispatch();

    // Get the number of telem messages
    ASSERT_TLM_SIZE(1);
    // verify the desired telemetry channel was sent once
    ASSERT_TLM_STATE_SIZE(1);
    // verify the values of the telemetry channel
    ASSERT_TLM_STATE(0, states[1]);
    // verify one event was sent
    ASSERT_EVENTS_SIZE(1);
    // verify the expected event was sent once
    ASSERT_EVENTS_STATE_CHANGE_SIZE(1);
    // verify the expect value of the event
    ASSERT_EVENTS_STATE_CHANGE(0, states[1]);

    this->setMode(states[0]);

    

    for (int i = 0; i < 3; i ++){
      for (int j = 0; j < 3; j++){
        if (i == 1 & j == 2 ){
          this->changeState();
          return 0;
        }
      }
    }
  }

  void Tester::safeAnomTest(){

    this->invoke_to_Run(0,0);
    this->component.doDispatch();

    // Get the number of telem messages
    ASSERT_TLM_SIZE(1);
    // verify the desired telemetry channel was sent once
    ASSERT_TLM_STATE_SIZE(1);
    // verify the values of the telemetry channel
    ASSERT_TLM_STATE(0, State::SAFE_ANOM);
    // verify one event was sent
    ASSERT_EVENTS_SIZE(1);
    // verify the expected event was sent once
    ASSERT_EVENTS_STATE_CHANGE_SIZE(1);
    // verify the expect value of the event
    ASSERT_EVENTS_STATE_CHANGE(0,  State::SAFE_ANOM);

    this->setMode(State::START_UP,0);

    this->invoke_to_Run(0,0);
    this->component.doDispatch();

    // Get the number of telem messages
    ASSERT_TLM_SIZE(0);
    // verify the desired telemetry channel was sent once
    ASSERT_TLM_STATE_SIZE(0);
    // verify one event was sent
    ASSERT_EVENTS_SIZE(0);
    // verify the expected event was sent once
    ASSERT_EVENTS_STATE_CHANGE_SIZE(0);
  }

  // ----------------------------------------------------------------------
  // Helper methods
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts()
  {

    // Run
    this->connect_to_Run(
        0,
        this->component.get_Run_InputPort(0)
    );

    // cmdIn
    this->connect_to_cmdIn(
        0,
        this->component.get_cmdIn_InputPort(0)
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

  void Tester::setMode(State mode, int num){
    const U32 cmdSeq = 10;

    this->clearHistory();

    // Set state to cruise
    // Run the change state command
    this->sendCmd_CHANGE_STATE(0,cmdSeq,mode);
    this->component.doDispatch();

    // Invoke the run port to simulate proto thread execution
    this->invoke_to_Run(0,0);
    this->component.doDispatch();

    if (num > 0){
      // Get the number of telem messages
      ASSERT_TLM_SIZE(1);
      // verify the desired telemetry channel was sent once
      ASSERT_TLM_STATE_SIZE(1);
      // verify the values of the telemetry channel
      ASSERT_TLM_STATE(0, mode);
      // verify one event was sent
      ASSERT_EVENTS_SIZE(1);
      // verify the expected event was sent once
      ASSERT_EVENTS_STATE_CHANGE_SIZE(1);
      // verify the expect value of the event
      ASSERT_EVENTS_STATE_CHANGE(0, mode);
    }
  }

} // end namespace Ref
