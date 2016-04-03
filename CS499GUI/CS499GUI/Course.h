//Course structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include <string>

//Define structure for course
class Course
{
public:
	enum TIME { UNASSIGNED, MW8, MW9, MW11, MW12, MW2, MW3, MW5, TR8, TR9, TR11, TR12, TR2, TR3, TR5 };
	std::string courseNum;		//Name/num of course, ex: CS499
	std::string profName;		//professor name
	bool hasPreference;		//1 if there is a prefence, 0 if not
	std::string preference;		//NULL if no preference, contains string of preference if there is one
	TIME courseTime; /* see TIME enum in schedule.h */

	Course();
	~Course();
	Course(std::string courseName);
	Course(std::string courseName, std::string profName);
	std::string getTime();
	void printCourses();
};
