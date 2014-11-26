#include <regex>
#include <string>
#include "url_handler.h"


//namespace web_crawler{

//const std::string urlRegex = "\\b(([\\w-]+://?|www[.])[^\\s()<>]+(?:\\([\\w\\d]+\\)|([^[:punct:]\\s]|/)))";

//void handleUrl(const UrlWithDepth& url)
//{
//    if(!web::http::uri::validate(url.first)){
//        std::cout << "Invalid URL: " << url.first << std::endl;
//        return;
//    }

//    try{
//        web::http::client::http_client client(url.first);

//        auto depth = url.second;

//        depth++;

//        auto task = client.request(web::http::methods::GET).then([](web::http::http_response response){
//            if(web::http::status_codes::OK == response.status_code()){
//                auto responseString = response.extract_string().get();

//                std::smatch regexSmatch;
//                while(std::regex_search(responseString, regexSmatch, std::regex(urlRegex))){
//                    if(web::http::uri::validate(regexSmatch.str())){
//                        web::http::uri foundURI(regexSmatch.str());
//                        std::cout << foundURI.host() << std::endl;
//                    }

//                    responseString = regexSmatch.suffix().str();
//                }
//            }
//        });

//        task.wait();
//    } catch (const std::exception& ex) {
//        std::cout << "exception caught: "  << ex.what() << std::endl;
//    }

//}

//} // namespace
