#pragma once

#include <iostream>
#include <time.h>

#include "Header.h"

namespace Geometric
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

	//!\brief extern
	// --------------------------------------------------------------------
	//|					About The graphics transformation				   |
	// --------------------------------------------------------------------
	
	extern	HANDLE		AMutex;
	extern	vector<int>	PoxXCircle;
	extern	vector<int>	PoxYCircle;
	extern	vector<int>	DirectionXCircle;
	extern	vector<int>	DirectionYCircle;

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
		double OffsetX;
		double OffsetW;
	public:
		//!\brief draw rectangle
		bool DrawCylindrical(System::Drawing::Graphics^ myGraphics);
		bool DrawPoints(System::Drawing::Graphics^ myGraphics);
		bool DrawCircle(System::Drawing::Graphics^ myGraphics);

		//!\brief move my object
		void Move();
	};

//! \brief Process rand test-numbers 
//-------------------------------------------------------------------------
	inline vector<int> RandNumbers(int value);
}