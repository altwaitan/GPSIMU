/*
 * Author: Abdullah Altawaitan
 * File: GPSIMUState.cpp
 */

#include "GPSIMUState.h"
#include <vector>
#include <sstream>

// Constructor
GPSIMUState::GPSIMUState(void)
{
	// Initilize everything to ZEROs
	setWeek(0);
	setSeconds(0);
	setLatitude(0);
	setLongitude(0);
	setState("");
	setLocation("");
	return; 
}

// Constructor with argument
GPSIMUState::GPSIMUState(std::string sentence)
{
	// Create a string and store the line in it 
	std::string line = sentence; 
	size_t location = line.find("#INSPVAA"); 
	std::string junk = "";
	std::string statusName = "";

	int change = 1;

	// Check if we found "#INSPVAA"
	if (location != std::string::npos)
	{
		location = line.find(";"); 
		location = location + 1; 
		line.erase(0, location);
	}
	// If I did not find any semicolon 
	while (change == 1)
	{
		location = line.find(",");
		if (location != std::string::npos)
		{
			line.at(location) = ' ';
			change = 1;
		}
		else
		{
			change = 0;
		}
	}
	// Delete * symbol from the sentence 
	location = line.find("*");
	if (location != std::string::npos)
	{
		line.at(location) = ' ';
	}

	// Create a stringstream for the sentence line 
	std::stringstream stream(line);

	// Store the values inside the members of GPSIMUState 
	stream >> this->week;
	stream >> this->seconds; 
	stream >> this->latitude; 
	stream >> this->longitude;
	stream >> junk; // unnecessary info
	stream >> junk; // unnecessary info
	stream >> junk; // unnecessary info
	stream >> junk; // unnecessary info
	stream >> junk; // unnecessary info
	stream >> junk; // unnecessary info
	stream >> junk; // unnecessary info
	stream >> statusName;
	stream >> junk; // unnecessary info

	// Converting the status names 
	if (statusName == "INS_INACTIVE" || statusName == "INS_ALIGNING")
	{
		this->state = "Init"; 
	}
	else if (statusName == "INS_SOLUTION_NOT_GOOD" || statusName == "INS_BAD_GPS_AGREEMENT")
	{
		this->state = "Standby";
	}
	else if (statusName == "INS_SOLUTION_GOOD" || statusName == "INS_ALIGNMENT_COMPLETE")
	{
		this->state = "Ready";
	}

	

}

// Destructor
GPSIMUState::~GPSIMUState(void)
{
	return;
}


