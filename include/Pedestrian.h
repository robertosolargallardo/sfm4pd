#ifndef _PEDESTRIAN_H_
#define _PEDESTRIAN_H_
#include <vector>
#include <stdint.h>
#include <random>
#include <iostream>
#include "PositionGeo.h"
extern std::mt19937 rng;

enum Model{SHORTEST_PATH};

template<unsigned int MODEL>
class Pedestrian{
	private:	uint32_t _id;
				double   _speed;
				double	_pause;
				std::vector<PositionGeo> _path;//memory

	public:	Pedestrian(void);
				Pedestrian(const uint32_t&,const double&,const double&,const double&,const std::vector<std::vector<PositionGeo>>&);
				~Pedestrian(void);
};
#endif
