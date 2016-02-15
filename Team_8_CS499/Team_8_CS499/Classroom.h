//Classroom structure
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#ifndef CLASSROOM_H
#define CLASSROOM_H

//Define structure for room, create a new one for each time required
struct Classroom
{
	char roomNum[100];		//String for room number
	char bldgNum[100];		//String of the building name/num that the room is located in
	char classTime[100];	//The time of the class for this instance of the room (new classroom struct needed for each time represented)
};

#endif