//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "BuildObj.h"
#include <vector>

//Define structure for dept
class Schedule
{
public:
	std::string deptName;
	vector<Course> courses;
	vector<string> professors;
	vector<Classroom> classrooms;

	bool setCourseProfessor(string courseName, string professor);
	bool linkCourseProfessor(vector<Course> courses, vector<Instructor> professors);
	bool AddObj(string Identifier);
	void makeSchedule();
};
