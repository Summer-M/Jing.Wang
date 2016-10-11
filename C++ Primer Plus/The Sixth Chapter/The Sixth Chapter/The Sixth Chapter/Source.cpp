//Top-6.cpp : some exercises in c++ primer plus. 
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
	char ch;
	while ((ch = cin.get())!='@')
	{
		//a->A
		if(!isupper(ch))
			ch = toupper(ch);
		else//A->a
			ch = tolower(ch);
		cout << ch;
	}

	system("pause");
	return 0;
}														

/*
2
*/

int main()
{

	const unsigned int arraysize = 10;
	unsigned int iCounter = 0;
	unsigned int sum = 0,donasum = 0;
	double donation[arraysize];

	while (cin >> donation[iCounter] && iCounter<arraysize )
	{
		if (!isalnum(donation[iCounter]))
		{
			donasum += donation[iCounter];
			iCounter++;
		}
		else
		{
			break;
		}
		
	}

	for (unsigned int i = 0; i <=iCounter; i++)
	{
		if (donation[i] < donasum/iCounter)
		{
			sum++;
		}
	}

	cout << "The sum of value is :" << sum << endl;

	system("pause");
	return 0;
}

/*
3
*/

int main()
{
	char ch,cMenu[4] = {'c','p','t','g'};

	cout << "Please enter one of the following choices: " << endl;
	cout << "c) carnivore\t\t" << "p) painist" << endl;
	cout << "t) tree\t\t\t" << "g) game" << endl;
	cout << "Please enter a c,p,t,or g: ";

	while (cin >> ch)
	{
		switch (ch)
		{
		case 'c':	cout << "A maple is a carnivore\n" << "Please enter a c,p,t,or g: "; continue;
		case 'p':	cout << "A maple is a painist\n" << "Please enter a c,p,t,or g: "; continue;
		case 't':	cout << "A maple is a tree\n" << "Please enter a c,p,t,or g: "; continue;
		case 'g':	cout << "A maple is a game\n" << "Please enter a c,p,t,or g: "; continue;

		default:
			cout << "Please enter a c,p,t,or g: ";
			continue;
		}
	}

	system("pause");
	return 0;
}

/*
4
*/

const unsigned int strsize = 20;
const unsigned int iSize = 5;

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int  preference;
};


int main()
{
	char ch;
	bop bopstr[iSize] = {
		
		{"cheng","SE","cz",0},
		{"qiu","SE","qi",1},
		{"wang","SE","wa",1},
		{"zhang","SE","wa",0},
		{"chen","SE","wa",2}
	};

	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name\t\t\t" << "b. display by title" << endl;
	cout << "c. display by bopname\t\t\t" << "d. display by preference" << endl;
	cout << "q. quit" << endl;
	cout << "Enter your choice:";

	while (cin>>ch)
	{
		switch (ch)
		{
		case 'a': 
			for (size_t i = 0; i < iSize; i++)
			{
				cout << bopstr[i].fullname << endl;
			}

			cout << "Enter your choice:";
			continue;
		case 'b':
			for (size_t i = 0; i < iSize; i++)
			{
				cout << bopstr[i].title << endl;
			}

			cout << "Enter your choice:";
			continue;
		case 'c':
			for (size_t i = 0; i < iSize; i++)
			{
				cout << bopstr[i].bopname << endl;
			}

			cout << "Enter your choice:";
			continue;
		case 'd':
			for (size_t i = 0; i < iSize; i++)
			{
				switch (bopstr[i].preference)
				{
				case 0: cout << bopstr[i].fullname << endl; continue;
				case 1: cout << bopstr[i].title << endl; continue;
				case 2: cout << bopstr[i].bopname << endl; continue;
				default:
					continue;
				}
			}

			cout << "Enter your choice:";
			continue;
		case 'q': cout << "Bye!" << endl; break;
		default:
			cout << "Enter your choice:";
			continue;
		}
	}

	system("pause");
	return 0;
}
  

/*
5
*/

int main()
{
	const double iTaxesPer[3] = { 0.1,0.15,0.2 };
	const unsigned int iLevel[3] = { 5000,10000,20000 };

	long long iMoney, iMiddle = 0,iTaxes = 0;	
	
	cout << "Enter your Money: ";
	while (cin >> iMoney && iMoney>0 )
	{
		if (iMiddle = iMoney - (iLevel[0])>0)
		{
			iTaxes += iLevel[1]*iTaxesPer[0];
		}
		else
		{
			iTaxes += 0;
		}

		if (iMiddle = iMiddle - (iLevel[1])>0)
		{
			iTaxes += iLevel[2] * iTaxesPer[1];
		}

		if (iMiddle = iMiddle - (iLevel[2])>0)
		{
			iTaxes += iMiddle * iTaxesPer[2];
		}

		cout << "This is your taxes: "<<iTaxes << endl;
		cout << "Enter your Money: ";
	}

	system("pause");
	return 0;
}

/*
6
*/

const unsigned int iName = 20;
const double dYourMoney = 10000;

struct donor
{
	char   cName[iName];
	double dMoney;
};


