
#include "Draw.h"

namespace AboutSort
{
	bool Object::DrawCylindrical(System::Drawing::Graphics^ myGraphics)
	{
		try
		{
			System::Drawing::Pen^  pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::DarkTurquoise);
			myGraphics->FillRectangle(brush, PosX + OffsetX, PosY - OffsetW, Width, Height + OffsetW);
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
			myGraphics->FillEllipse(brush, PosX1 + OffsetX, PosY1 - OffsetW, 3, 3);
			//myGraphics->DrawEllipse(pen, PosX1 + OffsetX, PosY1 - OffsetW, 3, 3);
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
}