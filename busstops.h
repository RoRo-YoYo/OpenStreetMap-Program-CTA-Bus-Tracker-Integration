/*bustops.h*/

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
#include <vector>
#include <utility>

#include "busstop.h"

using namespace std;

class BusStops
{
    public:  
    vector<BusStop> vecBusStops;
    //
    // constructor
    //
    // Given an CVS document, reads through the document and 
    // parse each line
    //

    BusStops();

    void print();

    vector<pair<BusStop,double>> ClosestStop(double building_lat, double building_lon);
    // pair<BusStop,double> SouthClosestStop(double place_lat,double place_lon);

    // pair<BusStop,double> NorthClosestStop(double building_lat, double building_lon);

};