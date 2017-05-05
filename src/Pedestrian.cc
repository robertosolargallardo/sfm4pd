#include "../include/Pedestrian.h"
Pedestrian::Pedestrian(void){
	;
}

Pedestrian::Pedestrian(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const double &_delay,const unsigned int &_model,const std::vector<PositionGeo> &_reference_points,const std::pair<PositionGeo,PositionGeo> &_limits){
	this->_id=_id;
	std::uniform_real_distribution<double> speed(_min_speed,_max_speed);
	this->_speed=speed(rng);

        PositionGeo p = this->get_random_init_position( _limits, _reference_points.at(0) );

	std::cout << "Limits (" << std::get<0>(_limits).lat() << "," << std::get<0>(_limits).lon() << ") : ("
            << std::get<1>(_limits).lat() << "," << std::get<1>(_limits).lon() << ") - Position lat="
            << p.lat() << " - lon=" << p.lon() << std::endl;

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

PositionGeo Pedestrian::get_random_init_position( const std::pair<PositionGeo,PositionGeo> &_limits, const PositionGeo &_reference_point ){
	//while(1){

		//Crear punto aleatorio - DEBE ESTAR DENTRO DE LOS LIMITES DE LIMITS
      //double range_latitude = _limits.get<1>.lat() -  _limits.get<0>.lat();
		//double range_longitude = _limits.get<1>.lon() -  _limits.get<1>.lon();

  std::uniform_real_distribution<double> random_latitude( std::get<0>(_limits).lat(), std::get<1>(_limits).lat() );
  double latitude = random_latitude(rng);

  std::uniform_real_distribution<double> random_longitude( std::get<0>(_limits).lon(), std::get<1>(_limits).lon() );
  double longitude = random_longitude(rng);
		
	//}
  return PositionGeo(latitude,longitude);
}

Pedestrian::~Pedestrian(void){
	;
}
