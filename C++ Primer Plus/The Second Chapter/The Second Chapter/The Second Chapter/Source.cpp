//Top-2.cpp : some exercises in c++ primer plus. 
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

using namespace std;

/*
1
*/

void PrintTime( unsigned int hour, unsigned int minutes )
{
	cout << "Time: " << hour << ":" << minutes << endl;
}

int main()
{
	unsigned int hour, minutes;

	while (1)
	{
		cout << "Enter the number of hours: ";
		cin  >> hour;
		cout << "Enter the number of minutes: ";
		cin  >> minutes;

		PrintTime(hour, minutes);
	}

	cin.get();
	return 0;
}
