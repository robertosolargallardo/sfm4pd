#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "../include/Simulator.h"

std::random_device device;  
std::mt19937 rng(device());

int main(int argc,char **argv){
	boost::property_tree::ptree fsettings;
	read_json(argv[1], fsettings);

	Simulator s(fsettings);
	s.run();
	
	/*std::string host("http://citiaps2.diinf.usach.cl");
	std::string port("5000");
	std::string resource("/route/v1/driving/");
	
	
	PositionGeo src(-33.0277,-71.6371);
	PositionGeo dst(-33.0277,-71.6323);
	std::string params("steps=true");

	boost::property_tree::ptree fresponse=OSRMWrapper::request(host,port,resource,src,dst,params);	

	boost::property_tree::ptree route=fresponse.get_child("routes").begin()->second;

   std::ostringstream oss;
   write_json(oss,route);
	std::cout << oss.str() << std::endl;

	std::cout << "duration::" << route.get<double>("duration") <<std::endl;
	std::cout << "distance::" << route.get<double>("distance") <<std::endl;*/
	
	return(0);
}
