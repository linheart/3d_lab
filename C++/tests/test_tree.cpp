#include <gtest/gtest.h>

#include "../include/timer.h"
#include "../include/tree.h"

TEST(TreeTest, InsertAndFind) {
  Timer timer;
  timer.start();
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);

  EXPECT_TRUE(tree.find(10));
  EXPECT_TRUE(tree.find(20));
  EXPECT_TRUE(tree.find(5));

  EXPECT_FALSE(tree.find(15));
  timer.elapsed();
}

TEST(TreeTest, RemoveLeafNode) {
  Timer timer;
  timer.start();
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);

  tree.remove(5);

  EXPECT_FALSE(tree.find(5));
  timer.elapsed();
}

TEST(TreeTest, RemoveNodeWithOneChild) {
  Timer timer;
  timer.start();
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(5);
  tree.insert(15);

  tree.remove(20);

  EXPECT_FALSE(tree.find(20));
  EXPECT_TRUE(tree.find(15));
  timer.elapsed();
}

TEST(TreeTest, RemoveNodeWithTwoChildren) {
  Timer timer;
  timer.start();
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
  timer.elapsed();
}

TEST(TreeTest, EmptyTree) {
  Timer timer;
  timer.start();
  Tree tree;

  EXPECT_FALSE(tree.find(10));

  tree.remove(10);
  EXPECT_FALSE(tree.find(10));
  timer.elapsed();
}

TEST(TreeTest, BalanceAfterInsertions) {
  Timer timer;
  timer.start();
  Tree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);

  EXPECT_TRUE(tree.find(10));
  EXPECT_TRUE(tree.find(20));
  EXPECT_TRUE(tree.find(30));
  timer.elapsed();
}
