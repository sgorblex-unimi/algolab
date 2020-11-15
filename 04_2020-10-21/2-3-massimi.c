#include <stdio.h>

void max_secondmax(int a[], int n, int *max, int *second_max) {
	if (a[0] >= a[1]) {
		*max = a[0];
		*second_max = a[1];
	} else {
		*max = a[1];
		*second_max = a[0];
	}
	for (int i = 2; i < n; i++) {
		if (a[i] > *max) {
			*second_max = *max;
			*max = a[i];
		} else if (a[i] > *second_max) {
			*second_max = a[i];
		}
	}
}

int main() {
	int max, max2, n;
	scanf(" %d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf(" %d", &a[i]);
	}
	max_secondmax(a, n, &max, &max2);
	printf("max:\t\t%d\n", max);
	printf("second max:\t%d\n", max2);
	return 0;
}
