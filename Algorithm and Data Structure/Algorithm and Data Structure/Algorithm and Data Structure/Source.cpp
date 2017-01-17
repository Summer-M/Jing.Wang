
#include <iostream>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;


int		SIZE = 50000;

struct MyStruct * create();
struct MyStruct * remove(struct MyStruct *link, int value);
void  print(struct MyStruct *link);

struct MyStruct
{
	int index;
	MyStruct *next;
};

int main()
{
	struct MyStruct *my = create();
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		my = remove(my, 3);
		print(my);
	}

	system("pause");
	return 0;
}

void print(struct MyStruct *link)
{
	struct MyStruct *head = link;

	cout << link->index << " ";
	link = link->next;

	while (link->next != head->next)
	{
		cout << link->index << " ";
		link = link->next;
	}

	cout << endl;
}
struct MyStruct * create()
{
	struct MyStruct *p1;
	struct MyStruct *p2;
	struct MyStruct *head;

	head = NULL;
	p2 = p1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));

	if (p1 == NULL)
	{
		EXIT_FAILURE;
	}
	else
	{
		for (size_t i = 1; i <= SIZE; i++)
		{
			p1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
			p1->index = i;
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
		}

		p2->next = head;
	}

	return head;
}
struct MyStruct * remove(struct MyStruct *link, int value)
{
	static int index = 0;
	struct MyStruct  *head1 = link;
	struct MyStruct  *head = link;
	struct MyStruct  *current = link;
	struct MyStruct  *p1 = link;
	if (p1 == NULL)
	{
		EXIT_FAILURE;
	}
	else
	{
		for (size_t i = 0; i < index + value; i++)
		{
			current = p1;
			p1 = p1->next;
		}

		if (p1 == link)
		{
			link = p1->next;
			while (head1->next != head)
			{
				head1 = head1->next;
			}

			head1->next = link;
		}
		else
		{
			current->next = p1->next;
			index++;
		}
	}

	return link;
}
