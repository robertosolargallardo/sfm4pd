#ifndef _POSITION_H_
#define _POSITION_H_
#include <iostream>
#include <math.h>
#include <boost/property_tree/ptree.hpp>
#include <cmath>
//#define R 6371e3
#define deg2rad(d) d*0.01745329251
#define rad2deg(r) r*57.2957795131

class Geographic{
	private:	double _longitude,_latitude,_elevation;

	public:	Geographic(void){
					this->_longitude=0.0;
					this->_latitude=0.0;
					this->_elevation=0.0;
				}
				Geographic(const double &_longitude,const double &_latitude,const double &_elevation){
					this->_longitude=_longitude;
					this->_latitude=_latitude;
					this->_elevation=_elevation;
				}
				Geographic(const Geographic &_g){
					this->_longitude=_g._longitude;
					this->_latitude=_g._latitude;
					this->_elevation=_g._elevation;
				}
				~Geographic(void){
					;
				}
				Geographic& operator=(const Geographic &_g){
					this->_longitude=_g._longitude;
					this->_latitude=_g._latitude;
					this->_elevation=_g._elevation;
					return(*this);
				}
				
				double longitude(void) const{
					return(this->_longitude);
				}
				double latitude(void) const{
					return(this->_latitude);
				}
				double elevation(void) const{
					return(this->_elevation);
				}
				void longitude(const double &_longitude){
					this->_longitude=_longitude;
				}
				void latitude(const double &_latitude){
					this->_latitude=_latitude;
				}
				void elevation(const double &_elevation){
					this->_elevation=_elevation;
				}
};
class Cartesian{
	private:	double _x,_y,_z;

	public:	Cartesian(void){
					this->_x=0.0;
					this->_y=0.0;
					this->_z=0.0;
				}
				Cartesian(const Cartesian&_c){
					this->_x=_c._x;
					this->_y=_c._y;
					this->_z=_c._z;
				}
				~Cartesian(void){
					;
				}
				Cartesian& operator=(const Cartesian &_c){
					this->_x=_c._x;
					this->_y=_c._y;
					this->_z=_c._z;
					return(*this);
				}
				
				double x(void) const{
					return(this->_x);
				}
				double y(void) const{
					return(this->_y);
				}
				double z(void) const{
					return(this->_z);
				}
				void x(const double &_x){
					this->_x=_x;
				}
				void y(const double &_y){
					this->_y=_y;
				}
				void z(const double &_z){
					this->_z=_z;
				}
};


class Position {
private:	Cartesian _coords;
	 
public:
    Position(void);
	 Position(const Position&);
	 Position(const Cartesian&);
	 Position(const Geographic&);
    ~Position(void);

	 Position& operator=(const Position&);
	 Geographic geographic(void) const;

    /*double lon(void) const;
    double lat(void) const;
    double alt(void) const;
		
    void lon(const double&);
    void lat(const double&);
    void alt(const double&);

    Position& operator+=(const Position&);
    Position& operator=(const Position&);
    Position operator+(const Position&);
    Position operator-(const Position&);
    Position& operator*(const double&);

    bool operator==(const Position&);
    bool operator!=(const Position&);

    //void normalize(void);
    double distance(const Position&);
    double bearing(const Position&);
    void traslate(const Position&,const double&);
    //void rotate(const double&);
    //double norm(void);
    //void to_rad(void);
    //void to_deg(void);*/

    //friend std::ostream& operator<<(std::ostream&,const Position&);
};
#endif
