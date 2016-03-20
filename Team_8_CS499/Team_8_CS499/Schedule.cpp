#include "Schedule.h"
#include <string>
#include <iostream>
//#include <initializer_list>

using namespace std;

bool Schedule::setCourseProfessor(string courseName, string professor)
{
	for(int x = 0; x < Schedule::courses.size(); x++)
	{
		if (!courses.at(x)->courseNum.compare(courseName))
		{
			courses.at(x)->profName = professor;
			return true;
		}
	}
	return false;
}

//this function looks over all current course objects and compares to professor's courses
//if a match is found, set the linker corresponding index to 1. index corresponds to course vector's index
bool Schedule::linkCourseProfessor(vector<Course> courses, vector<Instructor> professors)
{
	//need container to store reference between course and professor
	string courseName;
	int courseIndex;
	int professorIndex;
	int profCourse;

	//outer loop for courses
	for(courseIndex = 0; courseIndex < courses.size(); courseIndex++)//loops till at end of course vector
	{
		for(professorIndex = 0; professorIndex < professors.size(); professorIndex++)
		{
			for(profCourse = 0; profCourse <= sizeof(professors[professorIndex].profCourse); profCourse++)//loops till at end of prof's courses
			{
				//paul is my bff <3
				if(courses[courseIndex].courseNum == professors[professorIndex].profCourse[profCourse])//check if the two strings are equal
				{
					//if so, print out (for testing) and set the linker to 1 for existing
					cout << professors[professorIndex].profCourse << " teaches " << courses[courseIndex].courseNum << endl;
					professors[professorIndex].courseLinker[courseIndex] = 1;
					break;
				}
				else
				{
					cout << "Checking next course" << endl;
				}
			}
		}
	}
	return false;
}

