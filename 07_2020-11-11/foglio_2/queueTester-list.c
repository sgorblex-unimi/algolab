#include "unboundedQueue.h"
#include <stdio.h>

int main() {
	int nEnq = 0;
	Queue q = newUnboundedQueue();
	int input;
	while (scanf(" %d", &input) != EOF) {
		if (input == +1) {
			enqueue(q, ++nEnq);
		} else {
			if (isEmptyQueue(q))
				break;
			printf("%d\n", dequeue(q));
		}
	}
	printQueue(q);
	printf("%d\n", queueSize(q));
}
