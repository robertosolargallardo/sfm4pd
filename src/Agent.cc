#include "../include/Agent.h"
Agent::Agent(void) {
    ;
}
Agent::Agent(const Agent &_agent) {
    this->_id=_agent._id;
    this->_min_speed=_agent._min_speed;
    this->_max_speed=_agent._max_speed;
    this->_position=_agent._position;
    this->_model=_agent._model;
    this->_type=_agent._type;
    this->_memory=_agent._memory;
}
Agent::Agent(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const std::string &_model,const std::string &_type,const Cartesian &_position,const Cartesian &_direction){
    this->_id=_id;
    this->_min_speed=_min_speed;
    this->_max_speed=_max_speed;
	 this->_position=_position;
	 this->_direction=_direction;
    this->_model=MobilityModel(this->_hash(_model));
    this->_type=AgentType(this->_hash(_type));//TODO not yet used
}
Agent& Agent::operator=(const Agent &_agent){
    this->_id=_agent._id;
    this->_min_speed=_agent._min_speed;
    this->_max_speed=_agent._max_speed;
    this->_position=_agent._position;
    this->_model=_agent._model;
    this->_type=_agent._type;
    this->_memory=_agent._memory;

	 return(*this);
}
MobilityModel Agent::model(void) const{
	return(this->_model);
}
Agent::Memory& Agent::memory(void){
	return(this->_memory);
}
/*void Agent::update_position(const std::vector<std::shared_ptr<Agent>> &_neighbors) {
    double d=0.0;
    std::uniform_real_distribution<double> random_speed(_min_speed,_max_speed);
    double speed=random_speed(rng);

    while(!this->_path.empty()) {
        PositionGeo destination=this->_path.front();
        d=this->_position.distance(destination);

        if(speed>=d) {
            this->_position=destination;
            this->_path.pop_front();
            speed-=d;
        } else {
            this->_position.traslate(destination,speed);
            break;
        }
    }
}*/
Cartesian Agent::position(void) {
    return(this->_position);
}
uint32_t Agent::id(void) const{
	return(this->_id);
}
Agent::~Agent(void) {
}
Cartesian Agent::direction(void) {
    return(this->_direction);
}
