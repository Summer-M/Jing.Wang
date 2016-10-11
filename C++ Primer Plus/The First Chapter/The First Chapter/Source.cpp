//Top-1.cpp : some exercises in c++ primer plus. 
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

//void PrintTime( unsigned int hour, unsigned int minutes )
//{
//	cout << "Time: " << hour << ":" << minutes << endl;
//}
//
//int main()
//{
//	unsigned int hour, minutes;
//
//	while (1)
//	{
//		cout << "Enter the number of hours: ";
//		cin  >> hour;
//		cout << "Enter the number of minutes: ";
//		cin  >> minutes;
//
//		PrintTime(hour, minutes);
//	}
//
//	cin.get();
//	return 0;
//}

/*
2
*/
//int main()
//{
//	unsigned int iHeight;
//	const unsigned int Conversion_factor = 12;
//	while (1)
//	{
//		cout << "Please intput your height:_____\b\b\b\b\b";
//		cin  >> iHeight;
//		cout << "This is your height:" << iHeight / 12 << endl;
//	}
//
//	cin.get();
//	return 0;
//}
//

/*
3
*/
//int main()
//{
//	const unsigned int Conversionfactor_to_Lnches = 12;
//	const unsigned int Conversionfactor_to_Kg	  = 2.2;
//	const unsigned int Conversionfactor_to_Mi	  = 0.0254;
//	unsigned int iHeightFeet, iHeightLnches, iWeight;
//	double BMI;

//	while (1)
//	{
//		cout << "Please input your iHeightFeet,iHeightLnches,iWeight: " << endl;
//		cout << "First,input your iHeightFeet:___Feet\b\b\b\b\b\b\b";
//		cin  >> iHeightFeet;
//		cout << "Second,input your iHeightLnches:___Lnches\b\b\b\b\b\b\b\b\b";
//		cin  >> iHeightLnches;
//		cout << "Finally,input your Weight:_____\b\b\b\b\b";
//		cin  >> iWeight;
//
//		BMI = (iWeight*Conversionfactor_to_Kg) / pow(((iHeightFeet *Conversionfactor_to_Lnches + iHeightLnches)*Conversionfactor_to_Mi), 2);
//
//		cout << BMI << endl;
//	}
//		
//	cin.get();
//	return 0;
//}

/*
4
*/

//int main()
//{
//	const unsigned int factor = 60;
//	unsigned int degree, minute, seconds;
//	double   sum;
//
//	while (1)
//	{
//		cout << "Enter a latitude in degrees,minutes, and seconds:" << endl;
//		cout << "First,enter the degree: ";
//		cin >> degree;
//		cout << "Second,enter the minutes of arc: ";
//		cin >> minute;
//		cout << "Finally,enter the seconds of arc: ";
//		cin >> seconds;
//
//		sum = double(double(degree) + double(minute) / 60 + double(seconds) / 3600);
//
//		cout << degree << "degrees," << minute << "minutes," << seconds << "seconds = " << sum <<" degrees"<< endl;
//	}
//
//	cin.get();
//	return 0;
//}

/*
5
*/

//int main()
//{
//	long long PeopleInWorld,USInWorld;
//	double per;
//
//	while ( 1 )
//	{
//		cout << "Enter the world's population: ";
//		cin >> PeopleInWorld;
//		cout << "Enter the population of the US: ";
//		cin >> USInWorld;
//		per = double( USInWorld )/double( PeopleInWorld );
//		cout << "The population of the us is " << per << " of the world population." << endl;
//	}
//
//	cin.get();
//	return 0;
//}

/*
6
*/

//const unsigned int arraysize = 30;
//
//struct student
//{
//	char firstname[arraysize];
//	char lastname[arraysize];
//	char grade;
//	unsigned int age;
//};
//
//void Diaplay(student mystudent)
//{
//	cout << "Name: " << mystudent.lastname << "," << mystudent.firstname<<endl;
//	cout << "Grade: " << char(mystudent.grade+1)<<endl;
//	cout << "Age: " << mystudent.age << endl;
//}
//
//int main()
//{
//	student mystudent;
//	
//	while (true)
//	{
//		cout << "What is your first name?";
//		cin.getline(mystudent.firstname,arraysize);
//
//		cout << "What is your last name?";
//		cin.getline(mystudent.lastname,arraysize);
//
//		cout << "What letter grade do you deserve?";
//		cin >> mystudent.grade;
//
//		cout << "What is your age?";
//		cin >> mystudent.age;
//
//		Diaplay(mystudent);
//	}
//	
//	cin.get();
//	return 0;
//}

