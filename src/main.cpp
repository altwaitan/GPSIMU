/*
 * Author: Abdullah Altawaitan
 * File: Location.cpp
 */

// standard includes are different in C++
#include <cstdio>
#include <cstdlib>

/***********************************************************************/
// Includes for classes needed to launch the main algorithms
#include "NMEAParser.h"
#include "Visit.h"
#include "VehicleJourney.h"
#include <iostream>
#include <vector>


// Reads in the file and starts the parsing process.
int main( int argc, char **argv )
{
    
	
	// printing out to the stderr if something goes wrong.
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " logFile outputFile" << std::endl;
		return -1;
	}
	
    // Create a new Journey.
	VehicleJourney journey;
    
    // Set the states for the journey by reading from the file.
	journey.setStates(NMEAParser::parseLogFile(argv[1]));

	if (journey.getStates().size() > 0)
	{
		journey.analyzeJourney();
            
		if (journey.writeOutputFile(argv[2]) == false)
		{
			std::cerr << "Cannot open the file " << argv[2] << std::endl;
			return -1; 
		}
	}
	else
	{
		std::cerr << "Cannot open the file " << argv[2] << ", or file is empty" << std::endl;
		return -1; 
	}
     
	

	return 0;
}