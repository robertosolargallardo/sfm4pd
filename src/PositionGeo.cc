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
	_stream << _p._lat << "," << _p._lon;
	return(_stream);
}
double PositionGeo::distance(const PositionGeo &_p){
	double lat1r, lon1r, lat2r, lon2r, u, v;
  	lat1r=deg2rad(this->_lat);
  	lon1r=deg2rad(this->_lon);
  	lat2r=deg2rad(_p._lat);
  	lon2r=deg2rad(_p._lon);
  	u=sin((lat2r-lat1r)/2);
  	v=sin((lon2r-lon1r)/2);
  	return(1000.0*2.0*earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v)));
}
void PositionGeo::to_rad(void){
	this->_lat=deg2rad(this->_lat);
	this->_lon=deg2rad(this->_lon);
}
void PositionGeo::to_deg(void){
	this->_lat=rad2deg(this->_lat);
	this->_lon=rad2deg(this->_lon);
}
void PositionGeo::rotate(const double &_angle){
	double cs=0.0,sn=0.0,lat=0.0,lon=0.0;
	cs=cos(_angle);
	sn=sin(_angle);

	lat=this->_lat*cs-this->_lon*sn;
	lon=this->_lat*sn+this->_lon*cs;

	this->_lat=lat;
	this->_lon=lon;
}

