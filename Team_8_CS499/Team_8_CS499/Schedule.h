//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "Classroom.h"
#include "Instructor.h"
#include "Course.h"
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
	vector<Classroom> classrooms;
	vector<Instructor *> instructors;

	bool contingent(vector<Course *> courses);
	bool setCourseProfessor(string courseName, Instructor *professor);
	bool setCourseProfessor(string courseName, string professor);
	bool linkCourseProfessor(vector<Course> courses, vector<Instructor> professors);
	bool AddObj(string Identifier);
	void toString();
	Course::TIME incTime(Course::TIME prevTime);
	void delegate(vector<Course *> courses);
	int fitness(vector<Course *> courses, vector<Instructor *> instructors);
	bool isValid(vector<Course *> courses, vector<Instructor *> instructors);
	bool nextSched(vector<Course *> courses, vector<Instructor *> instructors);
	void makeSchedule();
	void printProfessor();
	void printCourses();
};
