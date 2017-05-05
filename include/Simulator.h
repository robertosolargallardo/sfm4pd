#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include "Pedestrian.h"
#include "PositionGeo.h"

class Simulator{
	private:	boost::property_tree::ptree _fsettings;
				std::vector<Pedestrian> _pedestrians;

	public:	Simulator(void);
				Simulator(const boost::property_tree::ptree&);
		
				void run(void);

				~Simulator(void);
};
#endif
