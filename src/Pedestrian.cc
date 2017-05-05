#include "../include/Pedestrian.h"
template<unsigned int MODEL>
Pedestrian<MODEL>::Pedestrian(void){
	;
}
template<unsigned int MODEL>
Pedestrian<MODEL>::Pedestrian(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const double &_delay,const std::vector<PositionGeo> &_points){
	this->_id=_id;
	std::uniform_real_distribution<double> speed(_min_speed,_max_speed);
	this->_speed=speed(rng);

	switch(MODEL){
		case SHORTEST_PATH:{
			break;
		}
		default:{
			std::cerr << "Error::movement model not implemented" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}
template<unsigned int MODEL>
Pedestrian<MODEL>::~Pedestrian(void){

}
