#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Schedule.h"

using namespace std;

void splitString(string line, char delim, vector<string> &vec)
{
	string temp;
	stringstream stream(line);

	while(getline(stream, temp, delim))
	{
		temp = temp.substr(temp.find_first_not_of(" \n\r\t"));
		vec.push_back(temp);
	}
}

void splitString(string line, char delim, Schedule *dept, int state)
{
	string temp;
	stringstream stream(line);

	while(getline(stream, temp, delim))
	{
		temp = temp.substr(temp.find_first_not_of(" \n\r\t"));
		temp = temp.substr(0,temp.find_last_not_of("\n\r\t")+1);
		if(state == 2)
		{
			Course c(temp);
			dept->courses.push_back(c);
		}
	}
}

void parseInput(Schedule *dept)
{
	char state = 0;
	ifstream input;
	input.open("Dept1ClassData.csv");
	string strn;
	while(!input.eof())
	{
		getline(input, strn);
		/* Every line has a newline at the end */
		if(strn.length() < 2)
		{
			state++;
			continue;
		}
		/* Compare the character before the newline */
		if(strn[strn.length()-2] == ':') continue;

		//cout << (int)state << ": " << strn << endl;

		switch (state)
		{
			case 2:/*  	CS 107, CS 108, CS 114, CS 144, CS 172 */
				splitString(strn, ',', dept, state);
			break;
			case 4:/*   CS 342 must be taught in Technology Hall, room 342 */
				//TODO: implement contstraints on a case-by-case basis
			break;
			case 6:/*   Dr. Echo, CS 107, CS 226, CS 342 - Preference: Morning classes only */
				vector<string> temp;
				string tempPreference;
				splitString(strn, ',', temp);
				tempPreference = temp.at(temp.size() - 1).substr(temp.at(temp.size() - 1).find_first_of("-") + 2);
				temp.at(temp.size() - 1) = temp.at(temp.size() - 1).substr(0, temp.at(temp.size() - 1).find_first_of("-") - 1);
				for(int x = 1; x < temp.size(); x++)/* Start at 1 because the professor's name is temp.at(0) */
				{
					if(!dept->setCourseProfessor(temp.at(x),temp.at(0)))
						cout << "Unable to set professor for " << temp.at(x) << endl;
				}
			break;
		}
	}

	cout << "Number of courses parsed: " << dept->courses.size() << endl;
}

int main(void) 
{
	Schedule dept;
	parseInput(&dept);

	for(int x = 0; x < dept.courses.size(); x++)
	{
		cout << dept.courses.at(x).courseNum << ", taught by " << dept.courses.at(x).profName << endl;
	}
}
