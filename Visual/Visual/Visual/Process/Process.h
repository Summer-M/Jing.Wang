#pragma once

#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <process.h>
#include <Windows.h>
#include <malloc.h>

#include "../Variable/Variable.h"


namespace Process
{
	//namespace
	using namespace std;
	using namespace System;

	// extern 
	extern	HANDLE				HMutex;
	extern	bool				SortFinished;
	extern  vector<int>			ExchangeIndex;
	extern  int                 SleepTime;

	/*
	the part of this namespace is used for sort
	*/

	template <typename T>
	struct MyStruct
	{
		vector<T> nums;
		unsigned int SortIndex;
	};

	template <typename DataType>
	class Sort
	{
	public:
		enum { size = 80, othersize = 100 };
		Sort(vector<DataType> Object)
			//IArraysize(size)
		{
			IArraysize<int, 1> = Object;
		};
		Sort(string Model)
		{
			ModelInModel = Model;
		}
		~Sort() {};

	private:
		//!\brief no code
	public:
		//!\brief passing parameters
		// vector<DataType> array;
		string ModelInModel;
	public:
		//!\brief thread

	public:
		//Bubble
		void Bubble(vector<DataType> array)
		{
			int iMimddle;
			for (size_t i = 0; i < array.size(); i++)
			{
				for (size_t j = i + 1; j < array.size(); j++)
				{
					if (array[i] > array[j])
					{
						iMimddle = array[i];
						array[i] = array[j];
						array[j] = iMimddle;

						if (ModelInModel == "normal")
						{
							//lock
							WaitForSingleObject(HMutex, INFINITE);

							//----------------------------------------------------------------------------------
							ExchangeIndex[0] = i;
							ExchangeIndex[1] = j;

							//update IArraysize
							IArraysize = array;
							StepInNormal++;
							//----------------------------------------------------------------------------------

							//unlock
							ReleaseMutex(HMutex);
							Sleep(SleepTime);
						}
						else if (ModelInModel == "step partten")
						{
							Every_Step_Of_The_Change.push_back(i);
							Every_Step_Of_The_Change.push_back(j);
							Every_Step_Of_The_Value.push_back(array);
						}
					}
				}
			}

			SortFinished = false;
			return;
		}
		//Select
		void Select(vector<DataType> array)
		{
			int index;
			int iMiddle;
			for (size_t i = 0; i < array.size(); i++)
			{
				index = i;
				for (size_t j = i + 1; j <= array.size() - 1; j++)
				{
					if (array[index] > array[j])
					{
						index = j;
					}
				}

				iMiddle = array[index];
				array[index] = array[i];
				array[i] = iMiddle;

				if (ModelInModel == "normal")
				{
					//lock
					WaitForSingleObject(HMutex, INFINITE);

					//----------------------------------------------------------------------------------
					ExchangeIndex[0] = index;
					ExchangeIndex[1] = i;

					//update IArraysize
					IArraysize = array;
					StepInNormal++;
					//----------------------------------------------------------------------------------

					//unlock	
					ReleaseMutex(HMutex);
					Sleep(SleepTime);
				}
				else if (ModelInModel == "step partten")
				{
					Every_Step_Of_The_Change.push_back(index);
					Every_Step_Of_The_Change.push_back(i);
					Every_Step_Of_The_Value.push_back(array);
				}
			}

			SortFinished = false;
			return;
		}
		//insert
		void Insert(vector<DataType> array)
		{
			int temp, j;
			for (size_t i = 1; i < array.size(); i++)
			{
				temp = array[i];
				for (j = i; j > 0 && array[j - 1] > temp; j--)
				{
					array[j] = array[j - 1];
				}

				array[j] = temp;

				if (ModelInModel == "normal")
				{
					//lock
					WaitForSingleObject(HMutex, INFINITE);

					//----------------------------------------------------------------------------------
					ExchangeIndex[0] = i;
					ExchangeIndex[1] = j;

					//update IArraysize
					IArraysize = array;
					StepInNormal++;
					//----------------------------------------------------------------------------------

					//unlock	
					ReleaseMutex(HMutex);
					Sleep(SleepTime);
				}
				else if (ModelInModel == "step partten")
				{
					Every_Step_Of_The_Change.push_back(i);
					Every_Step_Of_The_Change.push_back(j);
					Every_Step_Of_The_Value.push_back(array);
				}
			}

			SortFinished = false;
			return;
		}
		//Shell
		void Shell(vector<DataType> array)
		{
			int temp, j;
			int gap = array.size() / 2;

			while (gap > 0)
			{
				for (size_t i = gap; i < array.size(); i++)
				{
					temp = array[i];
					j = i - gap;

					while (j >= 0 && array[j] > temp)
					{
						array[j + gap] = array[j];
						j -= gap;
					}

					array[j + gap] = temp;

					if (ModelInModel == "normal")
					{
						//lock
						WaitForSingleObject(HMutex, INFINITE);

						//----------------------------------------------------------------------------------
						ExchangeIndex[0] = i;
						ExchangeIndex[1] = j + gap;

						//update IArraysize
						IArraysize = array;
						StepInNormal++;
						//----------------------------------------------------------------------------------

						//unlock	
						ReleaseMutex(HMutex);
						Sleep(SleepTime);
					}
					else if (ModelInModel == "step partten")
					{
						Every_Step_Of_The_Change.push_back(i);
						Every_Step_Of_The_Change.push_back(j + gap);
						Every_Step_Of_The_Value.push_back(array);
					}
				}

				gap /= 2;
			}

			SortFinished = false;
			return;

		}
		//Quick
		void Quick(vector<DataType> array)
		{
			SortFinished = false;
			return;
		}
		//Heap
		void Heap(vector<DataType> array)
		{
			SortFinished = false;
			return;
		}
		//Merge
		void Merge(vector<DataType> array)
		{
			SortFinished = false;
			return;
		}
	};

