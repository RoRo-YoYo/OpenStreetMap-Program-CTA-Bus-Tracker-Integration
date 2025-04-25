/*building.cpp*/

//
// A building in the Open Street Map.
// 
// Prof. Joe Hummel
// Northwestern University
// CS 211
// 

#include <utility>
#include <string>
#include <vector>
#include <iostream>

#include "building.h"
#include "node.h"
#include "nodes.h"
#include "busstops.h"
#include "busstop.h"
#include "json.hpp"


using namespace std;
using json = nlohmann::json;



//
// constructor
//
Building::Building(long long id, string name, string streetAddr)
  : ID(id), Name(name), StreetAddress(streetAddr)
{
  // vector is default initialized by its constructor
}

//
// adds the given nodeid to the end of the vector.
//
void Building::add(long long nodeid)
{
  this->NodeIDs.emplace_back(nodeid);
}

void Building::print(Nodes& nodes) {
    cout << this->Name << endl;
    cout << "Address: " << this->StreetAddress << endl;
    cout << "Building ID: " << this->ID << endl;
    cout << "# perimeter nodes: " << this->NodeIDs.size() << endl; 
    pair<double,double> P = this->getLocation(nodes);
    cout << "Location: (" << P.first << ", " << P.second << ")" << endl;}

pair<double,double> Building::getLocation(Nodes& nodes) {
    double avgLat = 0;
    double avgLon = 0;
    double parameter = this->NodeIDs.size();
    for (long long& nodeid : this->NodeIDs) {
      double lat = 0.0;
      double lon = 0.0;
      bool entrance = false;

      bool foundNode = nodes.find(nodeid, lat, lon, entrance);

      if (foundNode) {
        // 
        // If node exist, then add up the lon and lat
        //
        avgLat = avgLat + lat;
        avgLon = avgLon + lon;
       } //if
      } //for
    
    // find average
    avgLat = avgLat / parameter;
    avgLon = avgLon / parameter;

return make_pair(avgLat,avgLon);

}
