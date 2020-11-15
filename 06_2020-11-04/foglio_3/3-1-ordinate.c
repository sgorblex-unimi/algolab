#include "3-stack_primacat.h"
#include <stdio.h>

int main() {
	Stack *p, *q, *r, *t;
	p = newStack();
	q = newStack();
	r = newStack();
	t = newStack();
	int n;
	printf("p: ");
	while (scanf(" %d", &n) != EOF)
		push(p, n);
	printf("q: ");
	while (scanf(" %d", &n) != EOF)
		push(q, n);
	return 0;
}
