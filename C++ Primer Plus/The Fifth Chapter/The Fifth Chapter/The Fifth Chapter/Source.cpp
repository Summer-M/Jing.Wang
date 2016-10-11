//Top-5.cpp : some exercises in c++ primer plus. 
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

long long sumin(long long First, long long Second)
{
	int sum = 0;
	long long gapNum = Second - First;

	for (unsigned  i = 0; i <= gapNum; i++)
	{
		sum += First;
		First++;
	}

	return sum;
}

int main()
{
	long long sum;
	long long FirstNum, SecondNum;
	
	while (true)
	{
		cout << "Please intput two number: ";
		cin >> FirstNum;
		cin >> SecondNum;
		
		sum = sumin(FirstNum,SecondNum);

		cout << "This is : " << sum << endl;
	}

	cin.get();
	return 0;
}

/*
2
*/

int main()
{
	array<long double, 101> factorial;

	factorial.at(0) = factorial.at(1) = 1;

	for (unsigned i = 2; i < factorial.size(); i++)
	{
		factorial.at(i) = i*factorial.at(i - 1);
	}

	for (unsigned i = 0; i < factorial.size(); i++)
	{
		cout << i << "! = " << factorial.at(i)<<endl;
	}

	cin.get();
	return 0;
}

/*
3
*/

int main()
{
	long long sum = 0;
	long long number = INT_MAX;

	cout << "Please intput your value: ";
	while (number!=0)
	{
		cin >> number;
		sum += number;
		cout << "The value is: " << sum << endl;
		cout << "Please intput your value: ";
	}

	cin.get();
	return 0;
}

/*
4
*/

int main()
{
	const unsigned int iMonth = 12;
	
	int  iCounter = 0,iSum = 0,iBook[iMonth];
	char *CMonth[] = {

		"Please intput the number of books of January: ",
		"Please intput the number of books of February: ",
		"Please intput the number of books of March: ",
		"Please intput the number of books of April: ",
		"Please intput the number of books of May : ",
		"Please intput the number of books of June : ",
		"Please intput the number of books of July: ",
		"Please intput the number of books of August : ",
		"Please intput the number of books of September : ",
		"Please intput the number of books of October : ",
		"Please intput the number of books of November: ",
		"Please intput the number of books of December: ",

	};

	while (iCounter<iMonth)
	{
		cout << CMonth[iCounter];
		cin >> iBook[iCounter];
	
		iSum += iBook[iCounter];
		iCounter++;
	}

	cout <<"This is the number of books in the year: "<<iSum<<endl;
	cin.get();
	cin.get();
	return 0;
}

/*
5
*/

int main()
{
	const unsigned int iYear  = 3;
	const unsigned int iMonth = 12;

	int iYearConunter = 0, iMonthCounter = 0, iBook[iYear][iMonth];
	
	int iSum[iYear] = { 0,0,0 };
	char *CMonth[][iMonth] = {
		// the first year
		{
			"Please intput the number of books of January in First year: ",
			"Please intput the number of books of February in First year: ",
			"Please intput the number of books of March in First year: ",
			"Please intput the number of books of April in First year: ",
			"Please intput the number of books of May in First year: ",
			"Please intput the number of books of June in First year: ",
			"Please intput the number of books of July in First year: ",
			"Please intput the number of books of August in First year: ",
			"Please intput the number of books of September in First year: ",
			"Please intput the number of books of October in First year: ",
			"Please intput the number of books of November in First year: ",
			"Please intput the number of books of December in First year: ",
		},
		// the second year
		{
			"Please intput the number of books of January in Second year: ",
			"Please intput the number of books of February in Second year: ",
			"Please intput the number of books of March in Second year: ",
			"Please intput the number of books of April in Second year: ",
			"Please intput the number of books of May in Second year: ",
			"Please intput the number of books of June in Second year: ",
			"Please intput the number of books of July in Second year: ",
			"Please intput the number of books of August in Second year: ",
			"Please intput the number of books of September in Second year: ",
			"Please intput the number of books of October in Second year: ",
			"Please intput the number of books of November in Second year: ",
			"Please intput the number of books of December in Second year: ",
		},
		// the Third year
		{
			"Please intput the number of books of January in Third year: ",
			"Please intput the number of books of February in Third year: ",
			"Please intput the number of books of March in Third year: ",
			"Please intput the number of books of April in Third year: ",
			"Please intput the number of books of May in Third year: ",
			"Please intput the number of books of June in Third year: ",
			"Please intput the number of books of July in Third year: ",
			"Please intput the number of books of August in Third year: ",
			"Please intput the number of books of September in Third year: ",
			"Please intput the number of books of October in Third year: ",
			"Please intput the number of books of November in Third year: ",
			"Please intput the number of books of December in Third year: ",
		}
	};

	while (iYearConunter<iYear)
	{
		cout << "¡¤ Please intput in current year: " << endl;
		while (iMonthCounter<iMonth)
		{
			cout << CMonth[iYearConunter][iMonthCounter];
			cin >> iBook[iYearConunter][iMonthCounter];

			iSum[iYearConunter] += iBook[iYearConunter][iMonthCounter];

			iMonthCounter++;
		}

		iYearConunter++;
		iMonthCounter = 0;
	}

	for (unsigned int i = 0; i < iYear; i++)
	{
		cout << "The number of books is " << iSum[i] << " in " << i + 1 << " year " << endl;
		if (i == 2)
		{
			cout << "The total of books is " << iSum[i] + iSum[i - 1] + iSum[i - 2] << endl;
		}
	}

	cin.get();
	cin.get();
	return 0;
}

/*
6
*/

struct car
{
	string sProducers;
	unsigned int year;
};

int main()
{
	unsigned int icar,iCounter = 1;

	cout << "How many cars do you wash to catalog?";
	while (cin>>icar)
	{
		car *mycar = new car[icar];

		for (unsigned int i = 0; i < icar; i++)
		{
			cout << "car #" << iCounter << ":" << endl;
			
			cout << "Please enter the make: ";	
			cin>> mycar[i].sProducers;
			
			cout << "Pleasr enter the year made: ";
			cin>>mycar[i].year;

			iCounter++;
		}

		cout << "Here is your collection: " << endl;
		for (unsigned int i = 0; i < icar; i++)
		{
			cout << mycar[i].year << " " << mycar[i].sProducers << endl;
		}

		cout << "How many cars do you wash to catalog?";
		iCounter = 1;
	}

	cin.get();
	cin.get();
	return 0;
}

/*
7
*/

int main()
{
	const unsigned int size = 1024;
	int  iSumWord = 0;
	char cArraysize[size];				

	while (cin>>cArraysize && strcmp("Done",cArraysize))									
	{
		iSumWord++;
	}

	cout << iSumWord << endl;

	cin.get();
	cin.get();

	return 0;
}

/*
8
*/

int main()
{
	int iCounter = 0;
	string sArraysize;

	while (cin >> sArraysize && sArraysize!="Done")
	{
		iCounter++;
	}

	cout << iCounter << endl;

	cin.get();
	cin.get();

	return 0;
}

/*
9
*/

int main()
{
	unsigned int line;

	cout << "Please intput lines: ";
	while (cin>>line)
	{
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int ii = 0; ii < line-1-i; ii++)
			{
				cout << " ";
			}

			for (unsigned int iii = 0; iii <= i; iii++)
			{
				cout << "*";
			}

			cout << endl;
		}

		cout << "Please intput lines: ";
	}

	cin.get();
	return 0;
}