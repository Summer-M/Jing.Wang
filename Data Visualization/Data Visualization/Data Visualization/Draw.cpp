
#include "Draw.h"

namespace Geometric
{
	//!\brief extern variable
	//-------------------------------------------------------
	HANDLE AMutex  = NULL;
	vector<int>	PoxXCircle = RandNumbers(400);
	vector<int>	PoxYCircle = RandNumbers(360);
	vector<int> DirectionXCircle = RandNumbers(20);
	vector<int> DirectionYCircle = RandNumbers(16);

	inline vector<int> RandNumbers(int value)
	{
		vector<int> RandNumber;
		srand((int)time(NULL));
		for (size_t i = 0; i < Circlesize; i++)
		{
			RandNumber.push_back(rand() % value + 3);
		}

		return RandNumber;
	}

	bool Object::DrawCylindrical(System::Drawing::Graphics^ myGraphics)
	{
		try
		{
			System::Drawing::Pen^  pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
			myGraphics->FillRectangle(brush, int(PosX + OffsetX), int(PosY - OffsetW), int(Width), int(Height + OffsetW));
			//myGraphics->DrawRectangle(pen, PosX + OffsetX, PosY - OffsetW, Width, Height + OffsetW);
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	bool Object::DrawPoints(System::Drawing::Graphics^ myGraphics)
	{
		try
		{
			System::Drawing::Pen^  pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Black);
			myGraphics->FillEllipse(brush, int(PosX1 + OffsetX), int(PosY1 - OffsetW), 3, 3);
			//myGraphics->DrawEllipse(pen, PosX1 + OffsetX, PosY1 - OffsetW, 3, 3);
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	bool Object::DrawCircle(System::Drawing::Graphics^ myGraphics)
	{
		try
		{
			System::Drawing::Pen^  pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
			myGraphics->FillEllipse(brush, OffsetX, OffsetW, 80, 80);
			//myGraphics->DrawEllipse(pen, PosX1 + OffsetX, PosY1 - OffsetW, 3, 3); 
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	void Object::Move(/*the function change circle position*/)
	{
		/*
			-----------------
			|				|
			|		|		|
			|	   -0-		|
			|		|		|
			|				|
			-----------------
		*/
	
		while (true)
		{
			//lock
			WaitForSingleObject(AMutex, INFINITE);

			//
			for (size_t i = 0; i < Circlesize; i++)
			{
				if (PoxXCircle[i] + CircleW >= BELOW || PoxXCircle[i] <= TOP)
				{
					DirectionXCircle[i] *= -1;
				}
				if (PoxYCircle[i] + CircleH >= RIGHT || PoxYCircle[i] <= LEFT)
				{
					DirectionYCircle[i] *= -1;
				}

				PoxXCircle[i] += DirectionXCircle[i];
				PoxYCircle[i] += DirectionYCircle[i];
			}
			
			//unlock
			Sleep(6);
			ReleaseMutex(AMutex);
		}
	}
}   