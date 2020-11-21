#include "functions.c"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void bist_printItem(Item n) { printf("%s: %d", n->key, n->value); }

void bist_orderPrint(BistNode t) {
	if (!t)
		return;
	bist_orderPrint(t->l);
	bist_printItem(t->item);
	printf("\n");
	bist_orderPrint(t->r);
}

void bist_invOrderPrint(BistNode t) {
	if (!t)
		return;
	bist_invOrderPrint(t->r);
	bist_printItem(t->item);
	printf("\n");
	bist_invOrderPrint(t->l);
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

Item newItem(Key k, int v) {
	Item i = malloc(sizeof(struct item));
	i->key = k;
	i->value = v;
	return i;
}

int main() {
	BistNode root;
	char *w;
	while ((w = read_word())) {
		Item i;
		if ((i = bist_search_it(root, w)))
			i->value++;
		else
			bist_insert(&root, newItem(w, 1));
	}

	printf("\n\nOccurrences (alphabetic order):\n");
	bist_orderPrint(root);
	printf("\n\nOccurrences (inverse order):\n");
	bist_invOrderPrint(root);

	printf("\n\nSearch occurrences:\n");
	while ((w = read_word())) {
		Item i;
		if ((i = bist_search_it(root, w)))
			bist_printItem(i);
		else
			printf("%s: 0", w);
		printf("\n");
	}
	return 0;
}
