
#include "Draw.h"

namespace Geometric
{
//!\brief extern variable
//-------------------------------------------------------------------------------------
	HANDLE AMutex = NULL;
	vector<int>	PoxXCircle = RandNumbers(850);
	vector<int>	PoxYCircle = RandNumbers(800);
	vector<int> DirectionXCircle(Circlesize,9);
	vector<int> DirectionYCircle(Circlesize,17);
	vector<bool> Collect(Circlesize);

//-------------------------------------------------------------------------------------
	inline vector<int> RandNumbers(int value)
	{
		vector<int> RandNumber;
		srand((int)time(NULL));
		for (size_t i = 0; i < Circlesize; i++)
		{
			RandNumber.push_back(rand() % value);
		}

		return RandNumber;
	}

	/*
		class Object
	*/

//-------------------------------------------------------------------------------------
	MyText<SortType> Object::DrawText()
	{
		MyText<SortType> mytext;

		try
		{
			mytext.TextX = PosX + OffsetX + 3;
			mytext.TextY = PosY - 6 * OffsetW - 15;

			return mytext;
		}
		catch (const std::exception&)
		{
			EXIT_FAILURE;
		}

		return mytext;
	}

//-------------------------------------------------------------------------------------
	MyRectangle<SortType> Object::DrawCylindrical()
	{
		MyRectangle<SortType> Rectangle;

		try
		{
			Rectangle.RectangleX = PosX + OffsetX;
			Rectangle.RectangleY = PosY - 6 * OffsetW;
			Rectangle.RectangleWidth = Width;
			Rectangle.RectangleHeight = Height + 6 * OffsetW;

			return Rectangle;
		}
		catch (const std::exception&)
		{
			EXIT_FAILURE;
		}

		return Rectangle;
	}

//-------------------------------------------------------------------------------------
	DottedLine<SortType> Object::DrawDottedLine()
	{
		// pt1->pt2 or pt2->pt1
		DottedLine<SortType> dottedline;

		try
		{
			dottedline.Point1X = PosX + OffsetX;
			dottedline.Point1Y = PosY - 6 * OffsetW;
			dottedline.Point2X = 0;
			dottedline.Point2Y = PosY - 6 * OffsetW;

			return dottedline;
		}
		catch (const std::exception&)
		{
			EXIT_FAILURE;
		}

		return dottedline;
	}

//-------------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------------
	bool Object::DrawCircle(System::Drawing::Graphics^ myGraphics)
	{
		try
		{
			System::Drawing::Pen^  pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Black);
			myGraphics->FillEllipse(brush, OffsetX, OffsetW, 80, 80);
			//myGraphics->DrawEllipse(pen, PosX1 + OffsetX, PosY1 - OffsetW, 3, 3); 
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

//-------------------------------------------------------------------------------------
	void Object::Move(/*the function change circle position*/)
	{
		/*
		-------------------------------------------------------------
		|															|
		|		                   |								|
		|	                      -0-								|
		|		                   |								|
		|															|
		------------------------------------------------------------
		*/
		while (true)
		{
			//lock
			WaitForSingleObject(AMutex, INFINITE);
			for (size_t i = 0; i < Circlesize; i++)
			{
				// go to the wall
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

				Collision collision(PoxXCircle, PoxYCircle);
				vector<int> CollsionAboutCircle = collision.CollsionAboutCircle(Circlesize);

				//! collision detection
				//! here will use several different collision detection algorithm
				//! Elastic change the speed
				//! -------------------------start-------------------------------------
				for (size_t iIndex = 0; iIndex < Circlesize; iIndex++)
				{
					if (iIndex == i)
						continue;
					if (!collision.AlgorithmFirst(CollsionAboutCircle, i * 2, iIndex * 2, Circlesize))								     //!!!
					{
						/* The First treament */
						Collect[i] = false;

						/* The Second treatment */
						/*------------------------------------------------------------------------------------------------------------------------
						------------------------------------------------------------------------------------------------------------------------
						double degreeFirst = (PoxXCircle[i] - PoxXCircle[iIndex]) == 0 ?
						Math::Atan((PoxYCircle[i] - PoxYCircle[iIndex]) / (PoxXCircle[i] - PoxXCircle[iIndex] + 0.1))
						: Math::Atan((PoxYCircle[i] - PoxYCircle[iIndex]) / (PoxXCircle[i] - PoxXCircle[iIndex] + 0.1));

						if (PoxXCircle[i] > PoxXCircle[iIndex])
						{
						DirectionXCircle[i] = Math::Cos(degreeFirst) + 3;
						DirectionYCircle[i] = Math::Sin(degreeFirst) + 3;

						PoxXCircle[i] += DirectionXCircle[i];
						PoxYCircle[i] += DirectionYCircle[i];

						PoxXCircle[iIndex] += DirectionXCircle[iIndex];
						PoxYCircle[iIndex] += DirectionYCircle[iIndex];
						}
						else
						{
						DirectionXCircle[i] = -Math::Cos(degreeFirst) - 3;
						DirectionYCircle[i] = -Math::Sin(degreeFirst) - 3;

						PoxXCircle[i] += DirectionXCircle[i];
						PoxYCircle[i] += DirectionYCircle[i];

						PoxXCircle[iIndex] += DirectionXCircle[iIndex];
						PoxYCircle[iIndex] += DirectionYCircle[iIndex];
						}

						double degreeSecond = (PoxXCircle[iIndex] - PoxXCircle[i]) == 0 ?
						Math::Atan((PoxYCircle[iIndex] - PoxYCircle[i]) / (PoxXCircle[iIndex] - PoxXCircle[i] + 0.1))
						: Math::Atan((PoxYCircle[iIndex] - PoxYCircle[i]) / (PoxXCircle[iIndex] - PoxXCircle[i]));

						if (PoxXCircle[iIndex] > PoxXCircle[i])
						{
						DirectionXCircle[iIndex] = Math::Cos(degreeSecond) + 3;
						DirectionYCircle[iIndex] = Math::Sin(degreeSecond) + 3;

						PoxXCircle[i] += DirectionXCircle[i];
						PoxYCircle[i] += DirectionYCircle[i];

						PoxXCircle[iIndex] += DirectionXCircle[iIndex];
						PoxYCircle[iIndex] += DirectionYCircle[iIndex];
						}
						else
						{
						DirectionXCircle[iIndex] = -Math::Cos(degreeSecond) - 3;
						DirectionYCircle[iIndex] = -Math::Sin(degreeSecond) - 3;

						PoxXCircle[i] += DirectionXCircle[i];
						PoxYCircle[i] += DirectionYCircle[i];

						PoxXCircle[iIndex] += DirectionXCircle[iIndex];
						PoxYCircle[iIndex] += DirectionYCircle[iIndex];
						}
						}

						-----------------------------------------------------------------------------------------
						-----------------------------------------------------------------------------------------
						*/
					}
				}

				//! ---------------------------end--------------------------------------
			}

			//unlock
			Sleep(50);
			ReleaseMutex(AMutex);
		}
	}

//-------------------------------------------------------------------------------------
	void Object::MoveRect(/*the function change circle position*/)
	{
		/*
		-------------------------------------------------------------
		|															|
		|		                   |								|
		|	                      -0-								|
		|		                   |								|
		|															|
		------------------------------------------------------------
		*/

		Collision collision;

		while (true)
		{
			//lock
			WaitForSingleObject(AMutex, INFINITE);
			for (size_t i = 0; i < Circlesize; i++)
			{
				// go to the wall
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

				GeoRectangular currentrectangle(PoxXCircle[i], PoxYCircle[i], CircleW, CircleH);

				////! collision detection
				////! here will use several different collision detection algorithm
				////! Elastic change the speed
				////! -------------------------start-------------------------------------
				for (size_t iIndex = 0; iIndex < Circlesize; iIndex++)
				{
					if (iIndex == i)
						continue;

					GeoRectangular georectangular(PoxXCircle[iIndex], PoxYCircle[iIndex], CircleW, CircleH);

					if (collision.AlgorithmSecond(currentrectangle.get(), georectangular.get()))			//!!!
					{
						Collect[i] = false;
						break;	
					}
					else
					{
						Collect[i] = true;
					}
				}

				//! ---------------------------end--------------------------------------
			}

			//unlock
			Sleep(30);
			ReleaseMutex(AMutex);
		}
	}

	/*
		Collision
	*/
	
//-------------------------------------------------------------------------------------
	vector<int> Collision::CollsionAboutCircle(const int size)
	{
		vector<int> PosCenter;
		for (size_t i = 0; i < Circlesize; i++)
		{
			GeoCircle gricircle(CheckPosx[i], CheckPosy[i], CircleW, CircleH);
			PosCenter.push_back(gricircle.CircleCenter()[0]);
			PosCenter.push_back(gricircle.CircleCenter()[1]);
		}

		return PosCenter;
	}

//-------------------------------------------------------------------------------------
	bool Collision::AlgorithmFirst(vector<int> mycenter, int index, int Others, const int size)
	{
		if (sqrt(pow(mycenter[index] - mycenter[Others], 2) + pow(mycenter[index + 1] - mycenter[Others + 1], 2)) <= CircleW)
		{
			return false;
		}

		return true;
	}

//-------------------------------------------------------------------------------------
	double Collision::Length(MyStructAboutRect p1, MyStructAboutRect p2)
	{
		return sqrt(p1.x*p2.x + p1.y*p2.y);
	}

//-------------------------------------------------------------------------------------
	double Collision::Multiplication(MyStructAboutRect p1, MyStructAboutRect p2)
	{
		return p1.x * p2.x + p1.y * p2.y;
	}

//-------------------------------------------------------------------------------------
	MyStructAboutRect Collision::vertical(MyStructAboutRect p)
	{
		return MyStructAboutRect{ -p.y,p.x };
	}

//-------------------------------------------------------------------------------------
	MyStructAboutRect Collision::Subtraction(MyStructAboutRect p1, MyStructAboutRect p2)
	{
		return MyStructAboutRect{ p1.x - p2.x,p1.y - p2.y };
	}
//-------------------------------------------------------------------------------------
	double Collision::Distance(MyStructAboutRect p1, MyStructAboutRect p2)
	{
		return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
	}
//-------------------------------------------------------------------------------------
	void Collision::ProjectionOfPolygon(MyStructAboutRect p1, AboutRect polygon, double *min, double *max)
	{
		double distance = Multiplication(p1, polygon.rect[0]);
		*min = *max = distance;

		for (size_t i = 0; i < polygon.vertices; i++)
		{
			distance = Multiplication(p1, polygon.rect[i]);
			if (distance < *min)
			{
				*min = distance;
			}
			else if (distance > *max)
			{
				*max = distance;
			}
		}
	}
//-------------------------------------------------------------------------------------
	double Collision::ProjectionDistance(double minx0, double maxx0, double minx1, double maxx1)
	{
		return (minx0 < minx1) ? (minx1 - maxx0) : (minx0 - maxx1);
	}
//-------------------------------------------------------------------------------------
	bool Collision::AlgorithmSecond(AboutRect A,AboutRect B)
	{
		MyStructAboutRect verticals, origin;
		double minx0 = 0, maxx0 = 0, minx1 = 0, maxx1 = 0;
		for (size_t i = 0,j = A.vertices-1; i < A.vertices + B.vertices; j = i,i++)
		{
			if (i < A.vertices)
			{
				// the criterion in A
				origin = Subtraction(A.rect[i], A.rect[j]);
			}
			else
			{
				// the criterion in B
				origin = Subtraction(B.rect[i - A.vertices], B.rect[j - A.vertices]);
			}

			// get vertical
			verticals = vertical(origin);

			// get projections
			ProjectionOfPolygon(verticals, A, &minx0, &maxx0);
			ProjectionOfPolygon(verticals, B, &minx1, &maxx1);

			// collision?
			if (ProjectionDistance(minx0, maxx0, minx1, maxx1)>0)
			{
				return false;
			}
		}

		return true;
	}

	/*
		class GeoCircle
	*/

//-------------------------------------------------------------------------------------
	const int &GeoCircle::UppeLeftx() const
	{
		return UppeLeftX;
	}

//-------------------------------------------------------------------------------------
	const int &GeoCircle::UppeLefty() const
	{
		return UppeLeftY;
	}

//-------------------------------------------------------------------------------------
	const int &GeoCircle::width() const
	{
		return Width;
	}

//-------------------------------------------------------------------------------------
	const int &GeoCircle::height() const
	{
		return Height;
	}

//-------------------------------------------------------------------------------------
	inline vector<int> GeoCircle::CircleCenter()
	{
		vector<int> CircleStruct;
		CircleStruct.push_back(UppeLeftx() + width() / 2);
		CircleStruct.push_back(UppeLefty() + height() / 2);
		return CircleStruct;
	}
}