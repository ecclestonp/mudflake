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

//Links course to professor
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

//Sets preference for courses
bool Schedule::setCoursePreference(string courseName, string pref)
{
	for(int x = 0; x < Schedule::courses.size(); x++)
	{
		if (!courses.at(x)->courseNum.compare(courseName))
		{
			courses.at(x)->preference = pref;
			courses.at(x)->hasPreference = true;
			return true;
		}
	}
	return false;
}

//Algorithm
//Still needs to account for course and instructor that teaches the course both having a preference
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
	//Zero out instructor times
	for (int i = 1; i < this->instructors.size(); i++)
	{
		instructors[i]->classTimeMW = instructors[i]->classTimeTT = 0;
	}
	
	//Handle instructors with a preference
	for (int i = 0; i < this->instructors.size(); i++)
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
				for (int j = 0; j < this->classrooms.size(); j++)
				{
					int numShifted = 0;
					//Mon/Weds time checks
					bitPos = origPos;
					while (bitPos != 0x00000000)
					{
						//first try for a mon/weds time slot
						if (((this->classrooms[j]->classTimeMW & bitPos) == 0) && mwonly && ((instr->classTimeMW & bitPos) == 0))
						{
							SetScheduleInfo(bitPos, tcourse, j, 1, instr);
							bitPos = 0;
							j = classrooms.size();
						}
						//Then check tues/thurs instead
						else if (((this->classrooms[j]->classTimeTT & bitPos) == 0) && ttonly && ((instr->classTimeTT & bitPos) == 0))
						{
							SetScheduleInfo(bitPos, tcourse, j, 2, instr);
							bitPos = 0;
							j = classrooms.size();
						}
						else
						{
							//No time slot so shift bitPos left 4 bits
							bitPos <<= 4;
							numShifted++;
							if(numShifted > 2 && mwonly && ttonly)
								bitPos = 0;
						}
					}
				}
			}
		}
	}

	//Handle courses with a preference
	for (int k = 0; k < this->instructors.size(); k++)
	{
		Instructor *instr = instructors[k];
		for (int i = 0; i < this->courses.size(); i++)
		{
			Course *c = courses[i];
			//TODO: shit breaks if course and instructor have preference
			if (c->alreadyScheduled)
				continue;

			if (c->profName.compare(instr->instructorName))
				continue;

			if (c->hasPreference)
			{
				unsigned int bitPos = 0x00000001;
				c->alreadyScheduled = true;
				// preference = "room 342"
				//check for a classroom/time opening and assign it
				for (int j = 0; j < this->classrooms.size(); j++)
				{
					//This causes an error sometimes, not always same text.  Needed to use .find instead
					//if (classrooms[j]->roomNum.compare(c->preference.substr(5,3)))
					//	continue;

					if (c->preference.find(classrooms[j]->roomNum) == std::string::npos)
						continue;

					bitPos = 0x00000001;
					//Mon/Weds time checks
					while (bitPos != 0x00000000)
					{
						//first try for a mon/weds time slot
						if (((this->classrooms[j]->classTimeMW & bitPos) == 0) && ((instr->classTimeMW & bitPos) == 0))
						{
							SetScheduleInfo(bitPos, i, j, 1, instr);
							bitPos = 0;
							j = classrooms.size();
						}
						//Then check tues/thurs instead
						else if (((this->classrooms[j]->classTimeTT & bitPos) == 0) && ((instr->classTimeTT & bitPos) == 0))
						{
							SetScheduleInfo(bitPos, i, j, 2, instr);
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
	}

	unsigned int bitPos = 0x00000001;

	//For all other unschedule things
	for (int k = 0; k < this->instructors.size(); k++)
	{
		Instructor *instr = instructors[k];
		for (int i = 0; i < this->courses.size(); i++)
		{
			// If has preference, should already be scheduled
			if(this->courses[i]->hasPreference || this->courses[i]->alreadyScheduled)
				continue;

			if (courses[i]->profName.compare(instr->instructorName))
				continue;

			//check for a classroom/time opening and assign it
			for (int j = 0; j < this->classrooms.size(); j++)
			{
				bitPos = 0x00000001;
				//Mon/Weds time checks
				while (bitPos != 0x00000000)
				{
					//first try for a mon/weds time slot
					if (((this->classrooms[j]->classTimeMW & bitPos) == 0) && ((instr->classTimeMW & bitPos) == 0))
					{
						SetScheduleInfo(bitPos, i, j, 1, instr);
						bitPos = 0;
						j = classrooms.size();
					}
					//Then check tues/thurs instead
					else if (((this->classrooms[j]->classTimeTT & bitPos) == 0) && ((instr->classTimeTT & bitPos) == 0))
					{
						SetScheduleInfo(bitPos, i, j, 2, instr);
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
	return;
}

//Created this to remove the repeats of it in above algorithm
void Schedule::SetScheduleInfo(unsigned int bitPos, int i, int j, int MWorTT, Instructor *instr)
{
	if (MWorTT == 1)
	{
		//Set to location in vector for course because time not yet used
		scheduleArray[i][0] = j;		//room vec location
		scheduleArray[i][1] = i;		//course vec location
		scheduleArray[i][2] = bitPos;	//time flag
		scheduleArray[i][3] = 1;		//1 for mon/weds
		//update flag to show that time is now taken
		this->classrooms[j]->classTimeMW = this->classrooms[j]->classTimeMW | bitPos;
		instr->classTimeMW = instr->classTimeMW | bitPos;
	}
	else if (MWorTT == 2)
	{
		//Set to location in vector for course because time not yet used
		scheduleArray[i][0] = j;		//room vec location
		scheduleArray[i][1] = i;		//course vec location
		scheduleArray[i][2] = bitPos;	//time flag
		scheduleArray[i][3] = 2;		//2 for tues/thurs
		//update flag in classroom to show that time is now taken
		this->classrooms[j]->classTimeTT = this->classrooms[j]->classTimeTT | bitPos;
		instr->classTimeTT = instr->classTimeTT | bitPos;
	}
	return;
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
