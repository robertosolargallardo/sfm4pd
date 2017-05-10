#ifndef _POSITIONGEO_H_
#define _POSITIONGEO_H_
#include <iostream>
#include <math.h>
#include <boost/property_tree/ptree.hpp>
#include "OSRMWrapper.h"
#include <cmath> 
#define R 6371e3
#define deg2rad(d) d*0.01745329251
#define rad2deg(r) r*57.2957795131

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

            //void normalize(void);
            double distance(const PositionGeo&);
				double bearing(const PositionGeo&);
				void traslate(const PositionGeo&,const double&);
            //void rotate(const double&);
            //double norm(void);
            //void to_rad(void);
            //void to_deg(void);

            friend std::ostream& operator<<(std::ostream&,const PositionGeo&);
};
#endif