/*
7
*/

//int main()
//{
//	std::string name, dessert;
//	while (true)
//	{
//		cout << "Enter your name: "<<endl;
//		cin >> name;
//
//		cout << "Enter your favorite dessert: "<<endl;
//		cin >> dessert;
//
//		cout << "I have some delicious " << dessert;
//		cout << " for you, " << name << endl; 
//	}
//	
//	cin.get();
//	return 0;
//}

/*
8
*/
//int main()
//{
//	const unsigned int arraysize = 30;
//	char firststring[arraysize];
//	char secondstring[arraysize];
//	std::string sumstring = "";
//
//	while (true)
//	{
//		cout << "Enter your first name: ";
//		cin.getline(firststring, arraysize);
//
//		sumstring.append(firststring);
//		sumstring.append(",");
//
//		cout << "Enter your last name: ";
//		cin.getline(secondstring, arraysize);
//		sumstring.append(secondstring);
//
//		cout <<"Here is the information in a single string: " << sumstring <<endl;
//	}
//	
//	cin.get();
//	return 0;
//}
//

/*
9
*/

//int main()
//{
//	std::string firststring;
//	std::string secondstring;
//	std::string sumstring = "";
//
//	while (true)
//	{
//		cout << "Enter your first name: ";
//		cin >> firststring;
//		sumstring.append(firststring+",");
//
//		cout << "Enter your last name: ";
//		cin >> secondstring;
//		sumstring.append(secondstring);
//
//		cout <<"Here is the information in a single string: " << sumstring <<endl;
//	}
//	
//	cin.get();
//	return 0;
//}

/*
10 and 11
*/

//const unsigned int arraysize = 30;
//
//struct CandyBar
//{
//	char   brand[arraysize];
//	double weight;
//	int    calories;
//};
//
//int main()
//{
//	CandyBar	candybar[2]= 
//	{
//		{"The Alps",45.13,120 },
//		{"The Apple",32,58}
//	};
//
//	cout << candybar[0].brand << "," << candybar[0].calories << "," << candybar[0].weight << endl;
//	cout << candybar[1].brand << "," << candybar[1].calories << "," << candybar[1].weight << endl;
//
//	cin.get();
//	return 0;
//}
//

/*
12 and 13
*/
//
//const unsigned int arraysize = 100;
//
//struct mystruct
//{
//	char CompanyName[arraysize];
//	unsigned int  diameter;
//	unsigned int  weight;
//};
//
//int main()
//{
//	//mystruct  company;
//	//while (true)
//	//{
//	//	cout << "Please input some information about this company: " << endl;
//	//	cout << "First,intput this company: ";
//	//	cin.getline(company.CompanyName,arraysize);
//
//	//	cout << "Second,intput this diameter: ";
//	//	cin >> company.diameter;
//
//	//	cout << "Finally,intput this weight: ";
//	//	cin >> company.weight;
//
//	//	cout << "Company Name : " << company.CompanyName<<endl;
//	//	cout << "diamater : " << company.diameter<<endl;
//	//	cout << "weight : " << company.weight<<endl;
//	//}
//
//	mystruct *company = new mystruct;
//
//	while (true)
//	{
//		cout << "Please intput some information about this company: " << endl;
//		cout << "First,intput this diameier: ";
//		cin >> company->diameter;
//
//		cout << "Second,intput this company: ";
//		cin >> company->CompanyName;
//
//		cout << "Finally,intput this weight: ";
//		cin >> company->weight;
//
//		cout << "Company Name : " << company->CompanyName<<endl;
//		cout << "diamater : " << company->diameter<<endl;
//		cout << "weight : " << company->weight<<endl;
//}
//
//	cin.get();
//	return 0;
//}
//

/*
14
*/

//const unsigned int arraysize = 100;
//
//struct mystruct
//{
//	char CompanyName[arraysize];
//	unsigned int  diameter;
//	unsigned int  weight;
//};
//
//int main()
//{
//	unsigned int size;
//
//	cout << "Please intput the size of company: ";
//	while (cin>>size)
//	{
//		mystruct *company = new mystruct[size];
//		
//		for (unsigned int i = 0; i < size; i++)
//		{
//			cout << "First,intput this company: ";
//			cin >> company[i].CompanyName;
//
//			cout << "Second,intput this diameter: ";
//			cin >> company[i].diameter;
//
//			cout << "Second,intput this weight: ";
//			cin >> company[i].weight;
//		}
//
//		for(unsigned int i = 0;i<size;i++)
//		{
//			cout << "--------------------------------------------\n";
//			cout << "The Company: ";
//			cout << company[i].CompanyName << endl;
//
//			cout << "The diameter: ";
//			cout << company[i].diameter << endl;
//			
//			cout << "The weight: ";
//			cout << company[i].weight << endl;
//		}
//
//		cout << "Please intput the size of company: ";
//	}
//	
//	cin.get();
//	return 0;
//}

