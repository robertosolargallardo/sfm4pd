#include "../include/Limits.h"
Limits::Limits(void) {
    ;
}
Limits::Limits(const boost::property_tree::ptree &_flimits) {
    this->_min=Geographic(_flimits.get<double>("min.longitude"),_flimits.get<double>("min.latitude"));
    this->_max=Geographic(_flimits.get<double>("max.longitude"),_flimits.get<double>("max.latitude"));
}
Limits::Limits(const Geographic &_min,const Geographic &_max) {
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
Geographic Limits::min(void) const {
    return(this->_min);
}
Geographic Limits::max(void) const {
    return(this->_max);
}
