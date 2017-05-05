#include "../include/PositionGeo.h"
PositionGeo::PositionGeo(void){
   this->_lat=0.0;
   this->_lon=0.0;
}
PositionGeo::PositionGeo(const double &_lat,const double &_lon){
   this->_lat=_lat;
   this->_lon=_lon;
}
PositionGeo::~PositionGeo(void){
   ;
}
double PositionGeo::lon(void) const{
	return(this->_lon);
}
double PositionGeo::lat(void) const{
	return(this->_lat);
}
