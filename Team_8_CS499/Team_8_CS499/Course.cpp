#include "Course.h"

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
}

Course::Course(std::string courseName, std::string profName)
{
	courseNum = courseName;
	Course::profName = profName;
}
