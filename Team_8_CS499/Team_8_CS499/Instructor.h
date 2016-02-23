//Instructor structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once

//Define class for teachers
class Instructor
{
	public:
		string instructorName;		//Name of instructor
		bool hasPreference;			//1 if there is a prefence, 0 if not
		string preference;			//NULL if no preference, contains string of preference if there is one
};
