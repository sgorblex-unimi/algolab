#include "1-4-lista_ordinata.c"

#ifndef printf
#include <stdio.h>
#endif

int main() {
	Node first = NULL;
	char input, o;
	int n, len = 0, *arr;
	do {
		printf("MENU\ne: exit   i: insert   d: delete   p: print list   a: print array   s: search element\nChoice: ");
		scanf(" %c", &input);
		switch (input) {
			case 'i':
				printf("Insert (till =0): ");
				scanf(" %d", &n);
				while (n != 0) {
					// first = list_add(first, n);
					first = olist_insert(first, n);
					len++;
					printf("Insert (till =0): ");
					scanf(" %d", &n);
				}
				break;
			case 'd':
				printf("Delete element: ");
				scanf(" %d", &n);
				first = list_delete(n, first);
				break;
			case 'p':
				printf("n: normal\ti: inverted\n");
				scanf(" %c", &o);
				if (o == 'n')
					list_print(first);
				else if (o == 'i')
					list_printInv(first);
				printf("\n");
				break;
			case 'a':
				printf("n: normal\telse: numbered (auto)\n");
				scanf(" %c", &o);
				if (o == 'n')
					arr = listToArray(first);
				else
					arr = listToArrayEz(first, len);
				for (int i = 0; i < len; i++) {
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			case 's':
				printf("element: ");
				scanf(" %d", &n);
				Node found;
				if ((found = olist_search(first, n)))
					printf("Element found at address %p\n", found);
				else
					printf("Element not found\n");
		}
	} while (input != 'e');
	printf("Destroy: n: normal\tr: recursive\n");
	scanf(" %c", &o);
	if (o == 'n')
		list_destroy(first);
	else if (o == 'r')
		list_destroyRic(first);
	return 0;
}
