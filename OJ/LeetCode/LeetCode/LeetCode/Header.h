#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// 1: 


// 2: add two number
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		std::vector<int> num(1000);
		ListNode *head;
		ListNode *p1, *p2;
		int iCounter = 0, iLen = 0;

		// add
		while (l1 != NULL || l2 != NULL)
		{
			int iTem = 0, iTem1 = 1;

			// 1 case
			if (l1 != NULL && l2 != NULL)
			{
				if (l1->val + l2->val >= 10)
				{
					num[iCounter + 1] = iTem1;
				}

				iTem = (l1->val + l2->val) >= 10 ? (l1->val + l2->val - 10) : (l1->val + l2->val);

				if (num[iCounter] + iTem >= 10)
				{
					num[iCounter] = num[iCounter] + iTem - 10;
					num[iCounter + 1] = 1;
				}
				else
				{
					num[iCounter] += iTem;
				}
			}
			// 2 case
			else if (l1 != NULL && l2 == NULL)
			{
				if (num[iCounter] + l1->val>=10)
				{
					num[iCounter] = num[iCounter] + l1->val - 10;
					num[iCounter + 1] = 1;
				}
				else
				{
					num[iCounter] += l1->val;
				}
			}
			// 3 case
			else if (l1 == NULL && l2 != NULL)
			{

				if (num[iCounter] + l2->val>=10)
				{
					num[iCounter] = num[iCounter] + l2->val - 10;
					num[iCounter + 1] = 1;
				}
				else
				{
					num[iCounter] += l2->val;
				}
			}

			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;

			iCounter++;
		}

		for (vector<int>::iterator i = num.end() - 1; i != num.begin(); i--)
		{
			if (*i == 0)
				iLen++;
			else
			{
				break;
			}
		}

		head = NULL;
		p2 = (ListNode *)malloc(sizeof(ListNode));
		for (size_t i = 0; i<1000 - iLen; i++)
		{
			p1 = (ListNode *)malloc(sizeof(ListNode));
			p1->val = num[i];
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
};
