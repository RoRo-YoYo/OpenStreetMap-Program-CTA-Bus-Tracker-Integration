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

#include "busstop.h"

using namespace std;

    
    //
    // constructor
    //


    BusStop::BusStop(int id, int route, string stopname, string direction, string location, double lat, double lon) // Create busstop and initialize variable
    : ID(id), Route(route), StopName(stopname),Direction(direction),Location(location),Lat(lat),Lon(lon)
    
    {

    }



