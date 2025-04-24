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
#include "dist.h"

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

    // Get vector size of the busstop
    int getNumBusStops();

    // Sort bus into ascending order by ID and print
    void print();

    // Iterate through bus stops,look for Southbound and Northbound. Take the lat and lon for each and calculate the distance given the building location
    // Return the northstop and southstop with it's associated miles
    vector<pair<BusStop,double>> ClosestStop(double building_lat, double building_lon);
   };