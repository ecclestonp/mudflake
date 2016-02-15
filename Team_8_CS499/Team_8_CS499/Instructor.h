//Instructor structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

//Define structure for teachers
struct Instructor
{
	char instructorName[100];		//Name of instructor
	bool hasPreference;			//1 if there is a prefence, 0 if not
	char preference[100];			//NULL if no preference, contains string of preference if there is one
};

#endif