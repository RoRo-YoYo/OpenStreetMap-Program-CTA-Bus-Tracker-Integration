/*bustop.cpp*/

//
// Take in and parse each line of the bus stop CVS file
// 
// Rocelyn Young
// Northwestern University
// CS 211
// 
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "busstop.h"
#include "curl_util.h"
#include "json.hpp"
#include "node.h"
#include "nodes.h"


using namespace std;
using json = nlohmann::json;

    
    //
    // constructor
    //


    BusStop::BusStop(int id, int route, string stopname, string direction, string location, double lat, double lon) // Create busstop and initialize variable
    : ID(id), Route(route), StopName(stopname),Direction(direction),Location(location),Lat(lat),Lon(lon)
    
    {

    }

    void BusStop::print(pair<pair<BusStop,double>,pair<BusStop,double>> ) {
    // //
    // // Find and Print closest south bound. Set up url
    // //

    if 

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

    }

    // void BusStop::printBusPrediction(CURL* curl, string url, string& response) {
    //     if (callWebServer(curl, url, response) == true) {
    //        auto jsondata = json::parse(response);
    //        auto bus_response = jsondata["bustime-response"];
    //        auto predictions = bus_response["prd"];
      
    //        // for each prediction (a map) in the prediction list
    //        for (auto& M : predictions) {
    //            cout << "  vehicle #" << stoi(M["vid"].get_ref<string&>()) << "on the route " << stoi(M["rt"].get_ref<string&>()) << " travelling " << M["rtdir"].get_ref<string&>() << "to arrive in " << stoi(M["prdctdn"].get_ref<string&>()) << " mins" << endl;}
    //     }
    //     else {
    //       cout << " << bus predictions unavailable, call failed>>" << endl;}
    //   }
      


