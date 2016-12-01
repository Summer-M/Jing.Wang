//
//// - Author：zhen.cheng
//// - Date: 2016/10/18
//// - Email: chengzhen021@outlook.com
//// - Introduce: The project file is a thirty day training program.  
//
///*
//0: hello world
//*/
//
#include <iostream>
#include <string>
#include <vector>
//
using namespace std;
//
//int main()
//{
//	string inputString;			// declare a variable to hold our input
//	getline(cin, inputString);  // get a line of input from cin and save it to our variable
//
//								// Your first line of output goes here
//	cout << "Hello, World." << endl;
//
//	// Write the second line of output
//
//	return 0;
//}
//
//
///*
//1: Data Types
//*/
//
//#include <iostream>
//#include <iomanip>
//#include <limits>
//
//using namespace std;
//
//int main()
//{
//	int i = 4;
//	double d = 4.0;
//	string s = "HackerRank ";
//
//	int iFirst;
//	double dSecond;
//	string sThird;
//
//	cin >> iFirst;
//	cin >> dSecond;
//	cin >> sThird;
//
//	cout << i + iFirst << endl;
//	cout << double(d) + double(dSecond) << endl;
//	cout << s << sThird << endl;
//
//	return 0;
//}
//
///*
//2: Operators
//*/
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	double dMealCost;
//	int    iTipPercent, iTaxPercent, Total;
//
//	double tip, tax;
//
//	cin >> dMealCost;
//	cin >> iTipPercent;
//	cin >> iTaxPercent;
//
//	double dP1 = double(iTipPercent) / double(100);
//	double dP2 = double(iTaxPercent) / double(100);
//
//	tip = double(dMealCost) * dP1;
//	tax = double(dMealCost) * dP2;
//
//	Total = tip + tax + dMealCost;
//	Total = (tip + tax + double(dMealCost)) - Total  > 0.5 ? (Total + 1) : Total;
//
//	cout << "The total meal cost is " << Total << " dollars." << endl;
//}
//
///*
//3: Intro to Conditional Statements
//*/
//
//#include <map>
//#include <set>
//#include <list>
//#include <cmath>
//#include <ctime>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <string>
//#include <bitset>
//#include <cstdio>
//#include <limits>
//#include <vector>
//#include <climits>
//#include <cstring>
//#include <cstdlib>
//#include <fstream>
//#include <numeric>
//#include <sstream>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	int i;
//	cin >> i;
//
//	if (i % 2 != 0)
//	{
//		cout << "Weird" << endl;
//	}
//	else
//	{
//		if (i >= 2 && i <= 5)
//		{
//			cout << "Not Weird" << endl;
//		}
//		else if (i >= 6 && i <= 20)
//		{
//			cout << "Weird" << endl;
//		}
//		else if (i >20)
//		{
//			cout << "Not Weird" << endl;
//		}
//	}
//
//	return 0;
//}
//
///*
//4: Class vs. Instance
//*/
//
//class Person
//{
//public:
//	int age;
//	Person(int initialAge);
//	void amIOld();
//	void yearPasses();
//};
//
//Person::Person(int initialAge)
//{
//	// Add some more code to run some checks on initialAge
//	if (initialAge<0)
//		cout << "Age is not valid, setting age to 0." << endl;
//	age = initialAge;
//}
//
//void Person::amIOld()
//{
//	// Do some computations in here and print out the correct statement to the console 
//	if (age<13)
//		cout << "You are young." << endl;
//	else if ((age>13 || age == 13) && age<18)
//		cout << "You are a teenager." << endl;
//	else if (age>18 || age == 18)
//		cout << "You are old." << endl;
//}
//
//void Person::yearPasses()
//{
//	// Increment the age of the person in here
//	age++;
//}
//
///*
//5: Loops
//*/
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	int n;
//	cin >> n;
//	for (size_t i = 1; i <= 10; i++)
//	{
//		cout << n << " x " << i << " = " << n*i << endl;
//	}
//	return 0;
//}
//
///*
//6: Let's Review
//*/
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//
//	int n;
//	string sStr;
//	cin >> n;
//	vector<std::string> str;
//
//	for (size_t i = 0; i<n; i++)
//	{
//		cin >> sStr;
//		str.push_back(sStr);
//	}
//
//	for (size_t i = 0; i<n; i++)
//	{
//		std::string str1 = str.at(i);
//		for (size_t i = 0; i<str1.length(); i++)
//		{
//			string dadad = str1.substr(i, 1);
//			if (i == 0 || (i % 2) == 0)
//				cout << str1.substr(i, 1);
//		}
//
//		cout << " ";
//
//		for (size_t i = 0; i<str1.length(); i++)
//		{
//			if (i % 2 != 0)
//				cout << str1.substr(i, 1);
//		}
//
//		cout << endl;
//	}
//
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	return 0;
//}
//
///*
//7: Arrays
//*/
//
//#include <map>
//#include <set>
//#include <list>
//#include <cmath>
//#include <ctime>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <string>
//#include <bitset>
//#include <cstdio>
//#include <limits>
//#include <vector>
//#include <climits>
//#include <cstring>
//#include <cstdlib>
//#include <fstream>
//#include <numeric>
//#include <sstream>
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//
//using namespace std;
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> arr(n);
//	for (int arr_i = 0; arr_i < n; arr_i++) {
//		cin >> arr[arr_i];
//	}
//
//	for (int arr_i = n - 1; arr_i >= 0; arr_i--)
//	{
//		cout << arr.at(arr_i) << " ";
//	}
//
//	cout << endl;
//	return 0;
//}
//
///*
//8: Dictionaries and Maps
//*/
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//
//int main()
//{
//
//	long long n;
//	std::string sValue;
//	cin >> n;
//
//	long long value;
//std:string str, str1;
//
//	map<string, long long> mData;
//	map<string, long long>::iterator mFind;
//
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> str >> value;
//		mData.insert(make_pair(str, value));
//	}
//
//	while (cin >> str1)
//	{
//		mFind = mData.find(str1);
//		if (mFind == mData.end())
//		{
//			cout << "Not found" << endl;
//		}
//		else
//		{
//			cout << mFind->first << "=" << mFind->second << endl;
//		}
//	}
//
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	return 0;
//}
//
///*
//9: Recursion
//*/
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//long Factorial(unsigned int i);
//
//int main()
//{
//
//	unsigned int n;
//	long sum = 1;
//
//	cin >> n;
//
//	cout << Factorial(n) << endl;
//
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	return 0;
//}
//
//long Factorial(unsigned int i)
//{
//	if (i == 1)
//		return i;
//	else
//		return i*Factorial(i - 1);
//}
//
///*
//10: Binary Numbers
//*/
//
//std::iterator
//
//
//
//


