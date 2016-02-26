//CPP file for BuildObj.h
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "BuildObj.h"
#include "Classroom.h"
#include "Course.h"
#include "Instructor.h"
#include <string>
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

//This is now reworked to use a template

//To create an object, make an instance of the BuildObj class
//Then ask it to create the object you need using the create function as in the below example and it will get a pointer:
//Example:
//BuildObj testbuilder;
//Course *testcourse;
//testcourse = testbuilder.Create<Course>("CS499", "Requires room 324", "", true, 1);
//
//For the last argument include int 1, 2 or 3 for which item you need built

template <class retType>
//Takes up to 3 strings, a boolean and an integer for the type of object
//Use the strings you need for the object you are building based on the below implementation
retType * BuildObj::Create(string a, string b, string c, bool d, int type)
{
	retType *tempPtr = new retType;				//create pointer of specified type
	
	switch(type)
	{
		case 1:						//Set type to 1 to get a course object
			tempPtr->hasPreference = d;		//input boolean d
			tempPtr->courseNum = a;			//input string a
			tempPtr->preference = b;		//input string b
			return coursePtr;
			break;
		case 2:						//Set type to 2 to get an instructor object
			tempPtr->instructorName = a;		//input string a
			tempPtr->hasPreference = d;		//input boolean d
			tempPtr->preference = b;		//input string b
			break;
		case 3:						//Set type to 3 to get a classroom object
			tempPtr->roomNum = a;			//input string a
			tempPtr->bldgNum = b;			//input string b
			tempPtr->classTime = c;			//input string c
			break;
		default:
			return NULL;				//return NULL if invalid type
	}
	return tempPtr;
}
