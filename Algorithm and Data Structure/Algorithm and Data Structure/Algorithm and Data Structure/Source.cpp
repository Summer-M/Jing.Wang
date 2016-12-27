// some Algorithm and Data Structure
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


//About: sort
//Information:This is used to practice about "sort"

//bubble
void Bubble(int *array, int size);
void Select(int *array, int size);
void Insert(int *array, int size);

int main()
{
	const unsigned int size = 10;
	int array[size] = {13,4,26,87,30,17,64,51,20,21};

	Bubble(array,size);

	//Select(array, size);

	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}


void Bubble(int *array, int size)
{
	int iMimddle;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				iMimddle = array[i];
				array[i] = array[j];
				array[j] = iMimddle;
			}
		}
	}
}

void Select(int *array, int size)
{
	int index;
	int iMiddle;
	for (size_t i = 0; i < size; i++)
	{
		index = i;
		for (size_t j = i+1; j <= size-1; j++)
		{
			if (array[index]>array[j])
			{
				index = j;
			}
		}

		iMiddle = array[index];
		array[index] = array[i];
		array[i] = iMiddle;
	}
}

void Insert(int *array, int size)
{
	
}


















