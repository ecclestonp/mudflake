//Interface file for BuildObj.cpp
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include <iostream>
#include "Instructor.h"
#include "Course.h"
#include "Classroom.h"
#include <string>
using namespace std;

#ifndef BUILDOBJ_H
#define BUILDOBJ_H

class BuildObj
{
	private:

	public:
		BuildObj();
		~BuildObj();

		Course * CreateCourse(string courseNum, bool hasPreference, string preference);					//Takes in course num/preference (if it has one), returns ptr to new course
		Instructor * CreateInstructor(string instructorName, bool hasPreference, string preference);		//Takes in instructor name/preference, returns ptr to new instructor
		Classroom * CreateClassroom(string roomNum, string bldgNum, string classTime);					//Takes in roomnum, bldgnum and class time and returns ptr to new class
};

#endif