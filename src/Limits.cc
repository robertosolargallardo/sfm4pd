#include "../include/Limits.h"
Limits::Limits(void) {
    ;
}
Limits::Limits(const boost::property_tree::ptree &_flimits){
	this->_min=Cartesian(Geographic(_flimits.get<double>("min.longitude"),_flimits.get<double>("min.latitude")));
	this->_max=Cartesian(Geographic(_flimits.get<double>("max.longitude"),_flimits.get<double>("max.latitude")));
}
Limits::Limits(const Cartesian &_min,const Cartesian &_max) {
    this->_min=_min;
    this->_max=_max;
}
Limits::Limits(const Limits &_limits) {
    this->_min=_limits._min;
    this->_max=_limits._max;
}
Limits::~Limits(void) {
    ;
}
Limits& Limits::operator=(const Limits &_limits) {
    this->_min=_limits._min;
    this->_max=_limits._max;
    return(*this);
}
Cartesian Limits::min(void) const {
    return(this->_min);
}
Cartesian Limits::max(void) const {
    return(this->_max);
}
