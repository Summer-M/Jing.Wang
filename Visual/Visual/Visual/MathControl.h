#pragma once

#include "../Visual/Thread/Thread.h"
#include "../Visual/Draw/Draw.h"
#include "../Visual/Variable/Variable.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace Geometric;


namespace Visual {

	/// <summary>
	/// Summary for MathControl
	/// </summary>
	public ref class MathControl : public System::Windows::Forms::UserControl
	{
	public:
		MathControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
			AloGraphics = this->pictureBox1->CreateGraphics();
			bitmapAlo = gcnew System::Drawing::Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
			canvasAlo = gcnew System::Drawing::Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MathControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		
		//
		System::Drawing::Brush^  brushAlo;
		System::Drawing::Graphics^  AloGraphics;
		System::Drawing::Bitmap^ bitmapAlo;
	private: System::Windows::Forms::Timer^  timer1;
			 System::Drawing::Bitmap^ canvasAlo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(13, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(845, 703);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MathControl::pictureBox1_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(864, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(173, 169);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Collision Detection";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->Location = System::Drawing::Point(33, 122);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Four - Tree";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(33, 72);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Separation";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(33, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"General";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MathControl::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox2->Location = System::Drawing::Point(864, 428);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(173, 169);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Shape";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton3->Location = System::Drawing::Point(33, 119);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(72, 21);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Polygon";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton2->Location = System::Drawing::Point(33, 75);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(82, 21);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Rectangle";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton1->Location = System::Drawing::Point(33, 33);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(57, 21);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Circle";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox3->Location = System::Drawing::Point(864, 223);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(173, 169);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"The query";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->Location = System::Drawing::Point(33, 122);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Four - Tree";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button5->Location = System::Drawing::Point(33, 72);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(108, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Separation";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button6->Location = System::Drawing::Point(33, 25);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(108, 23);
			this->button6->TabIndex = 0;
			this->button6->Text = L"General";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox2);
			this->groupBox4->Controls->Add(this->textBox1);
			this->groupBox4->Controls->Add(this->label2);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox4->Location = System::Drawing::Point(864, 634);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(173, 92);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Set";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(108, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(33, 23);
			this->textBox2->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(33, 23);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Location = System::Drawing::Point(41, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Speed : ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(30, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Number : ";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MathControl::timer1_Tick);
			// 
			// MathControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MathControl";
			this->Size = System::Drawing::Size(1043, 728);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ReadyGo();
	}

	private: void ReadyGo()
	{
		ThreadAboutAlgorithm threadaboutalgorithm;
		this->timer1->Interval = 15;
		try
		{
			HANDLE hThread2 = (HANDLE)_beginthreadex(NULL, 0, threadaboutalgorithm.ThreadOfA, NULL, 0, NULL);
			AMutex = CreateMutex(NULL, FALSE, LPCWSTR("Algorithm"));
			this->timer1->Start();
		}
		catch (const std::exception&)
		{
			return;
		}
	}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	AloGraphics = e->Graphics;
	AloGraphics->FromImage(bitmapAlo);
	AloGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

	if (radioButton1->Checked)													       // the circle  
	{
		for (size_t i = 0; i < Circlesize; i++)
		{
			if (Collect[i])
				brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
			else
				brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));

			AloGraphics->FillEllipse(brushAlo, PoxXCircle[i], PoxYCircle[i], CircleW, CircleH);
		}

		AloGraphics->DrawImage(bitmapAlo, 0, 0);
	}
	else if (radioButton2->Checked)													 // the rectangle  
	{
		for (size_t i = 0; i < Circlesize; i++)
		{
			if (Collect[i])
				brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
			else
				brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));

			AloGraphics->FillRectangle(brushAlo, PoxXCircle[i], PoxYCircle[i], CircleW, CircleH);
		}

		AloGraphics->DrawImage(bitmapAlo, 0, 0);
	}
	else if (radioButton3->Checked)												    // the polygon
	{
		for (size_t i = 0; i < Circlesize; i++)
		{
			if (Collect[i])
				brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
			else
				brushAlo = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));

			AloGraphics->FillRectangle(brushAlo, PoxXCircle[i], PoxYCircle[i], CircleW, CircleH);
		}

		AloGraphics->DrawImage(bitmapAlo, 0, 0);
	}
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	//lock
	WaitForSingleObject(AMutex, INFINITE);

	this->pictureBox1->Invalidate();

	// unlock
	ReleaseMutex(AMutex);
}
};
}
