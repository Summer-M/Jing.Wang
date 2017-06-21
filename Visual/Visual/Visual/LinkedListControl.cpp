#include "LinkedListControl.h"

namespace Visual
{
	System::Void LinkedListControl::button1_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		ReadyForLinkedList(0);
	}

	System::Void LinkedListControl::button2_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		ReadyForLinkedList(1);
	}

	System::Void LinkedListControl::button3_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		ReadyForLinkedList(2);
	}

	System::Void LinkedListControl::button4_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		ReadyForLinkedList(3);
	}

	System::Void LinkedListControl::button5_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		ReadyForLinkedList(4);
	}

	void LinkedListControl::ReadyForLinkedList( /* start */const unsigned int index )
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

	void LinkedListControl::UpdateTextBoxForOriginal( /* start */vector<long long> result )
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

	void LinkedListControl::UpdateTextBoxForResultAboutRemove( /* start */vector<long long> result )
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

	void LinkedListControl::UpdateTextBoxForResultAboutSearch( /* start */bool result )
	{
		String^ Textaboutlink = result ? "Yes!" : "No!";
		this->ResultData->Text = (this->ResultData->Text == "") ? Textaboutlink : this->ResultData->Text + "\r\n" + Textaboutlink;
	}
}