#include "Tester.hpp"
#include "Os/FileSystem.hpp"
#include <iostream>
#include <string>

TEST(TestNumRecycler_NUM, EmptyDirectory) {
    Ref::Tester tester;
    // This attempts to delete a single file when the directory is empty
    // using the NUM op
    tester.testNR_TestEmptyDirectory(Ref::FileRecyclerOp::NUM);
}

TEST(TestNumRecycler_NUM, OneFile) {
    Ref::Tester tester;
    // This attempts to delete a single file when the directory contains
    // one file using the MAX op. 
    //
    // The numerical argument is there just for readability to tell you 
    // how many files are expected to be deleted
    tester.testNR_TestOneFile(Ref::FileRecyclerOp::NUM, 1);
}

TEST(TestNumRecycler_NUM, OneFileLongName) {
  Ref::Tester tester;
  // Attempts to delete one file which has a long name (shouldn't be allowed to have a long name)
  tester.test_TestOneFileLongName(tester, Ref::FileRecyclerOp::NUM, 1);
}

TEST(TestNumRecycler_NUM, TwoFiles) {
    Ref::Tester tester;
    // expects 2 files to be deleted when the 2 argument for count is given
    // for the NUM enum in an environment where 2 files exist
    tester.testNR_TestTwoFiles(Ref::FileRecyclerOp::NUM, 2, 2);
}

TEST(TestNumRecycler_MAX, EmptyDirectory) {
    Ref::Tester tester;
    // This attempts to delete a single file when the directory is empty
    // using the MAX op
    tester.testNR_TestEmptyDirectory(Ref::FileRecyclerOp::MAX);
}

TEST(TestNumRecycler_MAX, OneFile) {
    Ref::Tester tester;
    // This attempts to delete a single file when the directory contains
    // one file using the NUM op. 
    //
    // The numerical argument is there just for readability to tell you 
    // how many files are expected to be deleted
    tester.testNR_TestOneFile(Ref::FileRecyclerOp::MAX, 0);

}

TEST(TestNumRecycler_MAX, TwoFiles_count_0) {
    Ref::Tester tester;
    // expects 2 files to be deleted when count is 0 when 2 files exist
    // and MAX enum is passed
    tester.testNR_TestTwoFiles(Ref::FileRecyclerOp::MAX, 2, 0);
}

TEST(TestNumRecycler_MAX, TwoFiles_count_1) {
    Ref::Tester tester;
    // expects 1 file to be deleted when count is 1 when 2 files exist
    // and MAX enum is passed
    tester.testNR_TestTwoFiles(Ref::FileRecyclerOp::MAX, 1, 1);
}

TEST(TestNumRecycler_MAX, TwoFiles_count_2) {
    Ref::Tester tester;
    // expects 0 files to be deleted when count is 2 and 2 files exist
    // and MAX enum is passed
    tester.testNR_TestTwoFiles(Ref::FileRecyclerOp::MAX, 0, 2);
}






int main(int argc, char **argv) {
  std::cout << "===========================" << std::endl; 
  std::cout << "=  PLEASE MAKE SURE THAT  =" << std::endl; 
  std::cout << "=  THE STORAGE DIRECTORY  =" << std::endl; 
  std::cout << "=     IS EMPTY BEFORE     =" << std::endl;
  std::cout << "=        BEGINNING        =" << std::endl;
  std::cout << "===========================" << std::endl; 
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
