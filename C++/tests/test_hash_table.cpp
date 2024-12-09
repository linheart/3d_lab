#include <gtest/gtest.h>

#include "../src/hash_table.h"
#include "../src/timer.h"

TEST(HashTableTest, ConstructorDestructor) {
  Timer timer;
  timer.start();
  HT ht;
  SUCCEED();
  timer.elapsed();
}

TEST(HashTableTest, InsertAndRetrieve) {
  Timer timer;
  timer.start();
  HT ht;

  ht["key1"] = "value1";
  ht["key2"] = "value2";

  EXPECT_EQ(ht["key1"], "value1");
  EXPECT_EQ(ht["key2"], "value2");
  EXPECT_EQ(ht["key3"], "");
  timer.elapsed();
}

TEST(HashTableTest, OverwriteValue) {
  Timer timer;
  timer.start();
  HT ht;

  ht["key1"] = "value1";
  EXPECT_EQ(ht["key1"], "value1");

  ht["key1"] = "new_value";
  EXPECT_EQ(ht["key1"], "new_value");
  timer.elapsed();
}

TEST(HashTableTest, HandleCollisions) {
  Timer timer;
  timer.start();
  HT ht;

  std::string key1 = "key1";
  std::string key2 = "key2";

  ht[key1] = "value1";
  ht[key2] = "value2";

  EXPECT_NE(ht[key1], ht[key2]);
  timer.elapsed();
}

TEST(HashTableTest, DestructorHandlesMemory) {
  Timer timer;
  timer.start();
  HT *ht = new HT();
  ht->operator[]("key1") = "value1";
  delete ht;
  timer.elapsed();
}

TEST(HashTableTest, LargeData) {
  Timer timer;
  timer.start();
  HT ht;

  for (int i = 0; i < 1000; ++i) {
    ht["key" + std::to_string(i)] = "value" + std::to_string(i);
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(ht["key" + std::to_string(i)], "value" + std::to_string(i));
  }
  timer.elapsed();
}

TEST(HashTableTest, EmptyValue) {
  Timer timer;
  timer.start();
  HT ht;
  ht["key1"] = "";
  EXPECT_EQ(ht["key1"], "");
  timer.elapsed();
}

TEST(HashTableTest, ReuseKey) {
  Timer timer;
  timer.start();
  HT ht;

  ht["key1"] = "value1";
  EXPECT_EQ(ht["key1"], "value1");

  ht["key1"] += "_appended";
  EXPECT_EQ(ht["key1"], "value1_appended");
  timer.elapsed();
}
