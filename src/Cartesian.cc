#include "../include/Cartesian.h"
Cartesian::Cartesian(void) {
    this->_data= {0.0,0.0,0.0};
}
Cartesian::Cartesian(const Cartesian& _c) {
    this->_data=_c._data;
}
Cartesian::Cartesian(const Geographic &_g) {
    this->_data[0]=_g.elevation()*cos(deg2rad(_g.latitude()))*sin(deg2rad(_g.longitude()));
    this->_data[1]=_g.elevation()*sin(deg2rad(_g.latitude()));
    this->_data[2]=_g.elevation()*cos(deg2rad(_g.latitude()))*cos(deg2rad(_g.longitude()));
}
Cartesian::~Cartesian(void) {
    ;
}
Cartesian& Cartesian::operator=(const Cartesian &_c) {
    this->_data=_c._data;
    return(*this);
}
Cartesian& Cartesian::operator+=(const Cartesian &_c) {
    this->_data[0]+=_c._data[0];
    this->_data[1]+=_c._data[1];
    this->_data[2]+=_c._data[2];
    return(*this);
}
Cartesian& Cartesian::operator-=(const Cartesian &_c) {
    this->_data[0]-=_c._data[0];
    this->_data[1]-=_c._data[1];
    this->_data[2]-=_c._data[2];
    return(*this);
}
Cartesian Cartesian::operator-(const Cartesian &_c) const {
    return(Cartesian(this->_data[0]-_c._data[0],this->_data[1]-_c._data[1],this->_data[2]-_c._data[2]));
}
Cartesian Cartesian::operator+(const Cartesian &_c) const {
    return(Cartesian(this->_data[0]+_c._data[0],this->_data[1]+_c._data[1],this->_data[2]+_c._data[2]));
}
Cartesian::Cartesian(const double &_x,const double &_y,const double &_z) {
    this->_data= {_x,_y,_z};
}
double Cartesian::x(void) const {
    return(this->_data[0]);
}
double Cartesian::y(void) const {
    return(this->_data[1]);
}
double Cartesian::z(void) const {
    return(this->_data[2]);
}
void Cartesian::x(const double &_x) {
    this->_data[0]=_x;
}
void Cartesian::y(const double &_y) {
    this->_data[1]=_y;
}
void Cartesian::z(const double &_z) {
    this->_data[2]=_z;
}
Geographic Cartesian::geographic(void) const {
    return(Geographic(*this));
}
double Cartesian::euclidean(const Cartesian &_c) {
    double dx=_c.x()-this->x();
    double dy=_c.y()-this->y();
    double dz=_c.z()-this->z();
    return(sqrt(dx*dx)+(dy*dy)+(dz*dz));
}
double Cartesian::angle(const Cartesian &_c) {
    return(acos(this->dot(_c)));
}
double Cartesian::dot(const Cartesian &_c) {
    return(this->x()*_c.x()+this->y()*_c.y()+this->z()*_c.z());
}
double Cartesian::norm(void) {
    return(this->euclidean(Cartesian()));
}
Cartesian Cartesian::cross(const Cartesian &_c) {
    return(Cartesian(this->y()*_c.z()-this->z()*_c.y(),this->z()*_c.x()-this->x()*_c.z(),this->x()*_c.y()-this->y()*_c.x()));
}
