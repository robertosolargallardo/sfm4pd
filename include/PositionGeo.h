#ifndef _POSITIONGEO_H_
#define _POSITIONGEO_H_
#include <iostream>
#include <math.h>
#include <boost/property_tree/ptree.hpp>
#include "OSRMWrapper.h"
#include <cmath> 
#define earthRadiusKm 6371.0
#define deg2rad(deg) (deg * M_PI / 180.0)
#define rad2deg(rad) (rad * 180.0 / M_PI)

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
            void rotate(const double&);
            double norm(void);
            void to_rad(void);
            void to_deg(void);

            friend std::ostream& operator<<(std::ostream&,const PositionGeo&);
};
#endif
