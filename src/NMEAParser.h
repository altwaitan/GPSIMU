/*
 * Name: Abdullah Altawaitan
 * File: NMEAParser.h
 */


#ifndef NMEAParser_H
#define NMEAParser_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "GPSIMUState.h"

// NMEAParser that handles all of the parsing for this assignment with static functions.
class NMEAParser {
public:
	// If unable to read file, the vector will be of size 0 
	static std::vector<GPSIMUState*> parseLogFile(std::string filename);
	static GPSIMUState* parseNMEASentence(std::string sentence);

private:
	// These are private because there is no need for them in a ‘static’ 
	// class.
	NMEAParser(void);
	~NMEAParser(void);
};











#endif