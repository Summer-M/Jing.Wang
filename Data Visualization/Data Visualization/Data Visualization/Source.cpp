#include "Header.h"

namespace Process
{
	//!\brief extern variable
	//-------------------------------------------------------

	HANDLE HMutex = NULL;
	bool SortFinished = true;

	//-------------------------------------------------------
	

	/*
		Sort
	*/
	
	// No code!!!

	/*
		LinkedList
	*/
	//!\brief extern variable
	//-------------------------------------------------------

	vector<long long>   Result(10);
	struct NoteList*    Mylink = NULL;
	struct DoublyNoteList*    Mylink1 = NULL;

	//-------------------------------------------------------
	
	bool LinkedList::Empty(struct NoteList *head)
	{
		return head->next == NULL;
	}
	
	bool LinkedList::Full(struct NoteList *head)
	{
		return false;
	}
	
	// Singly Linked List
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
		struct NoteList*  p1;
		struct NoteList*  prev = NULL;

		while (head !=NULL)
		{
			p1 = head->next;
			head->next = prev;
			prev = head;
			head = p1;
		}
		
		return prev;
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

	// Doubly linked List
	struct DoublyNoteList *LinkedList::CreateDoubly(int nums)
	{
		struct DoublyNoteList *head;
		struct DoublyNoteList *p1;
		struct DoublyNoteList *p2;

		head->pev = NULL;

		p2 = p1 = (struct DoublyNoteList *)malloc(sizeof(struct DoublyNoteList));

		if (p1 == NULL)
		{
			EXIT_FAILURE;
			return head;
		}
		else
		{
			for (size_t i = 0; i < nums; i++)
			{
				p1 = (struct DoublyNoteList *)malloc(sizeof(struct DoublyNoteList));
				p1->data = rand() % 100 * 3;
				if (head == NULL)
				{
					head = p1;
					p2 = p1;
					p1->pev = head;
				}
				else
				{
					p2->next = p1;
					p2 = p1;
					p1->pev = p2;
				}

				p2->next = NULL;
			}
		}

		return head;
	}

	vector<long long> LinkedList::Output1(struct DoublyNoteList *head)
	{
		struct DoublyNoteList *p;
		vector<long long>  OriginalData;
		p = head;
		while (p)
		{
			OriginalData.push_back(p->data);
			p = p->next;
		}

		return OriginalData;
	}

	bool LinkedList::SearchIndex(int data, struct DoublyNoteList *head)
	{
		struct DoublyNoteList *p = head;
		int iCounter = 0;

		while (p->next != NULL && p->data != data)
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
}