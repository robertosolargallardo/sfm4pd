#ifndef _PEDESTRIAN_H_
#define _PEDESTRIAN_H_
#include <list>
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

enum Model {SHORTEST_PATH};

class Pedestrian {
private:
    uint32_t _id;
    double   _min_speed;
    double   _max_speed;
    double   _delay;
    unsigned int _model;

    std::list<Position> _path;
    Position _current;

public:
    Pedestrian(void);
    Pedestrian(const Pedestrian&);
    //Pedestrian(const uint32_t&,const double&,const double&,const double&,const unsigned int&,const std::list<Position>&,const std::pair<PositionGeo,PositionGeo>&);
    ~Pedestrian(void);

    //asigna un PositionGeo dentro de &_limits
    /*void random_init_position(const std::pair<PositionGeo,PositionGeo>&,const PositionGeo&);//TODO
    void extract_path(boost::property_tree::ptree&);//TODO

    void update_position(const std::vector<std::shared_ptr<Pedestrian>>&);

    PositionGeo current(void);*/

    uint32_t id(void) const;
};
#endif
