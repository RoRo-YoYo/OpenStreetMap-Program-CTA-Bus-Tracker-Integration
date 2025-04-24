/*main.cpp*/

//
// Program to input Nodes (positions) and Buildings from
// an Open Street Map file.
// 
// Prof. Joe Hummel
// Northwestern University
// CS 211
// 

#include <iostream>
#include <string>

#include "building.h"
#include "buildings.h"
#include "node.h"
#include "nodes.h"
#include "osm.h"
#include "tinyxml2.h"
#include "busstop.h"
#include "busstops.h"
#include "dist.h"
#include "curl_util.h"


using namespace std;
using namespace tinyxml2;


//
// main
//
int main()
{
  XMLDocument xmldoc;
  
  cout << "** NU open street map **" << endl;

  string filename;

  cout << endl;
  cout << "Enter map filename>" << endl;
  getline(cin, filename);
  
  //
  // Initialize API
  //

  CURL* curl = curl_easy_init();
  if (curl == nullptr) {
  cout << "**ERROR:" << endl;
  cout << "**ERROR: unable to initialize curl library" << endl;
  cout << "**ERROR:" << endl;
  return 0;}

  //
  // 1. load XML-based map file 
  //
  if (!osmLoadMapFile(filename, xmldoc))
  {
    // failed, error message already output
    return 0;
  }
  
  //
  // 2. create and read the nodes, which are the various known 
  //    positions on the map:
  //
  Nodes nodes(xmldoc);

  //
  // 3. create and read the university buildings:
  //
  Buildings buildings(xmldoc);

  //
  // 4. create and read the bus stops:
  //
  BusStops busstops;

  //
  // 5. stats
  //
  cout << "# of nodes: " << nodes.getNumOsmNodes() << endl;
  cout << "# of buildings: " << buildings.getNumOsmBuildings() << endl;

  //
  // now let the user for search for 1 or more buildings:
  //
  while (true)
  {
    string name;

    cout << endl;
    cout << "Enter building name (partial or complete), or * to list, or @ for bus stops, or $ to end>" << endl;

    getline(cin, name);

    if (name == "$") {
      break;
    }
    else if (name == "@") {
      busstops.print();
    }
    else if (name == "*") {
      buildings.print();}
    else {
      // 
      // find every building that contains this name:
      //
      
      buildings.findAndPrint(name,nodes,busstops);
    }//else

  }//while



  //
  // done:
  //
  curl_easy_cleanup(curl);
  curl_global_cleanup();

  cout << endl;
  cout << "** Done **" << endl;
  //cout << "# of calls to getID(): " << Node::getCallsToGetID() << endl;
  //cout << "# of Nodes created: " << Node::getCreated() << endl;
  //cout << "# of Nodes copied: " << Node::getCopied() << endl;


  return 0;
}