/*
15
*/

//int main()
//{
//	unsigned int counter = 0;
//	array<double, 3> Grade;
//
//	while (true)
//	{
//		while (counter < Grade.size())
//		{
//			cout << "This is " << counter + 1 << " numbers" << endl;
//			cout << "please intput your Grade: ";
//			cin >> Grade[counter++];
//		}
//
//		counter = 0;
//
//		while (counter < Grade.size())
//		{
//			cout <<Grade[counter++]<<" "; 
//		}
//
//		counter = 0;
//		cout << endl;
//	}
//
//	cin.get();
//	return 0;
//}

/*
16
*/

//long long sumin(long long First, long long Second)
//{
//	int sum = 0;
//	long long gapNum = Second - First;
//
//	for (unsigned  i = 0; i <= gapNum; i++)
//	{
//		sum += First;
//		First++;
//	}
//
//	return sum;
//}
//
//int main()
//{
//	long long sum;
//	long long FirstNum, SecondNum;
//	
//	while (true)
//	{
//		cout << "Please intput two number: ";
//		cin >> FirstNum;
//		cin >> SecondNum;
//		
//		sum = sumin(FirstNum,SecondNum);
//
//		cout << "This is : " << sum << endl;
//	}
//
//	cin.get();
//	return 0;
//}

/*
17
*/

//int main()
//{
//	array<long double, 101> factorial;
//
//	factorial.at(0) = factorial.at(1) = 1;
//
//	for (unsigned i = 2; i < factorial.size(); i++)
//	{
//		factorial.at(i) = i*factorial.at(i - 1);
//	}
//
//	for (unsigned i = 0; i < factorial.size(); i++)
//	{
//		cout << i << "! = " << factorial.at(i)<<endl;
//	}
//
//	cin.get();
//	return 0;
//}

/*
18
*/

//int main()
//{
//	long long sum = 0;
//	long long number = INT_MAX;
//
//	cout << "Please intput your value: ";
//	while (number!=0)
//	{
//		cin >> number;
//		sum += number;
//		cout << "The value is: " << sum << endl;
//		cout << "Please intput your value: ";
//	}
//
//	cin.get();
//	return 0;
//}

/*
19
*/
//
//int main()
//{
//	const unsigned int iMonth = 12;
//	
//	int  iCounter = 0,iSum = 0,iBook[iMonth];
//	char *CMonth[] = {
//
//		"Please intput the number of books of January: ",
//		"Please intput the number of books of February: ",
//		"Please intput the number of books of March: ",
//		"Please intput the number of books of April: ",
//		"Please intput the number of books of May : ",
//		"Please intput the number of books of June : ",
//		"Please intput the number of books of July: ",
//		"Please intput the number of books of August : ",
//		"Please intput the number of books of September : ",
//		"Please intput the number of books of October : ",
//		"Please intput the number of books of November: ",
//		"Please intput the number of books of December: ",
//
//	};
//
//	while (iCounter<iMonth)
//	{
//		cout << CMonth[iCounter];
//		cin >> iBook[iCounter];
//	
//		iSum += iBook[iCounter];
//		iCounter++;
//	}
//
//	cout <<"This is the number of books in the year: "<<iSum<<endl;
//	cin.get();
//	cin.get();
//	return 0;
//}

/*
20
*/

