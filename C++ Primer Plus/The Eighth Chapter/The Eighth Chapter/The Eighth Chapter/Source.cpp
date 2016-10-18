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

using namespace std;


/*
1
*/
//
//void printstring( const char str[] );
//void printstring( const char str[], int iCounter );
//
//int main()
//{
//	int iCounter = 5;
//	const char ch[] = "hello world";
//	printstring(ch);
//
//	for (size_t i = 0; i < iCounter; i++)
//	{
//		printstring(ch, iCounter);
//	}
//
//	system("pause");
//	return 0;
//}
//
//void printstring(const char str[])
//{
//	cout << str << endl;
//}
//void printstring(const char str[], int iCounter)
//{
//	cout << str << endl;
//}

/*
2
*/

//const unsigned int iSize = 20;
//
//struct Candybar
//{
//	char *name;
//	double weight;
//	int hot;
//};
//
//void Update( Candybar &mybar, char *ch, double dWeight, int iHot );
//void Display( Candybar &mybar );
//
//int main()
//{
//	Candybar mybar;
//	Update( mybar,"Chengzhen",2.85,350);
//	Display(mybar);
//
//	system("pause");
//	return 0;
//}
//
//void Update(Candybar &mybar, char *ch, double dWeight, int iHot)
//{
//	mybar.name = ch;
//	mybar.weight = dWeight;
//	mybar.hot = iHot;
//}
//
//void Display( Candybar &mybar )
//{
//	cout << mybar.name << endl;
//	cout << mybar.weight <<endl;
//	cout << mybar.hot << endl;
//}

/*
3
*/

//void ConvertTocApital(string &str);
//
//int main()
//{
//	string str;
//	
//	while( getline(cin,str) && str!="q" )
//	{
//		ConvertTocApital(str);
//		cout << str << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
//void ConvertTocApital(string &str)
//{
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if(str.at(i)!=' ')
//		  str.at(i) = toupper(str.at(i));										//!< the "string" is "const string"
//	}
//}

/*
4£¨4 is omited£©
*/

/*
5
*/

template <typename T>
T max5(T Tarray[])
{
	T Tmax(0);
	for (size_t i = 0; i < 5; i++)
	{
		if (Tmax < Tarray[i])
		{
			Tmax = Tarray[i];
		}
	}

	return Tmax;
}

template <typename T>
T maxn(T Tarray[], int iSize)
{
	T Tmax(0);
	for (size_t i = 0; i < iSize; i++)
	{
		if (Tmax < Tarray[i])
		{
			Tmax = Tarray[i];
		}
	}

	return Tmax;
}

int main()
{
	int test1[5] = { 45,41,67,9,13 };
	double test2[5] = {34.09,21.02,3.4,699.2,0.5};

	int test3[6] = { 28,21,79,66,1,98 };
	double test4[4] = { 24.09,1.02,51.09,17.8};
	char *test5[] = {
						"test1",
						"test12",
						"test123",
						"test1234",
						"test12345"
	};

	cout << max5(test1) << endl;
	cout << max5(test2) << endl;
	cout << maxn(test3,6) << endl;
	cout << maxn(test4,4) << endl;
	cout << maxn(test5,5) << endl;

	system("pause");
	return 0;						
}





