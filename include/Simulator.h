#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Grid.h"
#include "Position.h"
#include "Pedestrian.h"
#include "SRTM3Wrapper.h"

#define CALIBRATION_TIME 100

class Simulator {
private: 
    Grid _grid;

    boost::property_tree::ptree _fsettings;
    //std::vector<Pedestrian> _pedestrians;//TODO deprecated, now using _grid

    void run(const uint32_t&,const bool&);
    void calibrate(void);

public:
    Simulator(void);
    Simulator(const boost::property_tree::ptree&);

    void run(void);

    ~Simulator(void);
};
#endif