//int main()
//{
//	const unsigned int iYear  = 3;
//	const unsigned int iMonth = 12;
//
//	int iYearConunter = 0, iMonthCounter = 0, iBook[iYear][iMonth];
//	
//	int iSum[iYear] = { 0,0,0 };
//	char *CMonth[][iMonth] = {
//		// the first year
//		{
//			"Please intput the number of books of January in First year: ",
//			"Please intput the number of books of February in First year: ",
//			"Please intput the number of books of March in First year: ",
//			"Please intput the number of books of April in First year: ",
//			"Please intput the number of books of May in First year: ",
//			"Please intput the number of books of June in First year: ",
//			"Please intput the number of books of July in First year: ",
//			"Please intput the number of books of August in First year: ",
//			"Please intput the number of books of September in First year: ",
//			"Please intput the number of books of October in First year: ",
//			"Please intput the number of books of November in First year: ",
//			"Please intput the number of books of December in First year: ",
//		},
//		// the second year
//		{
//			"Please intput the number of books of January in Second year: ",
//			"Please intput the number of books of February in Second year: ",
//			"Please intput the number of books of March in Second year: ",
//			"Please intput the number of books of April in Second year: ",
//			"Please intput the number of books of May in Second year: ",
//			"Please intput the number of books of June in Second year: ",
//			"Please intput the number of books of July in Second year: ",
//			"Please intput the number of books of August in Second year: ",
//			"Please intput the number of books of September in Second year: ",
//			"Please intput the number of books of October in Second year: ",
//			"Please intput the number of books of November in Second year: ",
//			"Please intput the number of books of December in Second year: ",
//		},
//		// the Third year
//		{
//			"Please intput the number of books of January in Third year: ",
//			"Please intput the number of books of February in Third year: ",
//			"Please intput the number of books of March in Third year: ",
//			"Please intput the number of books of April in Third year: ",
//			"Please intput the number of books of May in Third year: ",
//			"Please intput the number of books of June in Third year: ",
//			"Please intput the number of books of July in Third year: ",
//			"Please intput the number of books of August in Third year: ",
//			"Please intput the number of books of September in Third year: ",
//			"Please intput the number of books of October in Third year: ",
//			"Please intput the number of books of November in Third year: ",
//			"Please intput the number of books of December in Third year: ",
//		}
//	};
//
//	while (iYearConunter<iYear)
//	{
//		cout << "¡¤ Please intput in current year: " << endl;
//		while (iMonthCounter<iMonth)
//		{
//			cout << CMonth[iYearConunter][iMonthCounter];
//			cin >> iBook[iYearConunter][iMonthCounter];
//
//			iSum[iYearConunter] += iBook[iYearConunter][iMonthCounter];
//
//			iMonthCounter++;
//		}
//
//		iYearConunter++;
//		iMonthCounter = 0;
//	}
//
//	for (unsigned int i = 0; i < iYear; i++)
//	{
//		cout << "The number of books is " << iSum[i] << " in " << i + 1 << " year " << endl;
//		if (i == 2)
//		{
//			cout << "The total of books is " << iSum[i] + iSum[i - 1] + iSum[i - 2] << endl;
//		}
//	}
//
//	cin.get();
//	cin.get();
//	return 0;
//}

/*
21
*/
//
//struct car
//{
//	string sProducers;
//	unsigned int year;
//};
//
//int main()
//{
//	unsigned int icar,iCounter = 1;
//
//	cout << "How many cars do you wash to catalog?";
//	while (cin>>icar)
//	{
//		car *mycar = new car[icar];
//
//		for (unsigned int i = 0; i < icar; i++)
//		{
//			cout << "car #" << iCounter << ":" << endl;
//			
//			cout << "Please enter the make: ";	
//			cin>> mycar[i].sProducers;
//			
//			cout << "Pleasr enter the year made: ";
//			cin>>mycar[i].year;
//
//			iCounter++;
//		}
//
//		cout << "Here is your collection: " << endl;
//		for (unsigned int i = 0; i < icar; i++)
//		{
//			cout << mycar[i].year << " " << mycar[i].sProducers << endl;
//		}
//
//		cout << "How many cars do you wash to catalog?";
//		iCounter = 1;
//	}
//
//	cin.get();
//	cin.get();
//	return 0;
//}

/*
22
*/

//int main()
//{
//	const unsigned int size = 1024;
//	int  iSumWord = 0;
//	char cArraysize[size];				
//
//	while (cin>>cArraysize && strcmp("Done",cArraysize))									
//	{
//		iSumWord++;
//	}
//
//	cout << iSumWord << endl;
//
//	cin.get();
//	cin.get();
//
//	return 0;
//}

/*
23
*/

//int main()
//{
//	int iCounter = 0;
//	string sArraysize;
//
//	while (cin >> sArraysize && sArraysize!="Done")
//	{
//		iCounter++;
//	}
//
//	cout << iCounter << endl;
//
//	cin.get();
//	cin.get();
//
//	return 0;
//}

/*
24
*/

//int main()
//{
//	unsigned int line;
//
//	cout << "Please intput lines: ";
//	while (cin>>line)
//	{
//		for (unsigned int i = 0; i < line; i++)
//		{
//			for (unsigned int ii = 0; ii < line-1-i; ii++)
//			{
//				cout << " ";
//			}
//
//			for (unsigned int iii = 0; iii <= i; iii++)
//			{
//				cout << "*";
//			}
//
//			cout << endl;
//		}
//
//		cout << "Please intput lines: ";
//	}
//
//	cin.get();
//	return 0;
//}

