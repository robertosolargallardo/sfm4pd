#include "../include/Environment.h"
Environment::Environment(void) {
    ;
}
Environment::Environment(const Limits &_limits) {
    this->_limits=_limits;
}
Environment::Environment(const Environment &_env) {
    this->_cells=_env._cells;
    this->_limits=_env._limits;
}
Environment::~Environment(void) {
    this->_cells.clear();
}
Environment& Environment::operator=(const Environment &_env) {
    this->_cells=_env._cells;
    this->_limits=_env._limits;
    return(*this);
}
void Environment::insert(Agent* _agent) {
    ;
}
void Environment::remove(Agent* _agent) {
    ;
}
void Environment::search(Agent* _agent) {
    ;
}
Environment::Neighbors Environment::neighbors_of(Agent* _agent,const NeighborhoodType &_type,const unsigned int &_number_of_neighbors,const double &_angle) const {
    Environment::Neighbors nbs;
    return(nbs);
}
