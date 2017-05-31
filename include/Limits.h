#ifndef _LIMITS_H_
#define _LIMITS_H_
#include "Geographic.h"
#include <boost/property_tree/ptree.hpp>

class Limits {
private:
    Geographic _min;
    Geographic _max;
public:
    Limits(void);
    Limits(const boost::property_tree::ptree&);
    Limits(const Geographic&,const Geographic&);
    Limits(const Limits&);
    Limits& operator=(const Limits&);
    Geographic min(void) const;
    Geographic max(void) const;
    ~Limits(void);
};
#endif