// New tested working algorithm
// Does not include preferences yet
void Schedule::makeSchedule()
{
	/*Course::TIME possibleTimes[] = {Course::MW8, Course::MW9, Course::MW11, Course::MW12, Course::MW2, Course::MW3, Course::MW5, Course::TR8, Course::TR9, Course::TR11, Course::TR12, Course::TR2, Course::TR3, Course::TR5};
	for (Course *c : courses)
	{
		for (Course::TIME possibleTime : possibleTimes)
		{
			bool badTime = false;
			for (Course *t : courses)
			{
				if (!c->profName.compare(t->profName) && possibleTime == t->courseTime)
				{
					badTime = true;
					break;
				}
			}

			if(!badTime)
			{
				c->courseTime = possibleTime;
				break;
			}
		}
			
	}*/

	//Set schedule array
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scheduleArray[i][j] = 999;
		}
	}

	/*
	Time bit positions 1 hour 20 min increments (hard coded correspondence for now):
	0x00000001 = 8 - 9:20
	0x00000010 = 9:20-10:40
	0x00000100 = 10:40-12
	0x00001000 = 12-1:20
	0x00010000 = 1:20-2:40
	0x00100000 = 2:40-4
	0x01000000 = 4-5:20
	0x10000000 = 5:20-6:40
	*/
	unsigned int bitPos = 0x00000001;
	//For each course
	for (int i = 0; i < this->courses.size(); i++)
	{
		//check for a classroom/time opening and assign it
		for (int j = 0; j <= this->classrooms.size(); j++)
		{
			bitPos = 0x00000001;
			//Mon/Weds time checks
			while (bitPos != 0x00000000)
			{
				//first try for a mon/weds time slot
				if ((this->classrooms[j]->classTimeMW & bitPos) == 0)
				{
					//Set to location in vector for course because time not yet used
					scheduleArray[i][0] = j;		//room vec location
					scheduleArray[i][1] = i;		//course vec location
					scheduleArray[i][2] = bitPos;	//time flag
					scheduleArray[i][3] = 1;		//1 for mon/weds
					//update flag to show that time is now taken
					this->classrooms[j]->classTimeMW = this->classrooms[j]->classTimeMW | bitPos;
					bitPos = 0;
					j = classrooms.size();
				}
				//Then check tues/thurs instead
				else if ((this->classrooms[j]->classTimeTT & bitPos) == 0)
				{
					//Set to location in vector for course because time not yet used
					scheduleArray[i][0] = j;		//room vec location
					scheduleArray[i][1] = i;		//course vec location
					scheduleArray[i][2] = bitPos;	//time flag
					scheduleArray[i][3] = 2;		//2 for tues/thurs
					//update flag in classroom to show that time is now taken
					this->classrooms[j]->classTimeTT = this->classrooms[j]->classTimeTT | bitPos;
					bitPos = 0;
					j = classrooms.size();
				}
				else
				{
					//No time slot so shift bitPos left 4 bits
					bitPos <<= 4;
				}
			}
		}
	}

	//Test
	cout << "Course:	Room:	Day/Time:" << endl;
	//Test print the schedule to see if it makes sense
	for (int i = 0; scheduleArray[i][0] != 999; i++)
	{
		cout << courses[scheduleArray[i][1]]->courseNum << "	" << classrooms[scheduleArray[i][0]]->roomNum << "	";
			
		//check to see which time it is assigned and print it

		//mon/weds
		if (scheduleArray[i][2] == 0x00000001 && scheduleArray[i][3] == 1)
		{
			cout << "MW 8:00-9:20" << endl;
		}
		else if (scheduleArray[i][2] == 0x00000010  && scheduleArray[i][3] == 1)
		{
			cout << "MW 9:20-10:40" << endl;
		}
		else if (scheduleArray[i][2] == 0x00000100  && scheduleArray[i][3] == 1)
		{
			cout << "MW 10:40-12:00" << endl;
		}
		else if (scheduleArray[i][2] == 0x00001000  && scheduleArray[i][3] == 1)
		{
			cout << "MW 12:00-1:20" << endl;
		}
		else if (scheduleArray[i][2] == 0x00010000  && scheduleArray[i][3] == 1)
		{
			cout << "MW 1:20-2:40" << endl;
		}
		else if (scheduleArray[i][2] == 0x00100000  && scheduleArray[i][3] == 1)
		{
			cout << "MW 2:40-4:00" << endl;
		}
		else if (scheduleArray[i][2] == 0x01000000  && scheduleArray[i][3] == 1)
		{
			cout << "MW 4:00-5:20" << endl;
		}
		else if (scheduleArray[i][2] == 0x10000000  && scheduleArray[i][3] == 1)
		{
			cout << "MW 5:20-6:40" << endl;
		}

		//tues/thurs
		if (scheduleArray[i][2] == 0x00000001 && scheduleArray[i][3] == 2)
		{
			cout << "TT 8:00-9:20" << endl;
		}
		else if (scheduleArray[i][2] == 0x00000010  && scheduleArray[i][3] == 2)
		{
			cout << "TT 9:20-10:40" << endl;
		}
		else if (scheduleArray[i][2] == 0x00000100  && scheduleArray[i][3] == 2)
		{
			cout << "TT 10:40-12:00" << endl;
		}
		else if (scheduleArray[i][2] == 0x00001000  && scheduleArray[i][3] == 2)
		{
			cout << "TT 12:00-1:20" << endl;
		}
		else if (scheduleArray[i][2] == 0x00010000  && scheduleArray[i][3] == 2)
		{
			cout << "TT 1:20-2:40" << endl;
		}
		else if (scheduleArray[i][2] == 0x00100000  && scheduleArray[i][3] == 2)
		{
			cout << "TT 2:40-4:00" << endl;
		}
		else if (scheduleArray[i][2] == 0x01000000  && scheduleArray[i][3] == 2)
		{
			cout << "TT 4:00-5:20" << endl;
		}
		else if (scheduleArray[i][2] == 0x10000000  && scheduleArray[i][3] == 2)
		{
			cout << "TT 5:20-6:40" << endl;
		}
	}
	return;
}

void Schedule::toString()
{
	/*cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+             Schedule dump              +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+ " << courses.size() << " courses and " << professors.size() << " professors loaded." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	for (Course *c : courses)
	{
		cout << "------  " << c->courseNum << "  ------" << endl;
		cout << "Taught in room XXX" << endl;
		cout << "by " << c->profName << ", at " << c->getTime() << endl;
		cout << "----------------------" << endl;
	}
*/
}

void Schedule::printCourses()
{
	//for(Course *c : courses)
	//{
	//	//demonstrates all the following have been set
	//	cout << c->courseNum << endl;
	//	cout << c->preference << endl;
	//	cout << c->profName << "\n" << endl;
	//}
	
}

void Schedule::printProfessor()
{
	/*for(Instructor *i: instructors)
	{
		cout << i->instructorName << endl;
		cout << i->preference << "\n" << endl;
	}*/
}

//Used for adding instructors via GUI
void Schedule::AddInstructor(string iName, string preference, bool prefbool)
{
	instructors.push_back(addObject.BuildInstructor(iName, preference, prefbool));
	return;
}

//used for adding rooms via GUI
void Schedule::AddClassroom(string bldg, string room, unsigned int cTimeMW, unsigned int cTimeTT)
{
	classrooms.push_back(addObject.BuildClassroom(room, bldg, cTimeMW, cTimeTT));
	return;
}

//used for adding courses via GUI
void Schedule::AddCourse(string cName, string preference, bool prefbool)
{
	courses.push_back(addObject.BuildCourse(cName, preference, prefbool));
	return;
}
