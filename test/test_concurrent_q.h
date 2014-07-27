#ifndef __TEST_CONCURRENT_Q__
#define __TEST_CONCURRENT_Q__

#include "gtest/gtest.h"
#include "concurrentqueue.h"

TEST(ConcurrentQ, ConcurrentQCtor) {
    ASSERT_NO_THROW(web_crawler::ConcurrentQueue<int> q);
}

TEST(ConcurrentQ, PushPopBasicExcSafety) {
    web_crawler::ConcurrentQueue<int> q;
    for(int i = 0; i < 1000; ++i){
        q.push(i);
        int item = q.pop();
        ASSERT_EQ(i, item);
    }
}

TEST(ConcurrentQ, PushPopStrongExcSafety) {
    web_crawler::ConcurrentQueue<int> q;
    for(int i = 0; i < 1000; ++i){
        q.push(i);
        int item =  0;
        q.pop(item);
        ASSERT_EQ(i, item);
    }
}

TEST(ConcurrentQ, MovingPushPopStrongExcSafety) {
    web_crawler::ConcurrentQueue<int> q;
    for(int i = 0; i < 1000; ++i){
        int temp = i;
        q.push(std::move(temp));
        int item =  0;
        q.pop(item);
        ASSERT_EQ(i, item);
    }
}

#endif
