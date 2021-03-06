#include "../include/Position.h"
Position::Position(void) {
    ;
}
Position::Position(const Position &_p) {
    this->_coords=_p._coords;
}
Position::Position(const Geographic &_g) {
    this->_coords.x(deg2rad(_g.longitude()));
    this->_coords.y(deg2rad(_g.latitude()));
    this->_coords.z(_g.elevation());
}
Position::Position(const Cartesian &_c) {
    this->_coords=_c;
}
Position::~Position(void) {
    ;
}
Position& Position::operator=(const Position &_p) {
    this->_coords=_p._coords;
    return(*this);
}
Geographic Position::geographic(void) const {
    return(Geographic(rad2deg(this->_coords.x()),rad2deg(this->_coords.y()),this->_coords.z()));
}
/*
void Position::lon(const double &_lon){
	this->_lon=_lon;
}
void Position::lat(const double &_lat){
	this->_lat=_lat;
}
void Position::alt(const double &_alt){
	this->_alt=_alt;
}
double Position::lon(void) const{
    return(this->_lon);
}
double Position::lat(void) const{
    return(this->_lat);
}
double Position::alt(void) const{
    return(this->_alt);
}
Position& Position::operator+=(const Position &_p) {
    this->_lat=rad2deg(deg2rad(this->_lat)+deg2rad(_p._lat));
    this->_lon=rad2deg(deg2rad(this->_lon)+deg2rad(_p._lon));
    return(*this);
}
Position& Position::operator=(const Position &_p) {
    this->_lat=_p._lat;
    this->_lon=_p._lon;
    this->_alt=_p._alt;
    return(*this);
}*/
/*Position Position::operator+(const Position &_p) {
    return Position(rad2deg(deg2rad(this->_lat)+deg2rad(_p._lat)),rad2deg(deg2rad(this->_lon)+deg2rad(_p._lon)));

}
Position Position::operator-(const Position &_p) {
    return Position(rad2deg(deg2rad(this->_lat)-deg2rad(_p._lat)),rad2deg(deg2rad(this->_lon)-deg2rad(_p._lon)));
}
Position& Position::operator*(const double &_speed) {
    this->_lat=rad2deg(deg2rad(this->_lat)*_speed);
    this->_lon=rad2deg(deg2rad(this->_lon)*_speed);
    return(*this);
}*/
/*bool Position::operator==(const Position &_p) {
    return(this->_lat==_p._lat && this->_lon==_p._lon && this->_alt==_p._alt);
}
bool Position::operator!=(const Position &_p) {
    return(!(this->_lat==_p._lat && this->_lon==_p._lon && this->_alt==_p._alt));
}*/
/*void Position::normalize(void){
	double n=this->norm();
	this->_lat/=n;
	this->_lon/=n;
}
double Position::norm(void){
	return(sqrt(this->_lat*this->_lat+this->_lon*this->_lon));
}*/
/*std::ostream& operator<<(std::ostream& _stream,const Position &_p) {
    _stream << _p._lat << "," << _p._lon << "," << _p._alt;
    return(_stream);
}
double Position::distance(const Position &_p) {
    double l1,l2,d1,d2,a,c;
    l1=deg2rad(this->_lat);
    l2=deg2rad(_p._lat);
    d1=deg2rad(_p._lat)-deg2rad(this->_lat);
    d2=deg2rad(_p._lon)-deg2rad(_p._lon);

    a=sin(d1/2.0)*sin(d1/2.0)+cos(l1)*cos(l2)*sin(d2/2.0)*sin(d2/2.0);

    c=2.0*atan2(sqrt(a),sqrt(1.0-a));

    return(R*c);
}
double Position::bearing(const Position &_p) {
    double la1,la2,lo1,lo2;
    la1=deg2rad(this->_lat);
    la2=deg2rad(_p._lat);
    lo1=deg2rad(this->_lon);
    lo2=deg2rad(_p._lon);

    return(atan2(sin(lo2-lo1)*cos(la2),cos(la1)*sin(la2)-sin(la1)*cos(la2)*cos(lo2-lo1)));
}
void Position::traslate(const Position &_p,const double &_d) {
    double lat,lon;
    lat=deg2rad(this->_lat);
    lon=deg2rad(this->_lon);

    double b=this->bearing(_p);

    this->_lat=asin(sin(lat)*cos(_d/R)+cos(lat)*sin(_d/R)*cos(b));
    this->_lon=rad2deg(lon)+rad2deg(atan2(sin(b)*sin(_d/R)*cos(lat),cos(_d/R)-sin(lat)*sin(this->_lat)));
    this->_lat=rad2deg(this->_lat);
}*/
/*void Position::to_rad(void){
	this->_lat=deg2rad(this->_lat);
	this->_lon=deg2rad(this->_lon);
}
void Position::to_deg(void){
	this->_lat=rad2deg(this->_lat);
	this->_lon=rad2deg(this->_lon);
}
void Position::rotate(const double &_angle){
	double cs=0.0,sn=0.0,lat=0.0,lon=0.0;
	cs=cos(_angle);
	sn=sin(_angle);

	lat=this->_lat*cs-this->_lon*sn;
	lon=this->_lat*sn+this->_lon*cs;

	this->_lat=lat;
	this->_lon=lon;
}*/
