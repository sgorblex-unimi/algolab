#include "boundedQueue.h"
#include <stdio.h>
#include <stdlib.h>

// assuming no irregular behavior of the caller (es. dequeue on empty queue)

struct queue {
	Item *elements;
	int head, tail, cap;
};

Queue newBoundedQueue(int n) {
	Queue q = malloc(sizeof(Queue));
	q->head = -1;
	q->tail = 0;
	q->cap = n;
	q->elements = malloc(n * sizeof(Item));
	return q;
}

void destroyQueue(Queue q) {
	free(q->elements);
	free(q);
}

int isFullQueue(Queue q) { return q->tail == q->head; }

int isEmptyQueue(Queue q) {
	return q->head == -1;
}

void enqueue(Queue q, Item n) {
	if (isEmptyQueue(q))
		q->head = 0;
	q->elements[q->tail] = n;
	q->tail = (q->tail + 1) % q->cap;
}

Item dequeue(Queue q) {
	Item out = q->elements[q->head];
	q->head = (q->head + 1) % q->cap;
	if (q->head == q->tail) {
		q->head = -1;
		q->tail = 0;
	}
	return out;
}

int queueSize(Queue q) {
	if (isEmptyQueue(q))
		return 0;
	if (q->tail > q->head)
		return q->tail - q->head;
	else
		return q->cap - (q->head - q->tail);
}

Item frontValue(Queue q) { return q->elements[q->head]; }

void printQueue(Queue q) {
	printf("[");
	if (!isEmptyQueue(q)) {
		int i;
		for (i = 0; i < queueSize(q) - 1; i++)
			printf("%d, ", q->elements[(q->head + i) % q->cap]);
		printf("%d", q->elements[(q->head + i) % q->cap]);
	}
	printf("]\n");
}
