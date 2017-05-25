#pragma once
#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include <iostream>

using namespace std;

//! \file 
//! this namespace define some classes about VisualPaint
namespace Geo
{
	class CTMFORPOINT
	{
	public:
		CTMFORPOINT()
		{
			std::fill(matrix, matrix + 6, 0);
		};
		CTMFORPOINT(double x00, double x01, double x10, double x11,double x100,double x101)
		{
			matrix[0] = x00; matrix[1] = x01; matrix[2] = x10;
			matrix[3] = x11; matrix[4] = x100; matrix[5] = x101;
		}
		~CTMFORPOINT() {};

	private:
		double matrix[6];
	public:
		void Transform(double &x,double &y);
	};
}
#endif // !1
