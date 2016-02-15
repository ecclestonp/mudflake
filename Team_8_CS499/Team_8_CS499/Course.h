//Course structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#ifndef COURSE_H
#define COURSE_H

//Define structure for course
struct Course
{
	char courseNum[100];		//Name/num of course, ex: CS499
	bool hasPreference;		//1 if there is a prefence, 0 if not
	char preference[100];		//NULL if no preference, contains string of preference if there is one
};

#endif