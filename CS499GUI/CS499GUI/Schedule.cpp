#include "Schedule.h"
#include <string>
#include <iostream>
//#include <initializer_list>

using namespace std;

Schedule::Schedule()
{
	//Nothing to do
}

Schedule::~Schedule()
{
	//Cleanup
	ClearSchedule();
}

//Deletes pointers and such and resets the whole thing
void Schedule::ClearSchedule()
{
	deptName = "";

	//Resets schedule array
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scheduleArray[i][j] = 999;
		}
	}

	//Cleans up pointers
	for (int i = 0; i < courses.size(); i++)
	{
		delete (courses[i]);
	}
	courses.clear();
	for (int i = 0; i < classrooms.size(); i++)
	{
		delete (classrooms[i]);
	}
	classrooms.clear();
	for (int i = 0; i < instructors.size(); i++)
	{
		delete (instructors[i]);
	}
	instructors.clear();

	return;
}

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
#define TRUE true

bool Schedule::setCoursePreference(string courseName, string pref)
{
	for(int x = 0; x < Schedule::courses.size(); x++)
	{
		if (!courses.at(x)->courseNum.compare(courseName))
		{
			courses.at(x)->preference = pref;
			courses.at(x)->hasPreference = TRUE;
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
					//cout << "Checking next course" << endl;
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
	//Set schedule array
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scheduleArray[i][j] = 999;
		}
	}
	
	for (int i = 1; i < this->instructors.size(); i++)
	{
		Instructor *instr = instructors[i];
		if (instr->hasPreference)/*Morning classes only*/
		{
			for (int tcourse = 0; tcourse < this->courses.size(); tcourse++)
			{
				unsigned int bitPos = 0x00000001;
				bool ttonly = true;
				bool mwonly = true;
				
				//TODO: shit breaks if course and instructor have preference
				if (courses[tcourse]->profName.compare(instr->instructorName))
					continue;
				if(!instr->preference.compare("Afternoon classes only"))
				{
					bitPos = 0x00001000;
				}
				else if (!instr->preference.compare("Evening classes only"))
				{
					bitPos = 0x01000000;
				}
				else if (!instr->preference.compare("Morning classes only"))
				{
					bitPos = 0x00000001;
				}
				else if (!instr->preference.compare("All Tues-Thurs classes"))
				{
					mwonly = false;
				}
				else // Assuming it's All Mon-Wed classes...
				{
					ttonly = false;
				}
				Course *_c = courses[tcourse];
				_c->alreadyScheduled = true;
				unsigned int origPos = bitPos;
				// preference = "room 342"
				//check for a classroom/time opening and assign it
				for (int j = 0; j <= this->classrooms.size(); j++)
				{
					int numShifted = 0;
					//Mon/Weds time checks
					bitPos = origPos;
					while (bitPos != 0x00000000)
					{
						//first try for a mon/weds time slot
						if ((this->classrooms[j]->classTimeMW & bitPos) == 0 && mwonly)
						{
							//Set to location in vector for course because time not yet used
							scheduleArray[tcourse][0] = j;		//room vec location
							scheduleArray[tcourse][1] = tcourse;		//course vec location
							scheduleArray[tcourse][2] = bitPos;	//time flag
							scheduleArray[tcourse][3] = 1;		//1 for mon/weds
							//update flag to show that time is now taken
							this->classrooms[j]->classTimeMW = this->classrooms[j]->classTimeMW | bitPos;
							bitPos = 0;
							j = classrooms.size()+1;
						}
						//Then check tues/thurs instead
						else if ((this->classrooms[j]->classTimeTT & bitPos) == 0 && ttonly)
						{
							//Set to location in vector for course because time not yet used
							scheduleArray[tcourse][0] = j;		//room vec location
							scheduleArray[tcourse][1] = tcourse;		//course vec location
							scheduleArray[tcourse][2] = bitPos;	//time flag
							scheduleArray[tcourse][3] = 2;		//2 for tues/thurs
							//update flag in classroom to show that time is now taken
							this->classrooms[j]->classTimeTT = this->classrooms[j]->classTimeTT | bitPos;
							bitPos = 0;
							j = classrooms.size()+1;
						}
						else
						{
							//No time slot so shift bitPos left 4 bits
							bitPos <<= 4;
							numShifted++;
							if(numShifted > 3 && mwonly && ttonly)
								bitPos = 0;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < this->courses.size(); i++)
	{
		Course *c = courses[i];
		//TODO: shit breaks if course and instructor have preference
		if (c->hasPreference)
		{
			unsigned int bitPos = 0x00000001;
			// preference = "room 342"
			//check for a classroom/time opening and assign it
			for (int j = 0; j <= this->classrooms.size(); j++)
			{
				if (classrooms[j]->roomNum.compare(c->preference.substr(5,3)))
					continue;
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
		// If has preference, should already be scheduled
		if(this->courses[i]->hasPreference || this->courses[i]->alreadyScheduled)
			continue;

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
