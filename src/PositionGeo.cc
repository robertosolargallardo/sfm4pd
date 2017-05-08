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
PositionGeo& PositionGeo::operator+=(const PositionGeo &_p){
	this->_lat+=_p._lat;
	this->_lon+=_p._lon;
	return(*this);
}
PositionGeo& PositionGeo::operator=(const PositionGeo &_p){
	this->_lat=_p._lat;
	this->_lon=_p._lon;
	return(*this);
}
PositionGeo PositionGeo::operator+(const PositionGeo &_p){
   return PositionGeo(this->_lat+_p._lat,this->_lon+_p._lon);
}
PositionGeo PositionGeo::operator-(const PositionGeo &_p){
   return PositionGeo(this->_lat-_p._lat,this->_lon-_p._lon);
}
PositionGeo& PositionGeo::operator*(const double &_speed){
	this->_lat*=_speed;
	this->_lon*=_speed;
	return(*this);
}
bool PositionGeo::operator==(const PositionGeo &_p){
	return(this->_lat==_p._lat && this->_lon==_p._lon);
}
bool PositionGeo::operator!=(const PositionGeo &_p){
	return(!(this->_lat==_p._lat && this->_lon==_p._lon));
}
void PositionGeo::normalize(void){
	double n=this->norm();
	this->_lat/=n;
	this->_lon/=n;
}
double PositionGeo::norm(void){
	return(sqrt(this->_lat*this->_lat+this->_lon*this->_lon));
}
std::ostream& operator<<(std::ostream& _stream,const PositionGeo &_p){
	_stream << _p._lat << " " << _p._lon;
	return(_stream);
}
double PositionGeo::distance(const PositionGeo &_p){
	double lat_diff=this->_lat-_p._lat;
	double lon_diff=this->_lon-_p._lon;

	return(sqrt(lat_diff*lat_diff+lon_diff*lon_diff));
}
