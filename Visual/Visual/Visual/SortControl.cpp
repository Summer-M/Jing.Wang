#include "SortControl.h"

namespace Visual
{
	System::Void SortControl::SortControl_Load( System::Object^  sender, System::EventArgs^  e )
	{
		myGraphics->FromImage(bitmap);
		this->pictureBox1->Invalidate();
	}

	System::Void SortControl::timer1_Tick( System::Object^  sender, System::EventArgs^  e ) 
	{
		//lock
		WaitForSingleObject(Process::HMutex, INFINITE);

		//show();
		Updatetextbox((this->textBox1->GetLineFromCharIndex(this->textBox1->GetFirstCharIndexOfCurrentLine()) + 1).ToString() + ") " + " The " + The_digital_unit(StepInNormal + 1) + " steps : "
			+ "Swapping the " + The_digital_unit(ExchangeIndex[0])
			+ " with the " + The_digital_unit(ExchangeIndex[1]) + ".(As above the red rectangle!)");

		this->pictureBox1->Invalidate();
		this->button3->Text = "- The " + The_digital_unit(StepInNormal + 1) + " Steps -";

		//unlock
		ReleaseMutex(HMutex);
	}

	System::Void SortControl::button1_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		MyStruct<SortType> Sortstruct;

		//the start sort
		if (this->normal->Checked)
		{
			// bubble
			if (this->bubble->Checked)
				ReadyForSort(0);
			// select
			else if (this->select->Checked)
				ReadyForSort(1);
			// insert
			else if (this->insert->Checked)
				ReadyForSort(2);
			//shell
			else if (this->shell->Checked)
				ReadyForSort(3);
			else
				MessageBox::Show("Please select a sorting way!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else if (this->step->Checked)
		{
			// bubble
			if (this->bubble->Checked)
				ReadyForSortUseSecondModel(0);
			// select
			else if (this->select->Checked)
				ReadyForSortUseSecondModel(1);
			// insert
			else if (this->insert->Checked)
				ReadyForSortUseSecondModel(2);
			//shell
			else if (this->shell->Checked)
				ReadyForSortUseSecondModel(3);
			else
				MessageBox::Show("Please select a sorting order!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
			MessageBox::Show("Please select a sorting pattern!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void SortControl::button2_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
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
			MessageBox::Show("Only for single step pattern", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void SortControl::button4_Click( System::Object^  sender, System::EventArgs^  e )
	{
			if (this->step->Checked)
			{
				if (this->bubble->Checked || this->select->Checked || this->shell->Checked || this->insert->Checked)
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
					MessageBox::Show("please select the sort pattern in sort this part.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
				MessageBox::Show("please select the Step Pattern in Pattern this part.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void SortControl::button5_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
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
				MessageBox::Show("please select the sort pattern", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
			MessageBox::Show("please select the step pattern", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void SortControl::pictureBox1_Paint( System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e )
	{
		myGraphics = e->Graphics;
		myGraphics->FromImage(bitmap);
		myGraphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

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
			if (i % 4 == 0 && i != 0)
			{
				System::Drawing::Point Pt1(17, 5 + RECTANGULAR_SPACE * i);
				System::Drawing::Point Pt2(this->pictureBox1->Width - 12, 5 + RECTANGULAR_SPACE * i);
				myGraphics->DrawLine(penCoordinates2, Pt1, Pt2);
			}

			System::Drawing::Point Pt1(0, 5 + RECTANGULAR_SPACE * i);
			System::Drawing::Point Pt2(0 + 7, 5 + RECTANGULAR_SPACE * i);
			myGraphics->DrawLine(penCoordinates, Pt1, Pt2);
		}

		// draw sorting process
		if (this->normal->Checked)
		{
			VisualPaint::Object arrow;
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
						VisualPaint::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
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
						myGraphics->DrawString("- The " + The_digital_unit(StepInNormal + 1) + "Steps -", stepfont, stepbrush, float(abs(Pt2.X - Pt3.X) / 2 + min(Pt2.X, Pt3.X) - 50), float(Pt2.Y - 25));
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
						VisualPaint::Object object(RECTANGULAR_SPACE * i, IArraysize[i]);
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
					Updatetextbox("--------------------------------------------Over-------------------------------------------------");
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
				VisualPaint::Object object(RECTANGULAR_SPACE * i, Every_Step_Of_The_Value.at(SortStep).at(i));

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

				//myGraphics->DrawLine(penDottedLine, Pt5, Pt6);
				//myGraphics->DrawString((Every_Step_Of_The_Value.at(SortStep).at(i) + BaseNumber).ToString(), font, brush, float(object.DrawText().TextX), float(object.DrawText().TextY));
				myGraphics->DrawString("- The " + The_digital_unit(SortStep + 1) + "Steps -", stepfont, stepbrush, float(abs(Pt2.X - Pt3.X) / 2 + min(Pt2.X, Pt3.X) - 50), float(Pt2.Y - 25));
			}

			this->button3->Text = "- The " + The_digital_unit(SortStep + 1) + "Steps -";
			Updatetextbox((this->textBox1->GetLineFromCharIndex(this->textBox1->GetFirstCharIndexOfCurrentLine()) + 1).ToString() + ") " + " The " + The_digital_unit(SortStep + 1)
				+ " steps : " + "Swapping the " + The_digital_unit(Every_Step_Of_The_Change[2 * SortStep])
				+ " with the " + The_digital_unit(Every_Step_Of_The_Change[2 * SortStep + 1]) + " in the vector" + ".(As above the red rectangle!)");
		}
		else if (!Endpattern)
		{
			myGraphics->Clear(this->pictureBox1->BackColor);
		}
	}

	void SortControl::ReadyForSort( /* the function is start */ const unsigned int SortIndex ) 
	{
		MyStruct<SortType> Sortstruct;

		try
		{
			Shielding();
			IArraysize.clear();
			SortFinished = true;
			IArraysize = Sortstruct.nums = RandNumbers<SortType>();
			Sortstruct.SortIndex = SortIndex;
			Go(Sortstruct);
		}
		catch (const std::exception&)
		{
			return;
		}
	}

	void SortControl::Go( /* the function is start thread */ MyStruct<SortType> SortInfo ) 
	{
		MYThread<SortType> ThreadInSort(SortInfo.SortIndex, SortInfo.nums, "normal");

		if (SortInfo.nums.size() != NULL)
		{
			try
			{
				this->textBox1->AppendText("\r\n--------------------------------------------Start-------------------------------------------------");
				HMutex = CreateMutex(NULL, FALSE, LPCWSTR("sort"));
				HANDLE  HandleSort = (HANDLE)_beginthreadex(NULL, 0, ThreadInSort.ThreadOfSort, NULL, 0, NULL);
				this->timer1->Start();
			}
			catch (const std::exception&)
			{
				return;
			}
		}
	}

	void SortControl::ReadyForSortUseSecondModel( /*the function is start thread*/ const unsigned int SortIndex )
	{
		ShieldingModel();
		Endpattern = true;

		MYThread<SortType> ThreadInSort(SortIndex, RandNumbers<SortType>(), "step pattern");

		try
		{
			this->textBox1->AppendText("\r\n--------------------------------------------Start-------------------------------------------------");
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

	void SortControl::Shielding( /*The function is shield object*/ )
	{
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

	void SortControl::ShieldingModel( /* the function is shield widget */ )
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

	void SortControl::Opening( /*The function is open object*/ ) 
	{
		this->button1->Enabled = true;
		this->bubble->Enabled = true;
		this->button2->Enabled = false;
		this->select->Enabled = true;
		this->insert->Enabled = true;
		this->shell->Enabled = true;
		this->normal->Enabled = true;
		this->step->Enabled = true;
		this->button4->Enabled = false;
		this->button5->Enabled = false;
	}

	String^ SortControl::The_digital_unit( const unsigned int steps )
	{
		switch (steps)
		{
		case 1:	return steps.ToString() + "st";
		case 2:	return steps.ToString() + "nd";
		case 3:	return steps.ToString() + "rd";
		default:
			return steps.ToString() + "th";
			break;
		}
	}

	void SortControl::Updatetextbox(String^ infomation)
	{
		this->textBox1->AppendText("\r\n" + infomation);
	}
}