/*
25
*/
//
//int main()
//{
//
//	char ch;
//	int ct1, ct2;
//
//	ct1 = ct2 = 0;
//	while ((ch=cin.get())!='$')
//	{
//		cout << ch;
//		ct1++;
//		if (ch = '$')
//			ct2++;
//		cout << ch;
//	}
//
//	cout << "ct1= " << ct1 << ", ct2 =  " << ct2 << "\n";
//
//	cin.get();
//	return 0;
//}

/*
26
*/

//int main()
//{
//	char ch;
//	while ((ch = cin.get())!='@')
//	{
//		//a->A
//		if(!isupper(ch))
//			ch = toupper(ch);
//		else//A->a
//			ch = tolower(ch);
//		cout << ch;
//	}
//
//	system("pause");
//	return 0;
//}														

/*
27
*/

//int main()
//{
//
//	const unsigned int arraysize = 10;
//	unsigned int iCounter = 0;
//	unsigned int sum = 0,donasum = 0;
//	double donation[arraysize];
//
//	while (cin >> donation[iCounter] && iCounter<arraysize )
//	{
//		if (!isalnum(donation[iCounter]))
//		{
//			donasum += donation[iCounter];
//			iCounter++;
//		}
//		else
//		{
//			break;
//		}
//		
//	}
//
//	for (unsigned int i = 0; i <=iCounter; i++)
//	{
//		if (donation[i] < donasum/iCounter)
//		{
//			sum++;
//		}
//	}
//
//	cout << "The sum of value is :" << sum << endl;
//
//	system("pause");
//	return 0;
//}

/*
28
*/
//
//int main()
//{
//	char ch,cMenu[4] = {'c','p','t','g'};
//
//	cout << "Please enter one of the following choices: " << endl;
//	cout << "c) carnivore\t\t" << "p) painist" << endl;
//	cout << "t) tree\t\t\t" << "g) game" << endl;
//	cout << "Please enter a c,p,t,or g: ";
//
//	while (cin >> ch)
//	{
//		switch (ch)
//		{
//		case 'c':	cout << "A maple is a carnivore\n" << "Please enter a c,p,t,or g: "; continue;
//		case 'p':	cout << "A maple is a painist\n" << "Please enter a c,p,t,or g: "; continue;
//		case 't':	cout << "A maple is a tree\n" << "Please enter a c,p,t,or g: "; continue;
//		case 'g':	cout << "A maple is a game\n" << "Please enter a c,p,t,or g: "; continue;
//
//		default:
//			cout << "Please enter a c,p,t,or g: ";
//			continue;
//		}
//	}
//
//	system("pause");
//	return 0;
//}

/*
29
*/
//
//const unsigned int strsize = 20;
//const unsigned int iSize = 5;
//
//struct bop
//{
//	char fullname[strsize];
//	char title[strsize];
//	char bopname[strsize];
//	int  preference;
//};
//
//
//int main()
//{
//	char ch;
//	bop bopstr[iSize] = {
//		
//		{"cheng","SE","cz",0},
//		{"qiu","SE","qi",1},
//		{"wang","SE","wa",1},
//		{"zhang","SE","wa",0},
//		{"chen","SE","wa",2}
//	};
//
//	cout << "Benevolent Order of Programmers Report" << endl;
//	cout << "a. display by name\t\t\t" << "b. display by title" << endl;
//	cout << "c. display by bopname\t\t\t" << "d. display by preference" << endl;
//	cout << "q. quit" << endl;
//	cout << "Enter your choice:";
//
//	while (cin>>ch)
//	{
//		switch (ch)
//		{
//		case 'a': 
//			for (size_t i = 0; i < iSize; i++)
//			{
//				cout << bopstr[i].fullname << endl;
//			}
//
//			cout << "Enter your choice:";
//			continue;
//		case 'b':
//			for (size_t i = 0; i < iSize; i++)
//			{
//				cout << bopstr[i].title << endl;
//			}
//
//			cout << "Enter your choice:";
//			continue;
//		case 'c':
//			for (size_t i = 0; i < iSize; i++)
//			{
//				cout << bopstr[i].bopname << endl;
//			}
//
//			cout << "Enter your choice:";
//			continue;
//		case 'd':
//			for (size_t i = 0; i < iSize; i++)
//			{
//				switch (bopstr[i].preference)
//				{
//				case 0: cout << bopstr[i].fullname << endl; continue;
//				case 1: cout << bopstr[i].title << endl; continue;
//				case 2: cout << bopstr[i].bopname << endl; continue;
//				default:
//					continue;
//				}
//			}
//
//			cout << "Enter your choice:";
//			continue;
//		case 'q': cout << "Bye!" << endl; break;
//		default:
//			cout << "Enter your choice:";
//			continue;
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//  

