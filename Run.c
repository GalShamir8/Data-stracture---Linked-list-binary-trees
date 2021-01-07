/*
Authors:
 Gal Shamir 208613356
 Amit Levy 206841496
*/
#pragma once
#include "Run.h"
void Q1()
{
	int numOfSoldiers, numOfSkips;
	printf("\nEnter number of soldiers:\n");
	scanf_s("%d", &numOfSoldiers);
	printf("\nEnter number of skips:\n");
	scanf_s("%d", &numOfSkips);

	QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
	q = createQueue();
	for (int i = 0; i < numOfSoldiers; i++)
	{
		insert(&q, i + 1);
		q = q->next;
	}

	PrintQueue(q);
	Elimination(&q, numOfSoldiers, numOfSkips);
	freeQueue(q);
}

void Q2()
{
	NODE* list = (NODE*)malloc(sizeof(NODE));
	list = creatList();
	insertList(&list, 2);
	for (int i = 0; i < 10; i++)
	{
		insertList(&list, i+1);
	}
	printList(list);
	//list = reorder_byValue(list);
	printf("\nAfter reorder list (odd-even):");
	reorder_byRefernce(&list);
	printList(list);
}

void Q5()
{
	treePtr root = (treePtr)malloc(sizeof(treeNode));
	root = initBinTree();
	root = buildBinTree(NULL, NULL, 5);
	for (int i = 1; i < 10; i++)
		insertBinTree(&root, i);
	
	printf("\n----------Printing Tree----------");
	printf("\n[ ");
	printTree(root);
	printf("]\n");

	int u = 3, v = 8;
	printf("\n----------Printing Range Search (u = %d - %d = v )----------", u , v);
	printf("\n[ ");
	rangeSearch(root, u, v);
	printf("]\n");

	freeTree(root);
}