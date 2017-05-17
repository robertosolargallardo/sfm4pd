#ifndef _GRID_H_
#define _GRID_H_
#include "Position.h"
#include "Pedestrian.h"
#include <set>
#include <map>

enum Neighborhood{MOORE1,MOORE2,VONNEUMANN1,VONNEUMANN2};

using namespace std;
struct PedestrianComparator{
	bool operator()(const Pedestrian &_p1,const Pedestrian &_p2) const{
    	return(_p1.id()<_p2.id());
   }
};

typedef set<Pedestrian,PedestrianComparator> Pedestrians;

class Limits{
	private:	Position _min;
				Position _max;
	public:  Limits(void){
					;
				}
				Limits(const Position &_min,const Position &_max){
					this->_min=_min;
					this->_max=_max;
				}
				Limits(const Limits &_limits){
					this->_min=_limits._min;
					this->_max=_limits._max;
				}
				~Limits(void){
					;
				}
				Limits& operator=(const Limits &_limits){
					this->_min=_limits._min;
					this->_max=_limits._max;
					return(*this);
				}
				Position min(void) const{
					return(this->_min);
				}
				Position max(void) const{
					return(this->_max);
				}
};

class Grid{
	private:	
				class Cell{
					private:	Pedestrians _pedestrians;

					public:	Cell(void){
									;
								}
								Cell(const Cell &_cell){
									this->_pedestrians=_cell._pedestrians;
								}
								~Cell(void){
									this->_pedestrians.clear();
								}
								void operator=(const Cell &_cell){
									this->_pedestrians=_cell._pedestrians;
								}
				};

				map<pair<uint32_t,uint32_t>,Cell>  _cells;
				Limits _limits;
				
	public:	Grid(void);
				Grid(const Limits&);
				Grid(const Grid&);
				~Grid(void);

				Grid& operator=(const Grid&);

				void insert(const Pedestrian&);
				void remove(const Pedestrian&);
				void search(const Pedestrian&);
				Pedestrians neighbors_of(const Pedestrian&,const Neighborhood&);

};
#endif
