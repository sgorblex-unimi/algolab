#include "boundedQueue.h"
#include <stdio.h>

int main() {
	int nEnq = 0;
	int n;
	scanf(" %d", &n);
	Queue q = newBoundedQueue(n);
	int input;
	while (scanf(" %d", &input) != EOF) {
		if (input == +1) {
			if (isFullQueue(q)) {
				break;
			}
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
