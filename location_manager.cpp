#include "location_manager.h"

LocationManager::LocationManager()
{

}

LocationManager::~LocationManager()
{

}

bool LocationManager::knownLocation(const std::string &name)
{
    if(locations_.find(name) != locations_.end())
        return true;
    return new_locations_.find(name) != new_locations_.end();
}

bool LocationManager::getLocation(const std::string &name, geometry_msgs::Pose &location)
{
    for(auto &it : locations_){
        if(it.first == name){
            location = it.second.location;
            return true;
        }
    }

    for(auto &it : new_locations_){
        if(it.first == name){
            location = it.second.location;
        }
    }

    return false;
}

std::map<std::string, KnownLocation> &LocationManager::getLocations()
{
    return locations_;
}

void LocationManager::addLocation(const std::string &name, const geometry_msgs::Pose &pose)
{
    locations_[name].location = pose;
}

void LocationManager::removeLocation(const std::string &name)
{
    locations_.erase(name);
}
