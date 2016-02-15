//Writes to a .csv file
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "WriteFile.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Default constructor
WriteFile::WriteFile(char *fileName)
{
	strcpy(this->fName, fileName);
}

WriteFile::~WriteFile()
{
	//Do Nothing
}

void WriteFile::writeToFile(string theData[][5], string department, int numCourses)
{
	//Open file for output
	ofstream outFile;
	outFile.open(fName, ofstream::out);

	//Write first lines into .csv file
	outFile << department << endl;
	outFile << "Course #,Days,Time,Room,Professor" << endl;

	//Write the data array to the file in .csv format
	//Course - Day(s) - Time - Room - Professor
	for (int i = 0; i < numCourses; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			outFile << theData[i][j] << ",";
		}
		outFile << endl;
	}

	//Close file
	outFile.close();

	return;
}