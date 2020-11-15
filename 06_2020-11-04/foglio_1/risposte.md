# Lezione 6 - foglio 1


## 1
1. `struct node`;
2.
```c
 X typedef struct node* Node;
 6 Node list_insert( int n, Node l ){
 7 Node new = malloc(Node);
13 Node list_search( int n, Node l ){
```
3. il nuovo nodo rappresenta l'intera lista;
4. ok
5.
```c
struct node *list_search( int n, struct node *l ){
	for (; l != NULL && l -> info != n; l = l -> next){}
	return l;
```
6. la prima occorrenza;
7.
```c
struct node *list_search_rec( int n, struct node *l ){
	if (l -> info == n || l == NULL)
		return l;
	return list_search_rec(n, l->next);
}
```
8. 
```c
void list_insert( int n, struct node **l ){
	struct node *new = malloc(struct node);
	new -> info = n;
	new -> next = l;
	*l = new; 
}
```


## 2
5. nel caso di riga 12 in quanto il nuovo puntatore alla lista non viene restituito.


## 3
5. siccome la lista è stata eliminata non c'è più alcun indirizzo da restituire.
