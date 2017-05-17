#ifndef _PEDESTRIAN_H_
#define _PEDESTRIAN_H_
#include <list>
#include <functional>
#include <string>
#include <stdint.h>
#include <random>
#include <iostream>
#include <tuple>
#include <memory>
#include <boost/property_tree/ptree.hpp>


#include "Position.h"
//#include "OSRMWrapper.h"
//#include "SRTM3Wrapper.h"

extern std::mt19937 rng;

enum MobilityModel{SHORTESTPATH=9366416273040049814U,FOLLOWTHECROWD=10676684734677566718U};
enum PedestrianType{LOW,MEDIUM,HIGH};

class Limits;
class Pedestrian {
private:
	 static std::hash<std::string> _hash;

    uint32_t _id;
    double   _min_speed;
    double   _max_speed;
    MobilityModel _model;
	 PedestrianType _type;

    std::list<Position> _path;
    Position _current;

public:
    Pedestrian(void);
    Pedestrian(const Pedestrian&);
	 Pedestrian(const uint32_t&,const double&,const double&,const std::string&,const std::string&,const Limits&);
    ~Pedestrian(void);
	 Pedestrian& operator=(const Pedestrian&);

    Position current(void);
    uint32_t id(void) const;


    //asigna un PositionGeo dentro de &_limits
    /*void random_init_position(const std::pair<PositionGeo,PositionGeo>&,const PositionGeo&);//TODO
    void extract_path(boost::property_tree::ptree&);//TODO

    //Pedestrian(const uint32_t&,const double&,const double&,const double&,const unsigned int&,const std::list<Position>&,const std::pair<PositionGeo,PositionGeo>&);
    void update_position(const std::vector<std::shared_ptr<Pedestrian>>&);*/

};
#endif
