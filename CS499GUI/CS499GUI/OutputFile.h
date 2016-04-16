//Interface file for OutputFile.cpp
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston
#include "Schedule.h"
using namespace std;

#pragma once

class OutputFile
{
	public:
		void writeToFile(System::Windows::Forms::DataGridView ^ dgv, char *fName, string deptName);
};