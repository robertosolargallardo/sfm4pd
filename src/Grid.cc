#include "../include/Grid.h"
Grid::Grid(void){
	;
}
Grid::Grid(const Limits &_limits){
	this->_limits=_limits;
}
Grid::Grid(const Grid &_grid){
	this->_cells=_grid._cells;
	this->_limits=_grid._limits;
}
Grid::~Grid(void){
	this->_cells.clear();
}
Grid& Grid::operator=(const Grid &_grid){
	this->_cells=_grid._cells;
	this->_limits=_grid._limits;
	return(*this);
}
void Grid::insert(const shared_ptr<Pedestrian> &_pedestrian){

}
void Grid::remove(const Pedestrian &_pedestrian){

}
void Grid::search(const Pedestrian &_pedestrian){

}
Pedestrians neighbors_of(const Pedestrian &_pedestrian,const NeighborhoodType &_type,const unsigned int &_number_of_neighbors,const double &_angle){
	Pedestrians p;
	return(p);
}
