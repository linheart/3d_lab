#include "../src/stack.h"
#include <gtest/gtest.h>

TEST(StackTest, PushAndPop) {
  Stack s;

  EXPECT_TRUE(s.isEmpty());

  s.push("A");

  EXPECT_FALSE(s.isEmpty());
  EXPECT_EQ(s.top(), "A");

  s.pop();

  EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, PopFromEmptyStack) {
  Stack s;

  ASSERT_THROW(s.pop(), std::underflow_error);
}

TEST(StackTest, TopOnEmptyStack) {
  Stack s;

  ASSERT_THROW(s.top(), std::underflow_error);
}

TEST(StackTest, MultiplePushAndPop) {
  Stack s;

  s.push("A");
  s.push("B");
  s.push("C");

  EXPECT_EQ(s.top(), "C");

  s.pop();
  EXPECT_EQ(s.top(), "B");

  s.pop();
  EXPECT_EQ(s.top(), "A");

  s.pop();

  EXPECT_TRUE(s.isEmpty());
}
