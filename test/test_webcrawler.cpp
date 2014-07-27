#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "concurrent_set.h"

#include "test_concurrent_q.h"

class ConcurrentSetTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    for(int i = 0; i < 1000; ++i){
        intSet_.insert(i);
     }
  }

  // virtual void TearDown() {}

  web_crawler::ConcurrentSet<int> intSet_;
};


TEST(ConcurrentSetCase, ConcurrentSetInsertion) {
    web_crawler::ConcurrentSet<int> intSet;
    for(int i = 0; i < 1000; ++i){
        EXPECT_EQ(true, intSet.insert(i));
    }
}

TEST_F(ConcurrentSetTest, ConcurrentSetDuplicateInsertion) {
    for(int i = 0; i < 1000; ++i){
        EXPECT_EQ(false, intSet_.insert(i));
    }
}

TEST_F(ConcurrentSetTest, ConcurrentFind) {
    for(int i = 0; i < 1000; ++i){
        EXPECT_EQ(true, intSet_.contains(i));
    }

    for(int i = 1000; i < 2000; ++i){
        EXPECT_EQ(false, intSet_.contains(i));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


