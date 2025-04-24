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
  this->NodeIDs.push_back(nodeid);
}

void Building::print(Nodes& nodes) {
    BusStops busstops; // Hard-coded, not dependence on main
    cout << this->Name << endl;
    cout << "Address: " << this->StreetAddress << endl;
    cout << "Building ID: " << this->ID << endl;
    cout << "# perimeter nodes: " << this->NodeIDs.size() << endl; 
    pair<double,double> P = this->getLocation(nodes);
    cout << "Location: (" << P.first << ", " << P.second << ")" << endl;

    // //
    // // Find and Print closest south bound. Set up url
    // //
    // pair<BusStop,double> SouthDistance = busstops.SouthClosestStop(P.first, P.second);
    // cout << "Closest southbound bus stop:" << endl;
    // cout << " " << SouthDistance.first.ID << ":" << SouthDistance.first.StopName << ", bus #" << SouthDistance.first.Route << ", " << SouthDistance.first.Location << ", " << SouthDistance.second << " miles" << endl;
    // string southurl = "http://ctabustracker.com/bustime/api/v2/getpredictions?key=jehZ84bN7qAcqWhWj8Jzvs9qE&rt=" + to_string(SouthDistance.first.Route) + "&stpid=" + to_string(SouthDistance.first.ID) + "&format=json";

    // // string southresponce;
    // // SouthDistance.first.printBusPrediction(CURL* curl, southurl, southresponce);

    // //
    // // Find and Print closest nouth bound. Set up url
    // //
    // pair<BusStop,double> NorthDistance = busstops.NorthClosestStop(P.first, P.second);
    // cout << "Closest southbound bus stop:" << endl;
    // cout << " " << NorthDistance.first.ID << ":" << NorthDistance.first.StopName << ", bus #" << NorthDistance.first.Route << ", " << NorthDistance.first.Location << ", " << NorthDistance.second << " miles" << endl;
    // string northurl = "http://ctabustracker.com/bustime/api/v2/getpredictions?key=jehZ84bN7qAcqWhWj8Jzvs9qE&rt=" + to_string(NorthDistance.first.Route) + "&stpid=" + to_string(NorthDistance.first.ID) + "&format=json";

    // // string southresponce;
    // // SouthDistance.first.printBusPrediction(CURL* curl, southurl, southresponce);


    // cout << "Nodes:" << endl;
    // for (long long nodeid : this->NodeIDs)
    // {
      // cout << "  " << nodeid << ": ";

      // double lat = 0.0;
      // double lon = 0.0;
      // bool entrance = false;

      // bool foundNode = nodes.find(nodeid, lat, lon, entrance);

      // if (foundNode) {
      //   cout << "(" << lat << ", " << lon << ")";

      //   if (entrance)
      //     cout << ", is entrance";

      //   cout << endl;
      // }
      // else {
        // cout << "**NOT FOUND**" << endl;
      // }
    // }//for
}

pair<double,double> Building::getLocation(Nodes& nodes) {
    double avgLat = 0;
    double avgLon = 0;
    double parameter = this->NodeIDs.size();
    for (long long nodeid : this->NodeIDs) {
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
