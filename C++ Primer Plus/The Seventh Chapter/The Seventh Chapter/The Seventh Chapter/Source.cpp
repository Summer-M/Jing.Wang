//Top-7.cpp : some exercises in c++ primer plus. 
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

/*
struct boss
{};
*/

 // void igor();
 // float tofu(int iValue);
 // double mpg(double d1,double d2);
 // long summation(long larray[],long lSize);
 // void ofcourse(boss bStruct);
 // void plot(map *m);

const unsigned int iSize = 10;

void Modify1(int iarray[], int iSize, int iValue);
void Modify2(int *iPFirst, int *iPEnd, int iValue);
void ObtainMax(double darray[], int iSize);
int  replace(char *str, char c1, char c2);

int main()
{
	int iarray[iSize] = { 10,9,8,7,6,5,4,3,2,1 };
	char carry[iSize] = {'q','e','e','r','t','y','u','p','a','v'};
	double darray[iSize] = { 123.3,56,11.1,678,22,9,62.2,4.1,2,78.5 };

	//
	Modify1(iarray, iSize, 24);
	cout << endl;

	//
	Modify2(iarray, iarray + iSize, 23);
	cout << endl;

	//
	ObtainMax(darray, iSize);
	cout << endl;

	//
	cout << replace(carry, 'e', 'h') << endl;

	system("pause");
	return 0;
}

void Modify1(int iArray[], int iSize, int iValue)
{
	for (size_t i = 0; i < iSize; i++)
	{
		iArray[i] = iValue;
		cout << iArray[i] << " ";
	}
}

void Modify2(int *iPFirst, int *iPSecond, int iValue)
{
	while (iPFirst != iPSecond)
	{
		*iPFirst = iValue;
		cout << *iPFirst << " ";
		iPFirst++;
	}
}

void ObtainMax(double darray[], int iLength)
{
	double	*dPos = new double[iLength];
	dPos = darray;
	
	for ( size_t i = 0; i < iLength; i++ )
	{
		if (i + 1 < iLength && *dPos < darray[i + 1])
		{
			*dPos = darray[i + 1];
		}
	}

	cout << *dPos;
}

int replace(char *str, char c1, char c2)
{
	int iCounter = 0;
	while ( *str++ )
	{
		if (*str == c1)
		{
			*str = c2;
			iCounter++;
		}
	}

	return iCounter;
}


/*
2
*/

void ScanfGrand(double *dGrand, int Length);
void printfGrand(double *dGrand, int Length);
void Cal(double *dGrand, int Length);

int main()
{
	/*
	int ia, ib;
	while ( cin >> ia >> ib && ia!=0 && ib!=0)
	{
		cout << 2 * ia*ib / (ia+ib) << endl;
	}

	cout << "Over!" << endl;
	*/

	int length;
	double dGolfGrade[10];
	
	cin >> length;
	ScanfGrand(dGolfGrade, length);
	
	printfGrand(dGolfGrade, length);
	cout << endl;
	
	Cal(dGolfGrade, length);
	cout << endl;

	system("pause");
	return 0;
}

void ScanfGrand( double *dGrand, int Length )
{
	while ( Length-- )
	{
	   cin >> *dGrand++;
	}
}

void printfGrand( double *dGrand, int Length )
{
	while (Length--)
	{
	   cout << *dGrand << " ";
	   *dGrand++;
	}
}

void Cal( double *dGrand, int Length )
{
	int iSize = Length;
	double sum = 0;
	while (Length--)
	{
		sum = sum + *dGrand;
		*dGrand++;
	}

	cout << double(sum / iSize) << endl;
}

/*
3
*/

struct box
{
	char  marker[40];
	float height;
	float width;
	float length;
	float volume;
};

void display( box box1 );
void setvolumn(box &box1);

int main()
{
	box mybox = 
	{
		"123",
		1,
		2,
		3,
		21.3,
	};

	//display( mybox ); 
	//setvolumn(mybox);

	cout << mybox.volume << endl;

	system("pause");
	return 0;
}

void display(box box1)
{
	cout << box1.marker << endl;
	cout << box1.height << endl;
	cout << box1.width  << endl;

	cout << box1.length << endl;
	cout << box1.volume << endl;
}

void setvolumn( box &box1)
{
	box1.volume = box1.height * box1.length * box1.width;
}

/*
4
*/

long long factorial( int i );

int main()
{
	long long lSum = 0;
	int ia;
	while (cin>>ia)
	{
		lSum = factorial(ia);
		cout << lSum << endl;
	}

	system("pause");
	return 0;
}

long long factorial(int i)
{
	if ( i == 0 )
		return 1;
	else if (i > 0)
	{
		return i* factorial(i - 1);
	}
}

/*
5
*/

void Fill_array(double dArray[], int iLength);
void Show_array(double dArray[], int iLength);
void Reverse_array(double dArray[], int iLength);
double calculate(double x, double y, double p(double x, double y));
double add(double x, double y);

int main()
{
	double darray[10];

	Fill_array(darray, 10);
	Show_array(darray, 10);

	Reverse_array(darray, 10);
	Show_array(darray, 10);

	double sum = calculate(4, 5, add);
	cout << sum << endl;

	system("pause");
	return 0;
}

void Fill_array(double dArray[], int iLength)
{
	int iCounter = 0;
	for (size_t i = 0; i < iLength; i++)
	{
		cin >> dArray[i];
		if (isalpha(dArray[i]))
		{
			return;
		}
	}
}

void Show_array(double dArray[], int iLength)
{
	for (size_t i = 0; i < iLength; i++)
	{
		cout << dArray[i] << " ";
	}
	cout << endl;
}

void Reverse_array(double dArray[], int iLength)
{
	double *p = new double[iLength];
	p = dArray;

	double dMiddle = 0;
	for (size_t i = 0; i < 5; i++)
	{
		dMiddle = p[i];

		p[i] = p[iLength - i - 1];
		p[iLength - i - 1] = dMiddle;
	}
}

double calculate(double x, double y, double p(double x, double y))
{
	double sum = p(x, y);
	return sum;
}

double add(double x, double y)
{
	return x + y;
}












