#include "../include/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int *Data;

int compare(const void *n1, const void *n2) {
	return *(int *)n1 - *(int *)n2;
}

void pqueue_sort(Data a[], int l, int r) {
	PQueue p;
	pqueue_init(&p, compare, free);
	for (int i = l; i < r; i++)
		pqueue_insert(&p, a[i]);
	for (int i = r - 1; i >= l; i--)
		pqueue_extract(&p, (void **)&(a[i]));
}

void printData(Data d) { printf("%d ", *d); }

void printarr(Data a[], int len) {
	for (int i = 0; i < len; i++)
		printData(a[i]);
}

#define MAXARRLEN 30
int main() {
	srand(time(NULL));
	Data a[MAXARRLEN];
	for (int i = 0; i < MAXARRLEN; i++) {
		a[i] = malloc(sizeof(Data));
		*a[i] = rand() % 100;
	}
	printarr(a, MAXARRLEN);
	printf("\n");
	// pqueue_sort(a, 0, MAXARRLEN);
	heapSort((void **)a, MAXARRLEN, compare);
	printarr(a, MAXARRLEN);
	printf("\n");
	return 0;
}
