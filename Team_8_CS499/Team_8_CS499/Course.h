//Course structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once

//Define structure for course
class Course
{
public:
	string courseNum;		//Name/num of course, ex: CS499
	bool hasPreference;		//1 if there is a prefence, 0 if not
	string preference;		//NULL if no preference, contains string of preference if there is one
};