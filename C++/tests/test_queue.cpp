#include "../src/queue.h"
#include <gtest/gtest.h>

TEST(QueueTest, PushAndFront) {
  Queue q;

  EXPECT_TRUE(q.isEmpty());

  q.push("First");

  EXPECT_FALSE(q.isEmpty());
  EXPECT_EQ(q.front(), "First");

  q.push("Second");
  EXPECT_EQ(q.front(), "First");
}

TEST(QueueTest, Pop) {
  Queue q;
  q.push("First");
  q.push("Second");

  EXPECT_EQ(q.front(), "First");

  q.pop();
  EXPECT_EQ(q.front(), "Second");

  q.pop();
  EXPECT_TRUE(q.isEmpty());
}

TEST(QueueTest, PopFromEmptyQueue) {
  Queue q;

  ASSERT_THROW(q.pop(), std::overflow_error);
}

TEST(QueueTest, FrontOnEmptyQueue) {
  Queue q;

  ASSERT_THROW(q.front(), std::overflow_error);
}

TEST(QueueTest, MultiplePushAndPop) {
  Queue q;

  q.push("First");
  q.push("Second");
  q.push("Third");

  EXPECT_EQ(q.front(), "First");

  q.pop();
  EXPECT_EQ(q.front(), "Second");
  q.pop();
  EXPECT_EQ(q.front(), "Third");
  q.pop();

  EXPECT_TRUE(q.isEmpty());
}

TEST(QueueTest, QueueWithOneElement) {
  Queue q;

  q.push("OnlyElement");
  EXPECT_EQ(q.front(), "OnlyElement");

  q.pop();
  EXPECT_TRUE(q.isEmpty());
}