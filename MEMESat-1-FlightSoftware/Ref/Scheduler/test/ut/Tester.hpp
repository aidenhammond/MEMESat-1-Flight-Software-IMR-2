// ======================================================================
// \title  Scheduler/test/ut/Tester.hpp
// \author aiden
// \brief  hpp file for Scheduler test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "GTestBase.hpp"
#include "Ref/Scheduler/Scheduler.hpp"

namespace Ref {

  class Tester :
    public SchedulerGTestBase
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

      //! To do
      //!
      void toDo();
      void testGetScheduleHandler();
      void testPorts();

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_DownlinkCurrentSchedules
      //!
      Svc::SendFileResponse from_DownlinkCurrentSchedules_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Svc::sourceFileNameString &sourceFileName, /*!< 
      Path of file to downlink
      */
          const Svc::destFileNameString &destFileName, /*!< 
      Path to store downlinked file at
      */
          U32 offset, /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
          U32 length /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
      );

      //! Handler for from_runSchedule
      //!
      void from_runSchedule_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Ref::ScheduleStatus &status 
      );

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

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      Scheduler component;

  };

} // end namespace Ref

#endif
