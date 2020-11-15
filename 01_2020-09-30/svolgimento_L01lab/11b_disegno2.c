#include <stdio.h>

int main(void) {
	int n, i, j;
	char simbolo;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		simbolo = (i % 2) ? 'o' : '+';
		for (j = 0; j < n; j++) {
			simbolo = (j % 2) ? '+' : 'o';
			printf("%c ", simbolo);
		}
		printf("\n");
	}

	return 0;
}
