//Interface file for BuildObj.cpp
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include <iostream>
#include "Department.h"
#include "Instructor.h"
#include "Course.h"
#include "Classroom.h"
using namespace std;

#ifndef BUILDOBJ_H
#define BUILDOBJ_H

class BuildObj
{
	private:

	public:
		BuildObj();
		~BuildObj();

		Department * CreateDeptObj(char *deptName);														//Takes dept name in, returns ptr to new dept
		Course * CreateCourseObj(char *courseNum, bool hasPreference, char *preference);					//Takes in course num/preference (if it has one), returns ptr to new course
		Instructor * CreateInstructorObj(char *instructorName, bool hasPreference, char *preference);		//Takes in instructor name/preference, returns ptr to new instructor
		Classroom * CreateClassroomObj(char *roomNum, char *bldgNum, char *classTime);						//Takes in roomnum, bldgnum and class time and returns ptr to new class
};

#endif