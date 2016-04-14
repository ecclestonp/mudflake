//Load and parse the data

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