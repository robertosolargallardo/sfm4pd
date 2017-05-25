#ifndef _GRID_H_
#define _GRID_H_
#include <set>
#include <map>
#include <climits>
#include "Limits.h"
#include "Position.h"
#include "Agent.h"
#define DELTA_X 1.0 //metros
#define DELTA_Y 1.0 //metros

enum NeighborhoodType{MOORE1,MOORE2,VONNEUMANN1,VONNEUMANN2};

using namespace std;
struct AgentComparator {
    bool operator()(const shared_ptr<Agent> &_p1,const shared_ptr<Agent> &_p2) const {
        return(_p1->id()<_p2->id());
    }
};

typedef set<std::shared_ptr<Agent>,AgentComparator> Agents;
typedef Agents Neighbors;

class Grid {
private:
    class Cell {
    private:
        Agents _agents;

    public:
        Cell(void) {
            ;
        }
        Cell(const Cell &_cell) {
            this->_agents=_cell._agents;
        }
        ~Cell(void) {
            this->_agents.clear();
        }
        void operator=(const Cell &_cell) {
            this->_agents=_cell._agents;
        }
        void insert(const std::shared_ptr<Agent> &_p){
            this->_agents.insert(this->_agents.begin(),_p);
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

    void insert(const shared_ptr<Agent>&);
    void remove(const Agent&);
    void search(const Agent&);
	 /*
	  * @_angle equal M_PI means all agents in the surrounding area and is its default value
	  * @_number_of_neighbors equal UINT_MAX means all agents in the surrounding area and is its default value. Otherwise, the top-_number_of_neighbors is computed by selecting the most closest and ahead.
     */
    Neighbors neighbors_of(const Agent&,const NeighborhoodType&,const unsigned int &_number_of_neighbors=UINT_MAX,const double &_angle=M_PI);
};
#endif