#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

//int comp(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}

int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	std::vector<int> nums;
	int p;
	for (size_t i = 0; i < 12; i++)
	{
		cin >> p;
		nums.push_back(p);
	}

	/*std::qsort(array, 5, sizeof(int),comp);

	for (size_t i = 0; i < 5; i++)
	{
		if (i+1<5 && array[i] != array[i + 1])
		{
			nums.push_back(array[i]);
		}
		else
		{
			while(array[i]==array[i+1])
			{
				if(i+1<5)
				  i++;
			}
		}
	}

	for (size_t i = 0; i < nums.size(); i++)
	{
		cout << nums.at(i) << " ";
	}*/

	int findnum;
	std::sort(&nums[0], &nums[0]+nums.size());
	int middle;
	/*for (size_t i = 0; i < 12; i++)
	{
		for (size_t j = 0; j < 11; j++)
		{
			if (nums[j] > nums[j+1])
			{
				middle = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = middle;
			}
		}
	}
	*/
	for (vector<int>::iterator i = nums.begin(); i != nums.end();)
	{
		if (i + 1<nums.end() && *i != *(i + 1))
		{
			i++;
			continue;
		}
		else if(i + 1<nums.end())
		{
			findnum = *i;
			while (findnum==*i)
			{
				if(i<nums.end()-1)
					i = nums.erase(i);
				else
				{
					i = nums.erase(i);
					break;
				}
			}
		}
		else
		{
			i++;
		}
	}

	for (size_t i = 0; i < nums.size(); i++)
	{
		cout << nums.at(i) << endl;
	}

	system("pause");
	return 0;
}



