#pragma once

#include "../Visual/Process/Process.h"
#include "../Visual/Draw/Draw.h"
#include "../Visual/Thread/Thread.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace Process;


namespace Visual {

	/// <summary>
	/// Summary for SortControl
	/// </summary>
	public ref class SortControl : public System::Windows::Forms::UserControl
	{
	public:
		SortControl(void)
			:SortStep(0),
			 Endpattern(true)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//about repaint
			bitmap = gcnew System::Drawing::Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
			
			//about rectangular
			canvas = gcnew System::Drawing::Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
			brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
			brushChange = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Red);

			//about DottedLine
			pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 2);
			penDottedLine = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Gray, 2);
			penDottedLine->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;

			//about coordinates
			penCoordinates = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);

			//about text
			font = gcnew System::Drawing::Font(L"Microsoft YaHei", 9);
			stepfont = gcnew System::Drawing::Font(L"Microsoft YaHei", 10);
			stepbrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Purple);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SortControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  others;

	private: System::Windows::Forms::RadioButton^  shell;
	private: System::Windows::Forms::RadioButton^  insert;
	private: System::Windows::Forms::RadioButton^  select;
	private: System::Windows::Forms::RadioButton^  bubble;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  step;
	private: System::Windows::Forms::RadioButton^  normal;

	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		//about map 
		System::Drawing::Bitmap^   bitmap;
		System::Drawing::Graphics^ myGraphics;				// draw	
		HANDLE hThread1;									// thread for update sort

		//about rectangular
		System::Drawing::Bitmap^ canvas;					// board
		System::Drawing::Brush^  brush;					    // when don't data interchange
		System::Drawing::Brush^  brushChange;				// when data interchange
		System::Drawing::Pen^    pen;						// line 

		//about DottedLine
		System::Drawing::Pen^    penDottedLine;				// dotted line

		//about coordinates
		System::Drawing::Pen^    penCoordinates;			// coordinates 

		//about text
		System::Drawing::Font^   font;						// text data
		System::Drawing::Font^   stepfont;				    // steps data
		System::Drawing::Brush^  stepbrush;					// when don't data interchange

		//about step pattern
		unsigned int SortStep;							    // the step of sort
		bool  Endpattern;									// exit single-step mode

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SortControl::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->others = (gcnew System::Windows::Forms::RadioButton());
			this->shell = (gcnew System::Windows::Forms::RadioButton());
			this->insert = (gcnew System::Windows::Forms::RadioButton());
			this->select = (gcnew System::Windows::Forms::RadioButton());
			this->bubble = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->step = (gcnew System::Windows::Forms::RadioButton());
			this->normal = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(13, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(831, 595);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SortControl::pictureBox1_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(860, 21);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(173, 136);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Implement";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button3->Location = System::Drawing::Point(33, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"- The 0th Step - ";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(33, 61);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Quit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SortControl::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(33, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SortControl::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->others);
			this->groupBox2->Controls->Add(this->shell);
			this->groupBox2->Controls->Add(this->insert);
			this->groupBox2->Controls->Add(this->select);
			this->groupBox2->Controls->Add(this->bubble);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox2->Location = System::Drawing::Point(860, 201);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(173, 292);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sort";
			// 
			// others
			// 
			this->others->AutoSize = true;
			this->others->Enabled = false;
			this->others->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->others->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->others->Location = System::Drawing::Point(40, 233);
			this->others->Name = L"others";
			this->others->Size = System::Drawing::Size(62, 21);
			this->others->TabIndex = 4;
			this->others->TabStop = true;
			this->others->Text = L"others";
			this->others->UseVisualStyleBackColor = true;
			// 
			// shell
			// 
			this->shell->AutoSize = true;
			this->shell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->shell->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->shell->Location = System::Drawing::Point(40, 185);
			this->shell->Name = L"shell";
			this->shell->Size = System::Drawing::Size(51, 21);
			this->shell->TabIndex = 3;
			this->shell->TabStop = true;
			this->shell->Text = L"shell";
			this->shell->UseVisualStyleBackColor = true;
			// 
			// insert
			// 
			this->insert->AutoSize = true;
			this->insert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->insert->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->insert->Location = System::Drawing::Point(40, 138);
			this->insert->Name = L"insert";
			this->insert->Size = System::Drawing::Size(57, 21);
			this->insert->TabIndex = 2;
			this->insert->TabStop = true;
			this->insert->Text = L"insert";
			this->insert->UseVisualStyleBackColor = true;
			// 
			// select
			// 
			this->select->AutoSize = true;
			this->select->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->select->Location = System::Drawing::Point(40, 92);
			this->select->Name = L"select";
			this->select->Size = System::Drawing::Size(58, 21);
			this->select->TabIndex = 1;
			this->select->TabStop = true;
			this->select->Text = L"select";
			this->select->UseVisualStyleBackColor = true;
			// 
			// bubble
			// 
			this->bubble->AutoSize = true;
			this->bubble->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bubble->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->bubble->Location = System::Drawing::Point(40, 46);
			this->bubble->Name = L"bubble";
			this->bubble->Size = System::Drawing::Size(66, 21);
			this->bubble->TabIndex = 0;
			this->bubble->TabStop = true;
			this->bubble->Text = L"bubble";
			this->bubble->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->step);
			this->groupBox3->Controls->Add(this->normal);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox3->Location = System::Drawing::Point(860, 539);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(173, 85);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Pattern";
			// 
			// step
			// 
			this->step->AutoSize = true;
			this->step->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->step->Location = System::Drawing::Point(40, 50);
			this->step->Name = L"step";
			this->step->Size = System::Drawing::Size(96, 21);
			this->step->TabIndex = 1;
			this->step->TabStop = true;
			this->step->Text = L"step pattern";
			this->step->UseVisualStyleBackColor = true;
			// 
			// normal
			// 
			this->normal->AutoSize = true;
			this->normal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->normal->Location = System::Drawing::Point(40, 23);
			this->normal->Name = L"normal";
			this->normal->Size = System::Drawing::Size(66, 21);
			this->normal->TabIndex = 0;
			this->normal->TabStop = true;
			this->normal->Text = L"normal";
			this->normal->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->pictureBox3);
			this->groupBox5->Controls->Add(this->pictureBox2);
			this->groupBox5->Controls->Add(this->button5);
			this->groupBox5->Controls->Add(this->button4);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox5->Location = System::Drawing::Point(860, 630);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(173, 92);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Step Pattern";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(30, 59);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(20, 20);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(30, 24);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(20, 20);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button5->Location = System::Drawing::Point(54, 58);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(97, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Forward";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &SortControl::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button4->Location = System::Drawing::Point(54, 22);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(97, 23);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Backward";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &SortControl::button4_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &SortControl::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(13, 638);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(831, 83);
			this->textBox1->TabIndex = 6;
			// 
			// SortControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"SortControl";
			this->Size = System::Drawing::Size(1043, 728);
			this->Load += gcnew System::EventHandler(this, &SortControl::SortControl_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void SortControl_Load(System::Object^  sender, System::EventArgs^  e) {
	myGraphics->FromImage(bitmap);
	this->pictureBox1->Invalidate();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	//lock
	WaitForSingleObject(Process::HMutex, INFINITE);

	//show();
	updatetextbox((this->textBox1->GetLineFromCharIndex(this->textBox1->GetFirstCharIndexOfCurrentLine()) + 1).ToString() + ") " + " The " + (StepInNormal + 1).ToString() + " steps : " + "swap the " + ExchangeIndex[0].ToString()
		+  " with the " + ExchangeIndex[1].ToString() + ".");
	
	this->pictureBox1->Invalidate();
	this->button3->Text = The_digital_unit(StepInNormal + 1);

	//unlock
	ReleaseMutex(HMutex);
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	MyStruct<SortType> Sortstruct;

	//the start sort
	if (this->normal->Checked)
	{
		// bubble
		if (this->bubble->Checked)
		{
			ReadyForSort(0);
		}
		// select
		else if (this->select->Checked)
		{
			ReadyForSort(1);
		}
		// insert
		else if (this->insert->Checked)
		{
			ReadyForSort(2);
		}
		//shell
		else if (this->shell->Checked)
		{
			ReadyForSort(3);
		}
		else
		{
			MessageBox::Show("Please select a sorting way!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else if (this->step->Checked)
	{
		// bubble
		if (this->bubble->Checked)
		{
			ReadyForSortUseSecondModel(0);
		}
		// select
		else if (this->select->Checked)
		{
			ReadyForSortUseSecondModel(1);
		}
		// insert
		else if (this->insert->Checked)
		{
			ReadyForSortUseSecondModel(2);
		}
		//shell
		else if (this->shell->Checked)
		{
			ReadyForSortUseSecondModel(3);
		}
		else
		{
			MessageBox::Show("Please select a sorting order!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else
	{
		MessageBox::Show("Please select a sorting pattern!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->step->Checked)
	{
		//clear
		Every_Step_Of_The_Change.clear();
		for (size_t i = 0; i < Every_Step_Of_The_Value.size(); i++)
			Every_Step_Of_The_Value[i].clear();
		Every_Step_Of_The_Value.clear();
		SortStep = 0;

		//exit current step mode and update ui
		this->button3->Text = "- The 0th Step -";
		Endpattern = !Endpattern;
		this->pictureBox1->Invalidate();
		Opening();
	}
	else
	{
		MessageBox::Show("Only for single step pattern", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (this->step->Checked)
	{
		if (this->bubble->Checked || this->select->Checked || this->shell->Checked || this->insert->Checked )
		{
			if (SortStep > 0)
			{
				SortStep--;
				this->pictureBox1->Invalidate();
			}
			else
				MessageBox::Show("This is the first step! If you want to quit,please click on the Quit this button.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("please select the sort pattern in sort this part.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else
	{
		MessageBox::Show("please select the Step Pattern in Pattern this part.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (this->step->Checked)
	{
		if (this->bubble->Checked || this->select->Checked || this->shell->Checked || this->insert->Checked)
		{
			if (SortStep < Every_Step_Of_The_Value.size() - 1)
			{
				SortStep++;
				this->pictureBox1->Invalidate();
			}
			else
				MessageBox::Show("This is the last step! If you want to quit,please click on the Quit this button.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("please select the sort pattern", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else
	{
		MessageBox::Show("please select the step pattern", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
	myGraphics = e->Graphics;
	myGraphics->FromImage(bitmap);
	myGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

	// draw sorting process
	if (this->normal->Checked)
	{
		Geometric::Object arrow;
		vector<long long>::iterator SearchFirst;

		try
		{
			if (IArraysize.size() != 0 && SortFinished)
			{
				// update the line segment
				System::Drawing::Point Pt1(RECTANGULAR_SPACE * ExchangeIndex[0] + 22, 185 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt2(RECTANGULAR_SPACE * ExchangeIndex[0] + 22, 90 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt3(RECTANGULAR_SPACE * ExchangeIndex[1] + 22, 90 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt4(RECTANGULAR_SPACE * ExchangeIndex[1] + 22, 185 - IArraysize[ExchangeIndex[1]]);

				myGraphics->DrawLine(pen, Pt1, Pt2);
				myGraphics->DrawLine(pen, Pt2, Pt3);
				myGraphics->DrawLine(pen, Pt3, Pt4);

				// update cylindrical
				for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
				{
					Geometric::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
					if (i == ExchangeIndex[0] || i == ExchangeIndex[1])
					{
						brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::PaleVioletRed);
						myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
							int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
					}

					else
					{
						brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
						myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
							int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
					}

					//update dottedLine and text 
					System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
					System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

					//myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
					//myGraphics->DrawString((IArraysize[i] + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
					myGraphics->DrawString(The_digital_unit(StepInNormal + 1), stepfont, stepbrush, float(abs(Pt2.X - Pt3.X) / 2 + min(Pt2.X, Pt3.X) - 50), float(Pt2.Y - 25));
				}

				myGraphics->DrawImage(bitmap, 0, 0);
				//this->pictureBox1->Image = canvas;
			}
			else if (!SortFinished)
			{
				// finally update ui when thread is end.
				for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
				{
					// update cylindrical
					Geometric::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
					brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
					myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
						int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));

					//update dottedLine and text 
					System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
					System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

					//myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
					//myGraphics->DrawString((IArraysize[i] + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
				}

				// update controls
				Opening();

				// update data
				this->timer1->Stop();
				StepInNormal = 0;
				updatetextbox("--------------------------------------------Over-------------------------------------------------");
				myGraphics->DrawImage(bitmap, 0, 0);
			}
		}
		catch (const std::exception&)
		{
			return;
		}
	}
	else if (this->step->Checked && Endpattern)
	{
		// update ui about the previous step
		System::Drawing::Point Pt1(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep] + 22, 185 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt2(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep] + 22, 90 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt3(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep + 1] + 22, 90 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt4(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep + 1] + 22, 185 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep + 1]));

		myGraphics->DrawLine(pen, Pt1, Pt2);
		myGraphics->DrawLine(pen, Pt2, Pt3);
		myGraphics->DrawLine(pen, Pt3, Pt4);

		for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
		{
			Geometric::Object object(RECTANGULAR_SPACE * i, Every_Step_Of_The_Value.at(SortStep).at(i));

			if (i == Every_Step_Of_The_Change[2 * SortStep] || i == Every_Step_Of_The_Change[2 * SortStep + 1])
			{
				brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::PaleVioletRed);
				myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
					int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
			}
			else
			{
				brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
				myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
					int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
			}

			//update dottedLine and text and step
			System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
			System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

			myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
			myGraphics->DrawString((Every_Step_Of_The_Value.at(SortStep).at(i) + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
			myGraphics->DrawString(The_digital_unit(SortStep + 1), stepfont, stepbrush, float(abs(Pt2.X - Pt3.X) / 2 + min(Pt2.X, Pt3.X) - 50), float(Pt2.Y - 25));
			this->button3->Text = The_digital_unit(SortStep + 1);
		}
	}
	else if (!Endpattern)
	{
		myGraphics->Clear(this->pictureBox1->BackColor);
	}

	// draw x-coordinate
	for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
	{
		System::Drawing::Point Pt1(22 + RECTANGULAR_SPACE * i, this->pictureBox1->Height);
		System::Drawing::Point Pt2(22 + RECTANGULAR_SPACE * i, this->pictureBox1->Height - 7);
		myGraphics->DrawLine(penCoordinates, Pt1, Pt2);
	}

	// draw y-coordinate
	for (SortType i = 0; i < RECTANGULAR_NUMBER - 2; i++)
	{
		System::Drawing::Point Pt1(0, 5 + RECTANGULAR_SPACE * i);
		System::Drawing::Point Pt2(0 + 7, 5 + RECTANGULAR_SPACE * i);
		myGraphics->DrawLine(penCoordinates, Pt1, Pt2);
	}
}

//!\brief about the first model
private: void ReadyForSort( /* the function is start */ const unsigned int SortIndex) {

	MyStruct<SortType> Sortstruct;

	try
	{
		// exit thread and thread1
		// close the start button
		Shielding();

		IArraysize.clear();
		SortFinished = true;
		IArraysize = Sortstruct.nums = RandNumbers<SortType>();
		Sortstruct.SortIndex = SortIndex;

		//CloseHandle(hThread1);
		Go(Sortstruct);
	}
	catch (const std::exception&)
	{
		return;
	}
}
private: void Go( /* the function is start thread */ MyStruct<SortType> SortInfo) {

	MYThread<SortType> ThreadInSort(SortInfo.SortIndex, SortInfo.nums, "normal");

	// start two thread ( First is sort,second is display )
	if (SortInfo.nums.size() != NULL)
	{
		try
		{
			this->textBox1->Text = "--------------------------------------------Start-------------------------------------------------";
			HMutex = CreateMutex(NULL, FALSE, LPCWSTR("sort"));
			HANDLE  HandleSort = (HANDLE)_beginthreadex(NULL, 0, ThreadInSort.ThreadOfSort, NULL, 0, NULL);

			//this->pictureBox1->Invalidate();
			this->timer1->Start();
		}
		catch (const std::exception&)
		{
			return;
		}
	}
}

//!\brief about the second model(step)
private: void ReadyForSortUseSecondModel( /*the function is start thread*/ const unsigned int SortIndex)
{
	ShieldingModel();
	Endpattern = true;

	MYThread<SortType> ThreadInSort(SortIndex, RandNumbers<SortType>(), "step pattern");

	try
	{
		HMutex = CreateMutex(NULL, FALSE, LPCWSTR("sort"));
		HANDLE  HandleSort = (HANDLE)_beginthreadex(NULL, 0, ThreadInSort.ThreadOfSort, NULL, 0, NULL);
		DWORD ReturnStatus = WaitForSingleObject(HandleSort, INFINITE);
		if (ReturnStatus != WAIT_TIMEOUT)
			this->pictureBox1->Invalidate();
	}
	catch (const std::exception&)
	{
		return;
	}
}

//!\brief
//!\brief about update ui
private: void show()
{
	// draw sorting process
	if (this->normal->Checked)
	{
		Geometric::Object arrow;
		vector<long long>::iterator SearchFirst;

		try
		{
			if (IArraysize.size() != 0 && SortFinished)
			{
				// update the line segment
				System::Drawing::Point Pt1(RECTANGULAR_SPACE * ExchangeIndex[0] + 45, 185 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt2(RECTANGULAR_SPACE * ExchangeIndex[0] + 45, 90 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt3(RECTANGULAR_SPACE * ExchangeIndex[1] + 45, 90 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt4(RECTANGULAR_SPACE * ExchangeIndex[1] + 45, 185 - IArraysize[ExchangeIndex[1]]);

				myGraphics->DrawLine(pen, Pt1, Pt2);
				myGraphics->DrawLine(pen, Pt2, Pt3);
				myGraphics->DrawLine(pen, Pt3, Pt4);

				// update cylindrical
				for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
				{
					Geometric::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
					if (i == ExchangeIndex[0] || i == ExchangeIndex[1])
					{
						brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::PaleVioletRed);
						myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
							int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
					}

					else
					{
						brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkTurquoise);
						myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
							int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
					}

					//update dottedLine and text 
					System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
					System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

					myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
					myGraphics->DrawString((IArraysize[i] + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
					myGraphics->DrawString(The_digital_unit(StepInNormal + 1), stepfont, stepbrush, float(abs(Pt2.X - Pt3.X) / 2 + min(Pt2.X, Pt3.X) - 50), float(Pt2.Y - 25));
				}

				//myGraphics->DrawImage(bitmap, 0, 0);
				//this->pictureBox1->Image = canvas;
			}
			else if (!SortFinished)
			{
				// finally update ui when thread is end.
				for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
				{
					// update cylindrical
					Geometric::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
					brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkTurquoise);
					myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
						int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));

					//update dottedLine and text 
					System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
					System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

					myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
					myGraphics->DrawString((IArraysize[i] + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
				}

				// update controls
				Opening();

				// update data
				this->timer1->Stop();
				StepInNormal = 0;
				updatetextbox("--------------------------------------------OVER-------------------------------------------------");
				//myGraphics->DrawImage(bitmap, 0, 0);
			}
		}
		catch (const std::exception&)
		{
			return;
		}
	}
	else if (this->step->Checked && Endpattern)
	{
		// update ui about the previous step
		System::Drawing::Point Pt1(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep] + 45, 185 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt2(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep] + 45, 90 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt3(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep + 1] + 45, 90 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt4(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep + 1] + 45, 185 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep + 1]));

		myGraphics->DrawLine(pen, Pt1, Pt2);
		myGraphics->DrawLine(pen, Pt2, Pt3);
		myGraphics->DrawLine(pen, Pt3, Pt4);

		for (SortType i = 0; i < RECTANGULAR_NUMBER; i++)
		{
			Geometric::Object object(RECTANGULAR_SPACE * i, Every_Step_Of_The_Value.at(SortStep).at(i));

			if (i == Every_Step_Of_The_Change[2 * SortStep] || i == Every_Step_Of_The_Change[2 * SortStep + 1])
			{
				brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::PaleVioletRed);
				myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
					int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
			}
			else
			{
				brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkTurquoise);
				myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
					int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
			}

			//update dottedLine and text and step
			System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
			System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

			myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
			myGraphics->DrawString((Every_Step_Of_The_Value.at(SortStep).at(i) + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
			myGraphics->DrawString(The_digital_unit(SortStep + 1), stepfont, stepbrush, float(abs(Pt2.X - Pt3.X) / 2 + min(Pt2.X, Pt3.X) - 50), float(Pt2.Y - 25));
			this->button5->Text = The_digital_unit(SortStep + 1);
		}
	}
	else if (!Endpattern)
	{
		myGraphics->Clear(this->pictureBox1->BackColor);
	}
}
private: void Shielding( /*The function is shield object*/) {

	this->button1->Enabled = false;
	this->bubble->Enabled = false;
	this->button2->Enabled = false;
	this->select->Enabled = false;
	this->insert->Enabled = false;
	this->shell->Enabled = false;
	this->normal->Enabled = false;
	this->step->Enabled = false;
	this->button4->Enabled = false;
	this->button5->Enabled = false;
}
private: void ShieldingModel( /* the function is shield widget */)
{
	this->bubble->Enabled = false;
	this->button2->Enabled = true;
	this->select->Enabled = true;
	this->insert->Enabled = true;
	this->shell->Enabled = false;
	this->normal->Enabled = false;
	this->step->Enabled = false;
	this->button4->Enabled = true;
	this->button5->Enabled = true;
}
private: void Opening( /*The function is open object*/) {

	this->button1->Enabled = true;
	this->bubble->Enabled = true;
	this->button2->Enabled = false;
	this->select->Enabled = true;
	this->insert->Enabled = true;
	this->shell->Enabled = true;
	this->normal->Enabled = false;
	this->step->Enabled = true;
	this->button4->Enabled = false;
	this->button5->Enabled = false;
}
private: String^ The_digital_unit(const unsigned int steps)
{
	switch (steps)
	{
	case 1:	return "- The " + steps.ToString() + "st Step -";
	case 2:	return "- The " + steps.ToString() + "nd Step -";
	case 3:	return "- The " + steps.ToString() + "rd Step -";
	default:
		return "- The " + steps.ToString() + "th Step -";
		break;
	}
}
private: void updatetextbox(String^ infomation)
{
	//this->textBox1->Text = L"\r\n";
	this->textBox1->AppendText("\r\n" + infomation);
}  
};
}
