#include "../include/Pedestrian.h"
Pedestrian::Pedestrian(void) {
    ;
}
Pedestrian::Pedestrian(const Pedestrian &_pedestrian) {
    this->_id=_pedestrian._id;
    this->_min_speed=_pedestrian._min_speed;
    this->_max_speed=_pedestrian._max_speed;
    this->_model=_pedestrian._model;
    this->_type=_pedestrian._type;
    this->_path=_pedestrian._path;
    this->_current=_pedestrian._current;
}
Pedestrian::Pedestrian(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const std::string &_model,const std::string &_type,const Limits &_limits){
    this->_id=_id;
    this->_min_speed=_min_speed;
    this->_max_speed=_max_speed;
    this->_model=MobilityModel(this->_hash(_model));
    this->_type=PedestrianType(this->_hash(_type));//TODO not yet used
}
Pedestrian& Pedestrian::operator=(const Pedestrian &_pedestrian){
    this->_id=_pedestrian._id;
    this->_min_speed=_pedestrian._min_speed;
    this->_max_speed=_pedestrian._max_speed;
    this->_model=_pedestrian._model;
    this->_type=_pedestrian._type;
    this->_path=_pedestrian._path;
    this->_current=_pedestrian._current;
	 return(*this);
}
/*Pedestrian::Pedestrian(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const double &_delay,const unsigned int &_model,const std::list<PositionGeo> &_reference_points,const std::pair<PositionGeo,PositionGeo> &_limits) {*/
/*Pedestrian::Pedestrian(const uint32_t &_id,const double &_min_speed,const double &_max_speed,const double &_delay,const unsigned int &_model,const std::list<PositionGeo> &_reference_points,const std::pair<PositionGeo,PositionGeo> &_limits) {
    this->_id=_id;
    this->_min_speed=_min_speed;
    this->_max_speed=_max_speed;
    this->_delay=_delay;
    this->random_init_position(_limits,*_reference_points.begin());

    switch(_model) {
    case SHORTEST_PATH: {
        double mindist=DBL_MAX,d=0.0;
        boost::property_tree::ptree optimal_route;

        for(auto& reference_point : _reference_points) {
            boost::property_tree::ptree fresponse=OSRMWrapper::request(this->_current,reference_point);
            boost::property_tree::ptree route=fresponse.get_child("routes").begin()->second;

            d=route.get<double>("distance");
            if(d<mindist) {
                mindist=d;
                optimal_route=route;
            }
        }
        this->extract_path(optimal_route);
        this->_current=this->_path.front();
        this->_path.pop_front();

        //std::cout << this->_current << std::endl;
        //std::cout << this->_path.back() << std::endl;

        break;
    }
    default: {
        std::cerr << "Error::movement model not implemented" << std::endl;
        exit(EXIT_FAILURE);
    }
    }
}*/
/*void Pedestrian::extract_path(boost::property_tree::ptree &_route) {
    boost::property_tree::ptree steps=_route.get_child("legs").begin()->second.get_child("steps");

    for(auto& step : steps) {
        for(auto& intersection : step.second.get_child("intersections")) {
            boost::property_tree::ptree::iterator lon=intersection.second.get_child("location").begin();
            boost::property_tree::ptree::iterator lat=++intersection.second.get_child("location").begin();

            //this->_path.push_back(PositionGeo(lat->second.get<double>(""),lon->second.get<double>(""))); //TODO
        }
    }
}
void Pedestrian::random_init_position( const std::pair<PositionGeo,PositionGeo> &_limits,const PositionGeo &_reference_point ) {
    std::uniform_real_distribution<double> random_lat(std::get<0>(_limits).lat(),std::get<1>(_limits).lat());
    std::uniform_real_distribution<double> random_lon(std::get<0>(_limits).lon(),std::get<1>(_limits).lon());

    while(true) {
        double lat=random_lat(rng);
        double lon=random_lon(rng);
		  double alt=0.0;
        PositionGeo p(lat,lon,alt);

        boost::property_tree::ptree fresponse=OSRMWrapper::request(p,_reference_point);

        if(fresponse.get<std::string>("code").compare("Ok")==0) {
				boost::property_tree::ptree felevation=SRTM3Wrapper::request(p);
				p.alt(felevation.get<double>("elevation"));
            this->_current=p;
            break;
        }
    }
}


void Pedestrian::update_position(const std::vector<std::shared_ptr<Pedestrian>> &_neighbors) {
    double d=0.0;
    std::uniform_real_distribution<double> random_speed(_min_speed,_max_speed);
    double speed=random_speed(rng);

    while(!this->_path.empty()) {
        PositionGeo destination=this->_path.front();
        d=this->_current.distance(destination);

        if(speed>=d) {
            this->_current=destination;
            this->_path.pop_front();
            speed-=d;
        } else {
            this->_current.traslate(destination,speed);
            break;
        }
    }
}*/
Cartesian Pedestrian::current(void) {
    return(this->_current);
}
uint32_t Pedestrian::id(void) const{
	return(this->_id);
}
Pedestrian::~Pedestrian(void) {
    this->_path.clear();
}
