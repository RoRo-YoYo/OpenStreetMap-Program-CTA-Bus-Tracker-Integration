/*bustop.h*/

//
// Take in and parse each line of the bus stop CVS file
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

    BusStop(int id, int route, string stopname, string direction, string location, double lat, double lon);

    void print(double miles);

    // void printBusPrediction(CURL* curl, string url, string& response);

};