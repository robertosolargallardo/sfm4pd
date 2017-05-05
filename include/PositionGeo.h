#ifndef _POSITIONGEO_H_
#define _POSITIONGEO_H_

class PositionGeo{
   private: double _lon,_lat;

   public:  PositionGeo(void);
            PositionGeo(const double &_lon,const double &_lat);
            ~PositionGeo(void);
				double lon(void) const;
				double lat(void) const;
};
#endif
