#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_
#include <set>
#include <map>
#include <climits>
#include "Limits.h"
#include "Agent.h"
#define DELTA_X 1.0 //metros
#define DELTA_Y 1.0 //metros


enum NeighborhoodType {MOORE1,MOORE2,VONNEUMANN1,VONNEUMANN2};

class Agent;
class Neighbor {
private:
    double _distance;
    double _angle;
    Agent* _agent;

public:
    Neighbor(void) {
        this->_distance=0.0;
        this->_angle=0.0;
        this->_agent=nullptr;
    }
    Neighbor(const Neighbor &_n) {
        this->_distance=_n._distance;
        this->_angle=_n._angle;
        this->_agent=_n._agent;
    }
    ~Neighbor(void) {
        this->_distance=0.0;
        this->_angle=0.0;
        this->_agent=nullptr;
    }
    Neighbor& operator=(const Neighbor &_n) {
        this->_distance=_n._distance;
        this->_angle=_n._angle;
        this->_agent=_n._agent;
        return(*this);
    }
    double distance(void) const {
        return(this->_distance);
    }
    double angle(void) const {
        return(this->_angle);
    }
    Agent* agent(void) const {
        return(this->_agent);
    }
};

class Environment {
public:	/*class Comparator {
   	 		public:	bool operator()(Agent* _a1,Agent* _a2) const {
      	 					return(_a1->id()<_a2->id());
    	 					}
	 		};
			typedef std::set<Agent*,Comparator> Agents;*/

    typedef std::set<Agent*> Agents;
    typedef std::vector<Neighbor> Neighbors;

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
        void insert(Agent* _a) {
            this->_agents.insert(this->_agents.begin(),_a);
        }
    };

    std::map<std::pair<uint32_t,uint32_t>,Cell>  _cells;
    Limits _limits;

public:
    Environment(void);
    Environment(const Limits&);
    Environment(const Environment&);
    ~Environment(void);

    Environment& operator=(const Environment&);

    void insert(Agent*);
    void remove(Agent*);
    void search(Agent*);
    /*
     * @_angle equal M_PI means all agents in the surrounding area and is its default value
     * @_number_of_neighbors equal UINT_MAX means all agents in the surrounding area and is its default value. Otherwise, the top-_number_of_neighbors is computed by selecting the most closest and ahead.
    */
    Environment::Neighbors neighbors_of(Agent*,const NeighborhoodType&,const unsigned int &_number_of_neighbors=UINT_MAX,const double &_angle=M_PI) const;
};
#endif
