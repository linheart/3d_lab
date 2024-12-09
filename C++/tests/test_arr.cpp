#include <gtest/gtest.h>

#include "../include/arr.h"
#include "../include/timer.h"

TEST(ArrayTest, ConstructorAndSize) {
  Timer timer;
  timer.start();
  Array arr;

  EXPECT_EQ(arr.size(), 0);
  timer.elapsed();
}

TEST(ArrayTest, Append) {
  Timer timer;
  timer.start();
  Array arr;
  arr.append("Hello");
  arr.append("World");

  EXPECT_EQ(arr.size(), 2);
  EXPECT_EQ(arr[0], "Hello");
  EXPECT_EQ(arr[1], "World");
  timer.elapsed();
}

TEST(ArrayTest, Remove) {
  Timer timer;
  timer.start();
  Array arr;
  arr.append("One");
  arr.append("Two");
  arr.append("Three");

  arr.remove(1);

  EXPECT_EQ(arr.size(), 2);
  EXPECT_EQ(arr[0], "One");
  EXPECT_EQ(arr[1], "Three");
  timer.elapsed();
}

TEST(ArrayTest, AppendResizesArray) {
  Timer timer;
  timer.start();
  Array arr;
  for (int i = 0; i < 20; ++i) {
    arr.append("String" + std::to_string(i));
  }

  EXPECT_EQ(arr.size(), 20);
  timer.elapsed();
}

TEST(ArrayTest, IndexingOperator) {
  Timer timer;
  timer.start();
  Array arr;
  arr.append("A");
  arr.append("B");

  EXPECT_EQ(arr[0], "A");
  EXPECT_EQ(arr[1], "B");
  timer.elapsed();
}

TEST(ArrayTest, IndexOutOfBounds) {
  Timer timer;
  timer.start();
  Array arr;
  arr.append("A");

  EXPECT_EQ(arr[1], "");
  timer.elapsed();
}

TEST(ArrayTest, RemoveOutOfBounds) {
  Timer timer;
  timer.start();
  Array arr;
  arr.append("A");

  EXPECT_DEATH(arr.remove(1), "");
  timer.elapsed();
}

TEST(ArrayTest, DestructorClearsArray) {
  Timer timer;
  timer.start();
  Array *arr = new Array();
  arr->append("A");
  delete arr;
  timer.elapsed();
}
