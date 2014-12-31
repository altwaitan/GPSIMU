/*
 * Author: Abdullah Altawaitan
 * File: VehicleJourney.h
*/


#ifndef VehicleJourney_H
#define VehicleJourney_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Location.h"
#include "GPSIMUState.h"
#include "Visit.h"

// The journey class that stores all of the information about the vehicle’s journey
class VehicleJourney {
public:
	// Constructor and Destructor
	/* also constructs the interesting locations vector to consider in this journey */
	VehicleJourney(void);
	~VehicleJourney(void);

	/* Analyze journey calculates the visits and sorts them */
	void analyzeJourney();

	/* writes the output file */
	bool writeOutputFile(std::string filename);

	/* returns the output strings for printing out */
	std::string getVisitsAsStrings() const;

	Location* findLocation(GPSIMUState* state);

	/* Mutators for variables are below */
	void setStates(std::vector<GPSIMUState*> states) { this->states = states; }
    
	std::vector<GPSIMUState*> getStates() const { return this->states; }

private:
	/* looks through the state vector and determines the visits, including
	setting all values for each visit */
	void determineVisits();
	/* sorts the visits vector after it is populated */
	void sortVisits();

	// member variables
	std::vector<GPSIMUState*> states; // The list of GPS locations and states.
	std::vector<Visit*> visits;       // The locations that were visited.

	// if you create this list when you construct your vehicle journey, then
	// it may be easier to check whether you are in a location or not
	std::vector<Location*> locations;
};











#endif