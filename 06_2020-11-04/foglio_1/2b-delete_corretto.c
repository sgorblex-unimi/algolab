#include "1-3-altre_funzioni.c"

int main() {
	struct node *first = NULL;
	int n;
	scanf(" %d", &n);
	first = list_delete(n, first);
	list_print(first);
	return 0;
}
