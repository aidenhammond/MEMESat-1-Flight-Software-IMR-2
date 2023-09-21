#include "Tester.hpp"

TEST(Nominal, ChangeStateCommand) {
    Ref::Tester tester;
    tester.changeState();
}

TEST(Nominal, CheckState) {
    Ref::Tester tester;
    tester.checkState();
}

TEST(Nominal, InteruptState) {
    Ref::Tester tester;
    tester.testInterupt();
}

TEST(Nominal, SafeAnom) {
    Ref::Tester tester;
    tester.safeAnomTest();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}