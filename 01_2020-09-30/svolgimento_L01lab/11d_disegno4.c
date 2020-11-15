#include <stdio.h>

int main(void) {
	int n, i, j;
	char simbolo;

	scanf("%d", &n);

	int k = 3 - n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n + 2; j++) {
			if (j == n - i + 1) {
				simbolo = '*';
			} else if (i >= n - 3 && j == k) {
				simbolo = '*';
			} else
				simbolo = '.';
			printf("%c ", simbolo);
		}
		k++;
		printf("\n");
	}

	return 0;
}
