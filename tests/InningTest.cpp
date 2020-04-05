#include "gtest/gtest.h"

#include "Inning.h"
#include "Variables.h"
#include "Team.h"
#include "GameTeam.h"

class InningTest : public ::testing::Test {
protected:

    InningTest() {
      Team home = Team("PUC");
      GameTeam gt = GameTeam(home, TeamStatus::HOME);
      inn = new Inning(gt);
    }
    
    virtual void SetUp() {
      inn->initializer();
    }

    Inning *inn;
};

TEST_F(InningTest, BasesEmpty_ActionSingle) {
  inn->_single();
  std::vector<int> expected = {1, 0, 0};
  ASSERT_EQ(expected, inn->bases());
  ASSERT_EQ(0, inn->outs());
  ASSERT_EQ(0, inn->points());
}

TEST_F(InningTest, Bases1_ActionSingle) {
  inn->_single();
  inn->_single();
  std::vector<int> expected = {1, 1, 0};
  ASSERT_EQ(expected, inn->bases());
  ASSERT_EQ(0, inn->outs());
  ASSERT_EQ(0, inn->points());
}

TEST_F(InningTest, Bases12_ActionSingle) {
  inn->_single();
  inn->_single();
  inn->_single();
  std::vector<int> expected = {1, 1, 1};
  ASSERT_EQ(expected, inn->bases());
  ASSERT_EQ(0, inn->outs());
  ASSERT_EQ(0, inn->points());
}

TEST_F(InningTest, Bases123_ActionSingle) {
  inn->_single();
  inn->_single();
  inn->_single();
  inn->_single();
  std::vector<int> expected = {1, 1, 1};
  ASSERT_EQ(expected, inn->bases());
  ASSERT_EQ(0, inn->outs());
  ASSERT_EQ(1, inn->points());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}