#include "MathControl.h"

namespace Visual
{
	System::Void MathControl::button1_Click( System::Object^  sender, System::EventArgs^  e )
	{
		hidden();
		ReadyGo();
		ReadyGoB();
	}

	System::Void MathControl::button3_Click( System::Object^  sender, System::EventArgs^  e ) 
	{
		show();
		this->timer1->Stop();

		// exit thread
		exitthread = true;

		// release mutex 
		WaitForSingleObject(AMutex, 1000);
		ReleaseMutex(AMutex);

		// release mutex
		WaitForSingleObject(AMutexUseSecond, 1000);
		ReleaseMutex(AMutexUseSecond);
	}

	System::Void MathControl::pictureBox1_Paint( System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e ) 
	{
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

	System::Void MathControl::pictureBox2_Paint( System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e ) 
	{
		AloGraphicsUseSecond = e->Graphics;
		AloGraphicsUseSecond->FromImage(bitmapAloUseSecond);
		AloGraphicsUseSecond->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		if (radioButton1->Checked)													       // the circle  
		{
			for (size_t i = 0; i < Circlesize; i++)
			{
				if (CollectUseSecond[i])
					brushAloUseSecond = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
				else
					brushAloUseSecond = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));

				AloGraphicsUseSecond->FillEllipse(brushAloUseSecond, PoxXCircleUseSecond[i], PoxYCircleUseSecond[i], CircleW, CircleH);
			}

			AloGraphicsUseSecond->DrawImage(bitmapAloUseSecond, 0, 0);
		}
		else if (radioButton2->Checked)													 // the rectangle  
		{
			for (size_t i = 0; i < Circlesize; i++)
			{
				if (CollectUseSecond[i])
					brushAloUseSecond = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
				else
					brushAloUseSecond = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));

				AloGraphicsUseSecond->FillRectangle(brushAloUseSecond, PoxXCircleUseSecond[i], PoxYCircleUseSecond[i], CircleW, CircleH);
			}

			AloGraphicsUseSecond->DrawImage(bitmapAloUseSecond, 0, 0);
		}
		else if (radioButton3->Checked)												    // the polygon
		{
			for (size_t i = 0; i < Circlesize; i++)
			{
				if (CollectUseSecond[i])
					brushAloUseSecond = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::DeepSkyBlue));
				else
					brushAloUseSecond = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::FromArgb(90, System::Drawing::Color::Color::Red));

				AloGraphicsUseSecond->FillRectangle(brushAloUseSecond, PoxXCircleUseSecond[i], PoxYCircleUseSecond[i], CircleW, CircleH);
			}

			AloGraphicsUseSecond->DrawImage(bitmapAloUseSecond, 0, 0);
		}
	}

	System::Void MathControl::timer1_Tick( System::Object^  sender, System::EventArgs^  e ) 
	{

		//lock
		DWORD WAITFIRST = WaitForSingleObject(AMutex, 1);
		DWORD WAITSECOND = WaitForSingleObject(AMutexUseSecond, 1);

		if (WAITFIRST != WAIT_TIMEOUT)
		{
			this->pictureBox1->Invalidate();
			ReleaseMutex(AMutex);
		}

		if (WAITSECOND != WAIT_TIMEOUT)
		{
			this->pictureBox2->Invalidate();
			ReleaseMutex(AMutexUseSecond);
		}
		updatedata();
	}

	void MathControl::ReadyGo()
	{
		ThreadAboutAlgorithm threadaboutalgorithm;
		this->timer1->Interval = 15;
		try
		{
			this->textBox3->Text = "Normal Algorithm";
			HANDLE hThread2 = (HANDLE)_beginthreadex(NULL, 0, threadaboutalgorithm.ThreadOfA, NULL, 0, NULL);
			AMutex = CreateMutex(NULL, FALSE, LPCWSTR("Algorithm"));
			exitthread = false;
			this->timer1->Start();
		}
		catch (const std::exception&)
		{
			return;
		}
	}

	void MathControl::ReadyGoB()
	{
		ThreadAboutAlgorithm threadaboutalgorithm;
		this->timer1->Interval = 15;
		try
		{
			this->textBox5->Text = "Optimization algorithm";
			HANDLE hThread2 = (HANDLE)_beginthreadex(NULL, 0, threadaboutalgorithm.ThreadOfAB, NULL, 0, NULL);
			AMutexUseSecond = CreateMutex(NULL, FALSE, LPCWSTR("AlgorithmUseSecond"));
			//this->timer1->Start();
		}
		catch (const std::exception&)
		{
			return;
		}
	}

	void MathControl::hidden()
	{
		this->button1->Enabled = false;
		this->button2->Enabled = false;
		this->button3->Enabled = true;
		this->button4->Enabled = false;
		this->button5->Enabled = false;
		this->button6->Enabled = false;

		this->radioButton1->Enabled = false;
		this->radioButton2->Enabled = false;
		this->radioButton3->Enabled = false;

		this->label1->Enabled = false;
		this->label2->Enabled = false;

		this->textBox1->Enabled = false;
		this->textBox2->Enabled = false;
	}

	void MathControl::show()
	{
		this->button1->Enabled = true;
		this->button2->Enabled = true;
		this->button3->Enabled = false;
		this->button4->Enabled = true;
		this->button5->Enabled = true;
		this->button6->Enabled = true;

		this->radioButton1->Enabled = true;
		this->radioButton2->Enabled = true;
		this->radioButton3->Enabled = true;

		this->label1->Enabled = true;
		this->label2->Enabled = true;

		this->textBox1->Enabled = true;
		this->textBox2->Enabled = true;
	}

	void MathControl::updatedata( void )
	{
		this->textBox4->Text = checktimeaboutOrdinary.ToString();
		this->textBox6->Text = checktimeaboutOptimization.ToString();
	}
}