#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Pedestrian.h"
#include "PositionGeo.h"
#define CALIBRATION_TIME 10U

class Simulator {
private:
    boost::property_tree::ptree _fsettings;
    std::vector<Pedestrian> _pedestrians;

    void run(const uint32_t&,const bool&);
    void calibrate(void);

public:
    Simulator(void);
    Simulator(const boost::property_tree::ptree&);

    void run(void);

    ~Simulator(void);
};
#endif
