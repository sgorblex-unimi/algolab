#include "item.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	Item info;
	struct node *next;
} * Node;

void list_print(Node l) {
	while (l != NULL) {
		printf("%d ", l->info);
		l = l->next;
	}
}

void list_destroy(Node l) {
	Node help;
	while (l != NULL) {
		help = l->next;
		free(l);
		l = help;
	}
}

Node list_add(Node l, Item n) {
	Node new = malloc(sizeof(Node));
	new->info = n;
	new->next = l;
	return new;
}
