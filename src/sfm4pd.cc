#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "../include/Simulator.h"
#include "../include/OSRMWrapper.h"

std::random_device device;  
std::mt19937 rng(device());

int main(int argc,char **argv){
	/*configure osrm*/
	rng.seed(10);

	boost::property_tree::ptree fosrm;
	read_json(argv[2], fosrm);
	OSRMWrapper::host=fosrm.get<std::string>("osrm.host");
	OSRMWrapper::port=fosrm.get<std::string>("osrm.port");
	OSRMWrapper::resource=fosrm.get<std::string>("osrm.resource");
	OSRMWrapper::params=fosrm.get<std::string>("osrm.params");
	/*configure osrm*/

	boost::property_tree::ptree fsettings;
	read_json(argv[1], fsettings);
	Simulator s(fsettings);
	s.run();

	/*PositionGeo p1(1,1);
	PositionGeo p2(2,2);
	PositionGeo p3=p2-p1;
	PositionGeo p4=p2+p1;
	PositionGeo p5(1,1);
	PositionGeo p6(1,1);
	PositionGeo p7(2,2);
	PositionGeo p8(3,3);

	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
	std::cout << (p5==p6) << std::endl;
	std::cout << (p5!=p7) << std::endl;
	p8=p8*3;
	std::cout << p8 << std::endl;
	p8.normalize();
	std::cout << p8 << std::endl;
	std::cout << p1.distance(p2) << std::endl;*/

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
