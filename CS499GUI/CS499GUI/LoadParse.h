//CS499 Senior Project - Course Scheduling system
//Load and parse class
//Purpose: Loads/reads data from data files and parses it into the containers in the schedule class
//Written by: Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once

class LoadParse
{
	public:
		void splitString(string line, char delim, vector<string> &vec);
		void splitString(string line, char delim, Schedule *dept, int state);
		void parseInput(char *fName, Schedule *dept);
		void readRoomFile(char *fName, Schedule *dept);
		void readTimeFile(char *fName, Schedule *dept);
};