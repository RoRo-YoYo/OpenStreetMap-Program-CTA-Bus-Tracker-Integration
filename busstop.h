/*bustop.h*/

//
// A bus in a CVS file
// 
// Rocelyn Young
// Northwestern University
// CS 211
// 
#pragma once

#include <string>
#include <sstream>
#include <fstream>

#include "nodes.h"
#include "node.h"
#include "curl_util.h"

using namespace std;

class BusStop
{
    public:
    int ID;
    int Route; 
    string StopName;
    string Direction; 
    string Location;
    double Lat;
    double Lon;

    //
    // constructor
    //
    // Build a busstop
    // 
    //
    // Each bus stop consists of a stop ID (15924), the bus route (201), the stop name (Central & Sheridan), the direction of travel (Eastbound), the location of the stop (SW
    // corner), and the position in latitude and longitude
    BusStop(int id, int route, string stopname, string direction, string location, double lat, double lon);

    // print the nearest busstop, along with the prediction of incoming bus
    void print(double& miles,CURL* curl);

    // // Find the prediction given curl, url, and string to store the information found. Print out, if exist. Else, catch error if not.
    void printBusPrediction(CURL* curl, string url, string response);

};