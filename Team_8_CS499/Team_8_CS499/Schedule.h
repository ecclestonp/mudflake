//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "Classroom.h"
#include "Course.h"
#include "Instructor.h"
#include "WriteFile.h"
#include "BuildObj.h"
#include <vector>

//Define structure for dept
class Schedule
{
public:
	std::string deptName;
	vector<Course *> courses;
	vector<string> professors;
	vector<Classroom *> classrooms;
	vector<Instructor *> instructors;
	BuildObj addObject;

	bool setCourseProfessor(string courseName, string professor);
	bool linkCourseProfessor(vector<Course> courses, vector<Instructor> professors);
	bool AddObj(string Identifier);
	void toString();
	void makeSchedule();
	void printProfessor();
	void printCourses();
	void AddInstructor(string iName, string preference, bool prefbool);
	void AddClassroom(string bldg, string room, string cTime);
	void AddCourse(string courseNum, string preference, bool prefbool);
};
