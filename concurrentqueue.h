#ifndef CONCURRENTQUEUE_H
#define CONCURRENTQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "boost/noncopyable.hpp"

namespace web_crawler{

template <typename T>
class ConcurrentQueue : private boost::noncopyable
{
    public:
        typedef value_type T;

        ConcurrentQueue() = default;

        void pop(value_type& item){
            std::unique_lock<std::mutex> mlock(mtx_);
            while(queue_.empty()){
                cond_.wait(mtx_);
            }
            item = queue_.front();
            queue_.pop();
        }

        value_type pop(){
            std::unique_lock<std::mutex> mlock(mtx_);
            while(queue_.empty()){
                cond_.wait(mtx_);
            }
            auto item = queue_.front();
            queue_.pop();
            return item;
        }

        void push(const value_type& item){
            std::unique_lock<std::mutex> mlock(mtx_);
            queue_.push(item);
            mlock.unlock();
            cond_.notify_one();
        }

        void push(value_type&& item){
            std::unique_lock<std::mutex> mlock(mtx_);
            queue_.push(std::move(item));
            mlock.unlock();
            cond_.notify_one();
        }

    private:
        std::queue<T> queue_;
        std::mutex mtx_;
        std::condition_variable cond_;

};

}

#endif // CONCURRENTQUEUE_H
