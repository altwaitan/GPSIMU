/*
 * Author: Abdullah Altawaitan
 * File: Visit.h
 */


#ifndef Visit_H
#define Visit_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <locale>

// This Class will store information about locations that the vehicle visits along its journey.
class Visit {
public:
	// Constructor and Destructor
	Visit(void);
	Visit(std::string location, double startTime, double endTime);
	~Visit(void);

	// Compare two visits together to see which is before the other.
	// Returns true if v1 is before v2, false otherwise.
	// A visit is before another if its location is alphabetically before
	// the other visit’s location.
	// A visit with the same location name as another is before that
	// location if its startTime is before the other visit’s startTime.
	static bool compare(Visit* v1, Visit* v2);

	/* Implement other methods as you see fit */

	/* Mutators for variables are below */
	void setStartTime(double startTime) { this->startTime = startTime; }
	double getStartTime() const { return this->startTime; }

	void setEndTime(double endTime) { this->endTime = endTime; }
	double getEndTime() const { return this->endTime; }

	void addState(std::string stateString);
	std::vector<std::string> getStates() const { return this->state; }

	void setLocation(std::string location) { this->location = location; }
	std::string getLocation() const { return this->location; }

	// returns the string for this visit
	std::string getVisitString() const;
    
    // A function that returns uppercase a string
    std::string upperCase(std::string string);

private:
	// Note that you can assume the week will always
	// be the same for start and end times.
	std::string location;      // The location name for this visit.
	double startTime;     // The start seconds for the visit.
	double endTime;       // The end seconds for the visit.
	std::vector<std::string> state; // The ordered list of states at this location.
};











#endif