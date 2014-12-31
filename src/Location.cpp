/*
 * Author: Abdullah Altawaitan
 * File: Location.cpp
 */

#include <stdio.h>
#include <math.h>
#include "Location.h"

// implementation of Location nondefault constructor
/***
Note that in this nondefault constructor, the initialization
region of the constructor is used to pass along constructor 
parameters and directly set the values of the variables during
initialization. This means that when the object is placed on the stack
or on the heap, that the memory is initialized with these parameter values
already in it, rather than later assigning those values to the variables
of the functions. It makes all things run a little faster, but it only
works with constructors. We'll learn more about this in later chapters.
*/
Location::Location( std::string name,
				   double latitude, double longitude )
: name(name), latitude(latitude), longitude(longitude)
{
	
}

// returns TRUE if both latitude and longitude are within 
// LOCATION_TOLERANCE of this Location objects's latitude and longitude
bool Location::inLocation( double latitude, double longitude ) const
{
	bool result=false;

    // Checking 0.002 difference 
	double compLat = this->getLatitude();
	double compLong = this->getLongitude();

	if ((latitude <= (compLat + LOCATION_TOLERANCE) && latitude >= (compLat - LOCATION_TOLERANCE)) && (longitude <= (compLong + LOCATION_TOLERANCE) && longitude >= (compLong - LOCATION_TOLERANCE)))
	{
		result = true;
	}

	return result;
}

