//Top-8.cpp : some exercises in c++ primer plus. 
//

#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cctype>
#include <cmath>
#include <fstream>

#include "Header.h"

using namespace std;


/*
1
*/

int main()
{
	golf g;
	golf Ann;
	while (true)
	{
		cin >> g.fullname;
		cin >> g.handicap;

		setgolf(g);
		setgolf(Ann, "Ann Birdfree", 24);

		showgolf(g);
		cout << endl;
		showgolf(Ann);
		cout << endl;
	}

	system("pause");
	return 0;
}

// non-interactive version
void setgolf(golf &g, const char *name, int hc)
{
	//g.fullname = "";
	g.handicap = hc;
}

// interactive version
int setgolf(golf &g)
{
	//g.fullname

	return 1;
}

// reset handicap
void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

// display
void showgolf(const golf &g)
{
	cout << g.fullname << endl;
	cout << g.handicap << endl;
}

/*
2
*/

struct chaff
{
	char dross[20];
	int slag;
};


int main()
{
	chaff *mychaff = new chaff[2];

	for (size_t i = 0; i < 2; i++)
	{
		cin >> mychaff[i].dross;
		cin >> mychaff[i].slag;
	}

	for (size_t i = 0; i < 2; i++)
	{
		cout << mychaff[i].dross << endl;
		cout << mychaff[i].slag << endl;
	}

	system("pause");
	return 0;
}

/*
3
*/

int main()
{
	const double test[4] = { 4,12,43,71 };
	SALES::Sales mysale;

	SALES::setSales(mysale, test, 4);
	SALES::showSales(mysale);

	system("pause");
	return 0;
}











