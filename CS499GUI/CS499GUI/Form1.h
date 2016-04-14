#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <malloc.h>
#include <msclr/marshal_cppstd.h>
#include "Schedule.h"
#include "Course.h"
#include "Instructor.h"
#include "LoadParse.h"
#include "OutputFile.h"
#include <vector>
#include <sstream>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;

#pragma once

Schedule *dept = new Schedule;

namespace CS499GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->comboBox2->Items->Add("Morning classes only");
			this->comboBox2->Items->Add("Afternoon classes only");
			this->comboBox2->Items->Add("Evening classes only");
			this->comboBox2->Items->Add("All Tues-Thurs classes");
			this->comboBox2->Items->Add("All Mon-Weds classes");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Course;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Instructor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Bldg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Room;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Day;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Time;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  CourseNum;
	private: System::Windows::Forms::DataGridView^  dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  InstructorName;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Building;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  RoomNum;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Course = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Instructor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Bldg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Room = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Day = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->InstructorName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->CourseNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Building = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownButton2 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(35, 341);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(149, 66);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(2, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 20);
			this->textBox1->TabIndex = 7;
			this->textBox1->Text = L"Instructor Name";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(103, 77);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 20);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Add Instructor";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Comma Delimited files (*.csv)|*.csv";
			this->openFileDialog1->Title = L"Load a CSV file";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(103, 58);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 20);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Add Classroom";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(5, 32);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"Room Number";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(5, 6);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(200, 20);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"Building Number";
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(562, 357);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Schedule";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Course, 
				this->Instructor, this->Bldg, this->Room, this->Day, this->Time});
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(554, 354);
			this->dataGridView1->TabIndex = 0;
			// 
			// Course
			// 
			this->Course->HeaderText = L"Course";
			this->Course->Name = L"Course";
			this->Course->ReadOnly = true;
			this->Course->Width = 125;
			// 
			// Instructor
			// 
			this->Instructor->HeaderText = L"Instructor";
			this->Instructor->Name = L"Instructor";
			this->Instructor->ReadOnly = true;
			this->Instructor->Width = 125;
			// 
			// Bldg
			// 
			this->Bldg->HeaderText = L"Bldg";
			this->Bldg->Name = L"Bldg";
			this->Bldg->ReadOnly = true;
			this->Bldg->Width = 50;
			// 
			// Room
			// 
			this->Room->HeaderText = L"Room";
			this->Room->Name = L"Room";
			this->Room->ReadOnly = true;
			this->Room->Width = 50;
			// 
			// Day
			// 
			this->Day->HeaderText = L"Day";
			this->Day->Name = L"Day";
			this->Day->ReadOnly = true;
			this->Day->Width = 50;
			// 
			// Time
			// 
			this->Time->HeaderText = L"Time";
			this->Time->Name = L"Time";
			this->Time->ReadOnly = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(224, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(570, 383);
			this->tabControl1->TabIndex = 13;
			this->tabControl1->TabStop = false;
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage2);
			this->tabControl2->Controls->Add(this->tabPage3);
			this->tabControl2->Controls->Add(this->tabPage4);
			this->tabControl2->Enabled = false;
			this->tabControl2->Location = System::Drawing::Point(2, 28);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(217, 307);
			this->tabControl2->TabIndex = 14;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->comboBox2);
			this->tabPage2->Controls->Add(this->dataGridView4);
			this->tabPage2->Controls->Add(this->checkBox1);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(209, 281);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"Add Instructor";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(2, 51);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(200, 21);
			this->comboBox2->TabIndex = 12;
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->InstructorName});
			this->dataGridView4->Location = System::Drawing::Point(2, 103);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(200, 174);
			this->dataGridView4->TabIndex = 11;
			// 
			// InstructorName
			// 
			this->InstructorName->HeaderText = L"Instructor";
			this->InstructorName->Name = L"InstructorName";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(5, 29);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(106, 17);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->Text = L"Has Preference\?";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->comboBox1);
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Controls->Add(this->textBox6);
			this->tabPage3->Controls->Add(this->checkBox2);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->textBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(209, 281);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Add Course";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Choose Instructor for course:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(3, 93);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(199, 21);
			this->comboBox1->TabIndex = 13;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->CourseNum});
			this->dataGridView2->Location = System::Drawing::Point(3, 149);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(200, 128);
			this->dataGridView2->TabIndex = 12;
			// 
			// CourseNum
			// 
			this->CourseNum->HeaderText = L"Courses";
			this->CourseNum->Name = L"CourseNum";
			this->CourseNum->Width = 150;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(3, 47);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(200, 20);
			this->textBox6->TabIndex = 11;
			this->textBox6->Text = L"Preference";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(5, 29);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(106, 17);
			this->checkBox2->TabIndex = 10;
			this->checkBox2->Text = L"Has Preference\?";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(103, 126);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 20);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Add Course";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(3, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"Course #";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView3);
			this->tabPage4->Controls->Add(this->button4);
			this->tabPage4->Controls->Add(this->textBox4);
			this->tabPage4->Controls->Add(this->textBox2);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(209, 281);
			this->tabPage4->TabIndex = 2;
			this->tabPage4->Text = L"Add Room";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Building, 
				this->RoomNum});
			this->dataGridView3->Location = System::Drawing::Point(2, 84);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(200, 191);
			this->dataGridView3->TabIndex = 11;
			// 
			// Building
			// 
			this->Building->HeaderText = L"Building";
			this->Building->Name = L"Building";
			this->Building->Width = 75;
			// 
			// RoomNum
			// 
			this->RoomNum->HeaderText = L"Room";
			this->RoomNum->Name = L"RoomNum";
			this->RoomNum->Width = 75;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"csv";
			this->saveFileDialog1->FileName = L"MySchedule.csv";
			this->saveFileDialog1->Title = L"Save as .csv";
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripDropDownButton1, 
				this->toolStripDropDownButton2, this->toolStripButton3, this->toolStripButton4});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(794, 25);
			this->toolStrip1->TabIndex = 15;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem1});
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(29, 22);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->ToolTipText = L"Create New Schedule";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(149, 22);
			this->toolStripMenuItem1->Text = L"New Schedule";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			// 
			// toolStripDropDownButton2
			// 
			this->toolStripDropDownButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem2, 
				this->toolStripMenuItem3});
			this->toolStripDropDownButton2->Enabled = false;
			this->toolStripDropDownButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripDropDownButton2.Image")));
			this->toolStripDropDownButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton2->Name = L"toolStripDropDownButton2";
			this->toolStripDropDownButton2->Size = System::Drawing::Size(29, 22);
			this->toolStripDropDownButton2->Text = L"toolStripDropDownButton2";
			this->toolStripDropDownButton2->ToolTipText = L"Load .csv";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(163, 22);
			this->toolStripMenuItem2->Text = L"Load Data .csv";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(163, 22);
			this->toolStripMenuItem3->Text = L"Load Rooms .csv";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem3_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Enabled = false;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"toolStripButton3";
			this->toolStripButton3->ToolTipText = L"Generate Schedule";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Enabled = false;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"toolStripButton4";
			this->toolStripButton4->ToolTipText = L"Save Schedule";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButton4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 412);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->tabControl2);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"UAH Automated Semester Scheduler";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

			 //Add classroom button
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				msclr::interop::marshal_context context;
				string bldg = context.marshal_as<std::string>(this->textBox4->Text);
				string room = context.marshal_as<std::string>(this->textBox2->Text);
				dept->AddClassroom(bldg, room, 0, 0);
				this->dataGridView3->Rows->Add(this->textBox4->Text, this->textBox2->Text);
		 }

			 //Load data csv
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
				//Load and parse the data
				LoadParse tmploader;

				//Prompt for file and load it
				if (openFileDialog1->ShowDialog() == System::Windows::Forms:: DialogResult::OK)
				{
					System::String ^ tmpstr = openFileDialog1->FileName;

					IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(tmpstr);
					char* fName = static_cast<char*>(ptrToNativeString.ToPointer());

					tmploader.parseInput(fName, dept);

					System::String ^ theCourse;
					for (int i = 0; i < dept->courses.size(); i++)
					{
						theCourse = gcnew String(dept->courses[i]->courseNum.c_str());
						this->dataGridView2->Rows->Add(theCourse);
					}
					System::String ^ theInstr;
					for (int i = 1; i < dept->instructors.size(); i++)
					{
						theInstr = gcnew String(dept->instructors[i]->instructorName.c_str());
						this->dataGridView4->Rows->Add(theInstr);
						this->comboBox1->Items->Add(theInstr);
					}
				}
		 }
		 //Load room csv
