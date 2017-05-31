#ifndef _POSITION_H_
#define _POSITION_H_
#include <iostream>
#include <math.h>
#include <boost/property_tree/ptree.hpp>
#include <cmath>
#include "Cartesian.h"
#include "Geographic.h"

class Position {
private:
    Cartesian _coords;

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
