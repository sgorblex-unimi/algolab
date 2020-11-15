#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define STARTING_STACK_CAP 1

Item *stack = NULL;
int cap = 0;
int topInd = -1;

void make_empty() {
	free(stack);
	stack = NULL;
	cap = 0;
	topInd = -1;
}

int is_empty() { return topInd == -1; }

Item top() {
	if (is_empty())
		exit(1);
	return stack[topInd];
}

Item pop() {
	if (is_empty())
		exit(1);
	if (topInd < cap / 2) {
		cap /= 2;
		stack = realloc(stack, cap * sizeof(Item));
	}
	return stack[topInd--];
}

void push(Item n) {
	topInd++;
	if (cap == 0) {
		stack = malloc(STARTING_STACK_CAP * sizeof(Item));
		cap = STARTING_STACK_CAP;
	} else if (topInd > cap - 1) {
		cap *= 2;
		stack = realloc(stack, cap * sizeof(Item));
	}
	stack[topInd] = n;
}

void print_stack() {
	for (int i = topInd; i >= 0; i--)
		printf("%d ", stack[i]);
	// printf("%s ", stack[i]);
	// printf("%p ", stack[i]);
}
