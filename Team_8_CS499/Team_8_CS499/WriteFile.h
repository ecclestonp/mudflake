//Interface file for WriteFile.cpp
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifndef WRITEFILE_H
#define WRITEFILE_H

class WriteFile
{
	private:
		char fName[100];
	public:
		WriteFile(char *fileName);
		~WriteFile();

		//Input array of std::strings, could also use vectors
		//Input name of department and number of courses
		void writeToFile(std::string theData[][5], std::string department, int numCourses);
};

#endif
