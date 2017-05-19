#ifndef _LIMITS_H_
#define _LIMITS_H_
#include "Cartesian.h"
#include <boost/property_tree/ptree.hpp>

class Limits {
	private:	Cartesian _min;
    			Cartesian _max;
public:
    Limits(void);
    Limits(const boost::property_tree::ptree&);
    Limits(const Cartesian&,const Cartesian&);
    Limits(const Limits&);
    Limits& operator=(const Limits&);
    Cartesian min(void) const;
    Cartesian max(void) const;
    ~Limits(void);
};
#endif
