//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "Classroom.h"
#include "Course.h"
#include <vector>

//Define structure for dept
class Department
{
public:
	std::string deptName;
	vector<Course> courses;
	vector<string> professors;
	vector<Classroom> classrooms;
	bool setCourseProfessor(string courseName, string professor);
};
