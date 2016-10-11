//Top-4.cpp : some exercises in c++ primer plus. 
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

const unsigned int arraysize = 30;

struct student
{
	char firstname[arraysize];
	char lastname[arraysize];
	char grade;
	unsigned int age;
};

void Diaplay(student mystudent)
{
	cout << "Name: " << mystudent.lastname << "," << mystudent.firstname<<endl;
	cout << "Grade: " << char(mystudent.grade+1)<<endl;
	cout << "Age: " << mystudent.age << endl;
}

int main()
{
	student mystudent;
	
	while (true)
	{
		cout << "What is your first name?";
		cin.getline(mystudent.firstname,arraysize);

		cout << "What is your last name?";
		cin.getline(mystudent.lastname,arraysize);

		cout << "What letter grade do you deserve?";
		cin >> mystudent.grade;

		cout << "What is your age?";
		cin >> mystudent.age;

		Diaplay(mystudent);
	}
	
	cin.get();
	return 0;
}

/*
2
*/

int main()
{
	std::string name, dessert;
	while (true)
	{
		cout << "Enter your name: "<<endl;
		cin >> name;

		cout << "Enter your favorite dessert: "<<endl;
		cin >> dessert;

		cout << "I have some delicious " << dessert;
		cout << " for you, " << name << endl; 
	}
	
	cin.get();
	return 0;
}

/*
3
*/
int main()
{
	const unsigned int arraysize = 30;
	char firststring[arraysize];
	char secondstring[arraysize];
	std::string sumstring = "";

	while (true)
	{
		cout << "Enter your first name: ";
		cin.getline(firststring, arraysize);

		sumstring.append(firststring);
		sumstring.append(",");

		cout << "Enter your last name: ";
		cin.getline(secondstring, arraysize);
		sumstring.append(secondstring);

		cout <<"Here is the information in a single string: " << sumstring <<endl;
	}
	
	cin.get();
	return 0;
}


/*
4
*/

int main()
{
	std::string firststring;
	std::string secondstring;
	std::string sumstring = "";

	while (true)
	{
		cout << "Enter your first name: ";
		cin >> firststring;
		sumstring.append(firststring+",");

		cout << "Enter your last name: ";
		cin >> secondstring;
		sumstring.append(secondstring);

		cout <<"Here is the information in a single string: " << sumstring <<endl;
	}
	
	cin.get();
	return 0;
}

/*
5 and 6
*/

const unsigned int arraysize = 30;

struct CandyBar
{
	char   brand[arraysize];
	double weight;
	int    calories;
};

int main()
{
	CandyBar	candybar[2]= 
	{
		{"The Alps",45.13,120 },
		{"The Apple",32,58}
	};

	cout << candybar[0].brand << "," << candybar[0].calories << "," << candybar[0].weight << endl;
	cout << candybar[1].brand << "," << candybar[1].calories << "," << candybar[1].weight << endl;

	cin.get();
	return 0;
}


/*
7 and 8
*/

const unsigned int arraysize = 100;

struct mystruct
{
	char CompanyName[arraysize];
	unsigned int  diameter;
	unsigned int  weight;
};

int main()
{
	//mystruct  company;
	//while (true)
	//{
	//	cout << "Please input some information about this company: " << endl;
	//	cout << "First,intput this company: ";
	//	cin.getline(company.CompanyName,arraysize);

	//	cout << "Second,intput this diameter: ";
	//	cin >> company.diameter;

	//	cout << "Finally,intput this weight: ";
	//	cin >> company.weight;

	//	cout << "Company Name : " << company.CompanyName<<endl;
	//	cout << "diamater : " << company.diameter<<endl;
	//	cout << "weight : " << company.weight<<endl;
	//}

	mystruct *company = new mystruct;

	while (true)
	{
		cout << "Please intput some information about this company: " << endl;
		cout << "First,intput this diameier: ";
		cin >> company->diameter;

		cout << "Second,intput this company: ";
		cin >> company->CompanyName;

		cout << "Finally,intput this weight: ";
		cin >> company->weight;

		cout << "Company Name : " << company->CompanyName<<endl;
		cout << "diamater : " << company->diameter<<endl;
		cout << "weight : " << company->weight<<endl;
}

	cin.get();
	return 0;
}


/*
9
*/

const unsigned int arraysize = 100;

struct mystruct
{
	char CompanyName[arraysize];
	unsigned int  diameter;
	unsigned int  weight;
};

int main()
{
	unsigned int size;

	cout << "Please intput the size of company: ";
	while (cin>>size)
	{
		mystruct *company = new mystruct[size];
		
		for (unsigned int i = 0; i < size; i++)
		{
			cout << "First,intput this company: ";
			cin >> company[i].CompanyName;

			cout << "Second,intput this diameter: ";
			cin >> company[i].diameter;

			cout << "Second,intput this weight: ";
			cin >> company[i].weight;
		}

		for(unsigned int i = 0;i<size;i++)
		{
			cout << "--------------------------------------------\n";
			cout << "The Company: ";
			cout << company[i].CompanyName << endl;

			cout << "The diameter: ";
			cout << company[i].diameter << endl;
			
			cout << "The weight: ";
			cout << company[i].weight << endl;
		}

		cout << "Please intput the size of company: ";
	}
	
	cin.get();
	return 0;
}

/*
10
*/

int main()
{
	unsigned int counter = 0;
	array<double, 3> Grade;

	while (true)
	{
		while (counter < Grade.size())
		{
			cout << "This is " << counter + 1 << " numbers" << endl;
			cout << "please intput your Grade: ";
			cin >> Grade[counter++];
		}

		counter = 0;

		while (counter < Grade.size())
		{
			cout <<Grade[counter++]<<" "; 
		}

		counter = 0;
		cout << endl;
	}

	cin.get();
	return 0;
}