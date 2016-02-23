//Interface file for BuildObj.cpp
//Used to create all of the structure objects needed for a schedule
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "Instructor.h"
#include "Course.h"
#include "Classroom.h"
#include <string>
using namespace std;

#pragma once
template <class retType>
class BuildObj
{
	private:

	public:
		BuildObj();
		~BuildObj();
		
		//Now this uses templates to create any of the 3 object types with one function
		retType * Create(string a, string b, string c, bool d, int type);	
};
