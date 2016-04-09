//Load and parse the data

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Schedule.h"
#include "Course.h"
#include "Instructor.h"
#include "LoadParse.h"

using namespace std;

//use this to create professor objects
void LoadParse::splitString(string line, char delim, vector<string> &vec)
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
void LoadParse::splitString(string line, char delim, Schedule *dept, int state)
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

void LoadParse::parseInput(char *fName, Schedule *dept)
{
	vector<Instructor> prof;
	char state = 0;
	ifstream input;

	BuildObj testbuilder;
	Instructor *instrPtr;
	/* Only supports a max of 15 individual course prefs. Hardcoded */
	string courseName[15];
	string coursePref[15];
	size_t courseIdx = 0;

	input.open(fName);
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
				//currently only parses string for preference string, does not put in course
				if(strn.find("must") != std::string::npos)//had issues with "Classroom preferences" string, used to make sure error handled
				{
					courseName[courseIdx] = strn.substr(1, strn.find(" must")-1);
					coursePref[courseIdx++] = strn.substr(43, strn.find("/n"));
				}
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
					instrPreference =  tempPreference.substr(12, tempPreference.find("\n"));//prefernce: starts at index 12. goes till new line
					instrPtr = testbuilder.BuildInstructor(temp.at(0),instrPreference,true);
					
				}

				//creates instructor
				dept->instructors.push_back(instrPtr);
				//not sure what the following does
				for(int x = 1; x < temp.size(); x++)/* Start at 1 because the professor's name is temp.at(0) */
				{
					for(int y = 0; y < courseIdx; y++)
					{
						if(!temp.at(x).compare(courseName[y]))
						{
							/* TODO: we found a match for the preference at the top of the file. */
						}
					}
					if(!dept->setCourseProfessor(temp.at(x),temp.at(0)))
					{
						//cout << "Unable to set professor for " << temp.at(x) << endl;
					}
				}
			break;
		}
	}
}

//Read given room file name and add all classrooms to dept
void LoadParse::readRoomFile(char *fName, Schedule *dept)
{
	ifstream iFile;
	iFile.open(fName);
	
	string tempStr[50];
	int i = 0;

	while (!iFile.eof())
	{
		//See if i is even
		//If it is delim on comma
		//else delim on newline char
		if (i%2 == 0)
		{
			getline(iFile, tempStr[i], ',');
		}
		else 
		{
			getline(iFile, tempStr[i]);
		}
		i++;
	}
	for (int j = 0; j < i; j+=2)
	{
		//Add the strings from tempStr into the classrooms vector
		//building, room, timemw, timett
		dept->AddClassroom(tempStr[j], tempStr[j+1], 0, 0);
	}

	iFile.close();
	return;
}