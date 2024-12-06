#include "../src/arr.h"
#include <gtest/gtest.h>

TEST(ArrayTest, ConstructorAndSize) {
  Array arr;

  EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, Append) {
  Array arr;
  arr.append("Hello");
  arr.append("World");

  EXPECT_EQ(arr.size(), 2);
  EXPECT_EQ(arr[0], "Hello");
  EXPECT_EQ(arr[1], "World");
}

TEST(ArrayTest, Remove) {
  Array arr;
  arr.append("One");
  arr.append("Two");
  arr.append("Three");

  arr.remove(1);

  EXPECT_EQ(arr.size(), 2);
  EXPECT_EQ(arr[0], "One");
  EXPECT_EQ(arr[1], "Three");
}

TEST(ArrayTest, AppendResizesArray) {
  Array arr;
  for (int i = 0; i < 20; ++i) {
    arr.append("String" + std::to_string(i));
  }

  EXPECT_EQ(arr.size(), 20);
}

TEST(ArrayTest, IndexingOperator) {
  Array arr;
  arr.append("A");
  arr.append("B");

  EXPECT_EQ(arr[0], "A");
  EXPECT_EQ(arr[1], "B");
}

TEST(ArrayTest, IndexOutOfBounds) {
  Array arr;
  arr.append("A");

  EXPECT_EQ(arr[1], "");
}

TEST(ArrayTest, RemoveOutOfBounds) {
  Array arr;
  arr.append("A");

  EXPECT_DEATH(arr.remove(1), "");
}

TEST(ArrayTest, DestructorClearsArray) {
  Array *arr = new Array();
  arr->append("A");
  delete arr;
}
