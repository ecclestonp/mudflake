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
