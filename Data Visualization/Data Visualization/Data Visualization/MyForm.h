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
			:thread(nullptr),
			 hThread1(NULL),
			 hThread2(NULL),
			 timekeeping(0)
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
		    myGraphics = this->pictureBox1->CreateGraphics();
			thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadOfDraw));
			thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadOfDraw));
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
	private: System::Windows::Forms::RadioButton^ format1;
	private: System::Windows::Forms::RadioButton^ format2;
	private: System::Windows::Forms::GroupBox^	  groupBox2;
	private: System::Windows::Forms::GroupBox^	  groupBox3;
	private: System::Windows::Forms::Button^	  Bubble;
	private: System::Windows::Forms::Button^	  Select;
	private: System::Windows::Forms::Button^	  Insert;
	private: System::Windows::Forms::Button^	  Shell;
	private: System::Windows::Forms::Button^	  Quick;
	private: System::Windows::Forms::Button^	  Heap;
	private: System::Windows::Forms::Button^	  Merge;
	private: System::Windows::Forms::TextBox^	  Time;

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

	private: System::Windows::Forms::Label^	 labelNum1;
	private: System::Windows::Forms::Label^	 labelNum2;
	private: System::Windows::Forms::Label^	 labelNum3;
	private: System::Windows::Forms::Label^	 labelNum4;
	private: System::Windows::Forms::Label^	 labelNum5;
	private: System::Windows::Forms::Label^	 labelNum6;
	private: System::Windows::Forms::Label^  labelNum7;
	private: System::Windows::Forms::Label^  labelNum8;
	private: System::Windows::Forms::Label^  labelNum9;
	private: System::Windows::Forms::Label^  labelNum10;
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
		System::Drawing::Graphics^ myGraphics;				// draw	
		System::Threading::Thread^ thread;                  // thread for update Draw
		HANDLE hThread1;									// thread for update sort
		long long timekeeping;								// time for update sort

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
			this->menuStrip1->Size = System::Drawing::Size(860, 25);
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
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Sort", L"LinkedList", L"Tree" ,L"Algorithm"});
			this->comboBox1->Location = System::Drawing::Point(692, 28);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(156, 27);
			this->comboBox1->Text = L"Sort";
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 6;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			//
			this->SetStyle(System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer
				| System::Windows::Forms::ControlStyles::ResizeRedraw
				| System::Windows::Forms::ControlStyles::Selectable
				| System::Windows::Forms::ControlStyles::AllPaintingInWmPaint
				| System::Windows::Forms::ControlStyles::UserPaint
				| System::Windows::Forms::ControlStyles::SupportsTransparentBackColor,
				true);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(860, 622);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::Form_Closing);
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->Bubble = (gcnew System::Windows::Forms::Button());
			this->Select = (gcnew System::Windows::Forms::Button());
			this->Insert = (gcnew System::Windows::Forms::Button());
			this->Shell = (gcnew System::Windows::Forms::Button());
			this->Quick = (gcnew System::Windows::Forms::Button());
			this->Heap = (gcnew System::Windows::Forms::Button());
			this->Merge = (gcnew System::Windows::Forms::Button());
			this->Time = (gcnew System::Windows::Forms::TextBox());
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

			this->labelNum1 = (gcnew System::Windows::Forms::Label());
			this->labelNum2 = (gcnew System::Windows::Forms::Label());
			this->labelNum3 = (gcnew System::Windows::Forms::Label());
			this->labelNum4 = (gcnew System::Windows::Forms::Label());
			this->labelNum5 = (gcnew System::Windows::Forms::Label());
			this->labelNum6 = (gcnew System::Windows::Forms::Label());
			this->labelNum7 = (gcnew System::Windows::Forms::Label());
			this->labelNum8 = (gcnew System::Windows::Forms::Label());
			this->labelNum9 = (gcnew System::Windows::Forms::Label());
			this->labelNum10 = (gcnew System::Windows::Forms::Label());

			this->format1 = (gcnew System::Windows::Forms::RadioButton());
			this->format2 = (gcnew System::Windows::Forms::RadioButton());

			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Location = System::Drawing::Point(692, 56);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(156, 565);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Class";
			//
			// select
			//
			this->format1->AutoSize = true;
			this->format1->Location = System::Drawing::Point(12, 22);
			this->format1->Name = L"format1";
			this->format1->Size = System::Drawing::Size(95, 16);
			this->format1->TabIndex = 0;
			this->format1->TabStop = true;
			this->format1->Text = L"Points";
			this->format1->UseVisualStyleBackColor = true;

			this->format2->AutoSize = true;
			this->format2->Location = System::Drawing::Point(12, 50);
			this->format2->Name = L"format2";
			this->format2->Size = System::Drawing::Size(95, 16);
			this->format2->TabIndex = 0;
			this->format2->TabStop = true;
			this->format2->Text = L"Cylindrical";
			this->format2->UseVisualStyleBackColor = true;

			this->groupBox3->Text = L"Select";
			this->groupBox3->Size = System::Drawing::Size(145, 80);
			this->groupBox3->Location = System::Drawing::Point(5, 370);

			this->groupBox2->Text = L"";
			this->groupBox2->Visible = false;
			this->groupBox2->Size = System::Drawing::Size(682, 600);
			this->groupBox2->Location = System::Drawing::Point(5, 20);
			
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(650, 448);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;

			//nums
			this->label1->Text = L"";
			this->label1->Size = System::Drawing::Size(20, 20);
			this->label1->Location = System::Drawing::Point(77 , 500);

			this->label2->Text = L"";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->Location = System::Drawing::Point(77 + 60, 500);

			this->label3->Text = L"";
			this->label3->Size = System::Drawing::Size(20, 20);
			this->label3->Location = System::Drawing::Point(77 + 60 * 2, 500);

			this->label4->Text = L"";
			this->label4->Size = System::Drawing::Size(20, 20);
			this->label4->Location = System::Drawing::Point(77 + 60 * 3, 500);

			this->label5->Text = L"";
			this->label5->Size = System::Drawing::Size(20, 20);
			this->label5->Location = System::Drawing::Point(77 + 60 * 4, 500);

			this->label6->Text = L"";
			this->label6->Size = System::Drawing::Size(20, 20);
			this->label6->Location = System::Drawing::Point(77 + 60 * 5, 500);

			this->label7->Text = L"";
			this->label7->Size = System::Drawing::Size(20, 20);
			this->label7->Location = System::Drawing::Point(77 + 60 * 6, 500);

			this->label8->Text = L"";
			this->label8->Size = System::Drawing::Size(20, 20);
			this->label8->Location = System::Drawing::Point(77 + 60 * 7, 500);

			this->label9->Text = L"";
			this->label9->Size = System::Drawing::Size(20, 20);
			this->label9->Location = System::Drawing::Point(77 + 60 * 8, 500);

			this->label10->Text = L"";
			this->label10->Size = System::Drawing::Size(20, 20);
			this->label10->Location = System::Drawing::Point(77 + 60 * 9, 500);

			//index
			//this->labelNum1->Text = L"1";
			this->labelNum1->Size = System::Drawing::Size(20, 20);
			this->labelNum1->Location = System::Drawing::Point(77, 535);

			//this->labelNum2->Text = L"2";
			this->labelNum2->Size = System::Drawing::Size(20, 20);
			this->labelNum2->Location = System::Drawing::Point(77 + 60, 535);

			//this->labelNum3->Text = L"3";
			this->labelNum3->Size = System::Drawing::Size(20, 20);
			this->labelNum3->Location = System::Drawing::Point(77 + 60 * 2, 535);

			//this->labelNum4->Text = L"4";
			this->labelNum4->Size = System::Drawing::Size(20, 20);
			this->labelNum4->Location = System::Drawing::Point(77 + 60 * 3, 535);

			//this->labelNum5->Text = L"5";
			this->labelNum5->Size = System::Drawing::Size(20, 20);
			this->labelNum5->Location = System::Drawing::Point(77 + 60 * 4, 535);

			//this->labelNum6->Text = L"6";
			this->labelNum6->Size = System::Drawing::Size(20, 20);
			this->labelNum6->Location = System::Drawing::Point(77 + 60 * 5, 535);

			//this->labelNum7->Text = L"7";
			this->labelNum7->Size = System::Drawing::Size(20, 20);
			this->labelNum7->Location = System::Drawing::Point(77 + 60 * 6, 535);

			//this->labelNum8->Text = L"8";
			this->labelNum8->Size = System::Drawing::Size(20, 20);
			this->labelNum8->Location = System::Drawing::Point(77 + 60 * 7, 535);

			//this->labelNum9->Text = L"9";
			this->labelNum9->Size = System::Drawing::Size(20, 20);
			this->labelNum9->Location = System::Drawing::Point(77 + 60 * 8, 535);

			//this->labelNum10->Text = L"10";
			this->labelNum10->Size = System::Drawing::Size(20, 20);
			this->labelNum10->Location = System::Drawing::Point(77 + 60 * 9, 535);

			//bubble
			this->Bubble->Name = L"Bubble";
			this->Bubble->Location = System::Drawing::Point(20, 20);
			this->Bubble->Size = System::Drawing::Size(120, 25);
			this->Bubble->Text = L"Bubble";
			this->Bubble->Click += gcnew System::EventHandler(this, &MyForm::Bubble_Click);

			//select
			this->Select->Name = L"Select";
			this->Select->Location = System::Drawing::Point(20, 70);
			this->Select->Size = System::Drawing::Size(120, 25);
			this->Select->Text = L"Select";
			this->Select->Click += gcnew System::EventHandler(this, &MyForm::Select_Click);

			//insert
			this->Insert->Name = L"Insert";
			this->Insert->Location = System::Drawing::Point(20, 120);
			this->Insert->Size = System::Drawing::Size(120, 25);
			this->Insert->Text = L"Insert";
			this->Insert->Click += gcnew System::EventHandler(this, &MyForm::Insert_Click);
			
			//shell
			this->Shell->Name = L"Shell";
			this->Shell->Location = System::Drawing::Point(20, 170);
			this->Shell->Size = System::Drawing::Size(120, 25);
			this->Shell->Text = L"Shell";
			this->Shell->Click += gcnew System::EventHandler(this, &MyForm::Shell_Click);
			
			//quick
			this->Quick->Name = L"Quick";
			this->Quick->Location = System::Drawing::Point(20, 220);
			this->Quick->Size = System::Drawing::Size(120, 25);
			this->Quick->Text = L"Quick";
			this->Quick->Click += gcnew System::EventHandler(this, &MyForm::Quick_Click);

			//heap
			this->Heap->Name = L"Heap";
			this->Heap->Location = System::Drawing::Point(20, 270);
			this->Heap->Size = System::Drawing::Size(120, 25);
			this->Heap->Text = L"Heap";
			this->Heap->Click += gcnew System::EventHandler(this, &MyForm::Heap_Click);

			//merge
			this->Merge->Name = L"Merge";
			this->Merge->Location = System::Drawing::Point(20, 320);
			this->Merge->Size = System::Drawing::Size(120, 25);
			this->Merge->Text = L"Merge";
			this->Merge->Click += gcnew System::EventHandler(this, &MyForm::Merge_Click);

			//time
			this->Time->Name = L"Time";
			this->Time->Location = System::Drawing::Point(5, 460);
			this->Time->Size = System::Drawing::Size(145, 100);
			this->Time->BackColor = System::Drawing::Color::White;
			this->Time->Multiline = true;

			this->groupBox1->Controls->Add(this->Bubble);
			this->groupBox1->Controls->Add(this->Select);
			this->groupBox1->Controls->Add(this->Insert);
			this->groupBox1->Controls->Add(this->Shell);
			this->groupBox1->Controls->Add(this->Quick);
			this->groupBox1->Controls->Add(this->Heap);
			this->groupBox1->Controls->Add(this->Merge);
			this->groupBox1->Controls->Add(this->Time);

			this->groupBox3->Controls->Add(this->format1);
			this->groupBox3->Controls->Add(this->format2);
			this->groupBox1->Controls->Add(this->groupBox3);

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

			this->groupBox2->Controls->Add(this->labelNum1);
			this->groupBox2->Controls->Add(this->labelNum2);
			this->groupBox2->Controls->Add(this->labelNum3);
			this->groupBox2->Controls->Add(this->labelNum4);
			this->groupBox2->Controls->Add(this->labelNum5);
			this->groupBox2->Controls->Add(this->labelNum6);
			this->groupBox2->Controls->Add(this->labelNum7);
			this->groupBox2->Controls->Add(this->labelNum8);
			this->groupBox2->Controls->Add(this->labelNum9);
			this->groupBox2->Controls->Add(this->labelNum10);
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
			this->groupBox5->Location = System::Drawing::Point(692, 56);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(156, 565);
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
			this->groupBox5Tree->Location = System::Drawing::Point(692, 56);
			this->groupBox5Tree->Name = L"groupBox5Tree";
			this->groupBox5Tree->Size = System::Drawing::Size(156, 565);
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
			this->groupBox5Algorithm->Location = System::Drawing::Point(692, 56);
			this->groupBox5Algorithm->Name = L"groupBox5Algorithm";
			this->groupBox5Algorithm->Size = System::Drawing::Size(156, 565);
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
	InitializeText();
	InitializeRun(IArraysize);

	if (thread->ThreadState == System::Threading::ThreadState::Stopped)
	{
		Opening();
		
		//finally update ui
		ClearView(myGraphics);
		for (size_t i = 0; i < 10; i++)
		{
			Geometric::Object object(60 * i, IArraysize[i]);
			object.DrawCylindrical(myGraphics);
			object.DrawText(myGraphics, IArraysize[i].ToString());
		}

		this->timer1->Stop();
	}
}
private: System::Void Form_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	
	// exit thread and thread1
	thread->Abort();
	TerminateThread(hThread1, 0);
	CloseHandle(hThread1);

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
private: System::Void Bubble_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(0);
}
private: System::Void Select_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(1);
}
private: System::Void Insert_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(2);
}
private: System::Void Shell_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(3);
}
private: System::Void Quick_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(4);
}
private: System::Void Heap_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(5);
}
private: System::Void Merge_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForSort(6);
}

