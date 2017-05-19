#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_
#define rad2deg(r) r*57.2957795131
#include "Geographic.h"
#include <math.h>

#define EARTH_RADIUS 6371e3

class Geographic;
class Cartesian{
	private:	double _x,_y,_z;

	public:	Cartesian(void);
				Cartesian(const double&,const double&,const double &_z=0.0);
				Cartesian(const Cartesian&);
				Cartesian(const Geographic&);
				~Cartesian(void);
				Cartesian& operator=(const Cartesian&);
				double x(void) const;
				double y(void) const;
				double z(void) const;
				void x(const double&);
				void y(const double&);
				void z(const double&);
            Geographic geographic(void) const;

				double haversine(const Cartesian&);
				double euclidean(const Cartesian&);
				double angle(const Cartesian&);
				double dot(const Cartesian&);
};
#endif
