#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Visual {

	/// <summary>
	/// Summary for TreeControl
	/// </summary>
	public ref class TreeControl : public System::Windows::Forms::UserControl
	{
	public:
		TreeControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TreeControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox8;
	protected:
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  format5;
	private: System::Windows::Forms::RadioButton^  format4;
	private: System::Windows::Forms::RadioButton^  format3;

	protected:


















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
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->format5 = (gcnew System::Windows::Forms::RadioButton());
			this->format4 = (gcnew System::Windows::Forms::RadioButton());
			this->format3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(843, 592);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(200, 108);
			this->textBox8->TabIndex = 15;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(140, 291);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(35, 23);
			this->textBox7->TabIndex = 9;
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(140, 224);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(35, 23);
			this->textBox6->TabIndex = 8;
			this->textBox6->Text = L"True";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(140, 159);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(35, 23);
			this->textBox5->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(140, 95);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(35, 23);
			this->textBox4->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(140, 36);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(35, 23);
			this->textBox3->TabIndex = 5;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(22, 291);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(101, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Insert in Tree";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(22, 224);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(101, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Reserve";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(22, 159);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Detele";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Search Tree";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(843, 16);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(197, 337);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Operation";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Create Tree";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(25, 502);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(785, 198);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(22, 481);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 17);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Process";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 266);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(785, 172);
			this->textBox2->TabIndex = 11;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(22, 246);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Result Data";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 36);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(785, 172);
			this->textBox1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(22, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Origin Data";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->format5);
			this->groupBox2->Controls->Add(this->format4);
			this->groupBox2->Controls->Add(this->format3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox2->Location = System::Drawing::Point(843, 392);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 173);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Class";
			// 
			// format5
			// 
			this->format5->AutoSize = true;
			this->format5->Location = System::Drawing::Point(42, 128);
			this->format5->Name = L"format5";
			this->format5->Size = System::Drawing::Size(70, 21);
			this->format5->TabIndex = 2;
			this->format5->TabStop = true;
			this->format5->Text = L"Circular";
			this->format5->UseVisualStyleBackColor = true;
			// 
			// format4
			// 
			this->format4->AutoSize = true;
			this->format4->Location = System::Drawing::Point(42, 85);
			this->format4->Name = L"format4";
			this->format4->Size = System::Drawing::Size(67, 21);
			this->format4->TabIndex = 1;
			this->format4->TabStop = true;
			this->format4->Text = L"Doubly";
			this->format4->UseVisualStyleBackColor = true;
			// 
			// format3
			// 
			this->format3->AutoSize = true;
			this->format3->Location = System::Drawing::Point(42, 39);
			this->format3->Name = L"format3";
			this->format3->Size = System::Drawing::Size(60, 21);
			this->format3->TabIndex = 0;
			this->format3->TabStop = true;
			this->format3->Text = L"Singly";
			this->format3->UseVisualStyleBackColor = true;
			// 
			// TreeControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"TreeControl";
			this->Size = System::Drawing::Size(1043, 703);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
