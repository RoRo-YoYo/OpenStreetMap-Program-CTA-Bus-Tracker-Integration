/*bustop.cpp*/

//
// A bus in a CVS file
// 
// Rocelyn Young
// Northwestern University
// CS 211
// 
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "busstop.h"
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
    {}

    void BusStop::print(double miles, CURL* curl) {
    // //
    // // Find and Print closest south bound. Set up url
    // //
    if  (this->Direction == "Southbound") {
        cout << "Closest southbound bus stop:" << endl;
        cout << "  " << this->ID << ": " << this->StopName << ", bus #" << this->Route << ", " << this->Location << ", " << miles << " miles" << endl;
        string southurl = "http://ctabustracker.com/bustime/api/v2/getpredictions?key=jehZ84bN7qAcqWhWj8Jzvs9qE&rt=" + to_string(this->Route) + "&stpid=" + to_string(this->ID) + "&format=json";

        string southresponce;
        this->printBusPrediction(curl,southurl,southresponce);
    }
    // //
    // // Find and Print closest nouth bound. Set up url
    // //   
    else if (this->Direction == "Northbound") {
        cout << "Closest northbound bus stop:" << endl;
        cout << "  " << this->ID << ": " << this->StopName << ", bus #" << this->Route << ", " << this->Location << ", " << miles << " miles" << endl;
        string northurl = "http://ctabustracker.com/bustime/api/v2/getpredictions?key=jehZ84bN7qAcqWhWj8Jzvs9qE&rt=" + to_string(this->Route) + "&stpid=" + to_string(this->ID) + "&format=json";

        string northresponce;
        this->printBusPrediction(curl, northurl,northresponce);
    } }
    // //
    // // Find the prediction given curl, url, and string to store the information found. Print out, if exist. Else, catch error if not.
    // // 
    void BusStop::printBusPrediction(CURL* curl, string url, string& response) {
        if (callWebServer(curl, url, response) == true) {
           auto jsondata = json::parse(response);
           auto bus_response = jsondata["bustime-response"];
           auto predictions = bus_response["prd"];
      
           // for each prediction (a map) in the prediction list 
           for (auto& M : predictions) { 
            try {
               cout << "  vehicle #" << stoi(M["vid"].get_ref<string&>()) << " on the route " << stoi(M["rt"].get_ref<string&>()) << " travelling " << M["rtdir"].get_ref<string&>() << " to arrive in " << stoi(M["prdctdn"].get_ref<string&>()) << " mins" << endl;}
            //
            catch (exception& e) {
                cout << " error" << endl;
                cout << " malformed CTA response, prediction unavailable"
                     << " << bus predictions unavailable, call failed>>" << endl;}
            } //for
      }}
      


