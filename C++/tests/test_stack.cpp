#include <gtest/gtest.h>

#include "../include/stack.h"
#include "../include/timer.h"

TEST(StackTest, PushAndPop) {
  Timer timer;
  timer.start();
  Stack s;

  EXPECT_TRUE(s.isEmpty());

  s.push("A");

  EXPECT_FALSE(s.isEmpty());
  EXPECT_EQ(s.top(), "A");

  s.pop();

  EXPECT_TRUE(s.isEmpty());
  timer.elapsed();
}

TEST(StackTest, PopFromEmptyStack) {
  Timer timer;
  timer.start();
  Stack s;

  ASSERT_THROW(s.pop(), std::underflow_error);
  timer.elapsed();
}

TEST(StackTest, TopOnEmptyStack) {
  Timer timer;
  timer.start();
  Stack s;

  ASSERT_THROW(s.top(), std::underflow_error);
  timer.elapsed();
}

TEST(StackTest, MultiplePushAndPop) {
  Timer timer;
  timer.start();
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
  timer.elapsed();
}
