#include <stdio.h>

int main() {
	int n, i, num, flag = 1;
	scanf(" %d", &n);
	int valoreMancante = n - 1;
	for (i = 0; i < n - 1; i++) {
		scanf(" %d", &num);
		if (flag && num != i) {
			valoreMancante = i;
			flag = 0;
		}
	}
	printf("valore mancante: %d\n", valoreMancante);
}
