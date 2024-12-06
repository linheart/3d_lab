#include "../src/list.h"
#include <gtest/gtest.h>

TEST(SinglyLinkedListTest, AddHead) {
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second First \n");
}

TEST(SinglyLinkedListTest, AddTail) {
  SinglyLinkedList list;
  list.addTail("First");
  list.addTail("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First Second \n");
}

TEST(SinglyLinkedListTest, RemoveHead) {
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeHead();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First \n");
}

TEST(SinglyLinkedListTest, RemoveTail) {
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeTail();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
}

TEST(SinglyLinkedListTest, RemoveByValue) {
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeByValue("First");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
}

TEST(SinglyLinkedListTest, Search) {
  SinglyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  EXPECT_TRUE(list.search("First"));
  EXPECT_FALSE(list.search("NonExistent"));
}

TEST(DoublyLinkedListTest, AddHead) {
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second First \n");
}

TEST(DoublyLinkedListTest, AddTail) {
  DoublyLinkedList list;
  list.addTail("First");
  list.addTail("Second");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First Second \n");
}

TEST(DoublyLinkedListTest, RemoveHead) {
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeHead();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "First \n");
}

TEST(DoublyLinkedListTest, RemoveTail) {
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeTail();

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
}

TEST(DoublyLinkedListTest, RemoveByValue) {
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");
  list.removeByValue("First");

  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "Second \n");
}

TEST(DoublyLinkedListTest, Search) {
  DoublyLinkedList list;
  list.addHead("First");
  list.addHead("Second");

  EXPECT_TRUE(list.search("First"));
  EXPECT_FALSE(list.search("NonExistent"));
}
