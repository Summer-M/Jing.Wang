#pragma once

#include <iostream>
#include <time.h>

#include "Header.h"

namespace AboutSort
{
	//using mamespace
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Process;

	class Object
	{
	public:
		enum {/* the Cylindrical */ PosX = 65,PosY = 200,Width = 20,Height = 150 /*the Point*/ , PosX1 = 30,PosY1 = 400};
		Object(){};
		Object(double offX,double width)
			:OffsetX(0.00),
			 OffsetW(0.00)
		{
			OffsetX = offX;
			OffsetW = width;
		};

		~Object() {};

	private:
		//my code
		int OffsetX;
		int OffsetW;
	public:
		//!\brief draw rectangle
		bool DrawCylindrical(System::Drawing::Graphics^ myGraphics);
		bool DrawPoints(System::Drawing::Graphics^ myGraphics);
	};
}