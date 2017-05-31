#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Environment.h"
#include "Cartesian.h"
#include "Agent.h"
#include "OSRMWrapper.h"
#include "SRTM3Wrapper.h"

#define CALIBRATION_TIME 100

class Simulator {
private:
    static std::hash<std::string> _hash;

    Environment _env;
    std::list<Cartesian> _reference_points;
    std::vector<Agent*> _agents;
    boost::property_tree::ptree _fsettings;

    void run(const uint32_t&,const bool&);
    void calibrate(void);

    Geographic random_position_generator(const Limits&,const Cartesian&);
    std::list<Cartesian*> shortest_path(const Cartesian&);

public:
    Simulator(void);
    Simulator(const boost::property_tree::ptree&);

    void run(void);

    ~Simulator(void);
};
#endif
