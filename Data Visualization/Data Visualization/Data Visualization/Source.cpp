#include "Header.h"

namespace Process
{
	//!\brief extern variable
	//-------------------------------------------------------

	HANDLE HMutex = NULL;
	bool SortFinished = true;
	vector<long long> IArraysize(Sort::size);

	//-------------------------------------------------------
	

	/*
		Sort
	*/

	vector<long long> RandNumbers()
	{
		vector<long long> RandNumbers;
		srand((long long)time(NULL));
		for (size_t i = 0; i < Sort::size; i++)
		{
			RandNumbers.push_back(((rand() % 11) * 3));
		}

		return RandNumbers;
	}

	vector<long long> RandNums()
	{
		vector<long long> RandNumbers;
		srand((long long)time(NULL));
		for (size_t i = 0; i < Sort::othersize; i++)
		{
			RandNumbers.push_back(((rand() % 100) * 3));
		}

		return RandNumbers;
	}

	DWORD WINAPI ThreadReady(LPVOID lpParam)
	{
		return 0;
	}

	DWORD WINAPI ThreadOfSort(LPVOID lpParam)
	{
		Process::Sort *sort  = (Sort*)lpParam;
		MyStruct *sortstruct = (MyStruct*)lpParam;

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

    void Sort::Bubble(vector<long long> array)
	{
		int iMimddle;
		for (size_t i = 0; i < array.size(); i++)
		{
			//lock
			WaitForSingleObject(HMutex, INFINITE);
			
			for (size_t j = i + 1; j < array.size(); j++)
			{
				if (array[i] > array[j])
				{
					iMimddle = array[i];
					array[i] = array[j];
					array[j] = iMimddle;
				}
			}

			// update IArraysize
			IArraysize = array;
		
			//unlock
			Sleep(50);
			ReleaseMutex(HMutex);
		}

		SortFinished = false;
		return;
	}
	
	void Sort::Select(vector<long long> array)
	{
		int index;
		int iMiddle;
		for (size_t i = 0; i < array.size(); i++)
		{
			//lock
			WaitForSingleObject(HMutex, INFINITE);

			index = i;
			for (size_t j = i + 1; j <= array.size() - 1; j++)
			{
				if (array[index]>array[j])
				{
					index = j;
				}
			}

			iMiddle = array[index];
			array[index] = array[i];
			array[i] = iMiddle;

			// update IArraysize
			IArraysize = array;

			//unlock
			Sleep(50);
			ReleaseMutex(HMutex);
		}

		SortFinished = false;
		return;
	}

	void Sort::Insert(vector<long long> array)
	{
		int temp, j;
		for (size_t i = 1; i < array.size(); i++)
		{
			//lock
			WaitForSingleObject(HMutex, INFINITE);

			temp = array[i];
			for (j = i; j > 0 && array[j - 1]>temp; j--)
			{
				array[j] = array[j - 1];
			}

			array[j] = temp;

			// update IArraysize
			IArraysize = array;

			//unlock
			Sleep(50);
			ReleaseMutex(HMutex);
		}

		SortFinished = false;
		return;
	}

	void Sort::Shell(vector<long long> array)
	{
		int temp, j;
		int gap = array.size() / 2;

		while (gap > 0)
		{
			for (size_t i = gap; i < array.size(); i++)
			{
				// lock
				WaitForSingleObject(HMutex, INFINITE);
				
				temp = array[i];
				j = i - gap;

				while (j >= 0 && array[j] > temp)
				{
					array[j + gap] = array[j];
					j -= gap;
				}

				array[j + gap] = temp;

				// update IArraysize
				IArraysize = array;

				//unlock
				Sleep(50);
				ReleaseMutex(HMutex);
			}

			gap /= 2;
		}

		SortFinished = false;
		return;
	}

	void Sort::Quick(vector<long long> array)
	{
		SortFinished = false;
		return;
	}

	void Sort::Heap(vector<long long> array)
	{
		SortFinished = false;
		return;
	}

	void Sort::Merge(vector<long long> array)
	{
		SortFinished = false;
		return;
	}


	/*
		LinkedList
	*/
	//!\brief extern variable
	//-------------------------------------------------------

	vector<long long>   Result(10);
	struct NoteList*    Mylink = NULL;

	//-------------------------------------------------------
	
	bool LinkedList::Empty(struct NoteList *head)
	{
		return head->next == NULL;
	}
	
	bool LinkedList::Full(struct NoteList *head)
	{
		return false;
	}
	
	struct NoteList *LinkedList::Create(int nums)
	{
		struct NoteList *head;
		struct NoteList *p1;
		struct NoteList *p2;

		head = NULL;

		p2 = p1 = (struct NoteList *)malloc(sizeof(struct NoteList));

		if (p1 == NULL)
		{
			EXIT_FAILURE;
			return head;
		}
		else
		{
			for (size_t i = 0; i < nums; i++)
			{
				p1 = (struct NoteList *)malloc(sizeof(struct NoteList));
				p1->data = rand() % 100 * 3;
				if (head == NULL)
				{
					head = p1;
					p2 = p1;
				}
				else
				{
					p2->next = p1;
					p2 = p1;
				}

				p2->next = NULL;
			}
		}

		return head;
	}
	
	bool LinkedList::SearchIndex(int data, struct NoteList *head)
	{
		struct NoteList *p = head;
		int iCounter = 0;

		while (p->next!=NULL && p->data!=data)
		{
			p = p->next;
		}

		if (p->data == data)
		{
			return true;
		}
		else
		{
			return false;
		}

		return true;
	}

	struct NoteList* LinkedList::Reverse(struct NoteList *head)
	{
		struct NoteList*  prev = NULL;
		struct NoteList*  p1;

		if (head != NULL)
		{
			while (p1!=NULL)
			{
				head->next = prev;
				prev = head;
				head = p1;
				p1 = head->next;
			}
		}

		return head;
	}

	struct NoteList *LinkedList::SearchList(int data, struct NoteList *head)
	{
		return head;
	}

	struct NoteList * LinkedList::Insert(int Pos,struct NoteList *head,struct NoteList *insert)
	{
		struct NoteList *Current;
		struct NoteList *p1;
		struct NoteList *p = head;
		
		p1 = head;
		int iCounter = 0;
		if (head != NULL && insert != NULL)
		{
			while ((iCounter++)!=Pos)
			{
				Current = p;
				p = p->next;
			}

			if (p == head)
			{
				head = insert;
				insert->next = p1;
			}
			else
			{
				Current->next = insert;
				insert->next = p;
			}
		}

		return head;
	}

	struct NoteList * LinkedList::Remove(int data, struct NoteList *head)
	{
		struct NoteList *Current;
		struct NoteList *p = head;

		if (p != NULL)
		{
			while (p->next!=NULL && p->data!=data)
			{
				Current = p;
				p = p->next;
			}

			if (p->data == data)
			{
				if (p == head)
				{
					head = p->next;
				}
				else
				{
					Current->next = p->next;
				}
			}
			else
			{
				EXIT_FAILURE;
				return head;
			}
		}

		return head;
	}

	vector<long long> LinkedList::Output(struct NoteList *head)
	{
		struct NoteList *p;
		vector<long long>  OriginalData;
		p = head;
		while (p)
		{
			OriginalData.push_back(p->data);
			p = p->next;
		}

		return OriginalData;
	}
}