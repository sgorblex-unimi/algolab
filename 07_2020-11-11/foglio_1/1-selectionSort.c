#include "mySort.h"

void selectionSort(int a[], int n) {
	if (n > 1) {
		int maxInd = n - 1;
		for (int i = n - 2; i >= 0; i--)
			if (a[i] > a[maxInd])
				maxInd = i;
		swapArr(a, n - 1, maxInd);
		selectionSort(a, n - 1);
	}
}
