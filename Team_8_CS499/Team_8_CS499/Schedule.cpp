#include "Schedule.h"
#include <string>
#include <iostream>

using namespace std;

bool Schedule::setCourseProfessor(string courseName, string professor)
{
	for(int x = 0; x < Schedule::courses.size(); x++)
	{
		if (!courses.at(x).courseNum.compare(courseName))
		{
			courses.at(x).profName = professor;
			return true;
		}
	}
	return false;
}

//adds objects as needed, using Create function in BuildObj
//as of 2/28/2016 there is NO preference for testing purposes
bool Schedule::AddObj(string Identifier)
{
	//either need to use whole string to parse up or bits and pieces.
	//problem: either we parse as Paul put it (each course paired with a professor)
	//or parse it as the file says

	//variables matched to Creat function
	string a = "";
	string b = "";
	string c = "";
	bool d = false;
	int type = 1;

	//check for Dr. to find if it is instructor
	std::size_t found = Identifier.find("Dr.");

	if(found!=std::string::npos)
	{
		//do instructor object creation
		
	}
	else
	{
		//do course object creation
		
		
	}
	
	return false;
}

//this function looks over all current course objects and compares to professor's courses
//if a match is found, set the linker corresponding index to 1. index corresponds to course vector's index
bool Schedule::linkCourseProfessor(vector<Course> courses, vector<Instructor> professors)
{
	//need container to store reference between course and professor
	string courseName;
	int courseIndex;
	int professorIndex;
	int profCourse;

	//outer loop for courses
	for(courseIndex = 0; courseIndex < courses.size(); courseIndex++)//loops till at end of course vector
	{
		for(professorIndex = 0; professorIndex < professors.size(); professorIndex++)
		{
			for(profCourse = 0; profCourse <= sizeof(professors[professorIndex].profCourse); profCourse++)//loops till at end of prof's courses
			{
				//paul is my bff <3
				if(courses[courseIndex].courseNum == professors[professorIndex].profCourse[profCourse])//check if the two strings are equal
				{
					//if so, print out (for testing) and set the linker to 1 for existing
					cout << professors[professorIndex].profCourse << " teaches " << courses[courseIndex].courseNum << endl;
					professors[professorIndex].courseLinker[courseIndex] = 1;
					break;
				}
				else
				{
					cout << "Checking next course" << endl;
				}
			}
		}
	}
	return false;
}

void Schedule::makeSchedule()
{
	
}
