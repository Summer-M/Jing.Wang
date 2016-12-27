#pragma once

#include "Draw.h"
#include "Header.h"

namespace DataVisualization {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	//New namespace
	using namespace AboutSort;
	using namespace Process;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
			:thread(nullptr),
			 hThread1(NULL)
		{
			InitializeComponent();

			InitializeComponentSort();
			//
			//TODO: Add the constructor code here
			//
		    myGraphics = this->pictureBox1->CreateGraphics();
			thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadOfDraw));
			hThread1 = CreateThread(NULL, 0, ThreadReady, NULL, 0, NULL);
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
	private: System::Windows::Forms::Button^	  Create;
	private: System::Windows::Forms::Button^	  Search;
	private: System::Windows::Forms::Button^	  Delete;
	private: System::Windows::Forms::Button^	  Reverse;
	private: System::Windows::Forms::Button^	  InsertLink;
	private: System::Windows::Forms::TextBox^	  TextCreate;
	private: System::Windows::Forms::TextBox^	  TextSearch;
	private: System::Windows::Forms::TextBox^	  TextDelete;
	private: System::Windows::Forms::TextBox^	  TextInsert;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Drawing::Graphics^ myGraphics;				// draw	
		System::Threading::Thread^ thread;                  // thread for update label
		HANDLE hThread1;									// thread for update sort

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
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Sort", L"LinkedList", L"Tree" });
			this->comboBox1->Location = System::Drawing::Point(692, 28);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(156, 27);
			this->comboBox1->Text = L"Sort";
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 100;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
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
			this->labelNum1->Text = L"1";
			this->labelNum1->Size = System::Drawing::Size(20, 20);
			this->labelNum1->Location = System::Drawing::Point(77, 535);

			this->labelNum2->Text = L"2";
			this->labelNum2->Size = System::Drawing::Size(20, 20);
			this->labelNum2->Location = System::Drawing::Point(77 + 60, 535);

			this->labelNum3->Text = L"3";
			this->labelNum3->Size = System::Drawing::Size(20, 20);
			this->labelNum3->Location = System::Drawing::Point(77 + 60 * 2, 535);

			this->labelNum4->Text = L"4";
			this->labelNum4->Size = System::Drawing::Size(20, 20);
			this->labelNum4->Location = System::Drawing::Point(77 + 60 * 3, 535);

			this->labelNum5->Text = L"5";
			this->labelNum5->Size = System::Drawing::Size(20, 20);
			this->labelNum5->Location = System::Drawing::Point(77 + 60 * 4, 535);

			this->labelNum6->Text = L"6";
			this->labelNum6->Size = System::Drawing::Size(20, 20);
			this->labelNum6->Location = System::Drawing::Point(77 + 60 * 5, 535);

			this->labelNum7->Text = L"7";
			this->labelNum7->Size = System::Drawing::Size(20, 20);
			this->labelNum7->Location = System::Drawing::Point(77 + 60 * 6, 535);

			this->labelNum8->Text = L"8";
			this->labelNum8->Size = System::Drawing::Size(20, 20);
			this->labelNum8->Location = System::Drawing::Point(77 + 60 * 7, 535);

			this->labelNum9->Text = L"9";
			this->labelNum9->Size = System::Drawing::Size(20, 20);
			this->labelNum9->Location = System::Drawing::Point(77 + 60 * 8, 535);

			this->labelNum10->Text = L"10";
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

			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
		}
#pragma endregion

#pragma region LinkedList
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponentLinkedList(Void)
		{
			this->TextCreate = (gcnew System::Windows::Forms::TextBox());
			this->TextDelete = (gcnew System::Windows::Forms::TextBox());
			this->TextSearch = (gcnew System::Windows::Forms::TextBox());
			this->TextInsert = (gcnew System::Windows::Forms::TextBox());
			this->Create = (gcnew System::Windows::Forms::Button());
			this->Search = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Reverse = (gcnew System::Windows::Forms::Button());
			this->InsertLink = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->OriginalData = (gcnew System::Windows::Forms::TextBox());
			this->ResultData = (gcnew System::Windows::Forms::TextBox());
			this->labelOriginalData = (gcnew System::Windows::Forms::Label());
			this->labelResultData = (gcnew System::Windows::Forms::Label());

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

			this->groupBox5->Controls->Add(TextCreate);
			this->groupBox5->Controls->Add(TextSearch);
			this->groupBox5->Controls->Add(TextDelete);
			this->groupBox5->Controls->Add(TextInsert);

			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox5);

			//SET
			this->Focus();
			this->groupBox1->Visible = false;
			this->groupBox1->Enabled = false;
			this->groupBox2->Visible = false;
			this->groupBox2->Enabled = false;
			
		}
#pragma endregion

#pragma region Event Drive
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	InitializeRun(IArraysize);
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
		case 0:InitializeComponentSort(); break;
		case 1:InitializeComponentLinkedList(); break;
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
	
	MyStruct Sortstruct;

	try
	{
		// exit thread and thread1
		thread->Abort();
		while (true)
		{
			if (WaitForSingleObject(hThread1, 0) == WAIT_OBJECT_0)
			{
				IArraysize.clear();

				//
				if (this->format1->Checked)
				{
					IArraysize = Sortstruct.nums = Process::RandNums();
					HiddenLabel();

					Sortstruct.SortIndex = SortIndex;

					//CloseHandle(hThread1);
					Go(Sortstruct);
				}
				else if (this->format2->Checked)
				{
					IArraysize = Sortstruct.nums = Process::RandNumbers();
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
private: void Go( /*The function is create object*/ MyStruct SortInfo ){

	// initialize object
	if (this->format1->Checked)
	{
		for (size_t i = 0; i < 100; i++)
		{
			AboutSort::Object object(2*i, SortInfo.nums[i]);
			object.DrawPoints(myGraphics);
		}
	}
	else if(this->format2->Checked)
	{
		for (size_t i = 0; i < 10; i++)
		{
			AboutSort::Object object(60 * i, SortInfo.nums[i]);
			object.DrawCylindrical(myGraphics);
		}
	}
	
	// start two thread ( First is sort,second is display )
	if (SortInfo.nums.size() != NULL)
	{
		try
		{
			thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadOfDraw));
			hThread1 = CreateThread(NULL, 0, ThreadOfSort, &SortInfo, 0, NULL);

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

		if (this->format1->Checked)
		{
			timer1->Stop();

			for (size_t i = 0; i < 100; i++)
			{
				AboutSort::Object object(10*i, IArraysize[i]);
				object.DrawPoints(myGraphics);
			}
		}
		else if (this->format2->Checked)
		{
			timer1->Start();
			
			for (size_t i = 0; i < 10; i++)
			{
				AboutSort::Object object(60 * i, IArraysize[i]);
				object.DrawCylindrical(myGraphics);
			}
		}

		//unlock
		Sleep(50);
		ReleaseMutex(HMutex);
	}

	SortFinished = true;
	timer1->Stop();
	return;
}

private: void ClearView( /*The function is create object*/System::Drawing::Graphics^ myGraphics) {
	myGraphics->Clear(System::Drawing::Color::White);
}
private: void InitializeRun( /*The function is create object*/vector<long long> nums) {
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
					Mylink = link.Create(Convert::ToInt32(this->TextCreate->Text));

				Result = link.Output(Mylink);
				UpdateTextBoxForOriginal(Result);
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

#pragma endregion
};
}
