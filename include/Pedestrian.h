#ifndef _PEDESTRIAN_H_
#define _PEDESTRIAN_H_
#include <vector>
#include <stdint.h>
#include <random>
#include <iostream>
#include "PositionGeo.h"
extern std::mt19937 rng;

enum Model{SHORTEST_PATH};

class Pedestrian{
	private:	uint32_t _id;
				double   _speed;
				double	_pause;
				unsigned int _model;		
				std::vector<PositionGeo> _path;//memory

	public:	Pedestrian(void);
				Pedestrian(const uint32_t&,const double&,const double&,const double&,const unsigned int&,const std::vector<PositionGeo>&,const std::pair<PositionGeo,PositionGeo>&);
				~Pedestrian(void);
};
#endif
