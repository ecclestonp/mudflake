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

//adds objects as needed, using Create function in BuildObj
//as of 2/28/2016 there is NO preference for testing purposes
bool Schedule::AddObj(string Identifier)
{
	//either need to use whole string to parse up or bits and pieces.
	//problem: either we parse as Paul put it (each course paired with a professor)
	//or parse it as the file says

	//variables matched to Creat function
	string a = "";
	string b = "";
	string c = "";
	bool d = false;
	int type = 1;

	//check for Dr. to find if it is instructor
	std::size_t found = Identifier.find("Dr.");

	if(found!=std::string::npos)
	{
		//do instructor object creation
		
	}
	else
	{
		//do course object creation
		
		
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

// Super shitty brute force algo for making a schedule
// 11/10 - IGN
void Schedule::makeSchedule()
{
	Course::TIME possibleTimes[] = {Course::MW8, Course::MW9, Course::MW11, Course::MW12, Course::MW2, Course::MW3, Course::MW5, Course::TR8, Course::TR9, Course::TR11, Course::TR12, Course::TR2, Course::TR3, Course::TR5};
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
			
	}
}

void Schedule::toString()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
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

}

void Schedule::printCourses()
{
	for(Course *c : courses)
	{
		//demonstrates all the following have been set
		cout << c->courseNum << endl;
		cout << c->preference << endl;
		cout << c->profName << "\n" << endl;
	}
	
}

void Schedule::printProfessor()
{
	for(Instructor *i: instructors)
	{
		cout << i->instructorName << endl;
		cout << i->preference << "\n" << endl;
	}
}

//Used for adding instructors via GUI
void Schedule::AddInstructor(string iName, string preference, bool prefbool)
{
	instructors.push_back(addObject.BuildInstructor(iName, preference, prefbool));
	return;
}

//used for adding rooms via GUI
void Schedule::AddClassroom(string bldg, string room, string cTime)
{
	classrooms.push_back(addObject.BuildClassroom(room, bldg, cTime));
	return;
}

//used for adding courses via GUI
void Schedule::AddCourse(string cName, string preference, bool prefbool)
{
	courses.push_back(addObject.BuildCourse(cName, preference, prefbool));
	return;
}
