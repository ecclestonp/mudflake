//Classroom structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#pragma once
#include <string>
using namespace std;

//Define structure for room, create a new one for each time required
class Classroom
{
public:
	std::string roomNum;		//String for room number
	std::string bldgNum;		//String of the building name/num that the room is located in
	std::string classTime;	    //The time of the class for this instance of the room (new classroom struct needed for each time represented)
};
