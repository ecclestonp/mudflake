//CS499 Senior Project - Course Scheduling system
//Outputs the schedule to a .csv file
//Purpose: Writes the data or filtered data to an excel readable file
//Written by: Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "Schedule.h"
using namespace std;

#pragma once

class OutputFile
{
	public:
		void writeToFile(System::Windows::Forms::DataGridView ^ dgv, char *fName, string deptName);
};