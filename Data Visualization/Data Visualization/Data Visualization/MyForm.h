#pragma once

#include "Draw.h"
#include "Header.h"
#include "Variable.h"
#include "Thread.h"

namespace DataVisualization {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	//New namespace
	using namespace Geometric;
	using namespace Process;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
			 :SortStep(0),
			  timekeeping(0),
			  Endpattern(true)
		{
			//Initiallization
			InitializeComponent();
			InitializeComponentSort();
			InitializeComponentLinkedList();
			InitializeComponentTree();
			InitializeComponentAlgorithm();
			
			ShowSort();

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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutThisToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	//sort
	private: System::Windows::Forms::Button^	  Start;
	private: System::Windows::Forms::Button^	  Quit;
	private: System::Windows::Forms::RadioButton^ format1;
	private: System::Windows::Forms::RadioButton^ format2;
	private: System::Windows::Forms::RadioButton^ format1model;
	private: System::Windows::Forms::RadioButton^ format2model;
	private: System::Windows::Forms::GroupBox^	  groupBoxperform;
	private: System::Windows::Forms::GroupBox^	  groupBox2;
	private: System::Windows::Forms::GroupBox^	  groupBox3;
	private: System::Windows::Forms::GroupBox^	  groupBoxsort;
	private: System::Windows::Forms::GroupBox^	  groupBoxsortmodel;
	private: System::Windows::Forms::GroupBox^	  groupBoxsortStepmodel;
	private: System::Windows::Forms::Button^	  Backward;
	private: System::Windows::Forms::Button^	  Forward;
	private: System::Windows::Forms::TextBox^	  Time;
	private: System::Windows::Forms::TextBox^	  ExchangeInfo;

	private: System::Windows::Forms::RadioButton^ Bubble;
	private: System::Windows::Forms::RadioButton^ Select;
	private: System::Windows::Forms::RadioButton^ Insert;
	private: System::Windows::Forms::RadioButton^ Shell;
	private: System::Windows::Forms::RadioButton^ Quick;
	private: System::Windows::Forms::RadioButton^ Heap;
	private: System::Windows::Forms::RadioButton^ Merge;

	private: System::Windows::Forms::Label^	 label1;
	private: System::Windows::Forms::Label^	 label2;
	private: System::Windows::Forms::Label^	 label3;
	private: System::Windows::Forms::Label^	 label4;
	private: System::Windows::Forms::Label^	 label5;
	private: System::Windows::Forms::Label^	 label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  timer1;

	//LinkedList
	private: System::Windows::Forms::Label^	  labelOriginalData;
	private: System::Windows::Forms::Label^	  labelResultData;
	private: System::Windows::Forms::TextBox^	  OriginalData;
	private: System::Windows::Forms::TextBox^	  ResultData;
	private: System::Windows::Forms::GroupBox^	  groupBox4;
	private: System::Windows::Forms::GroupBox^	  groupBox5;
	private: System::Windows::Forms::GroupBox^	  groupBox6;
	private: System::Windows::Forms::Button^	  Create;
	private: System::Windows::Forms::Button^	  Search;
	private: System::Windows::Forms::Button^	  Delete;
	private: System::Windows::Forms::Button^	  Reverse;
	private: System::Windows::Forms::Button^	  InsertLink;
	private: System::Windows::Forms::TextBox^	  TextCreate;
	private: System::Windows::Forms::TextBox^	  TextSearch;
	private: System::Windows::Forms::TextBox^	  TextDelete;
	private: System::Windows::Forms::TextBox^	  TextReverse;
	private: System::Windows::Forms::TextBox^	  TextInsert;
	private: System::Windows::Forms::RadioButton^ format3;
	private: System::Windows::Forms::RadioButton^ format4;
	private: System::Windows::Forms::RadioButton^ format5;

	//Tree
	private: System::Windows::Forms::Label^	  labelOriginalDataTree;
	private: System::Windows::Forms::Label^	  labelResultDataTree;
	private: System::Windows::Forms::TextBox^	  OriginalDataTree;
	private: System::Windows::Forms::TextBox^	  ResultDataTree;
	private: System::Windows::Forms::GroupBox^	  groupBox4Tree;
	private: System::Windows::Forms::GroupBox^	  groupBox5Tree;
	private: System::Windows::Forms::GroupBox^	  groupBox6Tree;
	private: System::Windows::Forms::Button^	  CreateTree;
	private: System::Windows::Forms::Button^	  SearchTree;
	private: System::Windows::Forms::Button^	  DeleteTree;
	private: System::Windows::Forms::Button^	  ReverseTree;
	private: System::Windows::Forms::Button^	  InsertLinkTree;
	private: System::Windows::Forms::TextBox^	  TextCreateTree;
	private: System::Windows::Forms::TextBox^	  TextSearchTree;
	private: System::Windows::Forms::TextBox^	  TextDeleteTree;
	private: System::Windows::Forms::TextBox^	  TextReverseTree;
	private: System::Windows::Forms::TextBox^	  TextInsertTree;
	private: System::Windows::Forms::RadioButton^ format3Tree;
	private: System::Windows::Forms::RadioButton^ format4Tree;
	private: System::Windows::Forms::RadioButton^ format5Tree;

	//Algorithm
	private: System::Windows::Forms::Label^	  labelOriginalDataAlgorithm;
	private: System::Windows::Forms::Label^	  labelResultDataAlgorithm;
	private: System::Windows::Forms::TextBox^	  OriginalDataAlgorithm;
	private: System::Windows::Forms::TextBox^	  ResultDataAlgorithm;
	private: System::Windows::Forms::GroupBox^	  groupBox4Algorithm;
	private: System::Windows::Forms::GroupBox^	  groupBox5Algorithm;
	private: System::Windows::Forms::GroupBox^	  groupBox6Algorithm;
	private: System::Windows::Forms::Button^	  CreateAlgorithm;
	private: System::Windows::Forms::Button^	  SearchAlgorithm;
	private: System::Windows::Forms::Button^	  DeleteAlgorithm;
	private: System::Windows::Forms::Button^	  ReverseAlgorithm;
	private: System::Windows::Forms::Button^	  InsertLinkAlgorithm;
	private: System::Windows::Forms::TextBox^	  TextCreateAlgorithm;
	private: System::Windows::Forms::TextBox^	  TextSearchAlgorithm;
	private: System::Windows::Forms::TextBox^	  TextDeleteAlgorithm;
	private: System::Windows::Forms::TextBox^	  TextReverseAlgorithm;
	private: System::Windows::Forms::TextBox^	  TextInsertAlgorithm;
	private: System::Windows::Forms::RadioButton^ format3Algorithm;
	private: System::Windows::Forms::RadioButton^ format4Algorithm;
	private: System::Windows::Forms::RadioButton^ format5Algorithm;
	private: System::Windows::Forms::PictureBox^  pictureBoxAlgorithm;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//sort
		//about repaint
		System::Drawing::Bitmap^   bitmap;
		System::Drawing::Graphics^ myGraphics;				// draw	
		HANDLE hThread1;									// thread for update sort

		//about rectangular
		System::Drawing::Bitmap^ canvas;					// board
		System::Drawing::Brush^  brush;					   // when don't data interchange
		System::Drawing::Brush^  brushChange;				// when data interchange
		System::Drawing::Pen^    pen;						// line 

	    //about DottedLine
		System::Drawing::Pen^    penDottedLine;				// dotted line

		//about coordinates
		System::Drawing::Pen^    penCoordinates;			// coordinates 

		//about text
		System::Drawing::Font^   font;						// text data

		//about step pattern
		unsigned int SortStep;							    // the step of sort
		bool  Endpattern;									// exit single-step mode

		//about time
		unsigned int timekeeping;
		
		//Algorithm
		System::Threading::Thread^ threadAlgorithm;			// thread for update Draw
		HANDLE hThread2;									// thread for update move object in Algorithm

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutThisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1084, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(53, 21);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutThisToolStripMenuItem });
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(55, 21);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// aboutThisToolStripMenuItem
			// 
			this->aboutThisToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->aboutThisToolStripMenuItem->Name = L"aboutThisToolStripMenuItem";
			this->aboutThisToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->aboutThisToolStripMenuItem->Text = L"About This";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Control;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Sort", L"LinkedList", L"Tree", L"Algorithm" });
			this->comboBox1->Location = System::Drawing::Point(916, 28);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(163, 27);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 6;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1084, 907);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Data Visualization";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma region Sort
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponentSort(Void)
		{
			//
			// Sort
			//
			this->format1 = (gcnew System::Windows::Forms::RadioButton());
			this->format2 = (gcnew System::Windows::Forms::RadioButton());
			this->format1model = (gcnew System::Windows::Forms::RadioButton());
			this->format2model = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxperform = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxsort = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxsortmodel = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxsortStepmodel = (gcnew System::Windows::Forms::GroupBox());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->Quit = (gcnew System::Windows::Forms::Button());
			this->Backward = (gcnew System::Windows::Forms::Button());
			this->Forward = (gcnew System::Windows::Forms::Button());
			this->Bubble = (gcnew System::Windows::Forms::RadioButton());
			this->Select = (gcnew System::Windows::Forms::RadioButton());
			this->Insert = (gcnew System::Windows::Forms::RadioButton());
			this->Shell = (gcnew System::Windows::Forms::RadioButton());
			this->Quick = (gcnew System::Windows::Forms::RadioButton());
			this->Heap = (gcnew System::Windows::Forms::RadioButton());
			this->Merge = (gcnew System::Windows::Forms::RadioButton());
			this->Time = (gcnew System::Windows::Forms::TextBox());	
			this->ExchangeInfo = (gcnew System::Windows::Forms::TextBox());

			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();

			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());

			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Location = System::Drawing::Point(915, 60);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(165, 845);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Class";
			//
			// select
			//
			this->format1->Enabled = false;
			this->format1->AutoSize = true;
			this->format1->Location = System::Drawing::Point(18, 22);
			this->format1->Name = L"format1";
			this->format1->Size = System::Drawing::Size(95, 16);
			this->format1->TabIndex = 0;
			this->format1->TabStop = true;
			this->format1->Text = L"Points";
			this->format1->UseVisualStyleBackColor = true;

			this->format2->AutoSize = true;
			this->format2->Location = System::Drawing::Point(18, 50);
			this->format2->Name = L"format2";
			this->format2->Size = System::Drawing::Size(95, 16);
			this->format2->TabIndex = 0;
			this->format2->TabStop = true;
			this->format2->Text = L"Cylindrical";
			this->format2->UseVisualStyleBackColor = true;

			this->format1model->AutoSize = true;
			this->format1model->Location = System::Drawing::Point(18, 22);
			this->format1model->Name = L"format1model";
			this->format1model->Size = System::Drawing::Size(95, 16);
			this->format1model->TabIndex = 0;
			this->format1model->TabStop = true;
			this->format1model->Text = L"Normal";
			this->format1model->UseVisualStyleBackColor = true;

			this->format2model->AutoSize = true;
			this->format2model->Location = System::Drawing::Point(18, 50);
			this->format2model->Name = L"format2model";
			this->format2model->Size = System::Drawing::Size(95, 16);
			this->format2model->TabIndex = 0;
			this->format2model->TabStop = true;
			this->format2model->Text = L"Setp Model";
			this->format2model->UseVisualStyleBackColor = true;

			this->groupBox2->Text = L"";
			this->groupBox2->Visible = false;
			this->groupBox2->Size = System::Drawing::Size(906, 885);
			this->groupBox2->Location = System::Drawing::Point(5, 20);

			this->groupBoxperform->Text = L"Operation";
			this->groupBoxperform->Visible = true;
			this->groupBoxperform->Size = System::Drawing::Size(155, 100);
			this->groupBoxperform->Location = System::Drawing::Point(5, 20);

			this->groupBoxsort->Text = L"Sort";
			this->groupBoxsort->Visible = true;
			this->groupBoxsort->Size = System::Drawing::Size(155, 250);
			this->groupBoxsort->Location = System::Drawing::Point(5, 140);

			this->groupBox3->Text = L"Select";
			this->groupBox3->Size = System::Drawing::Size(155, 80);
			this->groupBox3->Location = System::Drawing::Point(5, 410);

			this->groupBoxsortmodel->Text = L"Model";
			this->groupBoxsortmodel->Visible = true;
			this->groupBoxsortmodel->Size = System::Drawing::Size(155, 80);
			this->groupBoxsortmodel->Location = System::Drawing::Point(5, 510); 

			this->groupBoxsortStepmodel->Text = L"Setp Model";
			this->groupBoxsortStepmodel->Visible = true;
			this->groupBoxsortStepmodel->Size = System::Drawing::Size(155, 80);
			this->groupBoxsortStepmodel->Location = System::Drawing::Point(5, 610);

			this->Backward->Enabled = false;
			this->Backward->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Backward->Location = System::Drawing::Point(55, 15);
			this->Backward->Name = L"Backward";
			this->Backward->Size = System::Drawing::Size(82, 23);
			this->Backward->TabIndex = 7;
			this->Backward->Text = L"Backward";
			this->Backward->UseVisualStyleBackColor = true;
			//this->Backward->Click += gcnew System::EventHandler(this, &MyForm::Backward_Click);

			this->Forward->Enabled = false;
			this->Forward->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Forward->Location = System::Drawing::Point(55, 48);
			this->Forward->Name = L"Forward";
			this->Forward->Size = System::Drawing::Size(82, 23);
			this->Forward->TabIndex = 7;
			this->Forward->Text = L"Forward";
			this->Forward->UseVisualStyleBackColor = true;
			//this->Forward->Click += gcnew System::EventHandler(this, &MyForm::Forward_Click);
			
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(890, 565);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);

			//nums
			this->label1->Text = L"0";
			this->label1->Size = System::Drawing::Size(20, 20);
			this->label1->Location = System::Drawing::Point(77 , 600);

			this->label2->Text = L"1";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->Location = System::Drawing::Point(77 + 60, 600);

			this->label3->Text = L"2";
			this->label3->Size = System::Drawing::Size(20, 20);
			this->label3->Location = System::Drawing::Point(77 + 60 * 2, 600);

			this->label4->Text = L"3";
			this->label4->Size = System::Drawing::Size(20, 20);
			this->label4->Location = System::Drawing::Point(77 + 60 * 3, 600);

			this->label5->Text = L"4";
			this->label5->Size = System::Drawing::Size(20, 20);
			this->label5->Location = System::Drawing::Point(77 + 60 * 4, 600);

			this->label6->Text = L"5";
			this->label6->Size = System::Drawing::Size(20, 20);
			this->label6->Location = System::Drawing::Point(77 + 60 * 5, 600);

			this->label7->Text = L"6";
			this->label7->Size = System::Drawing::Size(20, 20);
			this->label7->Location = System::Drawing::Point(77 + 60 * 6, 600);

			this->label8->Text = L"7";
			this->label8->Size = System::Drawing::Size(20, 20);
			this->label8->Location = System::Drawing::Point(77 + 60 * 7, 600);

			this->label9->Text = L"8";
			this->label9->Size = System::Drawing::Size(20, 20);
			this->label9->Location = System::Drawing::Point(77 + 60 * 8, 600);

			this->label10->Text = L"9";
			this->label10->Size = System::Drawing::Size(20, 20);
			this->label10->Location = System::Drawing::Point(77 + 60 * 9, 600);

			this->label11->Text = L"10";
			this->label11->Size = System::Drawing::Size(20, 20);
			this->label11->Location = System::Drawing::Point(77 + 60 * 10, 600);

			this->label12->Text = L"11";
			this->label12->Size = System::Drawing::Size(20, 20);
			this->label12->Location = System::Drawing::Point(77 + 60 * 11, 600);

			this->label13->Text = L"12";
			this->label13->Size = System::Drawing::Size(20, 20);
			this->label13->Location = System::Drawing::Point(77 + 60 * 12, 600);

			//start
			this->Start->Name = L"Start";
			this->Start->Location = System::Drawing::Point(18, 20);
			this->Start->Size = System::Drawing::Size(120, 25);
			this->Start->Text = L"Start";
			this->Start->Click += gcnew System::EventHandler(this, &MyForm::Start_Click);

			//Quit
			this->Quit->Name = L"Quit";
			this->Quit->Location = System::Drawing::Point(18, 60);
			this->Quit->Size = System::Drawing::Size(120, 25);
			this->Quit->Text = L"Quit";

			//bubble
			this->Bubble->Name = L"Bubble";
			this->Bubble->Location = System::Drawing::Point(18, 20);
			this->Bubble->Size = System::Drawing::Size(120, 25);
			this->Bubble->Text = L"Bubble";

			//select
			this->Select->Name = L"Select";
			this->Select->Location = System::Drawing::Point(18, 50);
			this->Select->Size = System::Drawing::Size(120, 25);
			this->Select->Text = L"Select";

			//insert
			this->Insert->Name = L"Insert";
			this->Insert->Location = System::Drawing::Point(18, 80);
			this->Insert->Size = System::Drawing::Size(120, 25);
			this->Insert->Text = L"Insert";
			
			//shell
			this->Shell->Name = L"Shell";
			this->Shell->Location = System::Drawing::Point(18, 110);
			this->Shell->Size = System::Drawing::Size(120, 25);
			this->Shell->Text = L"Shell";
			
			//quick
			this->Quick->Name = L"Quick";
			this->Quick->Location = System::Drawing::Point(18, 140);
			this->Quick->Size = System::Drawing::Size(120, 25);
			this->Quick->Text = L"Quick";

			//heap
			this->Heap->Name = L"Heap";
			this->Heap->Location = System::Drawing::Point(18, 170);
			this->Heap->Size = System::Drawing::Size(120, 25);
			this->Heap->Text = L"Heap";

			//merge
			this->Merge->Name = L"Merge";
			this->Merge->Location = System::Drawing::Point(18, 200);
			this->Merge->Size = System::Drawing::Size(120, 25);
			this->Merge->Text = L"Merge";

			//time
			this->Time->Name = L"Time";
			this->Time->Location = System::Drawing::Point(5, 710);
			this->Time->Size = System::Drawing::Size(155, 130);
			this->Time->BackColor = System::Drawing::Color::White;
			this->Time->Multiline = true;

			//ExchangeInfo
			this->ExchangeInfo->Name = L"ExchangeInfo";
			this->ExchangeInfo->Location = System::Drawing::Point(5, 710);
			this->ExchangeInfo->Size = System::Drawing::Size(895, 170);
			this->ExchangeInfo->BackColor = System::Drawing::Color::White;
			this->ExchangeInfo->Multiline = true;

			this->groupBoxperform->Controls->Add(this->Start);
			this->groupBoxperform->Controls->Add(this->Quit);

			this->groupBoxsort->Controls->Add(this->Bubble);
			this->groupBoxsort->Controls->Add(this->Select);
			this->groupBoxsort->Controls->Add(this->Insert);
			this->groupBoxsort->Controls->Add(this->Shell);
			this->groupBoxsort->Controls->Add(this->Quick);
			this->groupBoxsort->Controls->Add(this->Heap);
			this->groupBoxsort->Controls->Add(this->Merge);
			this->groupBoxsort->Controls->Add(this->Time);

			this->groupBoxsortmodel->Controls->Add(this->format1model);
			this->groupBoxsortmodel->Controls->Add(this->format2model);

			this->groupBoxsortStepmodel->Controls->Add(this->Backward);
			this->groupBoxsortStepmodel->Controls->Add(this->Forward);

			this->groupBox3->Controls->Add(this->format1);
			this->groupBox3->Controls->Add(this->format2);

			this->groupBox1->Controls->Add(this->groupBoxperform);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBoxsortmodel);
			this->groupBox1->Controls->Add(this->groupBoxsort);
			this->groupBox1->Controls->Add(this->groupBoxsortStepmodel);
			this->groupBox1->Controls->Add(this->Time);

			this->groupBox2->Controls->Add(this->pictureBox1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->ExchangeInfo);
		}
		void ShowSort(Void)
		{
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();

			//SET
			this->Focus();

			//open
			this->groupBox1->Visible = true;
			this->groupBox1->Enabled = true;
			this->groupBox2->Visible = true;
			this->groupBox2->Enabled = true;

			//close LinkedList
			this->groupBox4->Visible = false;
			this->groupBox4->Enabled = false;
			this->groupBox5->Visible = false;
			this->groupBox5->Enabled = false;

			//close Tree
			this->groupBox4Tree->Visible = false;
			this->groupBox4Tree->Enabled = false;
			this->groupBox5Tree->Visible = false;
			this->groupBox5Tree->Enabled = false;

			//close Algorithm
			this->groupBox4Algorithm->Visible = false;
			this->groupBox4Algorithm->Enabled = false;
			this->groupBox5Algorithm->Visible = false;
			this->groupBox5Algorithm->Enabled = false;
		}
