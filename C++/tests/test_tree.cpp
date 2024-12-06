#include "../src/tree.h"
#include <gtest/gtest.h>

TEST(TreeTest, InsertAndFind) {
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);

  EXPECT_TRUE(tree.find(10));
  EXPECT_TRUE(tree.find(20));
  EXPECT_TRUE(tree.find(5));

  EXPECT_FALSE(tree.find(15));
}

TEST(TreeTest, RemoveLeafNode) {
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);

  tree.remove(5);

  EXPECT_FALSE(tree.find(5));
}

TEST(TreeTest, RemoveNodeWithOneChild) {
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);
  tree.insert(15);

  tree.remove(20);

  EXPECT_FALSE(tree.find(20));
  EXPECT_TRUE(tree.find(15));
}

TEST(TreeTest, RemoveNodeWithTwoChildren) {
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);
  tree.insert(15);
  tree.insert(30);

  tree.remove(20);

  EXPECT_FALSE(tree.find(20));
  EXPECT_TRUE(tree.find(15));
  EXPECT_TRUE(tree.find(30));
}

TEST(TreeTest, EmptyTree) {
  Tree tree;

  EXPECT_FALSE(tree.find(10));

  tree.remove(10);
  EXPECT_FALSE(tree.find(10));
}

TEST(TreeTest, BalanceAfterInsertions) {
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);

  EXPECT_TRUE(tree.find(10));
  EXPECT_TRUE(tree.find(20));
  EXPECT_TRUE(tree.find(30));
}

TEST(TreeTest, PrintTree) {
  Tree tree;

  tree.insert(10);
  tree.insert(5);
  tree.insert(20);
  tree.insert(15);

  testing::internal::CaptureStdout();
  tree.print();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_TRUE(output.find("10") != std::string::npos);
  EXPECT_TRUE(output.find("5") != std::string::npos);
  EXPECT_TRUE(output.find("20") != std::string::npos);
  EXPECT_TRUE(output.find("15") != std::string::npos);
}
