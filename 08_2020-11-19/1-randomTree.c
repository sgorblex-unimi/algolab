#include "../include/bitree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRLEN 31
#define NULL_PROBABILITY 10

int **randomArr(int size) {
	int **a = malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++) {
		if (!(rand() % NULL_PROBABILITY))
			a[i] = NULL;
		else {
			a[i] = malloc(sizeof(int));
			*a[i] = rand() % 1000;
		}
	}
	return a;
}

void printSpaces(int n) {
	for (int i = 0; i < n; i++)
		printf(" ");
}

int printInt(void *data) {
	printf("%d ", *(int *)data);
	return 0;
}

void printassummary(BiTreeNode *node, int padding) {
	if (bitree_is_eob(node))
		return;
	printSpaces(padding);
	printf("* ");
	printInt(bitree_data(node));
	printf("\n");
	padding += 4;
	if (!bitree_is_eob(bitree_left(node)) || !bitree_is_eob(bitree_right(node))) {
		if (!bitree_is_eob(bitree_left(node)))
			printassummary(bitree_left(node), padding);
		else {
			printSpaces(padding);
			printf("* \n");
		}
		if (!bitree_is_eob(bitree_right(node)))
			printassummary(bitree_right(node), padding);
		else {
			printSpaces(padding);
			printf("* \n");
		}
	}
}

void bitree_printassummary(BiTree *tree) { printassummary(bitree_root(tree), 0); }

void printArr(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d: ", i);
		if (arr[i])
			printf("%d ", *arr[i]);
	}
	printf("\n");
}

int main() {
	srand(time(NULL));
	int **a = randomArr(ARRLEN);
	printf("Array:\n");
	printArr(a, ARRLEN);
	BiTree tree;
	bitree_init(&tree, free);
	if (bitree_fromarr(&tree, (const void **)a, ARRLEN)) {
		printf("Error creating the tree\n");
		return 1;
	}
	printf("Size: %d", bitree_size(&tree));
	printf("\nPreorder:  ");
	bitree_preorder(&tree, printInt);
	printf("\nIn-order:  ");
	bitree_inorder(&tree, printInt);
	printf("\nPostorder: ");
	bitree_postorder(&tree, printInt);
	printf("\nAs summary:\n");
	bitree_printassummary(&tree);
	printf("\n");
	return 0;
}
