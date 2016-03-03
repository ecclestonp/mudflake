//Course structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include <string>

//Define structure for course
class Course
{
public:
	std::string courseNum;		//Name/num of course, ex: CS499
	std::string profName;		//professor name
	bool hasPreference;		//1 if there is a prefence, 0 if not
	std::string preference;		//NULL if no preference, contains string of preference if there is one

	Course();
	~Course();
	Course(std::string courseName);
	Course(std::string courseName, std::string profName);
};
