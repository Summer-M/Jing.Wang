#pragma once

#include <vector>
#include <time.h>
#include <Windows.h>

#include "../Variable/Variable.h"
#include "../Geometric/Geometric.h"

namespace VisualPaint
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

	// The mutex
	extern	HANDLE		 AMutex;
	extern  HANDLE		 AMutexUseSecond;
	
	// The  Ordinary algorithm
	extern	vector<int>	 PoxXCircle;
	extern	vector<int>	 PoxYCircle;
	extern	vector<int>	 DirectionXCircle;
	extern	vector<int>	 DirectionYCircle;
	extern  vector<bool> Collect;

	// The  Optimization algorithm
	extern	vector<int>	 PoxXCircleUseSecond;
	extern	vector<int>	 PoxYCircleUseSecond;
	extern	vector<int>	 DirectionXCircleUseSecond;
	extern	vector<int>	 DirectionYCircleUseSecond;
	extern  vector<bool> CollectUseSecond;

	// The  Exit thread
	extern  bool exitthread;

	// The  Calculate Time
	extern  double checktimeaboutOrdinary;
	extern  double checktimeaboutOptimization;

	template <typename T>
	struct MyRectangle
	{
		SortType RectangleX;
		SortType RectangleY;
		SortType RectangleWidth;
		SortType RectangleHeight;
	};

	template <typename T>
	struct MyText
	{
		SortType TextX;
		SortType TextY;
	};

	template <typename T>
	struct DottedLine
	{
		SortType Point1X;
		SortType Point1Y;
		SortType Point2X;
		SortType Point2Y;
	};

	class Object
	{
	public:
		enum {/* the Cylindrical */ PosX = 20, PosY = 305, Width = 5, Height = 280 /*the Point*/, PosX1 = 30, PosY1 = 400 };
		Object() {};
		Object(SortType offX, SortType width)
			:OffsetX(0),
			OffsetW(0)
		{
			OffsetX = offX;
			OffsetW = width;
		};

		~Object() {};

	private:
		//my code
		SortType OffsetX;
		SortType OffsetW;
	public:
		//!\brief draw text
		MyText<SortType> Object::DrawText();

		//!\brief draw rectangle
		MyRectangle<SortType> Object::DrawCylindrical();

		//!\brief draw dotted line
		DottedLine<SortType> Object::DrawDottedLine();

		//!\brief draw points
		bool DrawPoints(System::Drawing::Graphics^ myGraphics);

		//!\brief draw circle
		bool DrawCircle(System::Drawing::Graphics^ myGraphics);

		//!\brief move my object
		void Move();

		//!\brief move my object
		void MoveRect();
	};

	class GeoCircle
	{
	public:
		GeoCircle(int x, int y, int width, int height)
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
		const int &UppeLeftx() const;

		//! access to the upper left corner Y coordinate
		const int &UppeLefty() const;

		//! access to the Width this object
		const int &width() const;

		//! access to the Hight this object
		const int &height() const;
	public:
		//! access to the center in this object
		inline vector<int> CircleCenter();
	};

	struct MyStructAboutRect
	{
		double x;
		double y;
	};

	struct AboutRect
	{
		unsigned int vertices;
		MyStructAboutRect rect[4];
	};

	class GeoRectangular
	{
	public:
		GeoRectangular() {};
		GeoRectangular(int leftX, int leftY, int width, int height)
		{
			upperleft.x = leftX;
			upperleft.y = leftY;
			lowerleft.x = leftX;
			lowerleft.y = leftY + height;
			topright.x = leftX + width;
			topright.y = leftY;
			lowerright.x = leftX + width;
			lowerright.y = leftY + height;

			aboutrect.vertices = 4;
			aboutrect.rect[0] = upperleft;
			aboutrect.rect[1] = lowerleft;
			aboutrect.rect[2] = topright;
			aboutrect.rect[3] = lowerright;
		};

		~GeoRectangular() {};

	private:

		// Rectangular four point coordinates
		MyStructAboutRect upperleft;
		MyStructAboutRect lowerleft;
		MyStructAboutRect topright;
		MyStructAboutRect lowerright;

		AboutRect aboutrect;

	public:
		//!\brief To obtain the normal vector
		AboutRect get() { return aboutrect; }
	};

	/*
		Notice: the class is going to be into a template class!!
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

		Collision() {}
		~Collision() {}

	private:
		// the first algorithm
		vector<int> CheckPosx;
		vector<int> CheckPosy;

	public:

		//!\brief the first algorithm
		//!\brief collision detection of the ellipse
		vector<int> CollsionAboutCircle(const int size);

		// the second algorithm
		bool AlgorithmFirst(vector<int> mycenter, int index, int Others, const int size);

		//!\brief the socond algorithm
		//!\brief collision detection of the rectangle
		// the length of this vector
		double Length(MyStructAboutRect p1, MyStructAboutRect p2);

		// the multiplication
		double Multiplication(MyStructAboutRect p1, MyStructAboutRect p2);

		// the verical
		MyStructAboutRect vertical(MyStructAboutRect p);

		// the subtraction
		MyStructAboutRect Subtraction(MyStructAboutRect p1, MyStructAboutRect p2);

		// the diatance of two vector
		double Distance(MyStructAboutRect p1, MyStructAboutRect p2);

		// the proiection
		void ProjectionOfPolygon(MyStructAboutRect p1, AboutRect rect, double *min, double *max);

		// the Projection'distance
		double ProjectionDistance(double minx0, double maxx0, double minx1, double maxx1);

		// the second algorithm
		bool AlgorithmSecond(AboutRect A, AboutRect B);
	};

	class TPoint
	{
	public:
		TPoint::TPoint()
			:x(0.00),
			 y(0.00),
			 x1(0.00),
			 y1(0.00)
		{}
		TPoint(double x00, double y00,double x01,double y01)
		{
			x  = x00;
			y  = y00;
			x1 = x01;
			y1 = y01;
		}
		~TPoint() {};

	private:
		double x;
		double y;
		double x1;
		double y1;
	public:
		double &X() { return x; }
		double &Y() { return y; }
		double &X1() { return x1; }
		double &Y1() { return y1; }
		void paint(System::Drawing::Graphics^ Object, System::Drawing::Brush^  brush, double x, double y, float size = 3.0);
	};

	//! \brief Process rand test-numbers 
	//-------------------------------------------------------------------------
	inline vector<int> RandNumbers(int value);
	inline vector<int> RandNumberss(int value);
	inline vector<int> RandNumberDirect(int value);
}