#include "../include/OSRMWrapper.h"

std::string OSRMWrapper::buffer=std::string();
std::string OSRMWrapper::host=std::string();
std::string OSRMWrapper::port=std::string();
std::string OSRMWrapper::resource=std::string();
std::string OSRMWrapper::params=std::string();

size_t OSRMWrapper::callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize=size*nmemb;
    buffer.append((char*)contents,realsize);
    return(realsize);
}

boost::property_tree::ptree OSRMWrapper::request(const Cartesian &_src,const Cartesian &_dst) {
	 return(OSRMWrapper::request(_src.geographic(),_dst.geographic()));
}
boost::property_tree::ptree OSRMWrapper::request(const Geographic &_src,const Geographic &_dst) {
    boost::property_tree::ptree fresponse;
	 
    std::string url=std::string(host + std::string(":") + port + resource + boost::lexical_cast<std::string>(_src.longitude()) + "," + boost::lexical_cast<std::string>(_src.latitude()) + ";" + boost::lexical_cast<std::string>(_dst.longitude()) + "," + boost::lexical_cast<std::string>(_dst.latitude()) + "?" + params);

    CURL *curl=NULL;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl=curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,OSRMWrapper::callback);

    if((res = curl_easy_perform(curl))!=CURLE_OK) {
        std::cerr << "curl_easy_perform() failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    std::istringstream iss(buffer);
    read_json(iss,fresponse);
    OSRMWrapper::buffer.clear();
    return(fresponse);
}
