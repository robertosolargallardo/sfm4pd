#include "../include/Simulator.h"
Simulator::Simulator(void){

}
Simulator::Simulator(const boost::property_tree::ptree &_fsettings){
   this->_fsettings=_fsettings;
   std::list<PositionGeo> reference_points;
   std::pair<PositionGeo,PositionGeo> limits(PositionGeo(this->_fsettings.get<double>("limits.bottom-left.lat"),
																			this->_fsettings.get<double>("limits.bottom-left.lon")),
                                             PositionGeo(this->_fsettings.get<double>("limits.top-right.lat"),
																			this->_fsettings.get<double>("limits.top-right.lon")));
   
   for(auto& freference_point : this->_fsettings.get_child("reference-points"))
      reference_points.push_back(PositionGeo(freference_point.second.get<double>("lat"),freference_point.second.get<double>("lon")));

   for(uint32_t id=0;id<this->_fsettings.get<uint32_t>("number-of-pedestrians");++id)
      this->_pedestrians.push_back(Pedestrian(id,this->_fsettings.get<double>("min-speed"),this->_fsettings.get<double>("max-speed"),this->_fsettings.get<double>("delay"),
                                              this->_fsettings.get<unsigned int>("model"),reference_points,limits));
	this->calibrate();
}
void Simulator::calibrate(void){
	this->run(10U,false);
};
void Simulator::run(){
	this->run(this->_fsettings.get<uint32_t>("duration"),true);
}
void Simulator::run(const uint32_t &_duration,const bool &_save_to_disk){
	std::vector<std::shared_ptr<Pedestrian>> neighbors;

	for(uint32_t t=0U;t<_duration;t++){
		if(_save_to_disk){
			std::ofstream ofs("output/positions_"+boost::lexical_cast<std::string>(t)+".txt");
			for(auto& pedestrian : this->_pedestrians)
				ofs << pedestrian.current() << std::endl;
		}

		std::vector<Pedestrian> pedestrians;
		for(auto& pedestrian : this->_pedestrians){
			Pedestrian p(pedestrian);
			p.update_position(neighbors);
			pedestrians.push_back(p);
		}
		this->_pedestrians.clear();
		this->_pedestrians=pedestrians;
	}
}

Simulator::~Simulator(void){
	this->_pedestrians.clear();
}
