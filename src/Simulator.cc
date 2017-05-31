#include "../include/Simulator.h"
Simulator::Simulator(void) {

}
Simulator::Simulator(const boost::property_tree::ptree &_fsettings) {
    this->_fsettings=_fsettings;
    Limits limits(this->_fsettings.get_child("limits"));
    this->_env=Environment(limits);

    for(auto freference_point : this->_fsettings.get_child("reference-points")) {
        Geographic g=Geographic(freference_point.second.get<double>("longitude"),freference_point.second.get<double>("latitude"));
        boost::property_tree::ptree felevation=SRTM3Wrapper::request(g);
        g.elevation(EARTH_RADIUS+felevation.get<double>("elevation"));
        this->_reference_points.push_back(g.cartesian());
    }

    uint32_t id=0U;
    for(auto fagent : this->_fsettings.get_child("agents")) {
        uint32_t number_of_pedestrians=fagent.second.get<uint32_t>("number");
        double min_speed=fagent.second.get<double>("speed.min");
        double max_speed=fagent.second.get<double>("speed.max");
        std::string mobility_model=fagent.second.get<std::string>("model");
        std::string agent_type=fagent.second.get<std::string>("type");

        for(uint32_t i=0U; i<number_of_pedestrians; i++,id++) {
            std::cout << "creating agent::" << id << std::endl;
            Geographic position=this->random_position_generator(limits,*this->_reference_points.begin());//TODO
            Agent* agent=new Agent(id,position.cartesian(),min_speed,max_speed,mobility_model,agent_type);

            switch(this->_hash(mobility_model)) {
            case SHORTESTPATH: {
                std::list<Cartesian*> route=this->shortest_path(position);
                while(!route.empty()) {
                    agent->memory()->push_back((char*)(route.front()));
                    route.pop_front();
                }
                break;
            };
            case FOLLOWTHECROWD: {
                break;
            };
            default: {
                std::cerr << "ERROR::Unknown Mobility Model: " << mobility_model << std::endl;
                exit(EXIT_FAILURE);
            }
            }

            this->_agents.push_back(agent);
            this->_env.insert(agent);
        }
    }
    this->calibrate();
}
std::list<Cartesian*> Simulator::shortest_path(const Cartesian &_position) {
    double mindist=DBL_MAX,d=0.0;
    boost::property_tree::ptree optimal_route;
    std::list<Cartesian*> route;

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
            boost::property_tree::ptree felevation=SRTM3Wrapper::request(g);
            g.elevation(EARTH_RADIUS+felevation.get<double>("elevation"));
            Cartesian *c=new Cartesian(g);
            route.push_back(c);
        }
    }
    route.pop_front();
    return(route);
}
//TODO HAY Q ARREGLAR ESTO PQ TARDA MUCHO.
Geographic Simulator::random_position_generator(const Limits &_limits,const Cartesian &_reference_point) {
    std::uniform_real_distribution<double> longitude(_limits.min().longitude(),_limits.max().longitude());
    std::uniform_real_distribution<double> latitude(_limits.min().latitude(),_limits.max().latitude());

    Geographic target(_reference_point);
    while(true) {
        Geographic g(longitude(rng),latitude(rng));
        boost::property_tree::ptree fresponse=OSRMWrapper::request(g,target);
        if(fresponse.get<std::string>("code").compare("Ok")==0) {
            boost::property_tree::ptree felevation=SRTM3Wrapper::request(g);
            g.elevation(EARTH_RADIUS+felevation.get<double>("elevation"));
            return(g);
        }
    }
}
void Simulator::calibrate(void) {
    std::cout << "calibrating" << std::endl;
    this->run(CALIBRATION_TIME,false);
};
void Simulator::run() {
    this->run(this->_fsettings.get<uint32_t>("duration"),true);
}
void Simulator::run(const uint32_t &_duration,const bool &_save_to_disk) {
    std::cout << "simulating" << std::endl;

    for(uint32_t t=0U; t<_duration; t++) {
        if(_save_to_disk) {
            std::ofstream ofs(this->_fsettings.get<std::string>("output.directory-path")+"/"+this->_fsettings.get<std::string>("output.filename-prefix")+boost::lexical_cast<std::string>(t)+this->_fsettings.get<std::string>("output.filename-sufix"));
            for(auto& agent: this->_agents)
                ofs << agent->position().geographic() << std::endl;
        }

        for(auto& agent : this->_agents) {
            Agent* a=new Agent(*agent);
            a->move(this->_env);
        }
    }
}

Simulator::~Simulator(void) {
    //this->_pedestrians.clear();
}
