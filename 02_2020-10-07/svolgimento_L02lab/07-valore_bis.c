#include <stdio.h>

// questa versione funziona anche per input disordinato
int main() {
	int n;
	scanf(" %d", &n);
	int valoreMancante = n * (n - 1) / 2;
	for (int i = 0; i < n - 1; i++) {
		int inserito;
		scanf(" %d", &inserito);
		valoreMancante -= inserito;
	}
	printf("valore mancante: %d\n", valoreMancante);
	return 0;
}
