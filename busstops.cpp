/*bustops.cpp*/

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
#include <algorithm> 
#include <vector>

#include "busstops.h"
#include "dist.h"

using namespace std;

    
    //
    // constructor
    //
    // Given an CVS document, reads through the document and 
    // parse each line
    //

    BusStops::BusStops() {
        ifstream infile;

        infile.open("bus-stops.txt"); //Open file
        if (infile.fail()) {
            cout << "Bus file failed";
        }




        while (true) {

        string line;
        getline(infile, line); // read a line from the input file    
        //cout << line << endl;
        if (infile.fail()) {
            //cout << "Second: Bus file failed";
            break;}

        stringstream parser(line); // setup to parse the line

        string id_str, route_str, stopname, direction, location, lat_str, lon_str;

        getline(parser, id_str, ',');// extract each value:
        getline(parser, route_str, ',');
        getline(parser, stopname, ',');
        getline(parser, direction, ',');
        getline(parser, location, ',');
        getline(parser, lat_str, ',');
        getline(parser, lon_str);

        // Type correction
        int id = stoi(id_str);  //int
        int route = stoi(route_str); 
        double lat = stod(lat_str);  // Double
        double lon = stod(lon_str);

        BusStop B(id,route,stopname,direction,location,lat,lon);

        this->vecBusStops.push_back(B);

    }//while
 };

 void BusStops::print() {
    //
    //Sort bus into ascending order by ID:
    //
    sort(this->vecBusStops.begin(),this->vecBusStops.end(),
        [](BusStop B1,BusStop B2){
            if (B1.ID < B2.ID) // keep
                return true;
            else // swap
                return false;
        });
 
    for (BusStop B : this->vecBusStops) {
        cout << B.ID << ": " << B.Route << ", " << B.StopName << ", " << B.Direction << ", " << B.Location << ", " << B.Lat << ", " << B.Lon <<  endl;}
};

pair<BusStop,double> BusStops::SouthClosestStop(double building_lat, double building_lon) {
    vector<pair<BusStop,double>> BusStopWithMiles;
    for (BusStop B: this->vecBusStops) {
        //
        // Iterate through bus stops. If it's SouthBound, take the lat and lon for each and calculate the distance given the building
        //
        if (B.Direction == "Southbound") {
        double miles = distBetween2Points(building_lat, building_lon, B.Lat, B.Lon);
        BusStopWithMiles.push_back(make_pair(B,miles));}}

    //
    // Sort miles into ascending order
    //    
    sort(BusStopWithMiles.begin(),BusStopWithMiles.end(),
    [](pair<BusStop,double> P1, pair<BusStop,double> P2){
        if (P1.second < P2.second) // keep
            return true;
        else // swap
            return false;
    });

    //
    // Return the pair with the shortest distance by indexing [0]
    //
    return BusStopWithMiles[0];

}


pair<BusStop,double> BusStops::NorthClosestStop(double building_lat, double building_lon) {
    vector<pair<BusStop,double>> BusStopWithMiles;
    for (BusStop B: this->vecBusStops) {
        //
        // Iterate through bus stops. If it's SouthBound, take the lat and lon for each and calculate the distance given the building
        //
        if (B.Direction == "Northbound") {
        double miles = distBetween2Points(building_lat, building_lon, B.Lat, B.Lon);
        BusStopWithMiles.push_back(make_pair(B,miles));}}

    //
    // Sort miles into ascending order
    //    
    sort(BusStopWithMiles.begin(),BusStopWithMiles.end(),
    [](pair<BusStop,double> P1, pair<BusStop,double> P2){
        if (P1.second < P2.second) // keep
            return true;
        else // swap
            return false;
    });

    //
    // Return the pair with the shortest distance by indexing [0]
    //
    return BusStopWithMiles[0];

}
