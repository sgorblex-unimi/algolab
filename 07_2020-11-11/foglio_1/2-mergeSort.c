#include "mySort.h"

void merge(int a[], int i, int m, int f) {
	int x[f - i];
	int i1 = i, i2 = m, k = 0;
	for (; i1 < m && i2 < f; k++)
		if (a[i1] <= a[i2]) {
			x[k] = a[i1];
			i1++;
		} else {
			x[k] = a[i2];
			i2++;
		}
	if (i1 < m)
		for (; i1 < m; i1++, k++)
			x[k] = a[i1];
	else
		for (; i2 < f; i2++, k++)
			x[k] = a[i2];
	for (k = 0; k < f - i; k++)
		a[i + k] = x[k];
}

void mergeSort(int a[], int sx, int dx) {
	if (dx - sx > 1) {
		int m = (sx + dx) / 2;
		mergeSort(a, sx, m);
		mergeSort(a, m, dx);
		merge(a, sx, m, dx);
	}
}
