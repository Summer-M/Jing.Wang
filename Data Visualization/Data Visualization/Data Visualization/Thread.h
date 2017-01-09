#pragma once

//! \file
//! This file define the thread

#include "Header.h"
#include "Variable.h"

template <class T>
class MYThread
{
public:
	MYThread() {};
	~MYThread() {};
	
private:
	// my code
public:
	static DWORD WINAPI ThreadOfSort(LPVOID lpParam)
	{
		Process::Sort<T> *sort = (Sort<T>*)lpParam;
		MyStruct<T> *sortstruct = (MyStruct<T>*)lpParam;

		switch (sortstruct->SortIndex)
		{
		case 0:	sort->Bubble(sortstruct->nums); break;
		case 1: sort->Select(sortstruct->nums); break;
		case 2: sort->Insert(sortstruct->nums); break;
		case 3: sort->Shell(sortstruct->nums);  break;
		case 4: sort->Quick(sortstruct->nums);  break;
		case 5: sort->Heap(sortstruct->nums);   break;
		case 6: sort->Merge(sortstruct->nums);  break;

		default:
			break;
		}

		return 0;
	}
};