#pragma endregion

#pragma region LinkedList
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponentLinkedList(Void)
		{
			//
			// LinkedList
			//
			this->TextCreate = (gcnew System::Windows::Forms::TextBox());
			this->TextDelete = (gcnew System::Windows::Forms::TextBox());
			this->TextReverse = (gcnew System::Windows::Forms::TextBox());
			this->TextSearch = (gcnew System::Windows::Forms::TextBox());
			this->TextInsert = (gcnew System::Windows::Forms::TextBox());
			this->Create = (gcnew System::Windows::Forms::Button());
			this->Search = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Reverse = (gcnew System::Windows::Forms::Button());
			this->InsertLink = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->OriginalData = (gcnew System::Windows::Forms::TextBox());
			this->ResultData = (gcnew System::Windows::Forms::TextBox());
			this->labelOriginalData = (gcnew System::Windows::Forms::Label());
			this->labelResultData = (gcnew System::Windows::Forms::Label());
			this->format3 = (gcnew System::Windows::Forms::RadioButton());
			this->format4 = (gcnew System::Windows::Forms::RadioButton());
			this->format5 = (gcnew System::Windows::Forms::RadioButton());

			//
			// select
			//
			this->format3->AutoSize = true;
			this->format3->Location = System::Drawing::Point(3, 22);
			this->format3->Name = L"format3";
			this->format3->Size = System::Drawing::Size(85, 16);
			this->format3->TabIndex = 0;
			this->format3->TabStop = true;
			this->format3->Text = L"Singly Linked List";
			this->format3->UseVisualStyleBackColor = true;

			this->format4->AutoSize = true;
			this->format4->Location = System::Drawing::Point(3, 50);
			this->format4->Name = L"format4";
			this->format4->Size = System::Drawing::Size(85, 16);
			this->format4->TabIndex = 0;
			this->format4->TabStop = true;
			this->format4->Text = L"Doubly linked List";
			this->format4->UseVisualStyleBackColor = true;

			this->format5->AutoSize = true;
			this->format5->Location = System::Drawing::Point(3, 78);
			this->format5->Name = L"format5";
			this->format5->Size = System::Drawing::Size(85, 16);
			this->format5->TabIndex = 0;
			this->format5->TabStop = true;
			this->format5->Text = L"Circular linked list ";
			this->format5->UseVisualStyleBackColor = true;

			this->groupBox6->Text = L"Select";
			this->groupBox6->Size = System::Drawing::Size(152, 110);
			this->groupBox6->Location = System::Drawing::Point(2, 445);

			//TextCreate
			this->TextCreate->Name = L"TextCreate";
			this->TextCreate->Location = System::Drawing::Point(105, 21);
			this->TextCreate->Size = System::Drawing::Size(33,32);
			this->TextCreate->BackColor = System::Drawing::Color::White;

			//TextSearch
			this->TextSearch->Name = L"TextSearch";
			this->TextSearch->Location = System::Drawing::Point(105, 71);
			this->TextSearch->Size = System::Drawing::Size(33, 32);
			this->TextSearch->BackColor = System::Drawing::Color::White;

			//TextDelete
			this->TextDelete->Name = L"TextDelete";
			this->TextDelete->Location = System::Drawing::Point(105, 121);
			this->TextDelete->Size = System::Drawing::Size(33, 32);
			this->TextDelete->BackColor = System::Drawing::Color::White;

			//TextReverse
			this->TextReverse->Text = L"True";
			this->TextReverse->Enabled = false;
			this->TextReverse->Name = L"TextReverse";
			this->TextReverse->Location = System::Drawing::Point(105, 171);
			this->TextReverse->Size = System::Drawing::Size(33, 32);
			this->TextReverse->BackColor = System::Drawing::Color::White;

			//TextDelete
			this->TextInsert->Name = L"TextInsert";
			this->TextInsert->Location = System::Drawing::Point(105, 221);
			this->TextInsert->Size = System::Drawing::Size(33, 32);
			this->TextInsert->BackColor = System::Drawing::Color::White;

			//Create
			this->Create->Name = L"Create";
			this->Create->Location = System::Drawing::Point(20, 20);
			this->Create->Size = System::Drawing::Size(80, 25);
			this->Create->Text = L"Create";
			this->Create->Click += gcnew System::EventHandler(this, &MyForm::Create_Click);

			//Search
			this->Search->Name = L"Search";
			this->Search->Location = System::Drawing::Point(20, 70);
			this->Search->Size = System::Drawing::Size(80, 25);
			this->Search->Text = L"Search";
			this->Search->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);

			//Delete
			this->Delete->Name = L"Delete";
			this->Delete->Location = System::Drawing::Point(20, 120);
			this->Delete->Size = System::Drawing::Size(80, 25);
			this->Delete->Text = L"Delete";
			this->Delete->Click += gcnew System::EventHandler(this, &MyForm::Delete_Click);

			//Reverse
			this->Reverse->Name = L"Reverse";
			this->Reverse->Location = System::Drawing::Point(20, 170);
			this->Reverse->Size = System::Drawing::Size(80, 25);
			this->Reverse->Text = L"Reverse";
			this->Reverse->Click += gcnew System::EventHandler(this, &MyForm::Reverse_Click);

			//InsertLink
			this->InsertLink->Name = L"InsertLink";
			this->InsertLink->Location = System::Drawing::Point(20, 220);
			this->InsertLink->Size = System::Drawing::Size(80, 25);
			this->InsertLink->Text = L"Insert";
			this->InsertLink->Click += gcnew System::EventHandler(this, &MyForm::InsertLink_Click);
			
			// 
			// groupBox1
			// 
			this->groupBox5->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox5->Location = System::Drawing::Point(757, 10);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(150, 565);
			this->groupBox5->TabIndex = 3;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Class";

			// 
			// groupBox4
			// 
			this->groupBox4->Location = System::Drawing::Point(5, 20);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(682, 600);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			
			//
			//
			//
			this->labelOriginalData->Text = L"Original :";
			this->labelOriginalData->Name = L"OriginalData";
			this->labelOriginalData->Size = System::Drawing::Size(120, 20);
			this->labelOriginalData->Location = System::Drawing::Point(5,10);
			this->labelOriginalData->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			//
			//
			//
			this->labelResultData->Text = L"Result :";
			this->labelResultData->Name = L"ResultData";
			this->labelResultData->Size = System::Drawing::Size(120, 20);
			this->labelResultData->Location = System::Drawing::Point(5,300);
			this->labelResultData->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			//
			// OriginalData
			//
			this->OriginalData->ReadOnly = true;
			this->OriginalData->Name = L"OriginalData";
			this->OriginalData->Location = System::Drawing::Point(5, 30);
			this->OriginalData->Size = System::Drawing::Size(670, 270);
			this->OriginalData->BackColor = System::Drawing::Color::White;
			this->OriginalData->Multiline = true;
			
			//
			// ResultData
			//
			this->ResultData->ReadOnly = true;
			this->ResultData->Name = L"ResultData";
			this->ResultData->Location = System::Drawing::Point(5, 320);
			this->ResultData->Size = System::Drawing::Size(670, 270);
			this->ResultData->BackColor = System::Drawing::Color::White;
			this->ResultData->Multiline = true;

			this->groupBox4->Controls->Add(OriginalData);
			this->groupBox4->Controls->Add(ResultData);
			this->groupBox4->Controls->Add(labelOriginalData);
			this->groupBox4->Controls->Add(labelResultData);

			this->groupBox5->Controls->Add(Create);
			this->groupBox5->Controls->Add(Search);
			this->groupBox5->Controls->Add(Delete);
			this->groupBox5->Controls->Add(Reverse);
			this->groupBox5->Controls->Add(InsertLink);
			this->groupBox5->Controls->Add(this->groupBox6);

			this->groupBox5->Controls->Add(TextCreate);
			this->groupBox5->Controls->Add(TextSearch);
			this->groupBox5->Controls->Add(TextDelete);
			this->groupBox5->Controls->Add(TextReverse);
			this->groupBox5->Controls->Add(TextInsert);

			this->groupBox6->Controls->Add(format3);
			this->groupBox6->Controls->Add(format4);
			this->groupBox6->Controls->Add(format5);
		}
		void ShowLinkedList(Void)
		{
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox5);

			//SET
			this->Focus();

			//open
			this->groupBox4->Visible = true;
			this->groupBox4->Enabled = true;
			this->groupBox5->Visible = true;
			this->groupBox5->Enabled = true;

			//close sort
			this->groupBox1->Visible = false;
			this->groupBox1->Enabled = false;
			this->groupBox2->Visible = false;
			this->groupBox2->Enabled = false;

			//close Tree
			this->groupBox4Tree->Visible = false;
			this->groupBox4Tree->Enabled = false;
			this->groupBox5Tree->Visible = false;
			this->groupBox5Tree->Enabled = false;

			//close Algorithm
			this->groupBox4Algorithm->Visible = false;
			this->groupBox4Algorithm->Enabled = false;
			this->groupBox5Algorithm->Visible = false;
			this->groupBox5Algorithm->Enabled = false;
		}
