//Interface file for BuildObj.cpp
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "Classroom.h"
#include "Course.h"
#include "Instructor.h"
#include <string>
using namespace std;

#pragma once


class BuildObj
{
	public:
		//Functions to create the objects
		Instructor * BuildInstructor(string instrName, string preference, bool prefBool);
		Course * BuildCourse(string courseNum, string preference, bool prefBool);
		Classroom * BuildClassroom(string roomNum, string bldg, unsigned int classTimeMW, unsigned int classTimeTT);
};
