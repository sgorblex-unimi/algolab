#include "../include/bistree.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry_ {
	char *key;
	int value;
} * Entry;

void printEntry(void *n) {
	printf("%s: %d\n", ((Entry)n)->key, ((Entry)n)->value);
}

char *read_word() {
	int size = 2, i = 0;
	char *a = malloc(size * sizeof(char));
	char cha;
	for (cha = getchar(); !isalnum(cha); cha = getchar()) {
		if (cha == '.' || cha == EOF)
			return NULL;
	}
	for (; isalnum(cha); cha = getchar()) {
		if (i >= size - 1) {
			size *= 2;
			a = realloc(a, size * sizeof(int));
		}
		a[i++] = cha;
	}
	if (cha == '.' || cha == EOF)
		return NULL;
	a[i] = '\0';
	return a;
}

Entry newEntry(char *k, int v) {
	Entry i = malloc(sizeof(struct Entry_));
	i->key = k;
	i->value = v;
	return i;
}

int keyCompare(const void *entry1, const void *entry2) {
	return strcmp(((Entry)entry1)->key, ((Entry)entry2)->key);
}

void destroyEntry(void *entry) {
	free(((Entry)entry)->key);
	free((Entry)entry);
}

void invorder(BiTreeNode *node, void (*action)(void *data)) {
	if (bitree_is_eob(node))
		return;
	invorder(node->right, action);
	action(node->data);
	invorder(node->left, action);
}

void bitree_invInorder(BiTree *tree, void (*action)(void *data)) {
	invorder(tree->root, action);
}

int main() {
	BisTree tree;
	bistree_init(&tree, keyCompare, destroyEntry);
	char *w;
	while ((w = read_word())) {
		Entry entry = newEntry(w, 1);
		int notfound;
		if ((notfound = bistree_lookup(&tree, (void *)&entry)))
			bistree_insert(&tree, entry);
		else
			entry->value++;
	}

	printf("Occurrences (alphabetic order):\n");
	bitree_inorder(&tree, printEntry);
	printf("\n\nOccurrences (inverse order):\n");
	bitree_invInorder(&tree, printEntry);

	printf("\n\nSearch occurrences:\n");
	while ((w = read_word())) {
		Entry entry = newEntry(w, 1);
		int notfound;
		if ((notfound = bistree_lookup(&tree, (void *)&entry)))
			printf("%s: 0\n", w);
		else
			printEntry(entry);
	}
	return 0;
}
