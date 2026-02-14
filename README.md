# OpenStreetMap + CTA Bus Tracker (C++)

A C++ application that integrates campus OpenStreetMap data with CTA bus stop information and live bus arrival predictions.

Given a building name, the program:
- Computes the building’s geographic center
- Finds the nearest Southbound and Northbound bus stops
- Retrieves real-time arrival predictions using the CTA Bus Tracker API

---

## Features

### Geospatial Computation
- Implemented `Building::getLocation(Nodes&)`
- Computes centroid from perimeter node coordinates

### Bus Stop System
- Designed `BusStop` and `BusStops` classes
- Parsed bus stop data from `bus-stops.txt` (CSV)
- Stored and sorted stops by Stop ID
- Added command to list all bus stops

### Closest Stop Calculation
- Computed nearest Southbound and Northbound stops
- Used provided geographic distance utility
- Implemented outside of `main()` (no nested loops)

### CTA API Integration
- Built dynamic REST URLs (API key, route, stop ID)
- Integrated CTA Bus Tracker using CURL
- Parsed JSON responses with `nlohmann::json`
- Displayed vehicle ID, route, direction, and predicted arrival time

### Robustness
- Exception handling for malformed or missing API data
- Offline mock mode (`-DOFFLINE`) for testing without live API
- Memory-safe (Valgrind clean)

---

## Tech Stack

C++17  
Object-Orien
