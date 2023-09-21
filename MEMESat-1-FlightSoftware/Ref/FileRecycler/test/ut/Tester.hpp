// ======================================================================
// \title  FileRecycler/test/ut/Tester.hpp
// \author aiden
// \brief  hpp file for FileRecycler test harness implementation class
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
#include "Ref/FileRecycler/FileRecycler.hpp"


namespace Ref {

  class Tester :
    public FileRecyclerGTestBase
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

      
      void toDo();
      void testNum();
      void testMax();
      void testBefore();
      void testAfter();
      void testNR_TestEmptyDirectory(Ref::FileRecyclerOp &op);
      void testNR_TestOneFile(Ref::FileRecyclerOp &op, U32 num_files_removed);
      void test_TestOneFileLongName(Ref::FileRecyclerOp &op, U32 num_files_removed);
      void testNR_TestTwoFiles(Ref::FileRecyclerOp op, U32 num_files_remaining, U32 count);
      void testOneFileHandler(Ref::FileRecyclerOp &op, U32 num_files_removed, std::string filename);
      void prepend_path(char* filename);
      std::tm* get_time();
      void testCleanUpData(U64 count, FileRecyclerOp op);      
    private:
      void customAssert_file_remove(const char* filename, const char* status , const char* message, int index = 0);
      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_sendSchedule
      //!
      void from_sendSchedule_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const nameString &name, /*!< 
      Name of schedule for libcron task
      */
          const scheduleString &schedule, /*!< 
      Schedule in libcron format
      */
          const Ref::ScheduleOp &action 
      );

      //! Handler for from_toFileRecyclerHandler
      //!
      void from_toFileRecyclerHandler_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 count, /*!< 
      File attribute that determines which files are deleted
      */
          const Ref::FileRecyclerOp &op 
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
      FileRecycler component;

    protected:
      void SetUp();
      void TearDown();

  };

} // end namespace Ref

#endif
