#include "Schedule.h"
#include <string>
#include <iostream>
//#include <initializer_list>

#define NUM_CLASSROOMS 6
#define NUM_COURSES_PER_PROF 3

using namespace std;

bool Schedule::setCourseProfessor(string courseName, Instructor *professor)
{
	for(int x = 0; x < Schedule::courses.size(); x++)
	{
		if (!courses.at(x)->courseNum.compare(courseName))
		{
			courses.at(x)->instructor = professor;
			courses.at(x)->courseTime = Course::UNASSIGNED;
			professor->courses.push_back(courses.at(x));
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
	/*
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
	*/
	return false;
}

bool Schedule::contingent(vector<Course *> courses)
{
	for (Course *c : courses)
		for (Course *d : courses)
			if (abs(c->courseTime - d->courseTime) > 1)
				return false;
	return true;
}

int Schedule::fitness(vector<Course *> courses, vector<Instructor *> instructors)
{
	int ret = 50;
	int time_count[15] = {0};

	for (Course *c : courses)
		time_count[c->courseTime]++;

	for (int x = 0; x < 15; x++)
	{
		if (time_count[x] > NUM_CLASSROOMS)
			ret--;
	}

	for (Instructor *c : instructors)
	{
		if (!c->coursesValid())
		{
			ret--;
		}
	}

	for (Instructor *i : instructors)
		if (contingent(i->courses))
			ret += 10;
	
	return ret;
}

bool Schedule::isValid(vector<Course *> courses, vector<Instructor *> instructors)
{
	/* Hard constraints here... no more than <num_classrooms> courses at a time, no 2 for same prof at same time */
	int time_count[15] = {0};
	for (Course *c : courses)
	{
		time_count[c->courseTime]++;
	}

	for (int x = 0; x < 15; x++)
	{
		if (time_count[x] > NUM_CLASSROOMS)
		{
			return false;
		}
	}

	/* This should never happen (UNASSIGNED) */
	if (time_count[0])
		return false;

	return true;
}

Course::TIME Schedule::incTime(Course::TIME prevTime)
{
	switch (prevTime)
	{
		case Course::MW8:
			return Course::MW9;
		case Course::MW9:
			return Course::MW11;
		case Course::MW11:
			return Course::MW12;
		case Course::MW12:
			return Course::MW2;
		case Course::MW2:
			return Course::MW3;
		case Course::MW3:
			return Course::MW5;
		case Course::MW5:
			return Course::TR8;
		case Course::TR8:
			return Course::TR9;
		case Course::TR9:
			return Course::TR11;
		case Course::TR11:
			return Course::TR12;
		case Course::TR12:
			return Course::TR2;
		case Course::TR2:
			return Course::TR3;
		case Course::TR3:
			return Course::TR5;
		case Course::TR5:
			return Course::MW8;
		default:
			return Course::MW8;
	}
	return Course::MW8;
}

void Schedule::delegate(vector<Course *> courses)
{
	int time_count[15] = {0};
	vector<Course *>::const_iterator first = courses.begin() + 7;
	vector<Course *>::const_iterator last = courses.end();
	vector<Course *> newVec(first, last);
	for (Course *c : newVec)
	{
		int max = *std::max_element(time_count+1,time_count+15);
		int min = *std::min_element(time_count+1,time_count+15);

		if (max != min)
		{
			while(time_count[c->courseTime] != min)
				c->courseTime = incTime(c->courseTime);
			
			time_count[c->courseTime]++;
		}

		else
		{
			while(time_count[c->courseTime] == NUM_CLASSROOMS || !c->courseTime)
				c->courseTime = incTime(c->courseTime);
		}

		while(!c->instructor->coursesValid())
			c->courseTime = incTime(c->courseTime);

		time_count[c->courseTime]++;
	}
}


bool Schedule::nextSched(vector<Course *> courses, vector<Instructor *> instructors)
{
	bool valid = false;
	do
	{
		for (Course *t : *new vector<Course *>(courses.begin(), courses.begin() + NUM_COURSES_PER_PROF))
		{
			if (t->courseTime == Course::TR5 || t->courseTime == Course::UNASSIGNED)
			{
				t->courseTime = Course::MW8;
			}
			else
			{
				t->courseTime = incTime(t->courseTime);
				goto here;
			}
		}
here:
		cout << "bout to delegate!" << endl;
		delegate(courses);	
		valid = isValid(courses, instructors);
	} while (!valid);
	cout << "Woo! Valid!" << endl;
	return true;
}

// Super shitty brute force algo for making a schedule
// 11/10 - IGN
void Schedule::makeSchedule()
{
	Course::TIME possibleTimes[] = {Course::MW8, Course::MW9, Course::MW11, Course::MW12, Course::MW2, Course::MW3, Course::MW5, Course::TR8, Course::TR9, Course::TR11, Course::TR12, Course::TR2, Course::TR3, Course::TR5};
	int bestFitness = -9999;

	nextSched(courses, instructors);
	while (bestFitness < 100)
	{
		int curFitness = fitness(courses, instructors);
		cout << curFitness << endl;
		if (curFitness > bestFitness)
		{
			bestFitness = curFitness;
			cout << "Best fitness: " << bestFitness << endl;
		}
		if(!nextSched(courses, instructors))
			break;
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
		cout << "by " << c->instructor->instructorName << ", at " << c->getTime() << endl;
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
		cout << "by " << c->instructor->instructorName << ", at " << c->getTime() << endl;
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
