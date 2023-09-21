// ======================================================================
// \title  StateMachine.hpp
// \author michael
// \brief  hpp file for StateMachine component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef StateMachine_HPP
#define StateMachine_HPP

#include <thread>
#include <iostream>
#include <atomic>
#include "Ref/StateMachine/StateMachineComponentAc.hpp"
#include <string>
#include <map>

namespace Ref {

  class StateMachine :
    public StateMachineComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object StateMachine
      //!
      StateMachine(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object StateMachine
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object StateMachine
      //!
      ~StateMachine();

      void setState(State state);

      State getState() const;

      void setError(int);

      int getError();

    PRIVATE:

    //-------------------------------------------------------------------------
    //Variables
    //-------------------------------------------------------------------------
      Ref::State currentState = State::START_UP;
      Ref::State nextState;
      std::map<std::string, double> persistentData;
      std::map<std::string, double>::iterator it;
      bool command = false;
      int error = -1;

    PRIVATE:

    //-------------------------------------------------------------------------
    // Helper Methods
    //-------------------------------------------------------------------------

    void stateHandler();

    void checkState(State);



    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for Run
      //!
      void Run_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

      //! Handler implementation for ChangeState
      //!
      void ChangeState_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Ref::State &state /*!< 
      The state of the component
      */
      );


    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for CHANGE_STATE command handler
      //! Command from Ground Station to change state
      void CHANGE_STATE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Ref::State state /*!< 
          State to change to from Ground Station
          */
      );

      void updateCruise();
      void updateAnom();
      void updateCritPower();
      void update();
      void readyForPowerOff();
      void restart();
      void shutdown();



  };

} // end namespace Ref

#endif

#ifdef __APPLE_API_PRIVATE
#define RB_POWER_OFF    0x4000
#endif
