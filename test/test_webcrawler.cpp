#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "concurrent_set.h"

TEST(ConcurrentSetCase, ConcurrentSetInsertion) {
    web_crawler::ConcurrentSet<int> intSet;
    for(int i = 0; i < 1000; ++i){
        EXPECT_EQ(true, intSet.insert(i));
    }
}

TEST(ConcurrentSetCase, ConcurrentSetDuplicateInsertion) {
    web_crawler::ConcurrentSet<int> intSet;
    for(int i = 0; i < 1000; ++i){
        intSet.insert(i);
    }

    for(int i = 0; i < 1000; ++i){
        EXPECT_EQ(false, intSet.insert(i));
    }
}

TEST(ConcurrentSetCase, ConcurrentFind) {
    web_crawler::ConcurrentSet<int> intSet;
    for(int i = 0; i < 1000; ++i){
        intSet.insert(i);
    }

    for(int i = 0; i < 1000; ++i){
        EXPECT_EQ(true, intSet.contains(i));
    }
    for(int i = 1000; i < 2000; ++i){
        EXPECT_EQ(false, intSet.contains(i));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


