#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

void parseInput()
{
	char state = 0;
	ifstream input;
	input.open("Dept1ClassData.csv");
	string strn;
	vector<string> courses;
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

		cout << (int)state << ": " << strn << endl;


		switch (state)
		{
			case 2:/*  	CS 107, CS 108, CS 114, CS 144, CS 172 */
				splitString(strn, ',', courses);
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
					//cout << temp.at(x) << endl;
				}
			break;
		}
	}

	cout << "Number of courses parsed: " << courses.size() << endl;
}

int main(void) 
{
	parseInput();
}
