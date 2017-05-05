#include "../include/OSRMWrapper.h"

std::string OSRMWrapper::buffer=std::string();

size_t OSRMWrapper::callback(void *contents, size_t size, size_t nmemb, void *userp){ 
	size_t realsize=size*nmemb;
   buffer.append((char*)contents,realsize);
   return(realsize);
}

boost::property_tree::ptree OSRMWrapper::request(const std::string &_host,const std::string &_port,const std::string &_resource,const PositionGeo &_src,const PositionGeo &_dst,const std::string &_params){
	boost::property_tree::ptree fresponse;
	std::string url=std::string(_host + std::string(":") + _port + _resource + boost::lexical_cast<std::string>(_src.lon()) + "," + boost::lexical_cast<std::string>(_src.lat()) + ";" + boost::lexical_cast<std::string>(_dst.lon()) + "," + boost::lexical_cast<std::string>(_dst.lat()) + "?" + _params);
	
	std::cout << url << std::endl;

   CURL *curl=NULL;
	CURLcode res;
   curl_global_init(CURL_GLOBAL_ALL);
   curl=curl_easy_init();

   curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,OSRMWrapper::callback);
                                                 
	if((res = curl_easy_perform(curl))!=CURLE_OK){
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
