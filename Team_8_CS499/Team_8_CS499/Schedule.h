//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "Classroom.h"
#include "Course.h"
#include "BuildObj.h"
#include "Instructor.h"
#include "WriteFile.h"
#include <vector>

//Define structure for dept
class Schedule
{
public:
	std::string deptName;
	//vector<Classroom> classrooms;
	vector<Course> courses;
	vector<std::string> professors;
	bool setCourseProfessor(std::string courseName, std::string professor);
};
