#include <stdio.h>
#include <stdlib.h>

void list_delete(int n, struct node *l) {
	struct node *curr, *prev;
	for (curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->info == n)
			break;
	}
	if (curr == NULL) // quando la lista è finita
		return;
	if (prev == NULL)
		l = l->next; // quando bisogna eliminare il primo nodo
	else
		prev->next = curr->next; // quando il nodo trovato non è il primo
	free(curr);
}

int main() {
	struct node *first = NULL;
	int n = ...... list_delete(n, first);
	list_print(first);
	return 0;
}