#pragma endregion

#pragma region Tree
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponentTree(Void)
		{
			//
			// Tree
			//
			this->TextCreateTree = (gcnew System::Windows::Forms::TextBox());
			this->TextDeleteTree = (gcnew System::Windows::Forms::TextBox());
			this->TextReverseTree = (gcnew System::Windows::Forms::TextBox());
			this->TextSearchTree = (gcnew System::Windows::Forms::TextBox());
			this->TextInsertTree = (gcnew System::Windows::Forms::TextBox());
			this->CreateTree = (gcnew System::Windows::Forms::Button());
			this->SearchTree = (gcnew System::Windows::Forms::Button());
			this->DeleteTree = (gcnew System::Windows::Forms::Button());
			this->ReverseTree = (gcnew System::Windows::Forms::Button());
			this->InsertLinkTree = (gcnew System::Windows::Forms::Button());
			this->groupBox4Tree = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5Tree = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6Tree = (gcnew System::Windows::Forms::GroupBox());
			this->OriginalDataTree = (gcnew System::Windows::Forms::TextBox());
			this->ResultDataTree = (gcnew System::Windows::Forms::TextBox());
			this->labelOriginalDataTree = (gcnew System::Windows::Forms::Label());
			this->labelResultDataTree = (gcnew System::Windows::Forms::Label());
			this->format3Tree = (gcnew System::Windows::Forms::RadioButton());
			this->format4Tree = (gcnew System::Windows::Forms::RadioButton());
			this->format5Tree = (gcnew System::Windows::Forms::RadioButton());

			//
			// select
			//
			this->format3Tree->AutoSize = true;
			this->format3Tree->Location = System::Drawing::Point(3, 22);
			this->format3Tree->Name = L"format3Tree";
			this->format3Tree->Size = System::Drawing::Size(85, 16);
			this->format3Tree->TabIndex = 0;
			this->format3Tree->TabStop = true;
			this->format3Tree->Text = L"Singly Linked List";
			this->format3Tree->UseVisualStyleBackColor = true;

			this->format4Tree->AutoSize = true;
			this->format4Tree->Location = System::Drawing::Point(3, 50);
			this->format4Tree->Name = L"format4Tree";
			this->format4Tree->Size = System::Drawing::Size(85, 16);
			this->format4Tree->TabIndex = 0;
			this->format4Tree->TabStop = true;
			this->format4Tree->Text = L"Doubly linked List";
			this->format4Tree->UseVisualStyleBackColor = true;

			this->format5Tree->AutoSize = true;
			this->format5Tree->Location = System::Drawing::Point(3, 78);
			this->format5Tree->Name = L"format5Tree";
			this->format5Tree->Size = System::Drawing::Size(85, 16);
			this->format5Tree->TabIndex = 0;
			this->format5Tree->TabStop = true;
			this->format5Tree->Text = L"Circular linked list ";
			this->format5Tree->UseVisualStyleBackColor = true;

			this->groupBox6Tree->Text = L"Select";
			this->groupBox6Tree->Size = System::Drawing::Size(152, 110);
			this->groupBox6Tree->Location = System::Drawing::Point(2, 445);

			//TextCreate
			this->TextCreateTree->Name = L"TextCreateTree";
			this->TextCreateTree->Location = System::Drawing::Point(105, 21);
			this->TextCreateTree->Size = System::Drawing::Size(33, 32);
			this->TextCreateTree->BackColor = System::Drawing::Color::White;

			//TextSearch
			this->TextSearchTree->Name = L"TextSearchTree";
			this->TextSearchTree->Location = System::Drawing::Point(105, 71);
			this->TextSearchTree->Size = System::Drawing::Size(33, 32);
			this->TextSearchTree->BackColor = System::Drawing::Color::White;

			//TextDelete
			this->TextDeleteTree->Name = L"TextDeleteTree";
			this->TextDeleteTree->Location = System::Drawing::Point(105, 121);
			this->TextDeleteTree->Size = System::Drawing::Size(33, 32);
			this->TextDeleteTree->BackColor = System::Drawing::Color::White;

			//TextReverse
			this->TextReverseTree->Text = L"True";
			this->TextReverseTree->Enabled = false;
			this->TextReverseTree->Name = L"TextReverseTree";
			this->TextReverseTree->Location = System::Drawing::Point(105, 171);
			this->TextReverseTree->Size = System::Drawing::Size(33, 32);
			this->TextReverseTree->BackColor = System::Drawing::Color::White;

			//TextDelete
			this->TextInsertTree->Name = L"TextInsertTree";
			this->TextInsertTree->Location = System::Drawing::Point(105, 221);
			this->TextInsertTree->Size = System::Drawing::Size(33, 32);
			this->TextInsertTree->BackColor = System::Drawing::Color::White;

			//Create
			this->CreateTree->Name = L"CreateTree";
			this->CreateTree->Location = System::Drawing::Point(20, 20);
			this->CreateTree->Size = System::Drawing::Size(80, 25);
			this->CreateTree->Text = L"Create Tree";
			this->CreateTree->Click += gcnew System::EventHandler(this, &MyForm::Create_Click);

			//Search
			this->SearchTree->Name = L"SearchTree";
			this->SearchTree->Location = System::Drawing::Point(20, 70);
			this->SearchTree->Size = System::Drawing::Size(80, 25);
			this->SearchTree->Text = L"Search Tree";
			this->SearchTree->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);

			//Delete
			this->DeleteTree->Name = L"DeleteTree";
			this->DeleteTree->Location = System::Drawing::Point(20, 120);
			this->DeleteTree->Size = System::Drawing::Size(80, 25);
			this->DeleteTree->Text = L"Tree";
			this->DeleteTree->Click += gcnew System::EventHandler(this, &MyForm::Delete_Click);

			//Reverse
			this->ReverseTree->Name = L"ReverseTree";
			this->ReverseTree->Location = System::Drawing::Point(20, 170);
			this->ReverseTree->Size = System::Drawing::Size(80, 25);
			this->ReverseTree->Text = L"Reverse Tree";
			this->ReverseTree->Click += gcnew System::EventHandler(this, &MyForm::Reverse_Click);

			//InsertLink
			this->InsertLinkTree->Name = L"InsertLinkTree";
			this->InsertLinkTree->Location = System::Drawing::Point(20, 220);
			this->InsertLinkTree->Size = System::Drawing::Size(80, 25);
			this->InsertLinkTree->Text = L"Insert Tree";
			this->InsertLinkTree->Click += gcnew System::EventHandler(this, &MyForm::InsertLink_Click);

			// 
			// groupBox1
			// 
			this->groupBox5Tree->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox5Tree->Location = System::Drawing::Point(757, 10);
			this->groupBox5Tree->Name = L"groupBox5Tree";
			this->groupBox5Tree->Size = System::Drawing::Size(150, 565);
			this->groupBox5Tree->TabIndex = 3;
			this->groupBox5Tree->TabStop = false;
			this->groupBox5Tree->Text = L"Class";

			// 
			// groupBox4
			// 
			this->groupBox4Tree->Location = System::Drawing::Point(5, 20);
			this->groupBox4Tree->Name = L"groupBox4Tree";
			this->groupBox4Tree->Size = System::Drawing::Size(682, 600);
			this->groupBox4Tree->TabIndex = 3;
			this->groupBox4Tree->TabStop = false;

			//
			//
			//
			this->labelOriginalDataTree->Text = L"Original :";
			this->labelOriginalDataTree->Name = L"labelOriginalDataTree";
			this->labelOriginalDataTree->Size = System::Drawing::Size(120, 20);
			this->labelOriginalDataTree->Location = System::Drawing::Point(5, 10);
			this->labelOriginalDataTree->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			//
			//
			//
			this->labelResultDataTree->Text = L"Result :";
			this->labelResultDataTree->Name = L"labelResultDataTree";
			this->labelResultDataTree->Size = System::Drawing::Size(120, 20);
			this->labelResultDataTree->Location = System::Drawing::Point(5, 300);
			this->labelResultDataTree->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			//
			// OriginalData
			//
			this->OriginalDataTree->ReadOnly = true;
			this->OriginalDataTree->Name = L"OriginalDataTree";
			this->OriginalDataTree->Location = System::Drawing::Point(5, 30);
			this->OriginalDataTree->Size = System::Drawing::Size(670, 270);
			this->OriginalDataTree->BackColor = System::Drawing::Color::White;
			this->OriginalDataTree->Multiline = true;

			//
			// ResultData
			//
			this->ResultDataTree->ReadOnly = true;
			this->ResultDataTree->Name = L"ResultDataTree";
			this->ResultDataTree->Location = System::Drawing::Point(5, 320);
			this->ResultDataTree->Size = System::Drawing::Size(670, 270);
			this->ResultDataTree->BackColor = System::Drawing::Color::White;
			this->ResultDataTree->Multiline = true;

			this->groupBox4Tree->Controls->Add(OriginalDataTree);
			this->groupBox4Tree->Controls->Add(ResultDataTree);
			this->groupBox4Tree->Controls->Add(labelOriginalDataTree);
			this->groupBox4Tree->Controls->Add(labelResultDataTree);

			this->groupBox5Tree->Controls->Add(CreateTree);
			this->groupBox5Tree->Controls->Add(SearchTree);
			this->groupBox5Tree->Controls->Add(DeleteTree);
			this->groupBox5Tree->Controls->Add(ReverseTree);
			this->groupBox5Tree->Controls->Add(InsertLinkTree);
			this->groupBox5Tree->Controls->Add(this->groupBox6Tree);

			this->groupBox5Tree->Controls->Add(TextCreateTree);
			this->groupBox5Tree->Controls->Add(TextSearchTree);
			this->groupBox5Tree->Controls->Add(TextDeleteTree);
			this->groupBox5Tree->Controls->Add(TextReverseTree);
			this->groupBox5Tree->Controls->Add(TextInsertTree);

			this->groupBox6Tree->Controls->Add(format3Tree);
			this->groupBox6Tree->Controls->Add(format4Tree);
			this->groupBox6Tree->Controls->Add(format5Tree);
		}
		void ShowTree(Void)
		{
			this->Controls->Add(this->groupBox4Tree);
			this->Controls->Add(this->groupBox5Tree);

			//SET
			this->Focus();

			//open
			this->groupBox4Tree->Visible = true;
			this->groupBox4Tree->Enabled = true;
			this->groupBox5Tree->Visible = true;
			this->groupBox5Tree->Enabled = true;

			//close Sort
			this->groupBox1->Visible = false;
			this->groupBox1->Enabled = false;
			this->groupBox2->Visible = false;
			this->groupBox2->Enabled = false;

			//close LinkedList
			this->groupBox4->Visible = false;
			this->groupBox4->Enabled = false;
			this->groupBox5->Visible = false;
			this->groupBox5->Enabled = false;

			//close Algorithm
			this->groupBox4Algorithm->Visible = false;
			this->groupBox4Algorithm->Enabled = false;
			this->groupBox5Algorithm->Visible = false;
			this->groupBox5Algorithm->Enabled = false;
		}
