/*
 * Author: Abdullah Altawaitan
 * File: Visit.cpp
 */

#include "Visit.h"
#include <sstream>
#include <iomanip>


// Constructor
Visit::Visit(void)
{
	return;
}

// Constructor with argument to store the location, startTime, and endTime when we create an object
Visit::Visit(std::string location, double startTime, double endTime)
{
	this->location = location;
	this->startTime = startTime;
	this->endTime = endTime;

	return;
}

// Destructor
Visit::~Visit(void)
{

	return;
}
// Add a new state to the visit
void Visit::addState(std::string stateString)
{
    if (state.size() == 0) {
        state.push_back(stateString);
    }
    else
    {
        std::string lastState = *(state.rbegin( ));
        if (lastState.compare(stateString) != 0) {
            this->state.push_back(stateString);
        }
    }
}

// returns the string for this visit
std::string Visit::getVisitString() const
{
	std::string visitString = "";
	std::stringstream stream; 
	int size = 0; 
	int i = 0; 

	size = this->state.size();

	stream << location << " " << "\n" << std::setprecision(8) << startTime << " " << "to" << " " << std::setprecision(8) << endTime << "\n" << "States: ";
	
	for (i = 0; i < size; i++)
	{
		stream << state[i]; 
		
		if (i != (size-1))
		{
			stream << ", ";
		}
		
	}

	stream << "\n" << "\n";

	visitString = stream.str(); 

	return visitString;
}

// A function that uppercase a string
std::string Visit::upperCase(std::string string)
{
    int i = 0;
    std::string result;
    int size = string.size();
    
    for (i = 0; i < size; i++)
    {
        result[i] = std::toupper(string[i]);
    }
    
    return result;
}

// Compare two visits together to see which is before the other.
// Returns true if v1 is before v2, false otherwise.
// A visit is before another if its location is alphabetically before
// the other visitís location.
// A visit with the same location name as another is before that
// location if its startTime is before the other visitís startTime.
bool Visit::compare(Visit* v1, Visit* v2)
{
	bool result = false;
    
    std::string visit1 = v1->upperCase(v1->getLocation());
    std::string visit2 = v2->upperCase(v2->getLocation());

	if (visit1.compare(visit2) > 0)
	{
		result = false;
	}
	else if (visit1.compare(visit2) == 0)
	{
		if (v1->getStartTime() < v2->getStartTime())
		{
			result = true;
		}
		else
		{
			result = false; 
		}
    }
    else
    {
        result = true;
    }
	

	return result;
}

