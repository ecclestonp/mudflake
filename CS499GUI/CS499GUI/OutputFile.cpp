//CS499 Senior Project - Course Scheduling system
//Outputs the schedule to a .csv file
//Purpose: Writes the data or filtered data to an excel readable file
//Written by: Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "OutputFile.h"
#include "Schedule.h"
#include <fstream>
#include <string>
#include <cstring>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace std;

void OutputFile::writeToFile(System::Windows::Forms::DataGridView ^ dgv, char *fName, string deptName)
{
	//Open file for output
	ofstream outFile;
	outFile.open(fName);

	//Write first lines into .csv file
	outFile << deptName << endl;
	outFile << "Course,Instructor,Building,Room,Day,Time" << endl;
	msclr::interop::marshal_context context;

	//Write the data array to the file in .csv format
	for (int i = 0; i < dgv->RowCount; i++)
	{
		if (dgv->Rows[i]->Visible == true)
		{
			outFile << context.marshal_as<std::string>(dgv->Rows[i]->Cells[0]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[1]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[2]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[3]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[4]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[5]->Value->ToString()) << endl;
		}
	}

	//Close file
	outFile.close();

	return;
}