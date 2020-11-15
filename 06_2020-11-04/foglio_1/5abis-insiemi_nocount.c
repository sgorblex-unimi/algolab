#include "1-4-lista_ordinata.c"
#include <stdbool.h>

#ifndef printf
#include <stdio.h>
#endif

int countElements(Node set) {
	int res = 0;
	while (set != NULL) {
		res++;
		set = set->next;
	}
	return res;
}

int main() {
	Node set = NULL;
	char input;
	int n;
	do {
		printf("\nMENU\n+ n: inserisci   - n: delete   ? n: print if in set   c: print cardinality   p: print elements   d: delete all elements   f: exit\nChoice: ");
		scanf(" %c", &input);
		switch (input) {
			case '+':
				scanf(" %d", &n);
				if (!olist_search(set, n))
					set = olist_insert(set, n);
				break;
			case '-':
				scanf(" %d", &n);
				set = list_delete(n, set);
				break;
			case '?':
				printf("Is in: ");
				scanf(" %d", &n);
				if (olist_search(set, n))
					printf("it is in\n");
				else
					printf("it is NOT in\n");
				break;
			case 'c':
				printf("Cardinality: %d\n", countElements(set));
				break;
			case 'p':
				printf("Elements:\n");
				list_print(set);
				printf("\n");
				break;
			case 'd':
				printf("Destroying set...\n");
				list_destroy(set);
				set = NULL;
				printf("Done\n");
		}
	} while (input != 'f');
}
