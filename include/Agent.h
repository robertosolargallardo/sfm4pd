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

extern std::mt19937 rng;

enum MobilityModel{SHORTESTPATH=9366416273040049814U,FOLLOWTHECROWD=10676684734677566718U,RANDOMWALKWAY,WORKINGDAY};
enum AgentType{CITIZEN=4010033517051247807U,TOURIST=4046867417885078969U};

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

	 class Memory{
    	public:	std::list<std::shared_ptr<void>> _container;
					Memory(void){;}
					Memory(Memory &_m){
						this->_container=_m._container;
					}
					~Memory(void){
						this->_container.clear();
					}
					Memory& operator=(const Memory &_m){
						this->_container=_m._container;
						return(*this);
					}
					void push_back(const std::shared_ptr<void> &_data){
						this->_container.push_back(_data);
					}
					void push_front(const std::shared_ptr<void> &_data){
						this->_container.push_front(_data);
					}
					void pop_front(void){
						this->_container.pop_front();
					}
					void pop_back(void){
						this->_container.pop_back();
					}
					std::shared_ptr<void> front(void){
						return(this->_container.front());
					}
					std::shared_ptr<void> back(void){
						return(this->_container.back());
					}

 
	 }_memory;


public:
    Agent(void);
    Agent(const Agent&);
	 Agent(const uint32_t&,const double&,const double&,const std::string&,const std::string&,const Cartesian&,const Cartesian&);
    ~Agent(void);
	 Agent& operator=(const Agent&);

    Cartesian position(void);
    Cartesian direction(void);

    uint32_t id(void) const;
	 MobilityModel model(void) const;
	
    Memory& memory(void);

	 Cartesian repulsion(const Cartesian&);
	 Cartesian aligning(const Cartesian&);
	 Cartesian attraction(const Cartesian&);

    //asigna un PositionGeo dentro de &_limits
    /*void random_init_position(const std::pair<PositionGeo,PositionGeo>&,const PositionGeo&);//TODO
    void extract_path(boost::property_tree::ptree&);//TODO

    //Agent(const uint32_t&,const double&,const double&,const double&,const unsigned int&,const std::list<Position>&,const std::pair<PositionGeo,PositionGeo>&);
    void move(const Agents&);*/

};
#endif
