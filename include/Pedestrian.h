#ifndef _PEDESTRIAN_H_
#define _PEDESTRIAN_H_
#include <list>
#include <stdint.h>
#include <random>
#include <iostream>
#include <tuple>
#include <memory>
#include <boost/property_tree/ptree.hpp>
#include "PositionGeo.h"
#include "OSRMWrapper.h"

extern std::mt19937 rng;

enum Model{SHORTEST_PATH};

class Pedestrian{
   private: uint32_t _id;
            double   _min_speed;
            double   _max_speed;
            double   _delay;
            unsigned int _model;      
            std::list<PositionGeo> _path;
            PositionGeo _current;

   public:  Pedestrian(void);
            Pedestrian(const Pedestrian&);
            Pedestrian(const uint32_t&,const double&,const double&,const double&,const unsigned int&,const std::list<PositionGeo>&,const std::pair<PositionGeo,PositionGeo>&);

            //asigna un PositionGeo dentro de &_limits
            void random_init_position(const std::pair<PositionGeo,PositionGeo>&,const PositionGeo&);
            void extract_path(boost::property_tree::ptree&);
            ~Pedestrian(void);

            void update_position(const std::vector<std::shared_ptr<Pedestrian>>&);
      
            PositionGeo current(void);
};
#endif
