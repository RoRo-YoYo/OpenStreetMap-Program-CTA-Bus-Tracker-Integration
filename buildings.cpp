/*buildings.cpp*/

//
// A collection of buildings in the Open Street Map.
// 
// Prof. Joe Hummel
// Northwestern University
// CS 211
// 

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <utility>

#include "buildings.h"

using namespace std;
using namespace tinyxml2;

//
// constructor
//
// Given an XML document, reads through the document and 
// stores all the buildings into the vector data member.
//
Buildings::Buildings(XMLDocument& xmldoc)
{
  XMLElement* osm = xmldoc.FirstChildElement("osm");
  assert(osm != nullptr);

  //
  // Parse the XML document way by way, looking for university buildings:
  //
  XMLElement* way = osm->FirstChildElement("way");

  while (way != nullptr)
  {
    const XMLAttribute* attr = way->FindAttribute("id");
    assert(attr != nullptr);

    //
    // if this is a building, store info into vector:
    //
    if (osmContainsKeyValue(way, "building", "university"))
    {
      string name = osmGetKeyValue(way, "name");

      string streetAddr = osmGetKeyValue(way, "addr:housenumber")
        + " "
        + osmGetKeyValue(way, "addr:street");

      //
      // create building object, then add the associated
      // node ids to the object:
      //
      long long id = attr->Int64Value();

      Building B(id, name, streetAddr);

      XMLElement* nd = way->FirstChildElement("nd");

      while (nd != nullptr)
      {
        const XMLAttribute* ndref = nd->FindAttribute("ref");
        assert(ndref != nullptr);

        long long id = ndref->Int64Value();

        B.add(id);

        // advance to next node ref:
        nd = nd->NextSiblingElement("nd");
      }

      //
      // add the building to the vector:
      //
      this->osmBuildings.push_back(B);
    }//if

    way = way->NextSiblingElement("way");
  }//while

  //
  // done:
  //
}
//
// accessors / getters
//
int Buildings::getNumOsmBuildings() {
  return (int) this->osmBuildings.size();}

void Buildings::print() {
  for (Building B : this->osmBuildings) {
    cout << B.ID << ": " << B.Name << ", " << B.StreetAddress << endl;
  }}

void Buildings::findAndPrint(string name,Nodes& nodes, BusStops& busstops, CURL* curl) {
  bool foundBuilding = false;
  for (Building B : this->osmBuildings)
  {
    if (B.Name.find(name) != string::npos) {  // contains name:
      foundBuilding = true;
      B.print(nodes);
      vector<pair<BusStop,double>> buswithdist = busstops.ClosestStop(B.getLocation(nodes).first,B.getLocation(nodes).second);
      
      //
      // Access the parameters for BusStop::Print and call BusPrint::Print
      //
      BusStop southbus = buswithdist[0].first;
      double southmiles = buswithdist[0].second;
      BusStop northbus = buswithdist[1].first;
      double nortmiles = buswithdist[1].second;

      southbus.print(southmiles, curl);
      northbus.print(nortmiles, curl);} //if
      }//for
  if (!foundBuilding)
  cout << "No such building" << endl;}
