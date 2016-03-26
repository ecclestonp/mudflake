#include <string>
#include <iostream>

#include "Course.h"
#include "Instructor.h"

using namespace std;

Course::Course()
{
	//do nothing
}

Course::~Course()
{
	//do nothing
}

Course::Course(string courseName)
{
	courseNum = courseName;
	courseTime = MW8;
}

Course::Course(std::string courseName, Instructor *instr)
{
	courseNum = courseName;
	instructor = instr;
	courseTime = MW8;
}

std::string Course::getTime()
{
	switch (courseTime)
	{
		case Course::MW8:
			return "MW8";
		case Course::MW9:
			return "MW9";
		case Course::MW11:
			return "MW11";
		case Course::MW12:
			return "MW12";

		//... With my current algorithm, it never selects beyond there. I plan on changing this ghetto code anyways.
		default:
			return "UNASSIGNED";
	}
}

void Course::printCourses()
{
	cout << courseNum << endl;
}
