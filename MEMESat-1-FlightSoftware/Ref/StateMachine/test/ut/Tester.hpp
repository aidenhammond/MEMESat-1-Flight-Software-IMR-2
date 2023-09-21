// ======================================================================
// \title  StateMachine/test/ut/Tester.hpp
// \author michael
// \brief  hpp file for StateMachine test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include<chrono>
#include<thread>
#include "GTestBase.hpp"
#include "Ref/StateMachine/StateMachine.hpp"

namespace Ref {

  class Tester :
    public StateMachineGTestBase
  {

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object Tester
      //!
      Tester();

      //! Destroy object Tester
      //!
      ~Tester();

    public:

      // ----------------------------------------------------------------------
      // Tests
      // ----------------------------------------------------------------------

      void checkState();

      void changeState();

      int testInterupt();

      void safeAnomTest();

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts();

      //! Initialize components
      //!
      void initComponents();

      void setMode(State,int num = 1);


    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      StateMachine component;

  };

} // end namespace Ref

#endif
