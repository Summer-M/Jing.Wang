// some Algorithm and Data Structure
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


//1

/*
int indexFunction1(int array[], int size,int index);									//! "Bubble Sort"
int indexFunction2(int array[], int index);												//! this is used to sort

int main()
{
	const unsigned int size = 5;
	int array[size],index1,middle_number;
	for (size_t i = 0; i < size; i++)
	{
		cin >> array[i];
	}

	cin >> index1;

	cout << indexFunction1(array, size,index1) << endl;
	
	for (size_t i = index1; i < size; i++)
	{
		if (array[i] < indexFunction2(array, index1))
		{
			middle_number = array[i];
			array[i] = array[index1 - 1];
			array[index1 - 1] = middle_number;
		}
	}

	cout << array[index1 - 1] << endl;
	
	system("pause");
	return 0;
}

int indexFunction1(int array[], int size,int index)
{
	int middle;
	for (size_t i = 0; i < size; i++)
	{
		int currentindex = array[i];
		for (size_t j = 0; j < size-1; j++)
		{
			if (currentindex > array[j])
			{
				middle = array[i];
				array[i] = array[j];
				array[j] = middle;
			}
		}
	}

	return index-1;
}

int indexFunction2(int *array, int index)
{
	int middle;
	for (size_t i = 0; i < index; i++)
	{
		int currentindex = array[i];
		for (size_t j = 0; j < index - 1; j++)
		{
			if (currentindex < array[j])
			{
				middle   = array[i];
				array[i] = array[j];
				array[j] = middle;
			}
		}
	}
	
	return array[index - 1];
}

*/

//2




















