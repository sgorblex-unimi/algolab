#include <stdio.h>

int *smallest(int a[], int n) {
	int *min = &a[0];
	for (int *addr = a; addr < a + n; addr++) {
		if (*addr < *min)
			min = addr;
	}
	return min;
}

int main() {
	int n;
	scanf(" %d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf(" %d", &a[i]);
	printf("%d", *smallest(a, n));
	return 0;
}
