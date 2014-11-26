#ifndef WEB_CRAWLER_H
#define WEB_CRAWLER_H

#include <cstdint>
#include <cassert>
#include <string>
#include <thread>
#include <future>
#include <atomic>
#include <exception>>
#include "boost/noncopyable.hpp"
#include "concurrent_set.h"
#include "concurrentqueue.h"

namespace web_crawler {

class WebCrawler : private boost::noncopyable{
    public:
        WebCrawler(const std::string& startUrl, std::uint32_t depthLevel = 1);

        void doCrawl();


        struct URLWithDepth{
            std::string URL_;
            std::uint32_t depthLevel_;
            std::promise<void> promise_;
        };

    private:
        std::string startURL_;
        std::uint32_t maxDepth_;
        std::uint32_t maxThreadCount_;
        std::vector<std::thread> threads_;
        std::atomic<bool> depthReached_;
        ConcurrentSet<std::string> URLSet_;
        ConcurrentQueue<URLWithDepth> URLq_;

        void crawlURL(const URLWithDepth& url);
        void crawlThread();
};

} // namespace web_crawler

#endif // WEB_CRAWLER_H
