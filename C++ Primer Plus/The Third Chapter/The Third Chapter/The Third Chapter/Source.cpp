//Top-3.cpp : some exercises in c++ primer plus. 
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
int main()
{
	const unsigned int Conversionfactor_to_Lnches = 12;
	const unsigned int Conversionfactor_to_Kg	  = 2.2;
	const unsigned int Conversionfactor_to_Mi	  = 0.0254;
	unsigned int iHeightFeet, iHeightLnches, iWeight;
	double BMI;

	while (1)
	{
		cout << "Please input your iHeightFeet,iHeightLnches,iWeight: " << endl;
		cout << "First,input your iHeightFeet:___Feet\b\b\b\b\b\b\b";
		cin  >> iHeightFeet;
		cout << "Second,input your iHeightLnches:___Lnches\b\b\b\b\b\b\b\b\b";
		cin  >> iHeightLnches;
		cout << "Finally,input your Weight:_____\b\b\b\b\b";
		cin  >> iWeight;

		BMI = (iWeight*Conversionfactor_to_Kg) / pow(((iHeightFeet *Conversionfactor_to_Lnches + iHeightLnches)*Conversionfactor_to_Mi), 2);

		cout << BMI << endl;
	}
		
	cin.get();
	return 0;
}

/*
2
*/

int main()
{
	const unsigned int factor = 60;
	unsigned int degree, minute, seconds;
	double   sum;

	while (1)
	{
		cout << "Enter a latitude in degrees,minutes, and seconds:" << endl;
		cout << "First,enter the degree: ";
		cin >> degree;
		cout << "Second,enter the minutes of arc: ";
		cin >> minute;
		cout << "Finally,enter the seconds of arc: ";
		cin >> seconds;

		sum = double(double(degree) + double(minute) / 60 + double(seconds) / 3600);

		cout << degree << "degrees," << minute << "minutes," << seconds << "seconds = " << sum <<" degrees"<< endl;
	}

	cin.get();
	return 0;
}

/*
3
*/

int main()
{
	long long PeopleInWorld,USInWorld;
	double per;

	while ( 1 )
	{
		cout << "Enter the world's population: ";
		cin >> PeopleInWorld;
		cout << "Enter the population of the US: ";
		cin >> USInWorld;
		per = double( USInWorld )/double( PeopleInWorld );
		cout << "The population of the us is " << per << " of the world population." << endl;
	}

	cin.get();
	return 0;
}
