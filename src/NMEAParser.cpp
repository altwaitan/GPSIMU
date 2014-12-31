/*
 * Author: Abdullah Altawaitan
 * File: NMEAParser.cpp
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "NMEAParser.h"

// A function that opens a file and gets a line from the file and store it in a vector of GPSIMUState.
std::vector<GPSIMUState*> NMEAParser::parseLogFile(std::string filename)
{
	// A new vector pointer that we will return from the function  
	std::vector<GPSIMUState*> state; 

	// Opening the file to read the data from 
	std::fstream file; 
	file.open(filename.c_str());
	std::string readLine; 
	size_t find; 
	GPSIMUState* ptr; 
	ptr = NULL;

	// Check if the file is opened successfully 
	if (file.is_open())
	{
		while (!file.eof())
		{

			// get one line from the file and store it in a string variable 
			getline(file, readLine);
			// find the string "#INSPVAA" in the line and return true if it is found, else return false 
			find = readLine.find("#INSPVAA");

			// If we found the string "#INSPVAA"
			if (find != std::string::npos)
			{
				// store the address of the new created object of GPSIMUState
				ptr = NMEAParser::parseNMEASentence(readLine);

				// Check if it not equal to NULL
				if (ptr != NULL)
				{
					// Now put the object in the vector list 
					state.push_back(ptr);
				}
			}
			ptr = NULL;
		}
	}

	return state; 
}



// A function that return the address of a new allocated variable of GPSIMUState by passing the sentence line. 
GPSIMUState* NMEAParser::parseNMEASentence(std::string sentence)
{
	// A pointer variable kind of GPSIMUState 
	GPSIMUState* newState;
	// Allocate memory for the new variable and store the address of it in the newState 
	newState = new GPSIMUState(sentence);
	// Return the address of the variable that has been allocated 
	return newState;


}