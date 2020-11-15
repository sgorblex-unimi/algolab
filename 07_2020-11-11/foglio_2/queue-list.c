#include "queue.h"
#include "unboundedQueue.h"
#include <stdio.h>
#include <stdlib.h>

// assuming no irregular behavior of the caller (es. dequeue on empty queue)

typedef struct node {
	Item info;
	struct node *next;
} * Node;

struct queue {
	Node head, tail;
};

Queue newUnboundedQueue() {
	Queue q = malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	return q;
}

void destroyQueue(Queue q) {
	while (q->head)
		dequeue(q);
	free(q);
}

void enqueue(Queue q, Item n) {
	Node new = malloc(sizeof(Node));
	new->info = n;
	new->next = NULL;
	if (q->tail)
		q->tail->next = new;
	else
		q->head = new;
	q->tail = new;
}

Item dequeue(Queue q) {
	Item res = q->head->info;
	Node tmp = q->head->next;
	free(q->head);
	q->head = tmp;
	return res;
}

int isEmptyQueue(Queue q) {
	return q->head == NULL;
}

int queueSize(Queue q) {
	int res = 0;
	Node tmp = q->head;
	while (tmp) {
		res++;
		tmp = tmp->next;
	}
	return res;
}

int frontValue(Queue q) { return q->head->info; }

void printQueue(Queue q) {
	Node tmp = q->head;
	printf("[ ");
	while (tmp) {
		printf("%d ", tmp->info);
		tmp = tmp->next;
	}
	printf("]\n");
}
