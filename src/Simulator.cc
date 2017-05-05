#include "../include/Simulator.h"
Simulator::Simulator(void){

}
Simulator::Simulator(const boost::property_tree::ptree &_fsettings){
	this->_fsettings=_fsettings;
	std::vector<PositionGeo> reference_points;
	std::pair<PositionGeo,PositionGeo> limits(PositionGeo(this->_fsettings.get<double>("limits.bottom-left.lat"),this->_fsettings.get<double>("limits.bottom-left.lon")),PositionGeo(this->_fsettings.get<double>("limits.top-right.lat"),this->_fsettings.get<double>("limits.top-right.lon")));
	
	for(auto& freference_point : this->_fsettings.get_child("reference-points"))
		reference_points.push_back(PositionGeo(freference_point.second.get<double>("lat"),freference_point.second.get<double>("lon")));

	for(uint32_t id=0;id<this->_fsettings.get<uint32_t>("number-of-pedestrians");++id)
		this->_pedestrians.push_back(Pedestrian(id,this->_fsettings.get<double>("min-speed"),this->_fsettings.get<double>("max-speed"),this->_fsettings.get<double>("delay"),this->_fsettings.get<unsigned int>("model"),reference_points,limits));
		
}
void Simulator::run(void){
	
}
Simulator::~Simulator(void){

}
