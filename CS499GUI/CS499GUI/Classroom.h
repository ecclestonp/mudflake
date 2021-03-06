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
	string roomNum;			//String for room number
	string bldgNum;			//String of the building name/num that the room is located in
	unsigned int classTimeMW;		//mon/weds bit flag times
	unsigned int classTimeTT;		//tues/thursday bit flag times
};
