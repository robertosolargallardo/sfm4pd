#ifndef _GRID_H_
#define _GRID_H_
#include <set>
#include <map>
#include <climits>
#include "Limits.h"
#include "Position.h"
#include "Pedestrian.h"

enum NeighborhoodType{MOORE1,MOORE2,VONNEUMANN1,VONNEUMANN2};

using namespace std;
struct PedestrianComparator {
    bool operator()(const Pedestrian &_p1,const Pedestrian &_p2) const {
        return(_p1.id()<_p2.id());
    }
};

typedef set<Pedestrian,PedestrianComparator> Pedestrians;
typedef Pedestrians Neighbors;

class Grid {
private:
    class Cell {
    private:
        Pedestrians _pedestrians;

    public:
        Cell(void) {
            ;
        }
        Cell(const Cell &_cell) {
            this->_pedestrians=_cell._pedestrians;
        }
        ~Cell(void) {
            this->_pedestrians.clear();
        }
        void operator=(const Cell &_cell) {
            this->_pedestrians=_cell._pedestrians;
        }
    };

    map<pair<uint32_t,uint32_t>,Cell>  _cells;
    Limits _limits;

public:
    Grid(void);
    Grid(const Limits&);
    Grid(const Grid&);
    ~Grid(void);

    Grid& operator=(const Grid&);

    void insert(const shared_ptr<Pedestrian>&);
    void remove(const Pedestrian&);
    void search(const Pedestrian&);
	 /*
	  * @_angle equal M_PI means all agents in the surrounding area and is its default value
	  * @_number_of_neighbors equal UINT_MAX means all agents in the surrounding area and is its default value. Otherwise, the top-_number_of_neighbors is computed by selecting the most closest and ahead.
     */
    Neighbors neighbors_of(const Pedestrian&,const NeighborhoodType&,const unsigned int &_number_of_neighbors=UINT_MAX,const double &_angle=M_PI);
};
#endif
