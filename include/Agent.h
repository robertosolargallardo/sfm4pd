#ifndef _AGENT_H_
#define _AGENT_H_
#include <list>
#include <functional>
#include <string>
#include <stdint.h>
#include <random>
#include <iostream>
#include <tuple>
#include <memory>
#include <boost/property_tree/ptree.hpp>
#include "Limits.h"
#include "Cartesian.h"
#include "Environment.h"

extern std::mt19937 rng;

enum MobilityModel {SHORTESTPATH=9366416273040049814U,FOLLOWTHECROWD=10676684734677566718U,RANDOMWALKWAY,WORKINGDAY};
enum AgentType {CITIZEN=4010033517051247807U,TOURIST=4046867417885078969U};

#define CLOSE_ENOUGH 1.0

#define REPULSION  0.75
#define ALIGNING   2.0
#define ATTRACTION 5.0

class Environment;
class Neighbor;
class Agent {
private:
    static std::hash<std::string> _hash;

    uint32_t _id;
    double   _min_speed;
    double   _max_speed;
    MobilityModel _model;
    AgentType _type;

    Cartesian _position;
    Cartesian _direction;

    class Memory {
    public:
        std::list<char*> _container;
        Memory(void) {
            ;
        }
        Memory(Memory &_m) {
            this->_container=_m._container;
        }
        ~Memory(void) {
            this->_container.clear();
        }
        Memory& operator=(const Memory &_m) {
            this->_container=_m._container;
            return(*this);
        }
        void push_back(char* _data) {
            this->_container.push_back(_data);
        }
        void push_front(char* _data) {
            this->_container.push_front(_data);
        }
        void pop_front(void) {
            this->_container.pop_front();
        }
        void pop_back(void) {
            this->_container.pop_back();
        }
        char* front(void) {
            return(this->_container.front());
        }
        char* back(void) {
            return(this->_container.back());
        }
		  bool empty(void){
				return(this->_container.empty());
		  }

    };
    std::shared_ptr<Memory> _memory;

public:
    Agent(void);
    Agent(const Agent&);
    Agent(const uint32_t&,const Cartesian &,const double&,const double&,const std::string&,const std::string&);
    ~Agent(void);
    Agent& operator=(const Agent&);

    Cartesian position(void);
    Cartesian direction(void);
    void position(const Cartesian&);
    void direction(const Cartesian&);

    uint32_t id(void) const;
    MobilityModel model(void) const;

    std::shared_ptr<Agent::Memory> memory(void);

    Cartesian repulsion(const Neighbor&);
    Cartesian aligning(const Neighbor&);
    Cartesian attraction(const Neighbor&);

    void move(const Environment&);
};
#endif