private: void ReadyForSort( /*The function is create object*/ const unsigned int SortIndex) {
	
	MyStruct<SortType> Sortstruct;

	try
	{
		// exit thread and thread1
		thread->Abort();
		while (true)
		{
			if (WaitForSingleObject(hThread1, 0) == WAIT_OBJECT_0 || hThread1==NULL)
			{
				IArraysize.clear();

				//
				if (this->format1->Checked)
				{
					IArraysize = Sortstruct.nums = RandNums<SortType>();
					HiddenLabel();

					Sortstruct.SortIndex = SortIndex;

					//CloseHandle(hThread1);
					Go(Sortstruct);
				}
				else if (this->format2->Checked)
				{
					IArraysize = Sortstruct.nums = RandNumbers<SortType>();
					ShowLabel();

					Sortstruct.SortIndex = SortIndex;

					//CloseHandle(hThread1);
					Go(Sortstruct);
				}

				break;
			}
		}
	}
	catch (const std::exception&)
	{
		return;
	}
}
private: void Go( /*The function is create object*/ MyStruct<SortType> SortInfo ){

	MYThread<SortType> ThreadInSort;
	
	// initialize object
	if (this->format1->Checked)
	{
		for (size_t i = 0; i < 100; i++)
		{
			Geometric::Object object(2*i, SortInfo.nums[i]);
			object.DrawPoints(myGraphics);
		}
	}
	else if(this->format2->Checked)
	{
		for (size_t i = 0; i < 10; i++)
		{
			Geometric::Object object(60 * i, SortInfo.nums[i]);
			object.DrawCylindrical(myGraphics);
		}
	}
	
	// start two thread ( First is sort,second is display )
	if (SortInfo.nums.size() != NULL)
	{
		try
		{
			Shielding();
			thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadOfDraw));
			hThread1 = CreateThread(NULL, 0, ThreadInSort.ThreadOfSort, &SortInfo, 0, NULL);

			thread->Start();
			timer1->Start();

			HMutex = CreateMutex(NULL, FALSE, LPCWSTR("sort"));
		}
		catch (const std::exception&)
		{
			return;
		}
	}
}
private: void ThreadOfDraw(void)
{
	// sorting objet 
	while (SortFinished)
	{
		//lock
		WaitForSingleObject(Process::HMutex, INFINITE);
		ClearView(myGraphics);

		System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
		System::Drawing::Brush^  brushChange = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Red);

		timer1->Start();

		try
		{
			Geometric::Object arrow;
			vector<long long>::iterator SearchFirst;

			if (ExchangeIndex[0]<IArraysize.size() && ExchangeIndex[1]<IArraysize.size())
				SearchFirst = std::find(IArraysize.begin(), IArraysize.end(), IArraysize[ExchangeIndex[0]]);

			if (SearchFirst != IArraysize.end())
			{
				System::Drawing::Point Pt1(60 * ExchangeIndex[0] + 75, 185 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt2(60 * ExchangeIndex[0] + 75, 100 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt3(60 * ExchangeIndex[1] + 75, 100 - IArraysize[ExchangeIndex[0]]);
				System::Drawing::Point Pt4(60 * ExchangeIndex[1] + 75, 185 - IArraysize[ExchangeIndex[1]]);
				arrow.DrawArrow(myGraphics, Pt1, Pt2, Pt3, Pt4);
			}
		}
		catch (const std::exception&)
		{
			return;
		}

		for (size_t i = 0; i < 10; i++)
		{
			Geometric::Object object(60 * i, IArraysize[i]);
			if (i == ExchangeIndex[0] || i == ExchangeIndex[1])
				object.DrawCylindrical(myGraphics, brushChange);
			else
				object.DrawCylindrical(myGraphics, brush);

			object.DrawText(myGraphics, IArraysize[i].ToString());
		}

		//unlock
		Sleep(500);
		ReleaseMutex(HMutex);
	}

	SortFinished = true;
	timekeeping = 0;
	return;
}
private: void ClearView( /*The function is create object*/System::Drawing::Graphics^ myGraphics) {
	myGraphics->Clear(this->pictureBoxAlgorithm->BackColor);
}
private: void InitializeRun( /*The function is create object*/vector<SortType> nums) {
	this->Controls->Add(this->groupBox2);
	this->label1->Text = nums[0].ToString();
	this->label2->Text = nums[1].ToString();
	this->label3->Text = nums[2].ToString();
	this->label4->Text = nums[3].ToString();
	this->label5->Text = nums[4].ToString();
	this->label6->Text = nums[5].ToString();
	this->label7->Text = nums[6].ToString();
	this->label8->Text = nums[7].ToString();
	this->label9->Text = nums[8].ToString();
	this->label10->Text = nums[9].ToString();
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
	Sleep(6);
	ReleaseMutex(AMutex);
}

#pragma endregion
};
}
