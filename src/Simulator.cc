#include "../include/Simulator.h"
Simulator::Simulator(void) {

}
Simulator::Simulator(const boost::property_tree::ptree &_fsettings) {
    std::list<Position> reference_points;
    this->_fsettings=_fsettings;

	 Limits limits(Position(Geographic(this->_fsettings.get<double>("limits.min.longitude"),this->_fsettings.get<double>("limits.min.latitude"),0.0)),Position(Geographic(this->_fsettings.get<double>("limits.max.longitude"),this->_fsettings.get<double>("limits.max.latitude"),0.0)));

	 this->_grid=Grid(limits);

    for(auto freference_point : this->_fsettings.get_child("reference-points")){
		  Geographic g=Geographic(freference_point.second.get<double>("longitude"),freference_point.second.get<double>("latitude"),0.0);
	     boost::property_tree::ptree felevation=SRTM3Wrapper::request(g);
		  g.elevation(felevation.get<double>("elevation"));
        reference_points.push_back(Position(g));
	 }

	 uint32_t id=0U;
    for(auto fpedestrians : this->_fsettings.get_child("pedestrians")){
		for(uint32_t i=0U;i<fpedestrians.second.get<uint32_t>("number");i++,id++){
			Pedestrian p(id,fpedestrians.second.get<double>("speed.min"),fpedestrians.second.get<double>("speed.max"),fpedestrians.second.get<std::string>("model"),fpedestrians.second.get<std::string>("type"),limits);
		}
	 }
//PositionGeo(freference_point.second.get<double>("lat"),freference_point.second.get<double>("lon"),0.0));//TODO 0.0
    
	 /*std::pair<PositionGeo,PositionGeo> limits(PositionGeo(this->_fsettings.get<double>("limits.bottom-left.lat"),this->_fsettings.get<double>("limits.bottom-left.lon"),0.0),PositionGeo(this->_fsettings.get<double>("limits.top-right.lat"),this->_fsettings.get<double>("limits.top-right.lon"),0.0));//TODO 0.0

    for(auto& freference_point : this->_fsettings.get_child("reference-points"))
        reference_points.push_back(PositionGeo(freference_point.second.get<double>("lat"),freference_point.second.get<double>("lon"),0.0));//TODO 0.0

    for(uint32_t id=0; id<this->_fsettings.get<uint32_t>("number-of-pedestrians"); ++id)
        this->_pedestrians.push_back(Pedestrian(id,this->_fsettings.get<double>("min-speed"),this->_fsettings.get<double>("max-speed"),this->_fsettings.get<double>("delay"),this->_fsettings.get<unsigned int>("model"),reference_points,limits));
    this->calibrate();*/
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
