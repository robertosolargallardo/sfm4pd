#include "../include/SRTM3Wrapper.h"

std::string SRTM3Wrapper::buffer=std::string();
std::string SRTM3Wrapper::host=std::string();
std::string SRTM3Wrapper::port=std::string();
std::string SRTM3Wrapper::resource=std::string();
std::string SRTM3Wrapper::params=std::string();

size_t SRTM3Wrapper::callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize=size*nmemb;
    buffer.append((char*)contents,realsize);
    return(realsize);
}

boost::property_tree::ptree SRTM3Wrapper::request(const Position &_p) {
	 Geographic g=_p.geographic();
	 return(SRTM3Wrapper::request(g));
}
boost::property_tree::ptree SRTM3Wrapper::request(const Geographic &_g) {
    boost::property_tree::ptree fresponse;

    std::string url=std::string(host + std::string(":") + port + resource + boost::lexical_cast<std::string>(_g.longitude()) + "," + boost::lexical_cast<std::string>(_g.latitude()));

    CURL *curl=NULL;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl=curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,SRTM3Wrapper::callback);

    if((res = curl_easy_perform(curl))!=CURLE_OK) {
        std::cerr << "curl_easy_perform() failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    std::istringstream iss(buffer);
    read_json(iss,fresponse);
    SRTM3Wrapper::buffer.clear();
    return(fresponse);
}
