#include <gtest/gtest.h>

#include "../include/list.h"
#include "../include/timer.h"

TEST(SinglyLinkedListTest, AddHead) {
  Timer timer;
  timer.start();
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second First \n");
  timer.elapsed();
}

TEST(SinglyLinkedListTest, AddTail) {
  Timer timer;
  timer.start();
  SinglyLinkedList list;
  list.addTail("First");
  list.addTail("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First Second \n");
  timer.elapsed();
}

TEST(SinglyLinkedListTest, RemoveHead) {
  Timer timer;
  timer.start();
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeHead();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First \n");
  timer.elapsed();
}

TEST(SinglyLinkedListTest, RemoveTail) {
  Timer timer;
  timer.start();
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeTail();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
  timer.elapsed();
}

TEST(SinglyLinkedListTest, RemoveByValue) {
  Timer timer;
  timer.start();
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeByValue("First");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
  timer.elapsed();
}

TEST(SinglyLinkedListTest, Search) {
  Timer timer;
  timer.start();
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  EXPECT_TRUE(list.search("First"));
  EXPECT_FALSE(list.search("NonExistent"));
  timer.elapsed();
}

TEST(DoublyLinkedListTest, AddHead) {
  Timer timer;
  timer.start();
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second First \n");
  timer.elapsed();
}

TEST(DoublyLinkedListTest, AddTail) {
  Timer timer;
  timer.start();
  DoublyLinkedList list;
  list.addTail("First");
  list.addTail("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First Second \n");
  timer.elapsed();
}

TEST(DoublyLinkedListTest, RemoveHead) {
  Timer timer;
  timer.start();
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeHead();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First \n");
  timer.elapsed();
}

TEST(DoublyLinkedListTest, RemoveTail) {
  Timer timer;
  timer.start();
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeTail();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
  timer.elapsed();
}

TEST(DoublyLinkedListTest, RemoveByValue) {
  Timer timer;
  timer.start();
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeByValue("First");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
  timer.elapsed();
}

TEST(DoublyLinkedListTest, Search) {
  Timer timer;
  timer.start();
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  EXPECT_TRUE(list.search("First"));
  EXPECT_FALSE(list.search("NonExistent"));
  timer.elapsed();
}