/*
21
*/
//
//int main()
//{
//	const double iTaxesPer[3] = { 0.1,0.15,0.2 };
//	const unsigned int iLevel[3] = { 5000,10000,20000 };
//
//	long long iMoney, iMiddle = 0,iTaxes = 0;	
//	
//	cout << "Enter your Money: ";
//	while (cin >> iMoney && iMoney>0 )
//	{
//		if (iMiddle = iMoney - (iLevel[0])>0)
//		{
//			iTaxes += iLevel[1]*iTaxesPer[0];
//		}
//		else
//		{
//			iTaxes += 0;
//		}
//
//		if (iMiddle = iMiddle - (iLevel[1])>0)
//		{
//			iTaxes += iLevel[2] * iTaxesPer[1];
//		}
//
//		if (iMiddle = iMiddle - (iLevel[2])>0)
//		{
//			iTaxes += iMiddle * iTaxesPer[2];
//		}
//
//		cout << "This is your taxes: "<<iTaxes << endl;
//		cout << "Enter your Money: ";
//	}
//
//	system("pause");
//	return 0;
//}

/*
22
*/

//const unsigned int iName = 20;
//const double dYourMoney = 10000;
//
//struct donor
//{
//	char   cName[iName];
//	double dMoney;
//};
//
//
//int main()
//{
//	long iPeople;
//	bool bc = true;
//
//	cout << "Please intput the number of donors:";
//	while (cin >> iPeople)
//	{
//		donor  *dPeople = new donor[iPeople];
//
//		cout << "Please intput information about your donor:\n\n";
//		for (size_t i = 0; i < iPeople; i++)
//		{
//			cout << "Your Name: ";
//			cin >> dPeople[i].cName;
//
//			cout << "Your Money: ";
//			cin >> dPeople[i].dMoney;
//			
//			cout << "------------------------------\n\n";
//		}
//
//		cout << "Grand Patrons: \n";
//		for (size_t i = 0; i < iPeople; i++)
//		{	
//			if (dPeople[i].dMoney > dYourMoney)
//			{
//				bc = false;
//				cout << "\t\t\t" << dPeople[i].cName << endl;
//			}
//		}
//
//		if (bc)
//		{
//			cout << "none!" << endl;
//		}
//		else
//		{
//			bc = !bc;
//		}
//
//		cout << "Patrons: \n";
//		for (size_t i = 0; i < iPeople; i++)
//		{
//			if (dPeople[i].dMoney < dYourMoney && dPeople[i].dMoney != 0)
//			{
//				bc = false;
//				cout << "\t\t\t" << dPeople[i].cName << endl;
//			}
//		}
//
//		if (bc)
//		{
//			cout << "none!" << endl;
//		}
//		else
//		{
//			bc = !bc;
//		}
//
//		cout << "Please intput the number of donors:";
//	}
//
//	system("pause");
//	return 0;
//}

/*
23
*/
//
//int main()
//{
//	string word;
//	int iCounterNot = 0,iCounterIsVowel = 0,iCounterNotVowel = 0;
//
//	cout << "Enter words (q to quit): \n";
//	while ( cin>>word && word!="q" )
//	{
//		char &ch = word[0];
//		if (!isalpha(ch))
//		{
//			iCounterNot++;
//		}
//		else
//		{
//			ch = tolower(ch);
//			switch (ch)
//			{
//			case 'a':
//			case 'e':
//			case 'i':
//			case 'o':
//			case 'u':
//			case 'A':
//				iCounterIsVowel++;
//				continue;
//				;
//			default:
//				iCounterNotVowel++;
//				break;
//			}	
//		}
//	}
//
//	cout << iCounterIsVowel <<" words is Vowel." << endl;
//	cout << iCounterNotVowel <<" words not is Vowel." << endl;
//	cout << iCounterNot << " words is others." << endl;
//
//	system("pause");
//	return 0;
//}

