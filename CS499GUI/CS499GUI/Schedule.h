//CS499 Senior Project - Course Scheduling system
//Dept/schedule class
//Purpose: Holds all of the schedule objects and automatically creates the schedule
//Written by: Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include "Classroom.h"
#include "Course.h"
#include "Instructor.h"
#include "BuildObj.h"
#include <string>
#include <vector>

using namespace std;

//Define structure for dept
class Schedule
{
public:
	//Vectors and other data items
	std::string deptName;
	vector<Course *> courses;
	vector<string> professors;
	vector<Classroom *> classrooms;
	vector<Instructor *> instructors;
	BuildObj addObject;
	int scheduleArray[100][4];
	string theTimes[10];

	//Functions
	Schedule();
	~Schedule();
	bool setCourseProfessor(string courseName, string professor);								//Links course to professor
	void makeSchedule();																		//builds a schedule
	void AddInstructor(string iName, string preference, bool prefbool);							//adds an instructor
	void AddClassroom(string bldg, string room, unsigned int cTimeMW, unsigned int cTimeTT);	//adds a classroom
	void AddCourse(string courseNum, string preference, bool prefbool);							//adds a course
	bool setCoursePreference(string courseName, string pref);									//sets course preference
	void SetScheduleInfo(unsigned int bitPos, int i, int j, int MWorTT, Instructor *instr);		//sets schedule rows into schedule array
	void ClearSchedule();																		//cleanup
	void ClearRooms();																			//cleanup
};
