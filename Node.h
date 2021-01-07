/*
Authors:
 Gal Shamir 208613356
 Amit Levy 206841496
 Q2
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int key;
	struct list* next;
}NODE;

//creats an empty list
NODE* creatList();

//return 1 if the list is empty 0 if not
int isEmptyList(NODE* head);

//inset new node after pNode with key x
void insertList(NODE** pNode, int key);

//delete the node AFTER pNode
void deleteAfter(NODE* pNode);

//list "toString"
void printList(NODE* head);

//free all the dynamic allocation
void freeList(NODE* head);

//reorder call by value @return newList "sorted" (odd - even)
NODE* reorder_byValue(NODE* head);

//reorder call by refernce new list "sorted" (odd - even)
void reorder_byRefernce(NODE** head);

//swap the NODES from->to , from<-to
void swap(NODE** from, NODE** to);
