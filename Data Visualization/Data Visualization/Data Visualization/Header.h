#pragma once

#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <process.h>
#include <Windows.h>
#include <malloc.h>

//namespace
using namespace std;
using namespace System;

namespace Process
{
	// extern 
	extern	HANDLE				HMutex;
	extern	bool				SortFinished;
	extern	vector<long long>   IArraysize;
	
	/*
		the part of this namespace is used for sort
	*/

	struct MyStruct
	{
		vector<long long> nums;
		unsigned int SortIndex;
	};

	class Sort
	{
	public:
		enum {size = 10,othersize = 100};
		Sort(vector<long long> Object)
			:array(0)
			//IArraysize(size)
		{
			array = Object;
			IArraysize = Object;
		};
		~Sort() {};

	private:
		//!\brief no code
	public:
		//!\brief passing parameters
		vector<long long> array;

	public:	
		//!\brief thread
	
	public:

		//Bubble
		void Bubble(vector<long long> array);
		//Select
		void Select(vector<long long> array);
		//insert
		void Insert(vector<long long> array);
		//Shell
		void Shell(vector<long long> array);
		//Quick
		void Quick(vector<long long> array);
		//Heap
		void Heap(vector<long long> array);
		//Merge
		void Merge(vector<long long> array);
	};

//! \brief Process rand test-numbers 
//---------------------------------------------------------------------------

	vector<long long> RandNumbers();				// 10
	vector<long long> RandNums();					// 300

//! \brief thread 
//---------------------------------------------------------------------------

	DWORD WINAPI ThreadOfSort(LPVOID lpParam);

	DWORD WINAPI ThreadReady(LPVOID lpParam);

	/*
		the part of this namespace is used for linkedlist
	*/

	// extern
	extern	vector<long long>   Result;
	extern  struct NoteList*    Mylink;

	struct NoteList
	{
		long long data;						// data area
		NoteList *next;					// pointer area 
	};
	
	class LinkedList
	{
	public:
		LinkedList() {};
		~LinkedList() {};

	private:
		// no code
	public:

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
		struct NoteList* Reverse( struct NoteList *head);
		// insert in LinkedList
		struct NoteList * Insert(int Pos, struct NoteList *head, struct NoteList *insert);
		// remove in LinkedList
		struct NoteList * Remove(int data, struct NoteList *head);
		// Output data
		vector<long long> Output(struct NoteList *head);
	};
}