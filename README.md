GPSIMU
==========

An application that analyzes the behavior of an autonomous vehicle from the output of its GPS/IMU recorded along its journey.  The application will read in NMEA sentences from log files output by the vehicle and record GPS information (latitude, longitude, and accuracy) and the time (in weeks and seconds) based on one specific NMEA sentence type.  It should store this information within a class that represents the state of the vehicle at that second.  Finally, the program will analyze the data to determine the operating state of the vehicle’s GPS/IMU at a range of specific locations the vehicle visited on its journey.  The program will output an alphabetized list of these destinations that it visited based on GPS coordinates, and the state(s) of the GPS/IMU at that location (in order).

Note: This program is motivated by research done with the CAT Vehicle (http://catvehicle.arizona.edu/) in the ECE department.

==========

Command-line Arguments:

	gpsimu logFile outputFile