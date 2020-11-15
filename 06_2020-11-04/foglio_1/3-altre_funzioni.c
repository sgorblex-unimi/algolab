#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *next;
} * Node;

Node list_delete(int n, Node l) {
	Node curr, prev;
	for (curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->info == n)
			break;
	}
	if (curr == NULL)
		return l;
	if (prev == NULL)
		l = l->next;
	else
		prev->next = curr->next;
	free(curr);
	return l;
}

void list_print(Node l) {
	while (l != NULL) {
		printf("%d ", l->info);
		l = l->next;
	}
}

void list_printInv(Node l) {
	if (l->next != NULL)
		list_printInv(l->next);
	printf("%d ", l->info);
}

int *listToArray(Node l) {
	int i = 0, size = 1;
	int *res = malloc(size * sizeof(int));
	while (l->next != NULL) {
		if (i >= size) {
			size *= 2;
			res = realloc(res, size * sizeof(int));
		}
		res[i] = l->info;
		l = l->next;
		i++;
	}
	res[i] = l->info;
	return res;
}

int *listToArrayEz(Node l, int n) {
	int i = 0, *res = malloc(n * sizeof(int));
	while (l->next != NULL) {
		res[i] = l->info;
		l = l->next;
		i++;
	}
	res[i] = l->info;
	return res;
}

void list_destroy(Node l) {
	Node help;
	while (l != NULL) {
		help = l->next;
		free(l);
		l = help;
	}
}

void list_destroyRic(Node l) {
	if (l->next != NULL)
		list_printInv(l->next);
	free(l);
}

Node list_add(Node l, int n) {
	Node new = malloc(sizeof(Node));
	new->info = n;
	new->next = l;
	return new;
}