/*
24
*/
//
//int main()
//{
//	! write to test file
//	double dTest  = 123.45;
//	char  ch[100] = { "Hi,I want to do my best!" };
//	ofstream writefile("D:\\test.txt");										//! the path of file
//
//	writefile << "\t"<<dTest << "\n\t" << ch << endl;
//	writefile.close();
//
//	! read to test file
//	double dTest;
//	char  ch[100];
//	ifstream readfile("D:\\test.txt");
//	
//	if (!readfile.is_open())
//	{
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		readfile >> ch;
//	}
//	
//	long lCounter = 0;
//	char ch[1000] = {
//		
//		"The Little Star\n\n"
//
//		"Jane Taylor\n\n"
//
//		"Twinkle,twinkle,little star,\n"
//		"How I wonder what you are!\n"
//		"Up above the world so high,\n"
//		"Like a diamond in the sky.\n\n"
//
//		"When the blazing sun is set,\n"
//		"And the grass with dew is wet,\n"
//		"Then you show your little light,\n"
//		"Twinkle,twinkle,all night.\n\n"
//
//		"Then the traveller in the dark,\n"
//		"Thanks you for your tiny spark;\n"
//		"He could not see where to go\n"
//		"If you did not twinkle so.\n\n"
//
//		"In the dark blue sky you keep,\n"
//		"And often through my curtains peep,\n"
//		"For you never shut your eye\n"
//		"Till the sun is in the sky.\n\n"
//
//		"As your bright and tiny spark\n"
//		"Lights the traveller in the dark,\n"
//		"Though I know not what you are,\n"
//		"Twinkle ,twinkle,little star.\n\n"
//	
//	};
//
//	ofstream writefile("D:\\test3.txt");
//	writefile << ch << endl;
//	 
//	ifstream readfile("D:\\test3.txt");
//	if (!readfile.is_open())
//	{
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		char cFile;
//		readfile >> cFile;
//		while (readfile.good())
//		{
//			lCounter++;
//			readfile >> cFile;
//		}
//	}
//
//	if (readfile.eof())
//	{
//		cout << ch << endl << endl;
//		cout <<"The number of file is : " << lCounter << endl;
//	}
//	else if (readfile.fail())
//	{
//		cout << "Fail!" << endl;
//	}
//	
//	system("pause");
//	return 0;
//}

/*
25
*/
//
//const unsigned int iSize = 20;
//const long lSize = 1000;
//const unsigned int iName = 20;
//const double dYourMoney = 10000;
//
//struct bop
//{
//	long lMoney;
//	string cName;
//};
//
//int main()
//{
//	bop	*mybop;
//	bool bc = true,line = true;
//	unsigned int iCounter = 0,iPeople;
//	
//	char ch[lSize] = {
//					   "4\n"
//					   "Sam Stone\n"
//					   "2000\n"
//					   "Freida Flass\n"
//					   "100500\n"
//					   "Tammy Tubbs\n"
//					   "5000\n"
//					   "Rich Raptor\n"
//					   "55000\n"
//	};
//
//	ofstream writefile("D:\\test.txt");
//	writefile << ch << endl;
//
//	ifstream readfile("D:\\test.txt");
//	if (!readfile.is_open())
//	{
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		readfile >> iPeople;
//
//		mybop = new bop[iPeople];
//		for (size_t i = 0; i < iPeople; i++)
//		{
//			//name
//			readfile.get();
//			getline(readfile,mybop[i].cName);
//			//Money
//			readfile >> mybop[i].lMoney;
//		}
//	}
//
//	cout << "Grand Patrons: \n";
//	for (size_t i = 0; i < iPeople; i++)
//	{	
//		if (mybop[i].lMoney > dYourMoney)
//		{
//			bc = false;
//			cout << "\t\t\t" << mybop[i].cName << endl;
//		}
//	}
//	
//	if (bc)
//	{
//		cout << "none!" << endl;
//	}
//	else
//	{
//		bc = !bc;
//	}
//	
//	cout << "Patrons: \n";
//	for (size_t i = 0; i < iPeople; i++)
//	{
//		if (mybop[i].lMoney < dYourMoney && mybop[i].lMoney != 0)
//		{
//			bc = false;
//			cout << "\t\t\t" << mybop[i].cName << endl;
//		}
//	}
//	
//	if (bc)
//	{
//		cout << "none!" << endl;
//	}
//	else
//	{
//		bc = !bc;
//	}
//	
//	system("pause");
//	return 0;
//}

