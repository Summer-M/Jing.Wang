#pragma once

#include "../Visual/Process/Process.h"
#include "../Visual/Variable/Variable.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace Process;


namespace Visual {

	/// <summary>
	/// Summary for LinkedListControl
	/// </summary>
	public ref class LinkedListControl : public System::Windows::Forms::UserControl
	{
	public:
		LinkedListControl(void)
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
		~LinkedListControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  OriginalData;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  ResultData;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  format5;

	private: System::Windows::Forms::RadioButton^  format4;

	private: System::Windows::Forms::RadioButton^  format3;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->OriginalData = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ResultData = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->format5 = (gcnew System::Windows::Forms::RadioButton());
			this->format4 = (gcnew System::Windows::Forms::RadioButton());
			this->format3 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(22, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Origin Data";
			// 
			// OriginalData
			// 
			this->OriginalData->Location = System::Drawing::Point(25, 36);
			this->OriginalData->Multiline = true;
			this->OriginalData->Name = L"OriginalData";
			this->OriginalData->Size = System::Drawing::Size(785, 172);
			this->OriginalData->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(22, 246);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Result Data";
			// 
			// ResultData
			// 
			this->ResultData->Location = System::Drawing::Point(25, 266);
			this->ResultData->Multiline = true;
			this->ResultData->Name = L"ResultData";
			this->ResultData->Size = System::Drawing::Size(785, 172);
			this->ResultData->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(22, 481);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Process";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(25, 502);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(785, 198);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
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
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Operation";
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
			this->button5->Text = L"Insert";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &LinkedListControl::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(22, 224);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(101, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Reserve";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &LinkedListControl::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(22, 159);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Detele";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &LinkedListControl::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Search";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LinkedListControl::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Create";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LinkedListControl::button1_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(843, 592);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(200, 108);
			this->textBox8->TabIndex = 7;
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
			this->groupBox2->TabIndex = 8;
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
			// LinkedListControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ResultData);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->OriginalData);
			this->Controls->Add(this->label1);
			this->Name = L"LinkedListControl";
			this->Size = System::Drawing::Size(1043, 703);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(0);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(1);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(2);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(3);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	ReadyForLinkedList(4);
}

private:void ReadyForLinkedList(/* start */const unsigned int index)
{
	LinkedList link;

	switch (index)
	{
	case 0:
	{
		if (this->textBox3->Text == "")
			break;
		else
		{
			if (this->format4->Checked)
			{
				Mylink1 = link.CreateDoubly(Convert::ToInt32(this->textBox3->Text));

				Result = link.Output1(Mylink1);
				UpdateTextBoxForOriginal(Result);
			}
			else if (this->format3->Checked)
			{
				Mylink = link.Create(Convert::ToInt32(this->textBox3->Text));

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
		if (this->textBox4->Text == "")
			break;
		else
			b_find = link.SearchIndex(Convert::ToInt32(this->textBox4->Text), Mylink);

		UpdateTextBoxForResultAboutSearch(b_find);
	}

	break;

	case 2:
	{
		if (this->textBox5->Text == "")
			break;
		else
			Mylink = link.Remove(Convert::ToInt32(this->textBox5->Text), Mylink);

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

		if (this->textBox7->Text == "")
			break;
		else
			Mylink = link.Insert(Convert::ToInt32(this->textBox7->Text), Mylink, Testinsert);
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
		if (i != result.size() - 1)
			Textaboutlink += ",";
	}

	this->OriginalData->Text = (this->OriginalData->Text == "") ? Textaboutlink : this->OriginalData->Text + "\r\n" + Textaboutlink;
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
};
}