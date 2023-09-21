// ======================================================================
// \title  StateMachine.cpp
// \author michael
// \brief  cpp file for StateMachine component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/StateMachine/StateMachine.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/reboot.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  StateMachine ::
    StateMachine(
        const char *const compName
    ) : StateMachineComponentBase(compName)
  {
    this->nextState = State::SAFE_ANOM;
    // I know this does not use the Fprime File object but it would have been less readable and more code
    std::ifstream file;
    file.open("persistent_data.txt");
    if (file.is_open()){
      std::string line;
      std::string param;
      double value;
      while (std::getline(file, line)){
        param = line.substr(0, line.find(':'));
        value = std::stod(line.substr(line.find(':') + 1));
        persistentData[param] = value;
      }
    }


  }

  void StateMachine ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    StateMachineComponentBase::init(queueDepth, instance);;
  }

  StateMachine ::
    ~StateMachine()
  {

  }

  void StateMachine::setError(int error){
    this->error = error;
  }

  int StateMachine::getError() {
    return this->error;
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

    void StateMachine ::
    Run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->update();
  }

  void StateMachine ::
    ChangeState_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::State &state
    )
  {
    if (state != State::CRUISE){
      this->setState((State)state);
      this->log_ACTIVITY_HI_STATE_CHANGE(this->getState());
    } else {
      this->log_WARNING_HI_AUTO_SWITCH_TO_CRUISE();
    }
    
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void StateMachine ::
    CHANGE_STATE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::State state
    )
  {
    this->nextState = state;
    this->tlmWrite_STATE(this->nextState);
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void StateMachine::
    setState(Ref::State state)
  {
    this->nextState = state;
    this->command = true;
  }

  State StateMachine::
    getState() const
  {
    return this->currentState;
  }

  void StateMachine::checkState(Ref::State state){
    this->command = false;
    if (this->currentState.e != state.e & state.e != State::START_UP){
      this->currentState = this->nextState;

      this->tlmWrite_STATE(this->nextState);
    }
  }

  // // All states look for the command bool before setting mode
  void StateMachine::updateCruise(){
    // need to allow people other than use to uplink
    // this will have to be done in the radio component

    // make sure the radio baud is 9600


  }

  void StateMachine::updateAnom(){
    // restrict communication to ssrl ground station - not sure how to do this
    // no more bbs comm until move back to cruise mode - same as above
    // baud rate is set to 9600 why are we changing the baud again instead of keeping it high

  }

  void StateMachine::updateCritPower(){
    this->shutdown();
  }

  // ready the system for poweroff
  // The file manager will make sure the directory instance is closed and reject any attempts to open it
  // the eps will message the mcu to tell it to switch comms to the eps mcu and stop receiving messages from the mcu
  void StateMachine::readyForPowerOff(){
    // send shutdown command to file manager
    // wait for response
    this->readyForPowerOff_out(0,0);
    // send shutdown command to eps so comm is switched to eps mcu
    // wait for response

    U8 msg[4] = {
      0x04,
      0x0E,
      0x01,
      0x05
    };
    Fw::Buffer shutdownMsg(msg,4 );
    this->epsCommand_out(0,shutdownMsg);
    // saves all persistent data to the file system
    std::ofstream file;
    file.open("persistent_data.txt",std::ios::trunc);
    if (file.is_open()){
      for (auto const& x : this->persistentData){
        file << x.first << ":" << x.second << std::endl;
      }
    }
    file.close();
  }

  void StateMachine::restart(){
    this->persistentData["restart"]++;
    this->readyForPowerOff();
    this->tlmWrite_RESTART_COUNT(this->persistentData["restarts"]);
    this->log_ACTIVITY_HI_RESTART();
    sync();
    reboot(RB_AUTOBOOT);
  }

  void StateMachine::shutdown(){
    this->persistentData["shutdowns"]++;
    this->tlmWrite_SHUTDOWN_COUNT(this->persistentData["shutdowns"]);
    this->readyForPowerOff();
    this->log_ACTIVITY_HI_SHUTDOWN();
    sync();
    reboot(RB_POWER_OFF);
  }

  void StateMachine::update() {
    this->checkState(this->nextState);
    switch (this->currentState.e)
    {
      case State::CRUISE:
        this->updateCruise();
        break;
      case State::SAFE_ANOM:
        this->updateAnom();
        break;
      case State::SAFE_CRIT_PWR:
        this->updateCritPower();
        break;
      case State::START_UP:
        this->nextState = State::SAFE_ANOM;
        break;
      case State::RESTART:
        this->restart();
        break;
      case State::SHUTDOWN:
        this->shutdown();
        break;
      default:
        this->nextState = State::SAFE_ANOM;
        this->updateAnom();
        break;
    }
  }

} // end namespace Ref