private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
				//Load and parse the data
				LoadParse tmploader;

				//Load times passively
				tmploader.readTimeFile("Times.csv", dept);

				//Prompt for file and load it
				if (openFileDialog1->ShowDialog() == System::Windows::Forms:: DialogResult::OK)
				{
					System::String ^ tmpstr = openFileDialog1->FileName;

					IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(tmpstr);
					char* fName = static_cast<char*>(ptrToNativeString.ToPointer());

					tmploader.readRoomFile(fName, dept);

					System::String ^ theBldg;
					System::String ^ theRoom;
					for (int i = 0; i < dept->classrooms.size(); i++)
					{
						theBldg = gcnew String(dept->classrooms[i]->bldgNum.c_str());
						theRoom = gcnew String(dept->classrooms[i]->roomNum.c_str());
						this->dataGridView3->Rows->Add(theBldg, theRoom);
					}

					this->toolStripButton3->Enabled = true;
					this->toolStripDropDownButton2->Enabled = false;
				}
		 }
		 //Generate Schedule
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Initiate schedule building
				 dept->makeSchedule();
				 
				 //Print the data into the table on screen
				 for (int i = 0; dept->scheduleArray[i][0] != 999; i++)
					{
						System::String ^ theDay;
						System::String ^ theTime;
						System::String ^ theCourse = gcnew String(dept->courses[dept->scheduleArray[i][1]]->courseNum.c_str());
						System::String ^ theBldg = gcnew String(dept->classrooms[dept->scheduleArray[i][0]]->bldgNum.c_str());
						System::String ^ theRoom = gcnew String(dept->classrooms[dept->scheduleArray[i][0]]->roomNum.c_str());
						System::String ^ theInstr = gcnew String(dept->courses[dept->scheduleArray[i][1]]->profName.c_str());

						//check to see which time it is assigned and print it
						//mon/weds
						if (dept->scheduleArray[i][2] == 0x00000001 && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[0].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00000010  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[1].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00000100  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[2].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00001000  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[3].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00010000  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[4].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00100000  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[5].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x01000000  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[6].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x10000000  && dept->scheduleArray[i][3] == 1)
						{
							theDay = "MW";
							theTime = gcnew String(dept->theTimes[7].c_str());
						}

						//tues/thurs
						if (dept->scheduleArray[i][2] == 0x00000001 && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[0].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00000010  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[1].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00000100  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[2].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00001000  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[3].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00010000  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[4].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x00100000  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[5].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x01000000  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[6].c_str());
						}
						else if (dept->scheduleArray[i][2] == 0x10000000  && dept->scheduleArray[i][3] == 2)
						{
							theDay = "TT";
							theTime = gcnew String(dept->theTimes[7].c_str());
						}
						//Add the row to the GUI table
						this->dataGridView1->Rows->Add(theCourse, theInstr, theBldg, theRoom, theDay, theTime);
					}
				 //Enable the save button now
				 this->toolStripButton4->Enabled = true;
				 this->toolStripButton3->Enabled = false;
		 }
		 //Save Schedule
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e) {
				OutputFile tmpW;
				//Prompt for file name and location and print to file
				if (saveFileDialog1->ShowDialog() == System::Windows::Forms:: DialogResult::OK)
				{
					System::String ^ tmpstr = saveFileDialog1->FileName;

					IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(tmpstr);
					char* fName = static_cast<char*>(ptrToNativeString.ToPointer());

					//Create writefile instance and write the file
					tmpW.writeToFile(this->dataGridView1, fName);
				}
		 }

