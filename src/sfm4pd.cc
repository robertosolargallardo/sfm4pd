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
    std::string outputdir=std::string();
    std::string osrm=std::string();

    while ((c = getopt(argc, argv, "f:d:o:")) != -1) {
        switch (c) {
        case 'f':
            settings=std::string(optarg);
            break;
        case 'd':
            outputdir=std::string(optarg);
            break;
        case 'o':
            osrm=std::string(optarg);
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
    if( outputdir.length() == 0 ) {
        std::cerr << "Mandatory parameter -d <output-directory> needed" << std::endl;
        exit(EXIT_FAILURE);
    } else {

        if(!exists(outputdir)) {
            std::cerr << "Error::Directory \"" << outputdir << "\" does not exists" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if( osrm.length() == 0 ) {
        std::cerr << "Mandatory parameter -o <osrm-settings-file> needed" << std::endl;
        exit(EXIT_FAILURE);
    } else {

        if(!exists(osrm)) {
            std::cerr << "Error::File \"" << osrm<< "\" does not exists" << std::endl;
            exit(EXIT_FAILURE);
        }
        boost::property_tree::ptree fosrm;
        read_json(osrm, fosrm);

        OSRMWrapper::host=fosrm.get<std::string>("osrm.host");
        OSRMWrapper::port=fosrm.get<std::string>("osrm.port");
        OSRMWrapper::resource=fosrm.get<std::string>("osrm.resource");
        OSRMWrapper::params=fosrm.get<std::string>("osrm.params");
    }

    boost::property_tree::ptree fsettings;
    read_json(settings,fsettings);

    Simulator s(fsettings,outputdir);
    s.run();

    return(EXIT_SUCCESS);
}
