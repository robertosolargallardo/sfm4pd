#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_
#include <boost/property_tree/ptree.hpp>
class Simulator{
	private:	boost::property_tree::ptree _settings;

	public:	Simulator(void);
				Simulator(const boost::property_tree::ptree&);
		
				void run(void);

				~Simulator(void);
};
#endif