//This section creates new schedules based on the dropdown selection for department
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Clear out anything existing in the dept currently
			dept->ClearSchedule();

			//Clear tables and stuff
			dataGridView1->Rows->Clear();
			dataGridView1->Refresh();
			dataGridView2->Rows->Clear();
			dataGridView2->Refresh();
			dataGridView3->Rows->Clear();
			dataGridView3->Refresh();
			dataGridView4->Rows->Clear();
			dataGridView4->Refresh();
			comboBox1->Items->Clear();

			//enable stuff
			this->toolStripDropDownButton2->Enabled = true;
			this->tabControl2->Enabled = true;
			this->toolStripButton3->Enabled = false;

			dept->deptName =  "Computer Science";
			this->tabPage1->Text = this->toolStripMenuItem1->Text;
		 }

		 //Add instructor button
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			bool prefbool = false;
			msclr::interop::marshal_context context;
			string instrName = context.marshal_as<std::string>(this->textBox1->Text);
			string instrPref = context.marshal_as<std::string>(this->comboBox2->SelectedText);
			if (this->checkBox1->Checked)
			{
				prefbool = true;
			}
			dept->AddInstructor(instrName, instrPref, prefbool);
			this->dataGridView4->Rows->Add(this->textBox1->Text);
			this->comboBox1->Items->Add(this->textBox1->Text);
		 }

		 //Add course button
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			bool prefbool = false;
			msclr::interop::marshal_context context;
			string courseNum = context.marshal_as<std::string>(this->textBox3->Text);
			string instrName = context.marshal_as<std::string>(this->comboBox1->SelectedText);
			if (this->checkBox1->Checked)
			{
				prefbool = true;
			}
			dept->AddCourse(courseNum, "", prefbool);
			dept->courses[dept->courses.size()-1]->profName = instrName;
			this->dataGridView2->Rows->Add(this->textBox3->Text);
		 }
};
}
