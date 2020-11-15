#include <stdio.h>
#include <stdlib.h>
#define STARTING_STACK_CAP 1
#include "3-stack_primacat.h"

Stack *newStack() {
	Stack *s = malloc(sizeof(Stack));
	s->els = NULL;
	s->cap = 0;
	s->topInd = -1;
	return s;
}

void destroy_stack(Stack *s) {
	make_empty(s);
	free(s);
}

void make_empty(Stack *s) {
	free(s->els);
	s->els = NULL;
	s->cap = 0;
	s->topInd = -1;
}

int is_empty(Stack *s) { return s->topInd == -1; }

Item top(Stack *s) {
	if (is_empty(s))
		exit(1);
	return s->els[s->topInd];
}

Item pop(Stack *s) {
	if (is_empty(s))
		exit(1);
	if (s->topInd < s->cap / 2) {
		s->cap /= 2;
		s->els = realloc(s->els, s->cap * sizeof(Item));
	}
	return s->els[s->topInd--];
}

void push(Stack *s, Item n) {
	s->topInd++;
	if (s->cap == 0) {
		s->els = malloc(STARTING_STACK_CAP * sizeof(Item));
		s->cap = STARTING_STACK_CAP;
	} else if (s->topInd > s->cap - 1) {
		s->cap *= 2;
		s->els = realloc(s->els, s->cap * sizeof(Item));
	}
	s->els[s->topInd] = n;
}

void print_stack(Stack *s) {
	printf("s->topInd: %d\n", s->topInd);
	for (int i = s->topInd; i >= 0; i--)
		printf("%d ", s->els[i]);
	// printf("%s ", s->els[i]);
	// printf("%p ", s->els[i]);
}
