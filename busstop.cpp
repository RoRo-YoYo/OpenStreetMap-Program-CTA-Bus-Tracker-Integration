/*bustop.cpp*/

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

#include "busstop.h"

using namespace std;

    
    //
    // constructor
    //
    // Given an CVS document, reads through the document and 
    // parse each line
    //

    BusStop::BusStop(string filename) {
        ifstream infile;
        infile.open(filename); //Open file

        string line;
        getline(infile, line); // read a line from the input file

        stringstream parser(line); // setup to parse the line

        getline(parser, id_str, ',');// extract each value:
        getline(parser, route_str, ',');
        getline(parser, stopname, ',');
        getline(parser, direction, ',');
        getline(parser, location, ',');
        getline(parser, lat_str, ',');
        getline(parser, lon_str);

        // Type correction
        id_str = stoi(id_str);  //int
        route_str = stoi(route_str); 
        lat_str = stod(lat_str);  // Double
        lon_str = stod(lon_str);
 };

