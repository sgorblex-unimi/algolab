#include "mySort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_START_SIZE 1

int main(int argc, char *argv[]) {
	if (argc != 2 || argv[1][0] != '-' || strlen(argv[1]) != 2) {
		fprintf(stderr, "Choose an algorithm (-s selection, -m merge)\n");
		return 1;
	}
	int *a;
	int cap = ARRAY_START_SIZE;
	a = malloc(cap * sizeof(int));
	int aSize = 0;
	for (int n; scanf(" %d", &n) != EOF; aSize++) {
		if (aSize > cap - 1) {
			cap *= 2;
			a = realloc(a, cap * sizeof(int));
		}
		a[aSize] = n;
	}
	switch (argv[1][1]) {
		case 's':
			selectionSort(a, aSize);
			break;
		case 'm':
			mergeSort(a, 0, aSize);
			break;
		default:
			fprintf(stderr, "Choose an algorithm (-s selection, -m merge)\n");
			return 2;
	}
	printArr(a, aSize);
}

void printArr(int a[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}
