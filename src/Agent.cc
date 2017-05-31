#include "../include/Agent.h"
Agent::Agent(void) {
    ;
}
Agent::Agent(const Agent &_agent) {
    this->_id=_agent._id;
    this->_min_speed=_agent._min_speed;
    this->_max_speed=_agent._max_speed;
    this->_position=_agent._position;
    this->_direction=_agent._direction;
    this->_model=_agent._model;
    this->_type=_agent._type;
    this->_memory=_agent._memory;
}
Agent::Agent(const uint32_t &_id,const Cartesian &_position,const double &_min_speed,const double &_max_speed,const std::string &_model,const std::string &_type) {
    this->_id=_id;
    this->_min_speed=_min_speed;
    this->_max_speed=_max_speed;
    this->_position=_position;
    this->_direction=_direction;
    this->_model=MobilityModel(this->_hash(_model));
    this->_type=AgentType(this->_hash(_type));
    this->_memory=std::make_shared<Agent::Memory>();
}
Agent& Agent::operator=(const Agent &_agent) {
    this->_id=_agent._id;
    this->_min_speed=_agent._min_speed;
    this->_max_speed=_agent._max_speed;
    this->_position=_agent._position;
    this->_direction=_agent._direction;
    this->_model=_agent._model;
    this->_type=_agent._type;
    this->_memory=_agent._memory;
    return(*this);
}
MobilityModel Agent::model(void) const {
    return(this->_model);
}
std::shared_ptr<Agent::Memory> Agent::memory(void) {
    return(this->_memory);
}
void Agent::move(const Environment &_env) {
    double d=0.0;
    std::uniform_real_distribution<double> random_speed(this->_min_speed,this->_max_speed);
    double speed=random_speed(rng);

    switch(this->_model) {
    case SHORTESTPATH: {
        while(speed>0.0 && !this->memory()->empty()){
        		Cartesian direction=(*(Cartesian*)this->memory()->front())-this->position();
        		Environment::Neighbors neighbors=_env.neighbors_of(this,MOORE1);
        		for(auto& neighbor : neighbors) {
            	if(neighbor.distance()<=REPULSION)
               	direction+=this->repulsion(neighbor);
				}
        		//speed-=direction.norm();

        		/*if(speed>=0.0)
        			this->memory()->pop_front();*/
		  }
        break;
    }
    case FOLLOWTHECROWD: {
        Cartesian direction;
        Environment::Neighbors neighbors=_env.neighbors_of(this,MOORE2);
        for(auto& neighbor : neighbors) {
            if(neighbor.distance()<=REPULSION)
                direction+=this->repulsion(neighbor);
            else if(neighbor.distance()<=ATTRACTION)
                direction+=this->attraction(neighbor);
        }
        break;
    }
    case WORKINGDAY: {
        break;
    }
    case RANDOMWALKWAY: {
        break;
    }
    }
}
Cartesian Agent::repulsion(const Neighbor &_n) {
	 if(_n.angle()<=M_PI_4){
		 Cartesian collision=_n.agent()->position()-this->position();
       Cartesian perpendicular=this->direction().cross(collision);
		 //TODO angle with sign: atan2((Vb x Va) . Vn, Va . Vb)
		 // atan2(perpendicular.dot(plane),this->direction().dot(collision));
    }
    return(Cartesian());
}
Cartesian Agent::aligning(const Neighbor &_n) {
    return(_n.agent()->direction());
}
Cartesian Agent::attraction(const Neighbor &_n) {
    return(_n.agent()->position()-this->position());
}
Cartesian Agent::position(void) {
    return(this->_position);
}
uint32_t Agent::id(void) const {
    return(this->_id);
}
Agent::~Agent(void) {
	//EMPTY MEMORY!!!
}
Cartesian Agent::direction(void) {
    return(this->_direction);
}
void Agent::position(const Cartesian &_position) {
    this->_position=_position;
}

void Agent::direction(const Cartesian &_direction) {
    this->_direction=_direction;
}
