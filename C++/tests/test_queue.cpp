#include "../src/queue.h"
#include "../src/timer.h"
#include <gtest/gtest.h>

TEST(QueueTest, PushAndFront) {
  Timer timer;
  timer.start();
  Queue q;

  EXPECT_TRUE(q.isEmpty());

  q.push("First");

  EXPECT_FALSE(q.isEmpty());
  EXPECT_EQ(q.front(), "First");

  q.push("Second");
  EXPECT_EQ(q.front(), "First");
  timer.elapsed();
}

TEST(QueueTest, Pop) {
  Timer timer;
  timer.start();
  Queue q;
  q.push("First");
  q.push("Second");

  EXPECT_EQ(q.front(), "First");

  q.pop();
  EXPECT_EQ(q.front(), "Second");

  q.pop();
  EXPECT_TRUE(q.isEmpty());
  timer.elapsed();
}

TEST(QueueTest, PopFromEmptyQueue) {
  Timer timer;
  timer.start();
  Queue q;

  ASSERT_THROW(q.pop(), std::overflow_error);
  timer.elapsed();
}

TEST(QueueTest, FrontOnEmptyQueue) {
  Timer timer;
  timer.start();
  Queue q;

  ASSERT_THROW(q.front(), std::overflow_error);
  timer.elapsed();
}

TEST(QueueTest, MultiplePushAndPop) {
  Timer timer;
  timer.start();
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
  timer.elapsed();
}

TEST(QueueTest, QueueWithOneElement) {
  Timer timer;
  timer.start();
  Queue q;

  q.push("OnlyElement");
  EXPECT_EQ(q.front(), "OnlyElement");

  q.pop();
  EXPECT_TRUE(q.isEmpty());
  timer.elapsed();
}
