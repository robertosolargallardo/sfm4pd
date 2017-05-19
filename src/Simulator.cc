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
			Cartesian position=this->random_position_generator(limits,*this->_reference_points.begin());
			shared_ptr<Pedestrian> p=make_shared<Pedestrian>(position,id,fpedestrians.second.get<double>("speed.min"),fpedestrians.second.get<double>("speed.max"),fpedestrians.second.get<std::string>("model"),fpedestrians.second.get<std::string>("type"));

			switch(p->model()){
				case SHORTESTPATH:{
					break;
				};
				case FOLLOWTHECROWD:{
					break; //no hacer nada
				};
				default:{
					std::cerr << "ERROR::Unknown Mobility Model: " << p->model() << std::endl;
					exit(EXIT_FAILURE);
				}
			}

			this->_pedestrians.push_back(p);
			this->_grid.insert(p);
		}
	 }
    this->calibrate();
}
//TODO HAY Q ARREGLAR ESTO PQ TARDA MUCHO.
std::list<std::shared_ptr<Cartesian>> Simulator::shortest_path(const Cartesian &_position){
	double mindist=DBL_MAX,d=0.0;
   boost::property_tree::ptree optimal_route;
	std::list<std::shared_ptr<Cartesian>> route;

   for(auto& reference_point : _reference_points) {
       boost::property_tree::ptree fresponse=OSRMWrapper::request(_position,reference_point);
       boost::property_tree::ptree route=fresponse.get_child("routes").begin()->second;

       d=route.get<double>("distance");
       if(d<mindist) {
          mindist=d;
        	 optimal_route=route;
       }
    }
	 boost::property_tree::ptree steps=optimal_route.get_child("legs").begin()->second.get_child("steps");

    for(auto& step : steps) {
        for(auto& intersection : step.second.get_child("intersections")) {
            boost::property_tree::ptree::iterator flongitude=intersection.second.get_child("location").begin();
            boost::property_tree::ptree::iterator flatitude=++intersection.second.get_child("location").begin();
				Geographic g(flongitude->second.get<double>(""),flatitude->second.get<double>(""));
				shared_ptr<Cartesian> c=make_shared<Cartesian>(g);
				boost::property_tree::ptree felevation=SRTM3Wrapper::request(g);
            c->z(felevation.get<double>("elevation"));
				route.push_back(c);
        }
    }
	 return(route);
}
Cartesian Simulator::random_position_generator(const Limits &_limits,const Cartesian &_reference_point){
	 std::uniform_real_distribution<double> x(_limits.min().x(),_limits.max().x());
	 std::uniform_real_distribution<double> y(_limits.min().y(),_limits.max().y());

    while(true) {
        Cartesian c(x(rng),y(rng));
        boost::property_tree::ptree fresponse=OSRMWrapper::request(c,_reference_point);
        if(fresponse.get<std::string>("code").compare("Ok")==0) {
				boost::property_tree::ptree felevation=SRTM3Wrapper::request(c);
				c.z(felevation.get<double>("elevation"));
				return(c);
        }
    }
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
