/***
Name: Abdullah Altawaitan
Netid: altwaitan
Course: ECE275
Assignment #: 3
File: VehicleJourney.cpp
*/

#include "VehicleJourney.h"


// Constructor
/* also constructs the interesting locations vector to consider in this journey */
VehicleJourney::VehicleJourney(void)
{
    // Put every location that we provided in a vector locations in VehicleJourney object
    std::vector<Location *> result;
    
    Location *a = new Location(FRYS, FRYS_LAT, FRYS_LON);
    result.push_back(a);
    
    Location *b = new Location(ECE, 32.235599, -110.953088);
    result.push_back(b);
    
    Location *c = new Location(UNIVERSITY, 32.231672, -110.959131);
    result.push_back(c);
    
    Location *d = new Location(FOURTH, 32.227751, -110.965590);
    result.push_back(d);
    
    Location *e = new Location(EEGEES, 32.235891, -110.934919);
    result.push_back(e);
    
    Location *f = new Location(CATTRAN, 32.217875, -110.914389);
    result.push_back(f);
    
    Location *g = new Location(INO, 32.221842, -110.957492);
    result.push_back(g);
    
    Location *h = new Location(ELLIOT, 32.205207, -110.959206);
    result.push_back(h);
    
    Location *i = new Location(UNKNOWN, 0, 0);
    result.push_back(i);
    
    locations = result;


	return; 
}

// Destructor
VehicleJourney::~VehicleJourney(void)
{
	return;
}


/* Analyze journey calculates the visits and sorts them */
void VehicleJourney::analyzeJourney()
{
    // First determine the visits
    determineVisits();
    
    // Then sort the visits
    sortVisits();
    
    
    /* Put the Location values inside For GPSIMUState */
    int size = this->states.size();
    int sizeLocation = this->locations.size();
    int i = 0;
    int j = 0;
    
    double latitude = 0;
    double longtitude = 0;
    
    
    for (i = 0; i < size; i++)
    {
        latitude = states.at(i)->getLatitude();
        longtitude = states.at(i)->getLongitude();
        
        for (j = 0; j < sizeLocation; j++)
        {
            bool check = locations.at(j)->inLocation(latitude, longtitude);
            if (check == 1)
            {
                // For GPSIMUState Location
                states.at(i)->setLocation(locations.at(j)->getName());
                break;
            }
        }
    }
    

}

/* writes the output file */
bool VehicleJourney::writeOutputFile(std::string filename)
{
	bool result = false;
    
    // Create a file for the output
    std::ofstream outfile;
    outfile.open(filename.c_str());
    
    // Check if the file is opened
    if (outfile.is_open())
    {
        result = true;
        outfile <<   getVisitsAsStrings();
    }
    
    // close the file
    outfile.close();
    
	return result; 
}

/* returns the output strings for printing out */
std::string VehicleJourney::getVisitsAsStrings() const
{
	std::string result;
    std::stringstream stream;
    int size = visits.size();
    int i = 0;
    
    // Printing all the visits that we have
    for (i = 0; i < size; i++)
    {
        stream << visits.at(i)->getVisitString();
    }
    
    result = stream.str();
    
	return result; 
}

/* return a pointer for location that found */
Location* VehicleJourney::findLocation(GPSIMUState* state)
{
    // Finding a location of a GPSIMUState
    Location* result = NULL;
    int j = 0;
    int sizeLocation = this->locations.size();
    double latitude = 0;
    double longtitude = 0;
    
    latitude = state->getLatitude();
    longtitude = state->getLongitude();
    
    for (j = 0; j < sizeLocation; j++)
    {
        bool check = locations.at(j)->inLocation(latitude, longtitude);
        if (check == 1)
        {
            result->setName(locations.at(j)->getName());
            break;
        }
    }
    
    result->setLatitude(latitude);
    result->setLongitude(longtitude);
    

	return result;

}

/* looks through the state vector and determines the visits, including
setting all values for each visit */
void VehicleJourney::determineVisits()
{
	int size = this->states.size(); 
	int sizeLocation = this->locations.size();
	int i = 0; 
	int j = 0;
    
    // Store the values of latitude and longtitude
	double latitude = 0;
	double longtitude = 0;
    
    // store previous values of latitude and longtitude
    double prevLat = 0;
    double prevLong = 0;
    std::string name = "";
    std::string prevState = "";
    int sizeVisit = 0;
	
    
    // Loopin through the states
	for (i = 0; i < size; i++)
	{
		latitude = states.at(i)->getLatitude();
        longtitude = states.at(i)->getLongitude();
        
        // If we are at the same location
        if (prevLat == latitude && prevLong == longtitude)
        {
            // Loop through list of locations
            for(j = 0; j < sizeLocation; j++)
            {
                // If we found the locarion in our list
                if (latitude == locations.at(j)->getLatitude() && longtitude == locations.at(j)->getLongitude())
                {
                    // Store the name of the location in name, so we can use it to determine if we have that visit in our vector visits
                    name = locations.at(j)->getName();
                    break;
                }
            }
            
        
            
            // Loop through vector visits
            for (j = 0; j < sizeVisit; j++)
            {
                // If we found the name in our vector list
                if(visits.at(j)->getLocation() == name)
                {
                    // Change the endTime for the visit
                    visits.at(j)->setEndTime(states.at(i)->getSeconds());
                    
                    // If the state is not the same that we have, then add a new state
                    if (prevState != states.at(i)->getState())
                    {
                        visits.at(j)->addState(states.at(i)->getState());
                        prevState = states.at(i)->getState();
                    }
                }
            }
            
        }
        else // If we are not at the same location
        {
            for (j = 0; j < sizeLocation; j++)
            {
                // If we found a visist in our list of locations
                bool check = locations.at(j)->inLocation(latitude, longtitude);
                if (check == 1)
                {
                    // Then create a new Visiit, and push it in the back of our vector visits
                    Visit* v = new Visit(locations.at(j)->getName(), states.at(i)->getSeconds(), states.at(i)->getSeconds());
                    v->addState(states.at(i)->getState());
                    prevState = states.at(i)->getState();
                    visits.push_back(v);
                
                    prevLat = latitude;
                    prevLong = longtitude;
                
                    sizeVisit = visits.size();
                    break;
                }
            }
        }
	}
	
}

/* sorts the visits vector after it is populated */
void VehicleJourney::sortVisits()
{
    // Sort the vectors by the compare function 
	std::sort(visits.begin(), visits.end(), Visit::compare);
	return;
}