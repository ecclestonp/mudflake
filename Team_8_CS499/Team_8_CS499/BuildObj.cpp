//CPP file for BuildObj.h
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "BuildObj.h"
#include "Classroom.h"
#include "Course.h"
#include "Department.h"
#include "Instructor.h"
#include <stdio.h>
#include <cstring>
using namespace std;

//Default constructor
BuildObj::BuildObj()
{
	//Do nothing
}

BuildObj::~BuildObj()
{
	//Do Nothing
}

//Creates and returns a new department pointer
Department * BuildObj::CreateDeptObj(char *deptName)
{
	Department *ptrDept = new Department;
	strcpy(ptrDept->deptName, deptName);
	return ptrDept;
}

//Creates and returns a new course pointer
Course * BuildObj::CreateCourseObj(char *courseNum, bool hasPreference, char *preference)
{
	Course *ptrCourse = new Course;
	ptrCourse->hasPreference = hasPreference;
	strcpy(ptrCourse->courseNum, courseNum);
	strcpy(ptrCourse->preference, preference);
	return ptrCourse;
}

//Creates and returns a new instructor pointer
Instructor * BuildObj::CreateInstructorObj(char *instructorName, bool hasPreference, char *preference)
{
	Instructor *ptrInstr = new Instructor;
	strcpy(ptrInstr->instructorName, instructorName);
	ptrInstr->hasPreference = hasPreference;
	strcpy(ptrInstr->preference, preference);
	return ptrInstr;
}

//Creates and returns a new classroom pointer
Classroom * BuildObj::CreateClassroomObj(char *roomNum, char *bldgNum, char *classTime)
{
	Classroom *ptrRoom = new Classroom;
	strcpy(ptrRoom->roomNum, roomNum);
	strcpy(ptrRoom->bldgNum, bldgNum);
	strcpy(ptrRoom->classTime, classTime);
	return ptrRoom;
}