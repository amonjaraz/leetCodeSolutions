#include "iostream"
#include "stdafx.h"
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution2 {
public:

	static long int getListTotal(ListNode* inputList) {
		long int total = 0;
		if (inputList->next != 0) {
			total = 10 * getListTotal(inputList->next);
		}
		total += inputList->val;
		return total;
	}

	static ListNode* addLists(ListNode* listA, ListNode* listB, bool overTen) {
		int sum = 0;
		int remainder = 0;
		ListNode *node  = NULL;
		ListNode *nextA = NULL;
		ListNode *nextB = NULL;


		if (listA != NULL || listB != NULL || overTen==true) {
			if (listA != NULL) {
				sum = listA->val;
				nextA = listA->next;
			}
			if (listB != NULL) {
				sum += listB->val;
				nextB = listB->next;
			}
			if (overTen) sum += 1;
			remainder = sum % 10;
			
			node = new ListNode(remainder);
			node->next = addLists(nextA, nextB, (sum >= 10));
		}
		return node;
	}

	static ListNode* convertIntToListNode(long int total) {
		long int number = 0;
		double result = total / 10.0;
		long int wholeNum  = (long int)result;
		long int remainder = total % 10;
		ListNode *node = new ListNode(remainder);
		if (wholeNum > 0) {
			node->next = convertIntToListNode(wholeNum);
		}
		return node;
	}

	static void solveProblem() {
		ListNode *list_1 = new ListNode(9);
		list_1->next = new ListNode(4);
		list_1->next->next = new ListNode(3);

		ListNode *list_2 = new ListNode(1);
		list_2->next = new ListNode(9);
		list_2->next->next = new ListNode(9);
		list_2->next->next->next = new ListNode(9);
		list_2->next->next->next->next = new ListNode(9);
		list_2->next->next->next->next->next = new ListNode(9);
		list_2->next->next->next->next->next->next = new ListNode(9);
		list_2->next->next->next->next->next->next->next = new ListNode(9);
		list_2->next->next->next->next->next->next->next->next = new ListNode(9);
		list_2->next->next->next->next->next->next->next->next->next = new ListNode(9);

		
		long int sum1 = getListTotal(list_1);
		long int sum2 = getListTotal(list_2);
		ListNode* sumList = convertIntToListNode(sum1 + sum2); // This failed due to int overflow.
		long int sum3 = getListTotal(sumList); 

		std::cout << "Solution 2" << "\n";
		std::cout << "List Totals:" << "\n";
		std::cout << sum1 << "\n";
		std::cout << sum2 << "\n";
		std::cout << sum3 << "\n";

		ListNode *list_3 = addLists(list_1, list_2, false); // This is the correct answer. 
	}


};
