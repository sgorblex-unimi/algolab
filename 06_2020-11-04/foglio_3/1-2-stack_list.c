#include "altre_funzioni_item.c"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

Node stack = NULL;

void make_empty() {
	list_destroy(stack);
	stack = NULL;
}

int is_empty() { return stack == NULL; }

Item top() {
	if (is_empty())
		exit(1);
	return stack->info;
}

Item pop() {
	if (is_empty())
		exit(1);
	Node tmp = stack->next;
	Item res = stack->info;
	free(stack);
	stack = tmp;
	return res;
}

void push(Item n) {
	stack = list_add(stack, n);
}

void print_stack() { list_print(stack); }
