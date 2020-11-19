#include "bitree.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRLEN 31
#define NULL_PROBABILITY 10

Item newItem(int v) {
	Item res = malloc(sizeof(struct item));
	res->val = v;
	return res;
}

Item *randomArr(int size) {
	Item *a = malloc(size * sizeof(Item));
	for (int i = 0; i < size; i++) {
		if (!(rand() % NULL_PROBABILITY))
			a[i] = NULL;
		else
			a[i] = newItem(rand() % 1000);
	}
	return a;
}

int main() {
	srand(time(NULL));
	Item *a = randomArr(ARRLEN);
	printf("\n");
	Bit_node t = bit_arr2tree(a, ARRLEN, 0);
	bit_printassummary(t, 0);
	bit_preorder(t);
	printf("\n");
	bit_inorder(t);
	printf("\n");
	bit_postorder(t);
	printf("\n");
	return 0;
}
