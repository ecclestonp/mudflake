//CPP file for BuildObj.h
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "BuildObj.h"
#include <string>
#include <vector>
using namespace std;

/*
Example usage:
//You only need to create one instance of the builder in the program
BuildObj testbuilder;

//Only need to create one of each of these, then pass the memory address into your vector
//reuse the pointer each time you create the next object
Course *coursePtr;
Classroom *classPtr;
Instructor *instrPtr;

coursePtr = testbuilder.BuildCourse("CS499","Requires room 324", true);
classPtr = testbuilder.BuildClassroom("324","Tech Hall","5:30-6:50");
instrPtr = testbuilder.BuildInstructor("Dr. Coleman","",false);

//delete each of these when done
*/


//Create and return instructor
//pass arguments instructor name string, preference string, and preference bool if there is a pref
Instructor * BuildObj::BuildInstructor(string instrName, string preference, bool prefBool, vector<string> linkCourses)
{
	Instructor *instrPtr = new Instructor;
	instrPtr->instructorName = instrName;
	instrPtr->hasPreference = prefBool;
	instrPtr->preference = preference;
	for(int i = 1; i <= linkCourses.size(); i++)
	{
		instrPtr->profCourse[i] = linkCourses.at(i);
	}
	return instrPtr;
}

//Create and return course
//pass arguments course number string, preference string, and preference bool if there is a pref
Course * BuildObj::BuildCourse(string courseNum, string preference, bool prefBool)
{
	Course *coursePtr = new Course;
	coursePtr->hasPreference = prefBool;
	coursePtr->courseNum = courseNum;
	coursePtr->preference = preference;
	return coursePtr;
}

//Create and return classroom
//pass arguments room number string, building string, and class time string
Classroom * BuildObj::BuildClassroom(string roomNum, string bldg, unsigned int classTimeMW, unsigned int classTimeTT)
{
	Classroom *roomPtr = new Classroom;
	roomPtr->roomNum = roomNum;			
	roomPtr->bldgNum = bldg;				
	roomPtr->classTimeMW = classTimeMW;
	roomPtr->classTimeTT = classTimeTT;
	return roomPtr;
}