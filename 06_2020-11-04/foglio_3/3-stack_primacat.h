#include "item.h"
#ifndef STACK_H
#define STACK_H

typedef struct stack {
	Item *els;
	int topInd;
	int cap;
} Stack;

Stack *newStack();

void destroy_stack(Stack *s);

/* svuota la pila */
void make_empty(Stack *s);

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty(Stack *s);

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
Item top(Stack *s);

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
Item pop(Stack *s);

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push(Stack *s, Item n);

/* stampa il contenuto della pila, partendo dal top. */
void print_stack(Stack *s);

#endif
