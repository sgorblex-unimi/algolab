#include "bitree.h"
#include <stdio.h>
#include <stdlib.h>

struct bit_node {
	Item item;
	struct bit_node *l, *r;
};

int key(Item i) { return i->val; }

void printkey(Bit_node n) { printf("%d", key(n->item)); }

Bit_node bit_new(Item i) {
	Bit_node t = malloc(sizeof(struct bit_node));
	t->item = i;
	t->l = NULL;
	t->r = NULL;
	return t;
}

void bit_preorder(Bit_node t) {
	if (!t)
		return;
	printkey(t);
	printf(" ");
	bit_preorder(t->l);
	bit_preorder(t->r);
}

void bit_inorder(Bit_node t) {
	if (!t)
		return;
	bit_inorder(t->l);
	printkey(t);
	printf(" ");
	bit_inorder(t->r);
}

void bit_postorder(Bit_node t) {
	if (!t)
		return;
	bit_postorder(t->l);
	bit_postorder(t->r);
	printkey(t);
	printf(" ");
}

void printSpaces(int n) {
	for (int i = 0; i < n; i++)
		printf(" ");
}

void bit_printassummary(Bit_node t, int padding) {
	if (!t)
		return;
	printSpaces(padding);
	printf("* ");
	printkey(t);
	printf("\n");
	padding += 4;
	if (t->l || t->r) {
		if (t->l)
			bit_printassummary(t->l, padding);
		else {
			printSpaces(padding);
			printf("* \n");
		}
		if (t->r)
			bit_printassummary(t->r, padding);
		else {
			printSpaces(padding);
			printf("* \n");
		}
	}
}

Bit_node bit_arr2tree(Item a[], int size, int i) {
	if (i >= size || a[i] == NULL)
		return NULL;
	Bit_node res = bit_new(a[i]);
	res->l = bit_arr2tree(a, size, 2 * i + 1);
	res->r = bit_arr2tree(a, size, 2 * i + 2);
	return res;
}