#pragma endregion

#pragma region Algorithm
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponentAlgorithm(Void)
		{
			//
			// Tree
			//
			this->pictureBoxAlgorithm = (gcnew System::Windows::Forms::PictureBox());
			this->TextCreateAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->TextDeleteAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->TextReverseAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->TextSearchAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->TextInsertAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->CreateAlgorithm = (gcnew System::Windows::Forms::Button());
			this->SearchAlgorithm = (gcnew System::Windows::Forms::Button());
			this->DeleteAlgorithm = (gcnew System::Windows::Forms::Button());
			this->ReverseAlgorithm = (gcnew System::Windows::Forms::Button());
			this->InsertLinkAlgorithm = (gcnew System::Windows::Forms::Button());
			this->groupBox4Algorithm = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5Algorithm = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6Algorithm = (gcnew System::Windows::Forms::GroupBox());
			this->OriginalDataAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->ResultDataAlgorithm = (gcnew System::Windows::Forms::TextBox());
			this->labelOriginalDataAlgorithm = (gcnew System::Windows::Forms::Label());
			this->labelResultDataAlgorithm = (gcnew System::Windows::Forms::Label());
			this->format3Algorithm = (gcnew System::Windows::Forms::RadioButton());
			this->format4Algorithm = (gcnew System::Windows::Forms::RadioButton());
			this->format5Algorithm = (gcnew System::Windows::Forms::RadioButton());

			// 
			// pictureBoxAlgorithm
			// 
			this->pictureBoxAlgorithm->BackColor = System::Drawing::Color::White;
			this->pictureBoxAlgorithm->Location = System::Drawing::Point(8, 10);
			this->pictureBoxAlgorithm->Name = L"pictureBoxAlgorithm";
			this->pictureBoxAlgorithm->Size = System::Drawing::Size(667, 585);
			this->pictureBoxAlgorithm->TabIndex = 1;
			this->pictureBoxAlgorithm->TabStop = false;
			this->pictureBoxAlgorithm->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBoxAlgorithm_Paint);

			//
			// select
			//
			this->format3Algorithm->AutoSize = true;
			this->format3Algorithm->Location = System::Drawing::Point(3, 22);
			this->format3Algorithm->Name = L"Singly";
			this->format3Algorithm->Size = System::Drawing::Size(85, 16);
			this->format3Algorithm->TabIndex = 0;
			this->format3Algorithm->TabStop = true;
			this->format3Algorithm->Text = L"Singly";
			this->format3Algorithm->UseVisualStyleBackColor = true;

			this->format4Algorithm->AutoSize = true;
			this->format4Algorithm->Location = System::Drawing::Point(3, 50);
			this->format4Algorithm->Name = L"Middle";
			this->format4Algorithm->Size = System::Drawing::Size(85, 16);
			this->format4Algorithm->TabIndex = 0;
			this->format4Algorithm->TabStop = true;
			this->format4Algorithm->Text = L"Middle";
			this->format4Algorithm->UseVisualStyleBackColor = true;

			this->format5Algorithm->AutoSize = true;
			this->format5Algorithm->Location = System::Drawing::Point(3, 78);
			this->format5Algorithm->Name = L"Diffcult";
			this->format5Algorithm->Size = System::Drawing::Size(85, 16);
			this->format5Algorithm->TabIndex = 0;
			this->format5Algorithm->TabStop = true;
			this->format5Algorithm->Text = L"Diffcult";
			this->format5Algorithm->UseVisualStyleBackColor = true;

			this->groupBox6Algorithm->Text = L"Select";
			this->groupBox6Algorithm->Size = System::Drawing::Size(152, 110);
			this->groupBox6Algorithm->Location = System::Drawing::Point(2, 445);

			//TextCreate
			this->TextCreateAlgorithm->Name = L"TextCreateAlgorithm";
			this->TextCreateAlgorithm->Location = System::Drawing::Point(105, 21);
			this->TextCreateAlgorithm->Size = System::Drawing::Size(33, 32);
			this->TextCreateAlgorithm->BackColor = System::Drawing::Color::White;

			//TextSearch
			this->TextSearchAlgorithm->Name = L"TextSearchAlgorithm";
			this->TextSearchAlgorithm->Location = System::Drawing::Point(105, 71);
			this->TextSearchAlgorithm->Size = System::Drawing::Size(33, 32);
			this->TextSearchAlgorithm->BackColor = System::Drawing::Color::White;

			//TextDelete
			this->TextDeleteAlgorithm->Name = L"TextDeleteAlgorithm";
			this->TextDeleteAlgorithm->Location = System::Drawing::Point(105, 121);
			this->TextDeleteAlgorithm->Size = System::Drawing::Size(33, 32);
			this->TextDeleteAlgorithm->BackColor = System::Drawing::Color::White;

			//TextReverse
			this->TextReverseAlgorithm->Text = L"True";
			this->TextReverseAlgorithm->Enabled = false;
			this->TextReverseAlgorithm->Name = L"TextReverseAlgorithm";
			this->TextReverseAlgorithm->Location = System::Drawing::Point(105, 171);
			this->TextReverseAlgorithm->Size = System::Drawing::Size(33, 32);
			this->TextReverseAlgorithm->BackColor = System::Drawing::Color::White;

			//TextDelete
			this->TextInsertAlgorithm->Name = L"TextInsertAlgorithm";
			this->TextInsertAlgorithm->Location = System::Drawing::Point(105, 221);
			this->TextInsertAlgorithm->Size = System::Drawing::Size(33, 32);
			this->TextInsertAlgorithm->BackColor = System::Drawing::Color::White;

			//Create
			this->CreateAlgorithm->Name = L"";
			this->CreateAlgorithm->Location = System::Drawing::Point(8, 20);
			this->CreateAlgorithm->Size = System::Drawing::Size(140, 25);
			this->CreateAlgorithm->Text = L"Collision Detection";
			this->CreateAlgorithm->Click += gcnew System::EventHandler(this, &MyForm::CreateAlgorithm_Click);

			//Search
			this->SearchAlgorithm->Name = L"SearchAlgorithm";
			this->SearchAlgorithm->Location = System::Drawing::Point(8, 70);
			this->SearchAlgorithm->Size = System::Drawing::Size(140, 25);
			this->SearchAlgorithm->Text = L"Search Algorithm";
			this->SearchAlgorithm->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);

			//Delete
			this->DeleteAlgorithm->Name = L"DeleteAlgorithm";
			this->DeleteAlgorithm->Location = System::Drawing::Point(8, 120);
			this->DeleteAlgorithm->Size = System::Drawing::Size(140, 25);
			this->DeleteAlgorithm->Text = L"Algorithm";
			this->DeleteAlgorithm->Click += gcnew System::EventHandler(this, &MyForm::Delete_Click);

			//Reverse
			this->ReverseAlgorithm->Name = L"ReverseAlgorithm";
			this->ReverseAlgorithm->Location = System::Drawing::Point(8, 170);
			this->ReverseAlgorithm->Size = System::Drawing::Size(140, 25);
			this->ReverseAlgorithm->Text = L"Reverse Algorithm";
			this->ReverseAlgorithm->Click += gcnew System::EventHandler(this, &MyForm::Reverse_Click);

			//InsertLink
			this->InsertLinkAlgorithm->Name = L"InsertLinkAlgorithm";
			this->InsertLinkAlgorithm->Location = System::Drawing::Point(8, 220);
			this->InsertLinkAlgorithm->Size = System::Drawing::Size(140, 25);
			this->InsertLinkAlgorithm->Text = L"Insert Algorithm";
			this->InsertLinkAlgorithm->Click += gcnew System::EventHandler(this, &MyForm::InsertLink_Click);

			// 
			// groupBox1
			// 
			this->groupBox5Algorithm->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox5Algorithm->Location = System::Drawing::Point(757, 10);
			this->groupBox5Algorithm->Name = L"groupBox5Algorithm";
			this->groupBox5Algorithm->Size = System::Drawing::Size(150, 565);
			this->groupBox5Algorithm->TabIndex = 3;
			this->groupBox5Algorithm->TabStop = false;
			this->groupBox5Algorithm->Text = L"Class";

			// 
			// groupBox4
			// 
			this->groupBox4Algorithm->Location = System::Drawing::Point(5, 20);
			this->groupBox4Algorithm->Name = L"groupBox4Algorithm";
			this->groupBox4Algorithm->Size = System::Drawing::Size(682, 600);
			this->groupBox4Algorithm->TabIndex = 3;
			this->groupBox4Algorithm->TabStop = false;

			//
			//
			//
			this->labelOriginalDataAlgorithm->Text = L"Original :";
			this->labelOriginalDataAlgorithm->Name = L"labelOriginalDataAlgorithm";
			this->labelOriginalDataAlgorithm->Size = System::Drawing::Size(120, 20);
			this->labelOriginalDataAlgorithm->Location = System::Drawing::Point(5, 10);
			this->labelOriginalDataAlgorithm->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			//
			//
			//
			this->labelResultDataAlgorithm->Text = L"Result :";
			this->labelResultDataAlgorithm->Name = L"labelResultDataAlgorithm";
			this->labelResultDataAlgorithm->Size = System::Drawing::Size(120, 20);
			this->labelResultDataAlgorithm->Location = System::Drawing::Point(5, 300);
			this->labelResultDataAlgorithm->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			//
			// OriginalData
			//
			this->OriginalDataAlgorithm->ReadOnly = true;
			this->OriginalDataAlgorithm->Name = L"OriginalDataAlgorithm";
			this->OriginalDataAlgorithm->Location = System::Drawing::Point(5, 30);
			this->OriginalDataAlgorithm->Size = System::Drawing::Size(670, 270);
			this->OriginalDataAlgorithm->BackColor = System::Drawing::Color::White;
			this->OriginalDataAlgorithm->Multiline = true;

			//
			// ResultData
			//
			this->ResultDataAlgorithm->ReadOnly = true;
			this->ResultDataAlgorithm->Name = L"ResultDataAlgorithm";
			this->ResultDataAlgorithm->Location = System::Drawing::Point(5, 320);
			this->ResultDataAlgorithm->Size = System::Drawing::Size(670, 270);
			this->ResultDataAlgorithm->BackColor = System::Drawing::Color::White;
			this->ResultDataAlgorithm->Multiline = true;

			/*this->groupBox4Algorithm->Controls->Add(OriginalDataAlgorithm);
			this->groupBox4Algorithm->Controls->Add(ResultDataAlgorithm);
			this->groupBox4Algorithm->Controls->Add(labelOriginalDataAlgorithm);
			this->groupBox4Algorithm->Controls->Add(labelResultDataAlgorithm);*/

			this->groupBox4Algorithm->Controls->Add(pictureBoxAlgorithm);

			this->groupBox5Algorithm->Controls->Add(CreateAlgorithm);
			this->groupBox5Algorithm->Controls->Add(SearchAlgorithm);
			this->groupBox5Algorithm->Controls->Add(DeleteAlgorithm);
			this->groupBox5Algorithm->Controls->Add(ReverseAlgorithm);
			this->groupBox5Algorithm->Controls->Add(InsertLinkAlgorithm);
			this->groupBox5Algorithm->Controls->Add(this->groupBox6Algorithm);

			/*this->groupBox5Algorithm->Controls->Add(TextCreateAlgorithm);
			this->groupBox5Algorithm->Controls->Add(TextSearchAlgorithm);
			this->groupBox5Algorithm->Controls->Add(TextDeleteAlgorithm);
			this->groupBox5Algorithm->Controls->Add(TextReverseAlgorithm);
			this->groupBox5Algorithm->Controls->Add(TextInsertAlgorithm);*/

			this->groupBox6Algorithm->Controls->Add(format3Algorithm);
			this->groupBox6Algorithm->Controls->Add(format4Algorithm);
			this->groupBox6Algorithm->Controls->Add(format5Algorithm);
		}
		void ShowAlgorithm(Void)
		{
			this->Controls->Add(this->groupBox4Algorithm);
			this->Controls->Add(this->groupBox5Algorithm);

			//SET
			this->Focus();

			//open
			this->groupBox4Algorithm->Visible = true;
			this->groupBox4Algorithm->Enabled = true;
			this->groupBox5Algorithm->Visible = true;
			this->groupBox5Algorithm->Enabled = true;

			//close Sort
			this->groupBox1->Visible = false;
			this->groupBox1->Enabled = false;
			this->groupBox2->Visible = false;
			this->groupBox2->Enabled = false;

			//close LinkedList
			this->groupBox4->Visible = false;
			this->groupBox4->Enabled = false;
			this->groupBox5->Visible = false;
			this->groupBox5->Enabled = false;

			//close Tree
			this->groupBox4Tree->Visible = false;
			this->groupBox4Tree->Enabled = false;
			this->groupBox5Tree->Visible = false;
			this->groupBox5Tree->Enabled = false;
		}
