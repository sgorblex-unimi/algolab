#include <stdio.h>

int main(void) {
	int n, x = 0, c = 0;
	printf("Inserisci una serie di numeri: ");

	do {
		scanf("%d", &n);
		x = x + n;
		c++;
	} while (n != 0);

	printf("%f\n", (double)x / c);
	return 0;
}
