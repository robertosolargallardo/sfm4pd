#include "../include/Simulator.h"
Simulator::Simulator(void) {

}
Simulator::Simulator(const boost::property_tree::ptree &_fsettings) {
    this->_fsettings=_fsettings;

	 Limits limits(_fsettings.get_child("limits"));
	 this->_grid=Grid(limits);

    for(auto freference_point : this->_fsettings.get_child("reference-points")){
		  Geographic g=Geographic(freference_point.second.get<double>("longitude"),freference_point.second.get<double>("latitude"));
	     boost::property_tree::ptree felevation=SRTM3Wrapper::request(g);
		  g.elevation(felevation.get<double>("elevation"));
        this->_reference_points.push_back(g.cartesian());
	 }

	 uint32_t id=0U;
    for(auto fpedestrians : this->_fsettings.get_child("pedestrians")){
		for(uint32_t i=0U;i<fpedestrians.second.get<uint32_t>("number");i++,id++){
			shared_ptr<Pedestrian> p=make_shared<Pedestrian>(id,fpedestrians.second.get<double>("speed.min"),fpedestrians.second.get<double>("speed.max"),fpedestrians.second.get<std::string>("model"),fpedestrians.second.get<std::string>("type"),limits);
			//TODO p->random_position();
			/*
				switch(p->model()){
					case SHORTESTPATH: do_something1();break //calcular la ruta
					case FOLLOWTHECROWD: do_something2();break //no hacer nada
				}
			*/
			this->_pedestrians.push_back(p);
			this->_grid.insert(p);
		}
	 }
    this->calibrate();
}
void Simulator::calibrate(void) {
    this->run(CALIBRATION_TIME,false);
};
void Simulator::run() {
    this->run(this->_fsettings.get<uint32_t>("duration"),true);
}
void Simulator::run(const uint32_t &_duration,const bool &_save_to_disk) {
    /*std::vector<std::shared_ptr<Pedestrian>> neighbors;

    for(uint32_t t=0U; t<_duration; t++) {
        if(_save_to_disk) {
            std::ofstream ofs(this->_fsettings.get<string>("output.directory-path")+"/"+this->_fsettings.get<string>("output.filename-prefix")+boost::lexical_cast<std::string>(t)+this->_fsettings.get<string>("output.filename-sufix"));
            for(auto& pedestrian : this->_pedestrians)
                ofs << pedestrian.current() << std::endl;//TODO radians or gis coordinates?
        }

        std::vector<Pedestrian> pedestrians;
        for(auto& pedestrian : this->_pedestrians) {
            Pedestrian p(pedestrian);
            p.update_position(neighbors);
            pedestrians.push_back(p);
        }
        this->_pedestrians.clear();
        this->_pedestrians=pedestrians;
    }*/
}

Simulator::~Simulator(void) {
    //this->_pedestrians.clear();
}
