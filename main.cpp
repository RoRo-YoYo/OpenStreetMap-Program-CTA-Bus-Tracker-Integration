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
    cout << "Enter building name (partial or complete), or * to list, or $ to end>" << endl;

    getline(cin, name);

    if (name == "$") {
      break;
    }
    else if (name == "*") {
      buildings.print();}
    else {

      // 
      // find every building that contains this name:
      //
      bool foundBuilding = false;

      for (Building B : buildings.osmBuildings)
      {
        if (B.Name.find(name) != string::npos) {  // contains name:

          foundBuilding = true;

          cout << B.Name << endl;
          cout << "Address: " << B.StreetAddress << endl;
          cout << "Building ID: " << B.ID << endl;

          cout << "Nodes:" << endl;
          for (long long nodeid : B.NodeIDs)
          {
            cout << "  " << nodeid << ": ";

            double lat = 0.0;
            double lon = 0.0;
            bool entrance = false;

            bool foundNode = nodes.find(nodeid, lat, lon, entrance);

            if (foundNode) {
              cout << "(" << lat << ", " << lon << ")";

              if (entrance)
                cout << ", is entrance";

              cout << endl;
            }
            else {
              cout << "**NOT FOUND**" << endl;
            }
          }//for
        }//if
      }//for

      if (!foundBuilding)
        cout << "No such building" << endl;

    }//else

  }//while

  //
  // done:
  //
  cout << endl;
  cout << "** Done **" << endl;
  cout << "# of calls to getID(): " << Node::getCallsToGetID() << endl;
  cout << "# of Nodes created: " << Node::getCreated() << endl;
  cout << "# of Nodes copied: " << Node::getCopied() << endl;

  return 0;
}
