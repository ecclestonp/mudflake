//CPP file for BuildObj.h
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "BuildObj.h"
#include "Classroom.h"
#include "Course.h"
#include "Instructor.h"
#include <stdio.h>
#include <string>
using namespace std;

//Default constructor
BuildObj::BuildObj()
{
	//Do nothing
}

BuildObj::~BuildObj()
{
	//Do Nothing
}

//Creates and returns a new course pointer
Course * BuildObj::CreateCourse(string courseNum, bool hasPreference, string preference)
{
	Course *ptrCourse = new Course;
	ptrCourse->hasPreference = hasPreference;
	ptrCourse->courseNum = courseNum;
	ptrCourse->preference = preference;
	return ptrCourse;
}

//Creates and returns a new instructor pointer
Instructor * BuildObj::CreateInstructor(string instructorName, bool hasPreference, string preference)
{
	Instructor *ptrInstr = new Instructor;
	ptrInstr->instructorName = instructorName;
	ptrInstr->hasPreference = hasPreference;
	ptrInstr->preference = preference;
	return ptrInstr;
}

//Creates and returns a new classroom pointer
Classroom * BuildObj::CreateClassroom(string roomNum, string bldgNum, string classTime)
{
	Classroom *ptrRoom = new Classroom;
	ptrRoom->roomNum = roomNum;
	ptrRoom->bldgNum = bldgNum;
	ptrRoom->classTime = classTime;
	return ptrRoom;
}