int main()
{
	long iPeople;
	bool bc = true;

	cout << "Please intput the number of donors:";
	while (cin >> iPeople)
	{
		donor  *dPeople = new donor[iPeople];

		cout << "Please intput information about your donor:\n\n";
		for (size_t i = 0; i < iPeople; i++)
		{
			cout << "Your Name: ";
			cin >> dPeople[i].cName;

			cout << "Your Money: ";
			cin >> dPeople[i].dMoney;
			
			cout << "------------------------------\n\n";
		}

		cout << "Grand Patrons: \n";
		for (size_t i = 0; i < iPeople; i++)
		{	
			if (dPeople[i].dMoney > dYourMoney)
			{
				bc = false;
				cout << "\t\t\t" << dPeople[i].cName << endl;
			}
		}

		if (bc)
		{
			cout << "none!" << endl;
		}
		else
		{
			bc = !bc;
		}

		cout << "Patrons: \n";
		for (size_t i = 0; i < iPeople; i++)
		{
			if (dPeople[i].dMoney < dYourMoney && dPeople[i].dMoney != 0)
			{
				bc = false;
				cout << "\t\t\t" << dPeople[i].cName << endl;
			}
		}

		if (bc)
		{
			cout << "none!" << endl;
		}
		else
		{
			bc = !bc;
		}

		cout << "Please intput the number of donors:";
	}

	system("pause");
	return 0;
}

/*
7
*/

int main()
{
	string word;
	int iCounterNot = 0,iCounterIsVowel = 0,iCounterNotVowel = 0;

	cout << "Enter words (q to quit): \n";
	while ( cin>>word && word!="q" )
	{
		char &ch = word[0];
		if (!isalpha(ch))
		{
			iCounterNot++;
		}
		else
		{
			ch = tolower(ch);
			switch (ch)
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
				iCounterIsVowel++;
				continue;
				;
			default:
				iCounterNotVowel++;
				break;
			}	
		}
	}

	cout << iCounterIsVowel <<" words is Vowel." << endl;
	cout << iCounterNotVowel <<" words not is Vowel." << endl;
	cout << iCounterNot << " words is others." << endl;

	system("pause");
	return 0;
}

/*
8
*/

int main()
{
	! write to test file
	double dTest  = 123.45;
	char  ch[100] = { "Hi,I want to do my best!" };
	ofstream writefile("D:\\test.txt");										//! the path of file

	writefile << "\t"<<dTest << "\n\t" << ch << endl;
	writefile.close();

	! read to test file
	double dTest;
	char  ch[100];
	ifstream readfile("D:\\test.txt");
	
	if (!readfile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		readfile >> ch;
	}
	
	long lCounter = 0;
	char ch[1000] = {
		
		"The Little Star\n\n"

		"Jane Taylor\n\n"

		"Twinkle,twinkle,little star,\n"
		"How I wonder what you are!\n"
		"Up above the world so high,\n"
		"Like a diamond in the sky.\n\n"

		"When the blazing sun is set,\n"
		"And the grass with dew is wet,\n"
		"Then you show your little light,\n"
		"Twinkle,twinkle,all night.\n\n"

		"Then the traveller in the dark,\n"
		"Thanks you for your tiny spark;\n"
		"He could not see where to go\n"
		"If you did not twinkle so.\n\n"

		"In the dark blue sky you keep,\n"
		"And often through my curtains peep,\n"
		"For you never shut your eye\n"
		"Till the sun is in the sky.\n\n"

		"As your bright and tiny spark\n"
		"Lights the traveller in the dark,\n"
		"Though I know not what you are,\n"
		"Twinkle ,twinkle,little star.\n\n"
	
	};

	ofstream writefile("D:\\test3.txt");
	writefile << ch << endl;
	 
	ifstream readfile("D:\\test3.txt");
	if (!readfile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		char cFile;
		readfile >> cFile;
		while (readfile.good())
		{
			lCounter++;
			readfile >> cFile;
		}
	}

	if (readfile.eof())
	{
		cout << ch << endl << endl;
		cout <<"The number of file is : " << lCounter << endl;
	}
	else if (readfile.fail())
	{
		cout << "Fail!" << endl;
	}
	
	system("pause");
	return 0;
}

/*
9
*/

const unsigned int iSize = 20;
const long lSize = 1000;
const unsigned int iName = 20;
const double dYourMoney = 10000;

struct bop
{
	long lMoney;
	string cName;
};

int main()
{
	bop	*mybop;
	bool bc = true,line = true;
	unsigned int iCounter = 0,iPeople;
	
	char ch[lSize] = {
					   "4\n"
					   "Sam Stone\n"
					   "2000\n"
					   "Freida Flass\n"
					   "100500\n"
					   "Tammy Tubbs\n"
					   "5000\n"
					   "Rich Raptor\n"
					   "55000\n"
	};

	ofstream writefile("D:\\test.txt");
	writefile << ch << endl;

	ifstream readfile("D:\\test.txt");
	if (!readfile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		readfile >> iPeople;

		mybop = new bop[iPeople];
		for (size_t i = 0; i < iPeople; i++)
		{
			//name
			readfile.get();
			getline(readfile,mybop[i].cName);
			//Money
			readfile >> mybop[i].lMoney;
		}
	}

	cout << "Grand Patrons: \n";
	for (size_t i = 0; i < iPeople; i++)
	{	
		if (mybop[i].lMoney > dYourMoney)
		{
			bc = false;
			cout << "\t\t\t" << mybop[i].cName << endl;
		}
	}
	
	if (bc)
	{
		cout << "none!" << endl;
	}
	else
	{
		bc = !bc;
	}
	
	cout << "Patrons: \n";
	for (size_t i = 0; i < iPeople; i++)
	{
		if (mybop[i].lMoney < dYourMoney && mybop[i].lMoney != 0)
		{
			bc = false;
			cout << "\t\t\t" << mybop[i].cName << endl;
		}
	}
	
	if (bc)
	{
		cout << "none!" << endl;
	}
	else
	{
		bc = !bc;
	}
	
	system("pause");
	return 0;
}

