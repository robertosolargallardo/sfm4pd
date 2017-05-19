#include "../include/Pedestrian.h"
Pedestrian::Pedestrian(void) {
    ;
}
Pedestrian::Pedestrian(const Pedestrian &_pedestrian) {
    this->_id=_pedestrian._id;
    this->_min_speed=_pedestrian._min_speed;
    this->_max_speed=_pedestrian._max_speed;
    this->_position=_pedestrian._position;
    this->_model=_pedestrian._model;
    this->_type=_pedestrian._type;
    this->_memory=_pedestrian._memory;
}
Pedestrian::Pedestrian(const Cartesian &_position,const uint32_t &_id,const double &_min_speed,const double &_max_speed,const std::string &_model,const std::string &_type){
    this->_id=_id;
    this->_min_speed=_min_speed;
    this->_max_speed=_max_speed;
	 this->_position=_position;
    this->_model=MobilityModel(this->_hash(_model));
    this->_type=PedestrianType(this->_hash(_type));//TODO not yet used
}
Pedestrian& Pedestrian::operator=(const Pedestrian &_pedestrian){
    this->_id=_pedestrian._id;
    this->_min_speed=_pedestrian._min_speed;
    this->_max_speed=_pedestrian._max_speed;
    this->_position=_pedestrian._position;
    this->_model=_pedestrian._model;
    this->_type=_pedestrian._type;
    this->_memory=_pedestrian._memory;
	 return(*this);
}
MobilityModel Pedestrian::model(void) const{
	return(this->_model);
}
Pedestrian::Memory& Pedestrian::memory(void){
	return(this->_memory);
}
/*void Pedestrian::update_position(const std::vector<std::shared_ptr<Pedestrian>> &_neighbors) {
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
Cartesian Pedestrian::position(void) {
    return(this->_position);
}
uint32_t Pedestrian::id(void) const{
	return(this->_id);
}
Pedestrian::~Pedestrian(void) {
}
Cartesian Pedestrian::direction(void) {
    return(this->_direction);
}
