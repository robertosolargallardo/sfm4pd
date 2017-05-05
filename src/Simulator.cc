#include "../include/Simulator.h"
Simulator::Simulator(void){

}
Simulator::Simulator(const boost::property_tree::ptree &_fsettings){
	this->_fsettings=_fsettings;
	std::vector<PositionGeo> _reference_points;

	for(uint32_t id=0;id<this->_fsettings.get<uint32_t>("number-of-pedestrians");++id)
		this->_pedestrians.push_back(Pedestrian(id,this->_fsettings.get<double>("min-speed"),this->_fsettings.get<double>("max-speed"),this->_fsettings.get<double>("delay"),this->_fsettings.get<unsigned int>("model"),_reference_points));
		
}
void Simulator::run(void){
	
}
Simulator::~Simulator(void){

}
