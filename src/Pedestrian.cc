#include "../include/Pedestrian.h"
Pedestrian::Pedestrian(void){
	;
}
Pedestrian::Pedestrian(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const double &_delay,const unsigned int &_model,const std::vector<PositionGeo> &_reference_points,const std::pair<PositionGeo,PositionGeo> &_limits){
	this->_id=_id;
	std::uniform_real_distribution<double> speed(_min_speed,_max_speed);
	this->_speed=speed(rng);

	switch(_model){
		case SHORTEST_PATH:{
			break;
		}
		default:{
			std::cerr << "Error::movement model not implemented" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}
Pedestrian::~Pedestrian(void){
	;
}
