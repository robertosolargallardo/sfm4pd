#include "../include/Geographic.h"
Geographic::Geographic(void) {
    this->_longitude=0.0;
    this->_latitude=0.0;
    this->_elevation=0.0;
}
Geographic::Geographic(const double &_longitude,const double &_latitude,const double &_elevation) {
    this->_longitude=_longitude;
    this->_latitude=_latitude;
    this->_elevation=_elevation;
}
Geographic::Geographic(const Geographic &_g) {
    this->_longitude=_g._longitude;
    this->_latitude=_g._latitude;
    this->_elevation=_g._elevation;
}
Geographic::Geographic(const Cartesian &_c) {
	double elevation=sqrt(_c.x()*_c.x()+_c.y()*_c.y()+_c.z()*_c.z());
   double latitude=asin(_c.y()/elevation);
   double longitude=asin(_c.x()/(elevation*cos(latitude)));

	this->_latitude=rad2deg(latitude);
	this->_longitude=rad2deg(longitude);
	this->_elevation=elevation;
}
Geographic::~Geographic(void) {
    ;
}
Geographic& Geographic::operator=(const Geographic &_g) {
    this->_longitude=_g._longitude;
    this->_latitude=_g._latitude;
    this->_elevation=_g._elevation;
    return(*this);
}

double Geographic::longitude(void) const {
    return(this->_longitude);
}
double Geographic::latitude(void) const {
    return(this->_latitude);
}
double Geographic::elevation(void) const {
    return(this->_elevation);
}
void Geographic::longitude(const double &_longitude) {
    this->_longitude=_longitude;
}
void Geographic::latitude(const double &_latitude) {
    this->_latitude=_latitude;
}
void Geographic::elevation(const double &_elevation) {
    this->_elevation=_elevation;
}
Cartesian Geographic::cartesian(void){
	return(Cartesian(deg2rad(this->_longitude),deg2rad(this->_latitude),deg2rad(this->_elevation)));
}
