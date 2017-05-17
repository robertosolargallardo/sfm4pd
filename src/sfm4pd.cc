#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <unistd.h>
#include <fstream>
#include "../include/Simulator.h"

std::random_device device;
std::mt19937 rng(device());

inline bool exists(const std::string& _name) {
    std::ifstream f(_name.c_str());
    return(f.good());
}

int main(int argc,char **argv) {
    char c;
    extern char *optarg;
    std::string settings=std::string();
    std::string services=std::string();

    while ((c = getopt(argc, argv, "f:s")) != -1) {
        switch (c) {
        case 'f':
            settings=std::string(optarg);
            break;
        case 's':
            services=std::string(optarg);
            break;
        default:
            std::cerr << "Error::unknwon parameter \"" << c << "\"" << std::endl;
            exit(EXIT_FAILURE);
            break;
        }
    }

    if( settings.length() == 0 ) {
        std::cerr << "Mandatory parameter -f <simulation-settings-file> needed" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        if(!exists(settings)) {
            std::cerr << "Error::File \"" << settings << "\" does not exists" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if( services.length() == 0 ) {
        std::cerr << "Mandatory parameter -s <services-file> needed" << std::endl;
        exit(EXIT_FAILURE);
    } else {

        if(!exists(services)) {
            std::cerr << "Error::File \"" << services << "\" does not exists" << std::endl;
            exit(EXIT_FAILURE);
        }
        /*boost::property_tree::ptree fosrm;
        read_json(osrm, fosrm);

        OSRMWrapper::host=fosrm.get<std::string>("osrm.host");
        OSRMWrapper::port=fosrm.get<std::string>("osrm.port");
        OSRMWrapper::resource=fosrm.get<std::string>("osrm.resource");
        OSRMWrapper::params=fosrm.get<std::string>("osrm.params");*/
    }

    boost::property_tree::ptree fsettings;
    read_json(settings,fsettings);

    Simulator s(fsettings);
    s.run();

    return(EXIT_SUCCESS);
}