/*
26
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

//const unsigned int iSize = 10;
//
//void Modify1(int iarray[], int iSize, int iValue);
//void Modify2(int *iPFirst, int *iPEnd, int iValue);
//void ObtainMax(double darray[], int iSize);
//int  replace(char *str, char c1, char c2);
//
//int main()
//{
//	int iarray[iSize] = { 10,9,8,7,6,5,4,3,2,1 };
//	char carry[iSize] = {'q','e','e','r','t','y','u','p','a','v'};
//	double darray[iSize] = { 123.3,56,11.1,678,22,9,62.2,4.1,2,78.5 };
//
//	//
//	Modify1(iarray, iSize, 24);
//	cout << endl;
//
//	//
//	Modify2(iarray, iarray + iSize, 23);
//	cout << endl;
//
//	//
//	ObtainMax(darray, iSize);
//	cout << endl;
//
//	//
//	cout << replace(carry, 'e', 'h') << endl;
//
//	system("pause");
//	return 0;
//}
//
//void Modify1(int iArray[], int iSize, int iValue)
//{
//	for (size_t i = 0; i < iSize; i++)
//	{
//		iArray[i] = iValue;
//		cout << iArray[i] << " ";
//	}
//}
//
//void Modify2(int *iPFirst, int *iPSecond, int iValue)
//{
//	while (iPFirst != iPSecond)
//	{
//		*iPFirst = iValue;
//		cout << *iPFirst << " ";
//		iPFirst++;
//	}
//}
//
//void ObtainMax(double darray[], int iLength)
//{
//	double	*dPos = new double[iLength];
//	dPos = darray;
//	
//	for ( size_t i = 0; i < iLength; i++ )
//	{
//		if (i + 1 < iLength && *dPos < darray[i + 1])
//		{
//			*dPos = darray[i + 1];
//		}
//	}
//
//	cout << *dPos;
//}
//
//int replace(char *str, char c1, char c2)
//{
//	int iCounter = 0;
//	while ( *str++ )
//	{
//		if (*str == c1)
//		{
//			*str = c2;
//			iCounter++;
//		}
//	}
//
//	return iCounter;
//}


/*
27
*/

//void ScanfGrand(double *dGrand, int Length);
//void printfGrand(double *dGrand, int Length);
//void Cal(double *dGrand, int Length);
//
//int main()
//{
//	/*
//	int ia, ib;
//	while ( cin >> ia >> ib && ia!=0 && ib!=0)
//	{
//		cout << 2 * ia*ib / (ia+ib) << endl;
//	}
//
//	cout << "Over!" << endl;
//	*/
//
//	int length;
//	double dGolfGrade[10];
//	
//	cin >> length;
//	ScanfGrand(dGolfGrade, length);
//	
//	printfGrand(dGolfGrade, length);
//	cout << endl;
//	
//	Cal(dGolfGrade, length);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
//
//void ScanfGrand( double *dGrand, int Length )
//{
//	while ( Length-- )
//	{
//	   cin >> *dGrand++;
//	}
//}
//
//void printfGrand( double *dGrand, int Length )
//{
//	while (Length--)
//	{
//	   cout << *dGrand << " ";
//	   *dGrand++;
//	}
//}
//
//void Cal( double *dGrand, int Length )
//{
//	int iSize = Length;
//	double sum = 0;
//	while (Length--)
//	{
//		sum = sum + *dGrand;
//		*dGrand++;
//	}
//
//	cout << double(sum / iSize) << endl;
//}

/*
28
*/
//
//
//struct box
//{
//	char  marker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//
//void display( box box1 );
//void setvolumn(box &box1);
//
//int main()
//{
//	box mybox = 
//	{
//		"123",
//		1,
//		2,
//		3,
//		21.3,
//	};
//
//	//display( mybox ); 
//	//setvolumn(mybox);
//
//	cout << mybox.volume << endl;
//
//	system("pause");
//	return 0;
//}
//
//void display(box box1)
//{
//	cout << box1.marker << endl;
//	cout << box1.height << endl;
//	cout << box1.width  << endl;
//
//	cout << box1.length << endl;
//	cout << box1.volume << endl;
//}
//
//void setvolumn( box &box1)
//{
//	box1.volume = box1.height * box1.length * box1.width;
//}

/*
29
*/
//
//long long factorial( int i );
//
//int main()
//{
//	long long lSum = 0;
//	int ia;
//	while (cin>>ia)
//	{
//		lSum = factorial(ia);
//		cout << lSum << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
//long long factorial(int i)
//{
//	if ( i == 0 )
//		return 1;
//	else if (i > 0)
//	{
//		return i* factorial(i - 1);
//	}
//}

/*
30
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