	//! \brief Process rand test-numbers 
	//---------------------------------------------------------------------------
	template <typename DataType>
	vector<DataType> RandNumbers()					// 13
	{
		vector<DataType> RandNumber;
		srand((unsigned int)time(NULL));
		for (size_t i = 0; i < Sort<DataType>::size; i++)
		{
			RandNumber.push_back(((rand() % 11) * 3));
		}

		return RandNumber;
	}


	template <typename DataType>
	vector<DataType> RandNums()					   // 300
	{
		vector<DataType> RandNumber;
		srand((unsigned int)time(NULL));
		for (size_t i = 0; i < Sort<DataType>::othersize; i++)
		{
			RandNumber.push_back(((rand() % 100) * 3));
		}

		return RandNumber;
	}

	//! \brief thread 
	//---------------------------------------------------------------------------

	/*
	the part of this namespace is used for linkedlist
	*/

	// extern
	extern	vector<long long>   Result;
	extern  struct NoteList*    Mylink;
	extern  struct DoublyNoteList*    Mylink1;

	struct NoteList
	{
		long long data;						// data area
		NoteList *next;						// pointer area 
	};

	struct DoublyNoteList
	{
		long long data;						// data area
		DoublyNoteList *pev;						// the pev pointer area
		DoublyNoteList *next;						// the next pointer area
	};


	/*
	- Notice: the class is going to be into a template class!!
	*/

	class LinkedList
	{
	public:
		LinkedList() {};
		~LinkedList() {};

	private:
		// no code
	public:
		// Singly Linked List
		// judge empty
		bool Empty(struct NoteList *head);
		// judge full
		bool Full(struct NoteList *head);
		// create in linkedlist
		struct NoteList *Create(int nums);
		// search index in LinkedList
		bool SearchIndex(int data, struct NoteList *head);
		// search in LinkedList
		struct NoteList* SearchList(int data, struct NoteList *head);
		// search in LinkedList
		struct NoteList* Reverse(struct NoteList *head);
		// insert in LinkedList
		struct NoteList * Insert(int Pos, struct NoteList *head, struct NoteList *insert);
		// remove in LinkedList
		struct NoteList * Remove(int data, struct NoteList *head);
		// Output data
		vector<long long> Output(struct NoteList *head);

		// Doubly linked List
		// create in linkedlist
		struct DoublyNoteList *CreateDoubly(int nums);
		// search in LinkedList
		bool SearchIndex(int data, struct DoublyNoteList *head);
		// Output data
		vector<long long> LinkedList::Output1(struct DoublyNoteList *head);
	};
}
