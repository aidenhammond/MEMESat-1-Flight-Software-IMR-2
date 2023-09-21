#include "Tester.hpp"

TEST(Nominal, toDo) {
  Ref::Tester tester;
  tester.toDo();
}
TEST(SchedulerTest, TestGetScheduleHandler) {
  Ref::Tester tester;
  tester.testGetScheduleHandler();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
