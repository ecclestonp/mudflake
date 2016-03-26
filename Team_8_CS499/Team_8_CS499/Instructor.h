//Instructor structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include <string>
#include <vector>
using namespace std;

class Course;

//Define class for instructors
class Instructor
{
	public:
		string instructorName;		//Name of instructor
		string preference;
		vector<Course *> courses;     // Vector of the courses to be taught by this professor
		int courseLinker[100];
		bool coursesValid();
};
