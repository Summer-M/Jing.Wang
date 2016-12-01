//This is test for Leetcode
//

#include <stdlib.h>
#include <malloc.h>
#include "Header.h"

ListNode *CreateList(int n)
{
	ListNode *head;
	ListNode *p1, *p2;

	head = NULL;
	p2 = (ListNode *)malloc(sizeof(ListNode));

	for (int i = 1; i <= n; i++)
	{
		p1 = (ListNode *)malloc(sizeof(ListNode));
		cin >> p1->val;
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
	return head;
}

int main()
{
	Solution mySolution;

	ListNode *l1 = CreateList(3);
	ListNode *l2 = CreateList(3);

	mySolution.addTwoNumbers(l1, l2);
	system("pause");
	return 0;
}