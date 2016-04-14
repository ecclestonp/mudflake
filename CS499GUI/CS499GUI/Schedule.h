//Dept structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

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
	std::string deptName;
	vector<Course *> courses;
	vector<string> professors;
	vector<Classroom *> classrooms;
	vector<Instructor *> instructors;
	BuildObj addObject;
	int scheduleArray[100][4];
	string theTimes[10];

	Schedule();
	~Schedule();
	bool setCourseProfessor(string courseName, string professor);
	void makeSchedule();
	void AddInstructor(string iName, string preference, bool prefbool);
	void AddClassroom(string bldg, string room, unsigned int cTimeMW, unsigned int cTimeTT);
	void AddCourse(string courseNum, string preference, bool prefbool);
	bool setCoursePreference(string courseName, string pref);
	void SetScheduleInfo(unsigned int bitPos, int i, int j, int MWorTT, Instructor *instr);
	void ClearSchedule();
};
