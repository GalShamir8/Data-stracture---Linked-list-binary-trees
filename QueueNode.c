/*
Authors:
 Gal Shamir 208613356
 Amit Levy 206841496
 Q1
*/
#pragma once
#include "QueueNode.h"

// creates an empty queue
QueueNode * createQueue()
{
	return NULL;
}
// returns 1 if the queue is empty, 0 if not
int isEmptyQueue(QueueNode * Q)
{
	return (Q == NULL);
}
// inserts item x at the rear of the queue Q
void insert(QueueNode **Q, queueinfo x)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (isEmptyQueue(*Q))
	{
		temp->value = x;
		temp->next = temp;
		(*Q) = temp;
	}
	else
	{
		temp->value = x;
		temp->next = (*Q)->next;
		(*Q)->next = temp;
	}
}
// deletes the node after node p from the list, and stores its contents in x
void delafter(QueueNode * p, queueinfo * x)
{
	*x = p->next->value;
	QueueNode* delLoaction = p->next;
	p->next = delLoaction->next;
	free(delLoaction);
}
// prints the contents of the queue
void PrintQueue(QueueNode * Q)
{
	if (!isEmptyQueue(Q))
	{
		printf("\n----------Printing Queue----------\n[");
		QueueNode* start = Q->next;
		Q = Q->next;
		do
		{
			if (Q->next == start)
				printf("%d]\n", Q->value);
			else
				printf("%d, ", Q->value);
			Q = Q->next;
		} while (Q != start);
	}
	else
		printf("Queue is empty\n");
}
//doing the elimination process
void Elimination(QueueNode** q, int n, int k)
{
	int* orderOfElimination = (int*)malloc(sizeof(int)*(n - 1)); //an array to save the order of the  elimination!
	int x = 0, i = 0;
	while ((*q)->next != *q)
	{
		*q = skip(*q, k - 1);//return the q next pos to eliminate
		delafter(*q, &x);
		orderOfElimination[i++] = x;
	}

	printf("\nOrder of elimination: ");
	printArray(orderOfElimination, n - 1);
	printf("\nLeader: %d ", (*q)->value);
}
//return the queue of the next k steps
QueueNode* skip(QueueNode* q, int k)
{
	for (int i = 0; i < k; i++)
		q = q->next;
	return q;
}
//printing array within size n
void printArray(const int* arr, int n)
{
	printf("\n[");
	for (int j = 0; j < n; j++)
	{
		if (j == n - 1)
			printf("%d]\n", arr[j]);
		else
			printf("%d, ", arr[j]);
	}
}
//free the dynamic allocations
void freeQueue(QueueNode* q)
{
	if (!q)
		return;
	int x;
	while (q->next != q)
	{
		delafter(q, &x);
		q = q->next;
	}
	delafter(q, &x);
}