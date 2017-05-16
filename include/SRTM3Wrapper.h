#ifndef _SRTM3WRAPPER_H_
#define _SRTM3WRAPPER_H_
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <curl/curl.h>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "PositionGeo.h"

class PositionGeo;
class SRTM3Wrapper{
public:
    static std::string buffer;
    static std::string host;
    static std::string port;
    static std::string resource;
    static std::string params;

    static size_t callback(void*,size_t,size_t,void*);
    static boost::property_tree::ptree request(const PositionGeo&);
};
#endif
