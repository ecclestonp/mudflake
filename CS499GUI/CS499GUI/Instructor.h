//Instructor structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include <string>
#include <array>
using namespace std;

#pragma once
//Define class for teachers
class Instructor
{
	public:
		string instructorName;		//Name of instructor
		bool hasPreference;			//1 if there is a prefence, 0 if not
		string preference;			//NULL if no preference, contains std::string of preference if there is one
		array <string, 100> profCourse;
		int courseLinker[100];
};