#pragma endregion

#pragma region Event Drive
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox1->Invalidate();
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox1->Invalidate();
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		comboBox1->Text = comboBox1->SelectedItem->ToString();

		//SELECT
		int index = comboBox1->SelectedIndex;
		switch (index)
		{
		case 0:ShowSort(); break;
		case 1:ShowLinkedList(); break;
		case 2:ShowTree(); break;
		case 3:ShowAlgorithm(); break;
		default:
			break;
		}
	}
#pragma region Event Drive

#pragma region  "Sort"
		 /// <summary>
		 /// Some functions about the order.
		 /// Including the thread and drive program
		 /// </summary>
private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {

		MyStruct<SortType> Sortstruct;

		//the start sort
		if (this->format1model->Checked)
		{
			// bubble
			if (this->Bubble->Checked)
			{
				ReadyForSort(0);
			}
			// select
			else if (this->Select->Checked)
			{
				ReadyForSort(1);
			}
			// insert
			else if (this->Insert->Checked)
			{
				ReadyForSort(2);
			}
			//shell
			else if (this->Shell->Checked)
			{
				ReadyForSort(3);
			}
			else if (this->Quick->Checked)
			{
				ReadyForSort(4);
			}
			else if (this->Heap->Checked)
			{
				ReadyForSort(5);
			}
			else if (this->Merge->Checked)
			{
				ReadyForSort(6);
			}
			else
			{
				MessageBox::Show("Please select a sorting way!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information); 
			}
		}
		else if (this->format2model->Checked)
		{
			// bubble
			if (this->Bubble->Checked)
			{
				ReadyForSortUseSecondModel(0);
			}
			// select
			else if (this->Select->Checked)
			{
				ReadyForSortUseSecondModel(1);
			}
			// insert
			else if (this->Insert->Checked)
			{
				ReadyForSortUseSecondModel(2);
			}
			//shell
			else if (this->Shell->Checked)
			{
				ReadyForSortUseSecondModel(3);
			}
			else if (this->Quick->Checked)
			{
				ReadyForSortUseSecondModel(4);
			}
			else if (this->Heap->Checked)
			{
				ReadyForSortUseSecondModel(5);
			}
			else if (this->Merge->Checked)
			{
				ReadyForSortUseSecondModel(6);
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
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	myGraphics = e->Graphics;
	myGraphics->FromImage(bitmap);
	myGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

	// draw sorting process
	if (this->format1model->Checked)
	{
		Geometric::Object arrow;
		vector<long long>::iterator SearchFirst;

		//lock
		WaitForSingleObject(Process::HMutex, INFINITE);

		try
		{
			if (IArraysize.size() != 0 && SortFinished)
			{
				// update the line segment
				System::Drawing::Point Pt1(RECTANGULAR_SPACE * ExchangeIndex[0] + 75, 185 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt2(RECTANGULAR_SPACE * ExchangeIndex[0] + 75, 100 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt3(RECTANGULAR_SPACE * ExchangeIndex[1] + 75, 100 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt4(RECTANGULAR_SPACE * ExchangeIndex[1] + 75, 185 - IArraysize[ExchangeIndex[1]]);

				myGraphics->DrawLine(pen, Pt1, Pt2);
				myGraphics->DrawLine(pen, Pt2, Pt3);
				myGraphics->DrawLine(pen, Pt3, Pt4);

				// update cylindrical
				for (size_t i = 0; i < RECTANGULAR_NUMBER; i++)
				{
					Geometric::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
					if (i == ExchangeIndex[0] || i == ExchangeIndex[1])
					{
						brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Red);
						myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
							int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
					}

					else
					{
						brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
						myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
							int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
					}

					//update dottedLine and text 
					System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
					System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

					myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
					myGraphics->DrawString(IArraysize[i].ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
				}

				myGraphics->DrawImage(bitmap, 0, 0);
				this->pictureBox1->Image = canvas;
			}
			else if (!SortFinished)
			{
				// finally update ui when thread is end.
				for (size_t i = 0; i < RECTANGULAR_NUMBER; i++)
				{
					// update cylindrical
					Geometric::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
					brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
					myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
						int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));

					//update dottedLine and text 
					System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
					System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

					myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
					myGraphics->DrawString(IArraysize[i].ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));

				}

				// update controls
				Opening();

				// update data
				this->timer1->Stop();
				myGraphics->DrawImage(bitmap, 0, 0);
			}
		}
		catch (const std::exception&)
		{
			return;
		}

		//unlock
		ReleaseMutex(HMutex);
	}
	else if (this->format2model->Checked && Endpattern)
	{
		// update ui about the previous step
		System::Drawing::Point Pt1(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep] + 75, 185 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt2(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep] + 75, 100 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt3(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep + 1] + 75, 100 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep]));
		System::Drawing::Point Pt4(RECTANGULAR_SPACE * Every_Step_Of_The_Change[2 * SortStep + 1] + 75, 185 - Every_Step_Of_The_Value.at(SortStep).at(Every_Step_Of_The_Change[2 * SortStep + 1]));

		myGraphics->DrawLine(pen, Pt1, Pt2);
		myGraphics->DrawLine(pen, Pt2, Pt3);
		myGraphics->DrawLine(pen, Pt3, Pt4);

		for (size_t i = 0; i < RECTANGULAR_NUMBER; i++)
		{
			Geometric::Object object(RECTANGULAR_SPACE * i, Every_Step_Of_The_Value.at(SortStep).at(i));

			if (i == Every_Step_Of_The_Change[2 * SortStep] || i == Every_Step_Of_The_Change[2 * SortStep + 1])
			{
				brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Red);
				myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
					int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
			}
			else
			{
				brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
				myGraphics->FillRectangle(brush, int(object.DrawCylindrical().RectangleX), int(object.DrawCylindrical().RectangleY),
					int(object.DrawCylindrical().RectangleWidth), int(object.DrawCylindrical().RectangleHeight));
			}

			//update dottedLine and text 
			System::Drawing::Point Pt5(object.DrawDottedLine().Point1X, object.DrawDottedLine().Point1Y);
			System::Drawing::Point Pt6(object.DrawDottedLine().Point2X, object.DrawDottedLine().Point2Y);

			myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
			myGraphics->DrawString(Every_Step_Of_The_Value.at(SortStep).at(i).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
		}

		this->timer1->Stop();
	}
	else if (!Endpattern)
	{
		myGraphics->Clear(this->pictureBox1->BackColor);
	}

	// draw x-coordinate
	for (size_t i = 0; i < RECTANGULAR_NUMBER; i++)
	{
		System::Drawing::Point Pt1(70 + RECTANGULAR_SPACE * i, this->pictureBox1->Height);
		System::Drawing::Point Pt2(70 + RECTANGULAR_SPACE * i, this->pictureBox1->Height - 7);
		myGraphics->DrawLine(penCoordinates, Pt1, Pt2);
	}

	// draw y-coordinate
	for (size_t i = 0; i < RECTANGULAR_NUMBER - 1; i++)
	{
		System::Drawing::Point Pt1(0, 50 + RECTANGULAR_SPACE * i);
		System::Drawing::Point Pt2(0 + 7, 50 + RECTANGULAR_SPACE * i);
		myGraphics->DrawLine(penCoordinates, Pt1, Pt2);
	}
}
private: void ReadyForSort( /* the function is create object */ const unsigned int SortIndex) {

	MyStruct<SortType> Sortstruct;

	try
	{
		// exit thread and thread1
		while (true)
		{
			if (WaitForSingleObject(hThread1, 0) == WAIT_OBJECT_0 || hThread1 == NULL)
			{
				//close the start button
				Shielding();

				IArraysize.clear();
				SortFinished = true;
				IArraysize = Sortstruct.nums = RandNumbers<SortType>();
				Sortstruct.SortIndex = SortIndex;

				//CloseHandle(hThread1);
				Go(Sortstruct);

				break;
			}
		}
	}
	catch (const std::exception&)
	{
		return;
	}
}
private: void Go( /* the function is create object */ MyStruct<SortType> SortInfo) {

	MYThread<SortType> ThreadInSort(SortInfo.SortIndex, SortInfo.nums, "Normal");
	SleepTime = 150;

	// start two thread ( First is sort,second is display )
	if (SortInfo.nums.size() != NULL)
	{
		try
		{
			HMutex = CreateMutex(NULL, FALSE, LPCWSTR("sort"));
			HANDLE  HandleSort = (HANDLE)_beginthreadex(NULL, 0, ThreadInSort.ThreadOfSort, NULL, 0, NULL);

			this->pictureBox1->Invalidate();
			timer1->Start();
		}
		catch (const std::exception&)
		{
			return;
		}
	}
}

