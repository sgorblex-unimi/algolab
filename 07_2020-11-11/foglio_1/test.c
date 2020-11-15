#include "mySort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM_ARRAY 100

void yourSortingAlgorithm(int arr[], int len) {
	// insert here your implementation

	mergeSort(arr, 0, DIM_ARRAY);
	// selectionSort(arr, DIM_ARRAY);
}

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
	srand(time(NULL));
	int b[DIM_ARRAY], a[DIM_ARRAY];
	printf("Random array:\n");
	for (int i = 0; i < DIM_ARRAY; i++) {
		a[i] = rand();
		// a[i] = rand() % DIM_ARRAY;
		b[i] = a[i];
		printf("%10d ", a[i]);
	}
	printf("\n\n\n\n");
	int wrong = 0, wrongInd;
	qsort(a, DIM_ARRAY, sizeof(int), cmpfunc);
	yourSortingAlgorithm(b, DIM_ARRAY);
	printf("   RIGHT  \t   YOURS  \n");
	for (int i = 0; i < DIM_ARRAY; i++) {
		if (a[i] != b[i])
			wrong = 1;
		wrongInd = i;
		printf("%10d\t", a[i]);
		printf("%10d\n", b[i]);
	}
	if (wrong) {
		printf("Your sorting algorithm failed the test. Last wrong index: %d", wrongInd);
		return 1;
	} else
		printf("Your sorting algorithm passed the test.");
	return 0;
}
