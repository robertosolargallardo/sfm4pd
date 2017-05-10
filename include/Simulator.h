#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Pedestrian.h"
#include "PositionGeo.h"
#define CALIBRATION_TIME 10U
#define PREFIX_FILE_NAME "positions_"
#define SUFFIX_FILE_NAME ".txt"

class Simulator {
private:
    boost::property_tree::ptree _fsettings;
    std::vector<Pedestrian> _pedestrians;

    std::string _outputdir;

    void run(const uint32_t&,const bool&);
    void calibrate(void);

public:
    Simulator(void);
    Simulator(const boost::property_tree::ptree&,const std::string&);

    void run(void);

    ~Simulator(void);
};
#endif
