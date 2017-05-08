#ifndef _POSITIONGEO_H_
#define _POSITIONGEO_H_
#include <iostream>
#include <math.h>

class PositionGeo{
   private: double _lon,_lat;

   public:  PositionGeo(void);
            PositionGeo(const double &_lon,const double &_lat);
            ~PositionGeo(void);

            double lon(void) const;
            double lat(void) const;

            PositionGeo& operator+=(const PositionGeo&);
            PositionGeo& operator=(const PositionGeo&);
            PositionGeo operator+(const PositionGeo&);
            PositionGeo operator-(const PositionGeo&);

            PositionGeo& operator*(const double&);

            bool operator==(const PositionGeo&);
            bool operator!=(const PositionGeo&);

            void normalize(void);
            double distance(const PositionGeo&);
            double norm(void);

            friend std::ostream& operator<<(std::ostream&,const PositionGeo&);
};
#endif
