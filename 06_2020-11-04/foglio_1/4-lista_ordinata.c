#include "1-3-altre_funzioni.c"

Node olist_insert(Node l, int n) {
	Node curr = l, prec = NULL;
	while (curr != NULL && curr->info < n) {
		prec = curr;
		curr = curr->next;
	}
	Node new = malloc(sizeof(Node));
	new->info = n;
	new->next = curr;
	if (prec == NULL)
		l = new;
	else
		prec->next = new;
	return l;
}

Node olist_search(Node l, int n) {
	while (l != NULL && l->info < n)
		l = l->next;
	if (l == NULL || l->info > n)
		return NULL;
	else
		return l;
}