private: void ReadyForSortUseSecondModel( /*the function is create object*/ const unsigned int SortIndex)
{
	Shielding();
	Endpattern = true;
	SleepTime = 10;

	MYThread<SortType> ThreadInSort(SortIndex, RandNumbers<SortType>(), "Step");

	try
	{
		HMutex = CreateMutex(NULL, FALSE, LPCWSTR("sort"));
		HANDLE  HandleSort = (HANDLE)_beginthreadex(NULL, 0, ThreadInSort.ThreadOfSort, NULL, 0, NULL);

		DWORD ReturnStatus = WaitForSingleObject(HandleSort, INFINITE);
		if (ReturnStatus != WAIT_TIMEOUT)
			this->timer1->Start();
	}
	catch (const std::exception&)
	{
		return;
	}
}

private: void Shielding( /*The function is create object*/ ) {
	
	this->Bubble->Enabled = false;
	this->Select->Enabled = false;
	this->Insert->Enabled = false;
	this->Shell->Enabled = false;
	this->Quick->Enabled = false;
	this->Heap->Enabled = false;
	this->Merge->Enabled = false;
	this->format1->Enabled = false;
	this->format2->Enabled = false;
	this->format3->Enabled = false;
}
private: void Opening( /*The function is create object*/) {

	this->Bubble->Enabled = true;
	this->Select->Enabled = true;
	this->Insert->Enabled = true;
	this->Shell->Enabled = true;
	this->Quick->Enabled = true;
	this->Heap->Enabled = true;
	this->Merge->Enabled = true;
	this->format1->Enabled = true;
	this->format2->Enabled = true;
	this->format3->Enabled = true;
}
private: void InitializeText(/*The function is update time*/)
{
	timekeeping += 50;
	this->Time->Text = timekeeping.ToString() + " ms ";
}
private: void HiddenLabel( /*The function is create object*/ ) {
	//this->groupBox2->Enabled = false;  
	this->groupBox2->Visible = true;
}
private: void ShowLabel( /*The function is create object*/){
	this->groupBox2->Visible = true;
	this->groupBox2->Enabled = true;
}
#pragma endregion

