#pragma once

//! \file
//! This file define the thread

#include "../Draw/Draw.h"
#include "../Process/Process.h"
#include "../Variable/Variable.h"

template <class T>
class MYThread
{
public:
	MYThread(unsigned int sort, vector<T> nums, string Model)
	{
		sortindex = sort;
		sortnums = nums;
		modelinSort = Model;
	};

	~MYThread() {};

public:
	// my code
	static unsigned int sortindex;
	static vector<T>    sortnums;
	static string modelinSort;

public:
	static unsigned int _stdcall ThreadOfSort(LPVOID lpParam)
	{
		Process::Sort<T> sort(modelinSort);
		switch (sortindex)
		{
		case 0:
		{
			sort.Bubble(sortnums);
		}

		break;

		case 1:
		{
			sort.Select(sortnums);
		}

		break;

		case 2:
		{
			sort.Insert(sortnums);
		}

		break;

		case 3:
		{
			sort.Shell(sortnums);
		}

		break;

		default:
			break;
		}

		return 0;
	}
};

class ThreadAboutAlgorithm
{
public:
	ThreadAboutAlgorithm() {};
	~ThreadAboutAlgorithm() {};

public:
	// no code
	static unsigned int _stdcall ThreadOfA(LPVOID lpParam)
	{
		Geometric::Object object;
		object.Move();
		return 0;
	}

	// no code
	static unsigned int _stdcall ThreadOfAB(LPVOID lpParam)
	{
		Geometric::Object object;
		object.MoveRect();
		return 0;
	}
};