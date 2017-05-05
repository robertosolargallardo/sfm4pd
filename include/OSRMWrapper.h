#ifndef _OSRMWRAPPER_H_
#define _OSRMWRAPPER_H_
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <curl/curl.h>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "PositionGeo.h"

class OSRMWrapper{
	public:	static std::string buffer;

				static size_t callback(void*,size_t,size_t,void*);
				static boost::property_tree::ptree request(const std::string&,const std::string&,const std::string&,const PositionGeo&,const PositionGeo&,const std::string&);
};
#endif
