/*
Authors:
 Gal Shamir 208613356
 Amit Levy 206841496
 Q1
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int queueinfo;

typedef struct node
{
	queueinfo value;
	struct node* next;
} QueueNode;

// creates an empty queue
QueueNode * createQueue();

// returns 1 if the queue is empty, 0 if not
int isEmptyQueue(QueueNode * Q);

// inserts item x at the rear of the queue Q
void insert(QueueNode **Q, queueinfo x);

// deletes the node after node p from the list, and stores its contents in x
void delafter(QueueNode * p, queueinfo * x);

// prints the contents of the queue
void PrintQueue(QueueNode * Q);

//doing the elimination process
void Elimination(QueueNode** q, int n, int k);

//return the queue of the next k steps
QueueNode* skip(QueueNode* q, int k);

//printing array within size n
void printArray(const int* arr, int n);

//free the dynamic allocations
void freeQueue(QueueNode* q);
