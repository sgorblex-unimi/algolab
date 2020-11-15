#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *next;
} * Node;

typedef struct set {
	Node head;
	int card;
} Set;

void set_delete(int n, Set *s) {
	Node curr, prev;
	for (curr = s->head, prev = NULL; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->info == n)
			break;
	}
	if (curr == NULL)
		return;
	if (prev == NULL)
		s->head = s->head->next;
	else
		prev->next = curr->next;
	free(curr);
}

void set_print(Set *s) {
	Node l = s->head;
	while (l != NULL) {
		printf("%d ", l->info);
		l = l->next;
	}
}

void set_destroy(Set *s) {
	Node help;
	while (s->head != NULL) {
		help = s->head->next;
		free(s->head);
		s->head = help;
	}
}

void set_insert(Set *s, int n) {
	Node curr = s->head, prec = NULL;
	while (curr != NULL && curr->info < n) {
		prec = curr;
		curr = curr->next;
	}
	Node new = malloc(sizeof(Node));
	new->info = n;
	new->next = curr;
	if (prec == NULL) {
		s->head = new;
	} else {
		prec->next = new;
	}
}

bool set_isIn(Set *s, int n) {
	Node l = s->head;
	while (l != NULL && l->info < n)
		l = l->next;
	if (l == NULL || l->info > n)
		return false;
	else
		return true;
}

int main() {
	Set *s = calloc(1, sizeof(Set));
	char input;
	int n;
	do {
		printf("\nMENU\n+ n: inserisci   - n: delete   ? n: print if in set   c: print cardinality   p: print elements   d: delete all elements   f: exit\nChoice: ");
		scanf(" %c", &input);
		switch (input) {
			case '+':
				scanf(" %d", &n);
				if (!set_isIn(s, n)) {
					set_insert(s, n);
					s->card++;
				}
				break;
			case '-':
				scanf(" %d", &n);
				if (set_isIn(s, n))
					s->card--;
				set_delete(n, s);
				break;
			case '?':
				printf("Is in: ");
				scanf(" %d", &n);
				if (set_isIn(s, n))
					printf("it is in\n");
				else
					printf("it is NOT in\n");
				break;
			case 'c':
				printf("Cardinality: %d\n", s->card);
				break;
			case 'p':
				printf("Elements:\n");
				set_print(s);
				printf("\n");
				break;
			case 'd':
				printf("Destroying set...\n");
				set_destroy(s);
				s->head = NULL;
				s->card = 0;
				printf("Done\n");
		}
	} while (input != 'f');
}
