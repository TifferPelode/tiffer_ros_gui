#ifndef LOCATION_MANAGER_H
#define LOCATION_MANAGER_H

#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <map>

class KnownLocation
{
public:
    std::string name;
    geometry_msgs::Pose location;
};

class LocationManager
{
public:
    LocationManager();
    virtual ~LocationManager();

    bool knownLocation(const std::string &name);
    bool getLocation(const std::string &name, geometry_msgs::Pose &location);
    std::map<std::string, KnownLocation> &getLocations();
    void addLocation(const std::string &name, const geometry_msgs::Pose &pose);
    void removeLocation(const std::string &name);
protected:
    std::map<std::string, KnownLocation> locations_;
    std::map<std::string, KnownLocation> new_locations_;
};

typedef boost::shared_ptr<LocationManager> LocationManagerPtr;

#endif // LOCATION_MANAGER_H
