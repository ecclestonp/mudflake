//Writes to a .csv file
//CS499 Senior Project
//Ryan Manecke, Jeffrey Webb, Paul Eccleston

#include "OutputFile.h"
#include "Schedule.h"
#include <fstream>
#include <string>
#include <cstring>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace std;

void OutputFile::writeToFile(System::Windows::Forms::DataGridView ^ dgv, char *fName)
{
	//Open file for output
	ofstream outFile;
	outFile.open(fName);

	//Write first lines into .csv file
	//outFile << dept->deptName << endl;
	outFile << "Course,Instructor,Building,Room,Day,Time" << endl;

	//Write the data array to the file in .csv format
	for (int i = 0; i < dgv->RowCount; i++)
	{
		msclr::interop::marshal_context context;
		outFile << context.marshal_as<std::string>(dgv->Rows[i]->Cells[0]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[1]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[2]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[3]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[4]->Value->ToString()) << "," << context.marshal_as<std::string>(dgv->Rows[i]->Cells[5]->Value->ToString()) << endl;
	}

	//Close file
	outFile.close();

	return;
}