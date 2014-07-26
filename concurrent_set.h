#ifndef CONCURRENT_SET_H
#define CONCURRENT_SET_H

#include <set>
#include <string>
#include <mutex>

namespace web_crawler {

template<typename T>
class ConcurrentSet
{
    public:
        // types
        typedef T key_type;
        typedef T value_type;

        ConcurrentSet()
        {
        }

        bool insert(const value_type& val)
        {
            std::lock_guard<std::mutex> lock(lock_);
            auto res = set_.insert(val);
            return res.second;
        }

        bool contains(const value_type& val)
        {
            std::lock_guard<std::mutex> lock(lock_);
            return set_.find(val) != std::end(set_);
        }


    private:
        std::set<T> set_;
        std::mutex lock_;
};


} // namespace

#endif // CONCURRENT_SET_H
