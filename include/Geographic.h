#ifndef _GEOGRAPHIC_H_
#define _GEOGRAPHIC_H_
#define deg2rad(d) d*0.01745329251
#include "Cartesian.h"

class Cartesian;
class Geographic{
	private:	double _longitude,_latitude,_elevation;

	public:	Geographic(void);
				Geographic(const double&,const double&,const double &_elevation=0.0);
				Geographic(const Geographic&);
				Geographic(const Cartesian&);
				~Geographic(void);
				Geographic& operator=(const Geographic&);
				double longitude(void) const;
				double latitude(void) const;
				double elevation(void) const;
				void longitude(const double&);
				void latitude(const double&);
				void elevation(const double&);
				Cartesian cartesian(void);
};
#endif
