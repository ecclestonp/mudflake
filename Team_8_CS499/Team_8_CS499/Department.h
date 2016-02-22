//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "Classroom.h"
#include "Course.h"

//Define structure for dept
class Department
{
public:
	string deptName;
	vector<string> courses;/* should be Courses */
	vector<string> professors;
	vector<Classroom> classrooms;
};