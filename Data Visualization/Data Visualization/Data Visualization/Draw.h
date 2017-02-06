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

	//!\brief extern
	// --------------------------------------------------------------------
	//|					About The graphics transformation				   |
	// --------------------------------------------------------------------
	
	extern	HANDLE		 AMutex;
	extern	vector<int>	 PoxXCircle;
	extern	vector<int>	 PoxYCircle;
	extern	vector<int>	 DirectionXCircle;
	extern	vector<int>	 DirectionYCircle;
	extern  vector<bool> Collect;

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
		//!\brief draw text
		bool Object::DrawText(System::Drawing::Graphics^ myGraphics, System::String^ sText);

		//!\brief draw rectangle
		bool Object::DrawCylindrical(System::Drawing::Graphics^ myGraphics);

		//!\brief draw rectangle
		bool DrawCylindrical(System::Drawing::Graphics^ myGraphics, System::Drawing::Brush^  brush);

		//!\brief draw arrow
		bool DrawArrow(System::Drawing::Graphics^ myGraphics, System::Drawing::Point Pt1,
			System::Drawing::Point Pt2, System::Drawing::Point Pt3, System::Drawing::Point Pt4);

		//!\brief draw points
		bool DrawPoints(System::Drawing::Graphics^ myGraphics);

		//!\brief draw circle
		bool DrawCircle(System::Drawing::Graphics^ myGraphics);

		//!\brief move my object
		void Move();
	};

	class GeoCircle
	{
	public:
		GeoCircle(int x,int y,int width,int height)
			:UppeLeftX(0),
			 UppeLeftY(0),
			 Width(0),
			 Height(0)
		{
			UppeLeftX = x;
			UppeLeftY = y;
			Width = width;
			Height = height;
		};
		~GeoCircle() 
		{
		};

	private:
		// no code
		int UppeLeftX;
		int UppeLeftY;
		int Width;
		int Height;
	public:

		//! access to the upper left corner X coordinate
		const int UppeLeftx() const;

		//! access to the upper left corner Y coordinate
		const int UppeLefty() const;

		//! access to the Width this object
		const int width() const;

		//! access to the Hight this object
		const int height() const;
	public:
		//! access to the center in this object
		inline vector<int> CircleCenter();
	};

	class GeoRrectangular
	{
	public:
		GeoRrectangular() {};
		~GeoRrectangular() {};

	private:
		// no code
	};

	/*
	- Notice: the class is going to be into a template class!!
	*/
	class Collision
	{

	public:
		Collision(vector<int> PosX, vector<int> PosY)
			:CheckPosx(0),
			CheckPosy(0)
		{
			CheckPosx = PosX;
			CheckPosy = PosY;
		};
		~Collision() {};

	private:
		// no code
		vector<int> CheckPosx;
		vector<int> CheckPosy;
	public:
		//! collision detection of the ellipse
		vector<int> CollsionAboutCircle(const int size);

		//! the first algorithm
		bool AlgorithmFirst(vector<int> mycenter, int index, int Others, const int size);
	};
//! \brief Process rand test-numbers 
//-------------------------------------------------------------------------
	inline vector<int> RandNumbers(int value);
}