#pragma region "LinkedList"
		 /// <summary>
		 /// Some functions about the LinkedList.
		 /// </summary>
private: System::Void Create_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(0);
}
private: System::Void Search_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(1);
}
private: System::Void Delete_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(2);
}
private: System::Void Reverse_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(3);
}
private: System::Void InsertLink_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(4);
}

private:void ReadyForLinkedList(/* start */const unsigned int index)
{
	LinkedList link;

	switch (index)
	{
		case 0: 
			{ 
				if (this->TextCreate->Text=="")
					break;
				else
				{
					if (this->format4->Checked)
					{
						Mylink1 = link.CreateDoubly(Convert::ToInt32(this->TextCreate->Text));

						Result = link.Output1(Mylink1);
						UpdateTextBoxForOriginal(Result);
					}
					else if (this->format3->Checked)
					{
						Mylink = link.Create(Convert::ToInt32(this->TextCreate->Text));

						Result = link.Output(Mylink);
						UpdateTextBoxForOriginal(Result);
					}
					else
					{
						// 
						break;
					}
				}
		    }
			
			break;
			
		case 1: 
			{
				bool b_find;
				if (this->TextSearch->Text=="")
					break;
				else
					b_find = link.SearchIndex(Convert::ToInt32(this->TextSearch->Text), Mylink);

				UpdateTextBoxForResultAboutSearch(b_find);
			}

			break;

		case 2: 
		   {	
				if (this->TextDelete->Text=="")
					break;
				else
					Mylink = link.Remove(Convert::ToInt32(this->TextDelete->Text), Mylink);

				Result = link.Output(Mylink);
				UpdateTextBoxForResultAboutRemove(Result);
		   }

		   break;

		case 3:
		   {
				if (Mylink == NULL)
					break;
				else
					Mylink = link.Reverse(Mylink);
				Result = link.Output(Mylink);
				UpdateTextBoxForResultAboutRemove(Result);
		   }
			
		   break;
		   
		case 4:
		   {
				struct NoteList *Testinsert;
				Testinsert = (struct NoteList *)malloc(sizeof(struct NoteList));
				Testinsert->data = 100;
				Testinsert->next = NULL;

				if (this->TextInsert->Text=="")
					break;
				else
					Mylink = link.Insert(Convert::ToInt32(this->TextInsert->Text), Mylink, Testinsert);
				Result = link.Output(Mylink);
				UpdateTextBoxForResultAboutRemove(Result);
		   }

			break;

		default:
			break;
	}
}
private:void UpdateTextBoxForOriginal(/* start */vector<long long> result)
{
	String^ Textaboutlink;
	for (size_t i = 0; i < result.size(); i++)
	{
		Textaboutlink += result[i].ToString();
		if(i!=result.size()-1)
		  Textaboutlink += ",";
	}

	this->OriginalData->Text = (this->OriginalData->Text=="") ? Textaboutlink: this->OriginalData->Text + "\r\n" + Textaboutlink;
}
private:void UpdateTextBoxForResultAboutRemove(/* start */vector<long long> result)
{
	String^ Textaboutlink;
	for (size_t i = 0; i < result.size(); i++)
	{
		Textaboutlink += result[i].ToString();
		if (i != result.size() - 1)
			Textaboutlink += ",";
	}

	this->ResultData->Text = (this->ResultData->Text == "") ? Textaboutlink : this->ResultData->Text + "\r\n" + Textaboutlink;
}
private:void UpdateTextBoxForResultAboutSearch(/* start */bool result)
{
	String^ Textaboutlink = result ? "Yes!" : "No!";
	this->ResultData->Text = (this->ResultData->Text == "") ? Textaboutlink : this->ResultData->Text + "\r\n" + Textaboutlink;
}
private:void Clear(/* start */)
{
	this->OriginalData->Text = "";
	this->ResultData->Text = "";
}
#pragma endregion

