#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Schedule.h"

using namespace std;


//use this to create professor objects
void splitString(string line, char delim, vector<string> &vec)
{
	string temp;
	stringstream stream(line);

	while(getline(stream, temp, delim))
	{
		temp = temp.substr(temp.find_first_not_of(" \n\r\t"));
		vec.push_back(temp);
	}
}

//this function splits the courses, use 
void splitString(string line, char delim, Schedule *dept, int state)
{
	BuildObj testbuilder;
	Course *coursePtr;
	string temp;
	stringstream stream(line);

	while(getline(stream, temp, delim))
	{
		temp = temp.substr(temp.find_first_not_of(" \n\r\t"));
		temp = temp.substr(0,temp.find_last_not_of("\n\r\t")+1);
		if(state == 2)
		{
			//using a ptr, call the BuildObj function for course
			coursePtr = testbuilder.BuildCourse(temp,"", false);
			//push to back of course vector
			dept->courses.push_back(coursePtr);
		}
	}
}

void parseInput(Schedule *dept)
{
	vector<Instructor> prof;
	char state = 0;
	ifstream input;

	BuildObj testbuilder;
	Instructor *instrPtr;

	input.open("Dept1ClassData.csv");
	string strn;
	while(!input.eof())
	{
		getline(input, strn);
		/* Every line has a newline at the end */
		if(strn.length() < 2)
		{
			state++;
			continue;
		}
		/* Compare the character before the newline */
		if(strn[strn.length()-2] == ':') continue;

		//cout << (int)state << ": " << strn << endl;

		switch (state)
		{
			case 2:/*  	CS 107, CS 108, CS 114, CS 144, CS 172 */
				splitString(strn, ',', dept, state);
			break;
			case 4:/*   CS 342 must be taught in Technology Hall, room 342 */
				//TODO: implement contstraints on a case-by-case basis
			break;
			case 6:/*   Dr. Echo, CS 107, CS 226, CS 342 - Preference: Morning classes only */
				vector<string> temp;
				string tempPreference;
				string instrPreference;

				splitString(strn, ',', temp);//added passing the Schedule object, allows pushing of instructor object
				tempPreference = temp.at(temp.size() - 1).substr(temp.at(temp.size() - 1).find_first_of("-") + 2); 
				temp.at(temp.size() - 1) = temp.at(temp.size() - 1).substr(0, temp.at(temp.size() - 1).find_first_of("-") - 1);
				if(tempPreference.find("None") != std::string::npos)
				{
					instrPreference = "None";
					instrPtr = testbuilder.BuildInstructor(temp.at(0),instrPreference,false);
				}
				else
				{
					instrPreference = "Has Preference";
					instrPtr = testbuilder.BuildInstructor(temp.at(0),instrPreference,true);
				}

				//creates instructor
				dept->instructors.push_back(instrPtr);
				//not sure what the following does
				for(int x = 1; x < temp.size(); x++)/* Start at 1 because the professor's name is temp.at(0) */
				{
					if(!dept->setCourseProfessor(temp.at(x),temp.at(0)))
						cout << "Unable to set professor for " << temp.at(x) << endl;
				}
			break;
		}
	}
}

//Read given room file name and add all classrooms to dept
void readRoomFile(char fName, Schedule *dept)
{
	ifstream iFile;
	iFile.open(fName);
	
	string tempStr[50];
	int i = 0;

	while (!iFile.eof())
	{
		getline(iFile, tempStr[i], ',');
		i++;
	}
	for (int j = 0; j < i; j+=2)
	{
		//building, room, time
		dept->AddClassroom(tempStr[j], tempStr[j+1], "");
	}
	
	iFile.close();
	return;
}

int main(void) 
{
	Schedule dept;
	
	//Adds rooms with bldg from file
	char fName[64];
	strcpy(fName, "CSRoomList.csv");
	readRoomFile(fName, &dept);
	
	parseInput(&dept);
	//dept.makeSchedule();
	//dept.toString();
	dept.printCourses();
	dept.printProfessor();
}
