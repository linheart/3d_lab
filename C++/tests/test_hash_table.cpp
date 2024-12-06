#include "../src/hash_table.h"
#include <gtest/gtest.h>

TEST(HashTableTest, ConstructorDestructor) {
  HT ht;
  SUCCEED();
}

TEST(HashTableTest, InsertAndRetrieve) {
  HT ht;

  ht["key1"] = "value1";
  ht["key2"] = "value2";

  EXPECT_EQ(ht["key1"], "value1");
  EXPECT_EQ(ht["key2"], "value2");
  EXPECT_EQ(ht["key3"], "");
}

TEST(HashTableTest, OverwriteValue) {
  HT ht;

  ht["key1"] = "value1";
  EXPECT_EQ(ht["key1"], "value1");

  ht["key1"] = "new_value";
  EXPECT_EQ(ht["key1"], "new_value");
}

TEST(HashTableTest, HandleCollisions) {
  HT ht;

  std::string key1 = "key1";
  std::string key2 = "key2";

  ht[key1] = "value1";
  ht[key2] = "value2";

  EXPECT_NE(ht[key1], ht[key2]);
}

TEST(HashTableTest, DestructorHandlesMemory) {
  HT *ht = new HT();
  ht->operator[]("key1") = "value1";
  delete ht;
}

TEST(HashTableTest, LargeData) {
  HT ht;

  for (int i = 0; i < 1000; ++i) {
    ht["key" + std::to_string(i)] = "value" + std::to_string(i);
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(ht["key" + std::to_string(i)], "value" + std::to_string(i));
  }
}

TEST(HashTableTest, EmptyValue) {
  HT ht;
  ht["key1"] = "";
  EXPECT_EQ(ht["key1"], "");
}

TEST(HashTableTest, ReuseKey) {
  HT ht;

  ht["key1"] = "value1";
  EXPECT_EQ(ht["key1"], "value1");

  ht["key1"] += "_appended";
  EXPECT_EQ(ht["key1"], "value1_appended");
}
