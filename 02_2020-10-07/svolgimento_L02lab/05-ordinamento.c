#include <stdio.h>
#define MAXINTARR 40

int main() {
	int sorted[MAXINTARR];
	int n;
	for (int i = 0; i < MAXINTARR; i++) {
		scanf("%d", &n);
		if (!n) {
			break;
		}
		int j;
		for (j = 0; j < i; j++) {
			if (n < sorted[j]) {
				for (int k = i; k > j; k--)
					sorted[k] = sorted[k - 1];
				sorted[j] = n;
				break;
			}
		}
		if (j == i) {
			sorted[i] = n;
		}
	}
	for (int i = 0; i < MAXINTARR; i++)
		printf("%d ", sorted[i]);
	return 0;
}
