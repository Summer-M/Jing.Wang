#pragma once

#include <iostream>

using namespace std;

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double averages;
		double max;
		double min;
	};

	//
	void setSales(Sales &s, const double ar[], int n);

	//
	void setSales(Sales &s);

	//
	void showSales(Sales &s);
}
