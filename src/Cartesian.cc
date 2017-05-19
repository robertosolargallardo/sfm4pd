#include "../include/Cartesian.h"
Cartesian::Cartesian(void) {
    this->_x=0.0;
    this->_y=0.0;
    this->_z=0.0;
}
Cartesian::Cartesian(const Cartesian& _c) {
    this->_x=_c._x;
    this->_y=_c._y;
    this->_z=_c._z;
}
Cartesian::Cartesian(const Geographic &_g) {
    this->_x=deg2rad(_g.longitude());
    this->_y=deg2rad(_g.latitude());
    this->_z=deg2rad(_g.elevation());
}
Cartesian::~Cartesian(void) {
    ;
}
Cartesian& Cartesian::operator=(const Cartesian &_c) {
    this->_x=_c._x;
    this->_y=_c._y;
    this->_z=_c._z;
    return(*this);
}
Cartesian::Cartesian(const double &_x,const double &_y,const double &_z){
    this->_x=_x;
    this->_y=_y;
    this->_z=_z;
}
double Cartesian::x(void) const {
    return(this->_x);
}
double Cartesian::y(void) const {
    return(this->_y);
}
double Cartesian::z(void) const {
    return(this->_z);
}
void Cartesian::x(const double &_x) {
    this->_x=_x;
}
void Cartesian::y(const double &_y) {
    this->_y=_y;
}
void Cartesian::z(const double &_z) {
    this->_z=_z;
}
Geographic Cartesian::geographic(void) const{
	return(Geographic(rad2deg(this->_x),rad2deg(this->_y),rad2deg(this->_z)));
}
double Cartesian::haversine(const Cartesian &_c){
	double latitude_diff=_c.y()-this->y();
	double longitude_diff=_c.x()-this->x();

   double a=sin(latitude_diff/2.0)*sin(latitude_diff/2.0)+cos(this->y())*cos(_c.y())*sin(longitude_diff/2.0)*sin(longitude_diff/2.0);

   return(EARTH_RADIUS*(2.0*atan2(sqrt(a),sqrt(1.0-a))));
}
double Cartesian::euclidean(const Cartesian &_c){
	double diff_x=_c.x()-this->x();
	double diff_y=_c.y()-this->y();
	double diff_z=_c.z()-this->z();
	return(sqrt(diff_x*diff_x)+(diff_y*diff_y)+(diff_z*diff_z));
}
double Cartesian::angle(const Cartesian &_c){
	return(acos(this->dot(_c)));
}
double Cartesian::dot(const Cartesian &_c){
	return(this->x()*_c.x()+this->y()*_c.y()+this->z()*_c.z());
}
