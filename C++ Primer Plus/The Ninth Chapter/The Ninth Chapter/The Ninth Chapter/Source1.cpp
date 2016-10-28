// Top-8.cpp : some exercises in c++ primer plus. 
//

#include "Header.h"

/*
1
*/
const int len = 40;
struct golf
{
	char fullname[len];
	int handicap;
};

// non-interactive version
void setgolf(golf &g, const char *name, int hc);

// interactive version
int setgolf(golf &g);

// reset handicap
void handicap(golf &g, int hc);

// display
void showgolf(const golf &g);


/*
3
*/
namespace SALES
{

	//------------------------------------------------------------------	
	void setSales(Sales &s, const double ar[], int n)
	{
		double average = 0;
		// sales
		for (size_t i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
		}

		int iMax, iMin;
		iMax = iMin = s.sales[0];

		//max and min
		for (size_t i = 0; i < n; i++)
		{
			if (iMax < s.sales[i])
			{
				iMax = s.sales[i];
			}

			if (iMin > s.sales[i])
			{
				iMin = s.sales[i];
			}

			average += s.sales[i];
		}

		s.averages = average / n;
		s.max = iMax;
		s.min = iMin;
	}

	//------------------------------------------------------------------	
	void setSales(Sales &s)
	{


	}

	//------------------------------------------------------------------
	void showSales(Sales &s)
	{
		for (size_t i = 0; i < 4; i++)
		{
			cout << s.sales[i] << endl;
		}

		cout << s.averages << endl;
		cout << s.max << endl;
		cout << s.min << endl;
	}

}