#pragma region "Tree"
		/// <summary>
		/// Some functions about the Tree.
		/// </summary>
#pragma endregion

#pragma region "Algorithm"
		/// <summary>
		/// Some functions about the Algorithm.
		/// </summary>

private: System::Void CreateAlgorithm_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyGo();
}

private: void ReadyGo()
{
	ThreadAboutAlgorithm threadaboutalgorithm;
	myGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

	try
	{
		hThread2 = CreateThread(NULL, 0, threadaboutalgorithm.ThreadOfA, NULL, 0, NULL);
		AMutex = CreateMutex(NULL, FALSE, LPCWSTR("Algorithm"));
	}
	catch (const std::exception&)
	{
		return;
	}
}

private: System::Void pictureBoxAlgorithm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	System::Drawing::Brush^  brush;
	System::Drawing::Graphics^  AloGraphics = e->Graphics;
	System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(this->pictureBoxAlgorithm->Width, this->pictureBoxAlgorithm->Height);
	System::Drawing::Bitmap^ canvas = gcnew System::Drawing::Bitmap(this->pictureBoxAlgorithm->Width, this->pictureBoxAlgorithm->Height);
	AloGraphics->FromImage(bitmap);
	AloGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

	//lock
	WaitForSingleObject(Geometric::AMutex, INFINITE);

	for (size_t i = 0; i < Circlesize; i++)
	{
		if (Collect[i])
			brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
		else
			brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));
	 	
		AloGraphics->FillEllipse(brush, PoxXCircle[i], PoxYCircle[i], CircleW, CircleH);
		
		Collect[i] = true;
	}
	
	AloGraphics->DrawImage(bitmap, 0, 0);
	pictureBoxAlgorithm->BackgroundImage = canvas;

	//unlock
	ReleaseMutex(AMutex);
}

#pragma endregion
};
}
