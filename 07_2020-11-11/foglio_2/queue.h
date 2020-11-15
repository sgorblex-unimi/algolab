#ifndef QUEUE_H
#define QUEUE_H
#include "item.h"

// Interface for the queue data structure
typedef struct queue *Queue;

void destroyQueue(Queue);

// Put element in queue
void enqueue(Queue, Item);

// Remove and return element from the queue
Item dequeue(Queue);

// Returns the queue's number of elements
int queueSize(Queue);

// Return element at the head
Item frontValue(Queue);

// Check if queue is empty
int isEmptyQueue(Queue);

// Print queue content
void printQueue(Queue);

#endif
