#include "cpprest/http_client.h"
#include "web_crawler.h"

namespace web_crawler{

WebCrawler::WebCrawler(const std::string& startUrl, std::uint32_t depthLevel)
    :startURL_{startUrl},
      maxDepth_{depthLevel},
      maxThreadCount_{std::thread::hardware_concurrency()*2-1},
      depthReached_{false}  {

    if(!web::http::uri::validate(startUrl)){
        throw std::logic_error("Start URL isn't valid");
    }

    auto res = URLSet_.insert(startUrl);
    assert(res == true);
}

void WebCrawler::doCrawl()
{
    this->crawlURL({startURL_, 0});
}

void WebCrawler::crawlURL(const WebCrawler::URLWithDepth& url)
{

}

void WebCrawler::crawlThread()
{
    while(!depthReached_){
        auto url = URLq_.pop();
        crawlURL(url);
    }
}

}
