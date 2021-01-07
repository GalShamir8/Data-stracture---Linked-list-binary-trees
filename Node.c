/*
Authors:
 Gal Shamir 208613356
 Amit Levy 206841496
 Q2
*/
#pragma once
#include "Node.h"

//creats an empty list
NODE* creatList()
{
	return NULL;
}

//return 1 if the list is empty 0 if not
int isEmptyList(NODE* head)
{
	return head == NULL;
}

//insert new node after pNode with key 
void insertList(NODE** pNode, int key)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (isEmptyList(*pNode))
	{
		newNode->key = key;
		newNode->next = *pNode;
		*pNode = newNode;
	}
	else
	{
		newNode->key = key;
		newNode->next = (*pNode)->next;
		(*pNode)->next = newNode;
	}
}

//delete the node AFTER pNode
void deleteAfter(NODE* pNode)
{
	if (!isEmptyList(pNode))
	{
		if (pNode->next)//checking that pNode not the last element
		{
			NODE* nodeToDelete = pNode->next;
			pNode->next = nodeToDelete->next;
			free(nodeToDelete);
		}
	}
}
//list "toString"
void printList(NODE* head)
{
	if (!isEmptyList(head))
	{
		printf("\n----------Printing List----------\n[%d, ", head->key);
		head = head->next;
		while (head)
		{
			if(!head->next)
				printf("%d]\n", head->key);
			else
				printf("%d, ", head->key);
			head = head->next;
		}
	}
}

//free all the dynamic allocation
void freeList(NODE* head)
{
	if (isEmptyList(head))
		return;
	while (head)
	{
		deleteAfter(head);
		head = head->next;
	}
}

//reorder call by value 
//@return newList "sorted" (odd - even)
NODE* reorder_byValue(NODE* head)
{
	NODE* newList = (NODE*)malloc(sizeof(NODE));
	if (!newList)
		return 0;//in case of unseccssefull allocation

	NODE* lastOddPointer = NULL;
	NODE* newListHead = newList;

	if (!isEmptyList(head))
	{
		/////////////first insert///////////
		newList = creatList();
		insertList(&newList, head->key);
		newListHead->next = newList;//list anchor
		if (head->key % 2 == 0)
			lastOddPointer = newListHead;
		else
			lastOddPointer = newList;
		head = head->next;
		/////////////first insert///////////
		while (head)
		{
			if (head->key % 2 == 0)
			{
				insertList(&newList, head->key);
				newList = newList->next;
			}
			else
			{
				insertList(&lastOddPointer, head->key);
				lastOddPointer = lastOddPointer->next;
			}
			head = head->next;
		}
		newList = newList->next;
		free(newList);
		return newListHead->next;
	}
	return NULL;//in case of empty list
}

//reorder call by refernce 
//new list "sorted" (odd - even)
void reorder_byRefernce(NODE** head)
{
	if (!isEmptyList(*head))
	{
		int isStartEven = 0;
		NODE* listAnchor = NULL;
		NODE* low = (NODE*)malloc(sizeof(NODE));
		if (!low)
			return;//in case of unseccssefull allocation

		NODE* high = *head;
		if ((*head)->key % 2 == 0)
		{
			low->next = *head;//list anchor
			listAnchor = low;
			isStartEven = 1;
		}
		else
			low = *head;
		while (high)
		{
			if (high->key % 2 == 0 && high->next)
			{
				if (high->next->key % 2 != 0)
				{
					swap(&low, &high);
					low = low->next;
				}
			}
			high = high->next;
		}
		if (isStartEven)
			*head = listAnchor->next;
	}
}

//swap the NODES from->to , from<-to
void swap(NODE** from, NODE** to)
{
	insertList(from, (*to)->next->key);
	deleteAfter(*to);	
}

