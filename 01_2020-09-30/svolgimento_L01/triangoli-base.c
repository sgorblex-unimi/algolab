#include <stdio.h>

int main(void) {
	float a, b, c;

	printf("Inserisci tre numeri separati da spazi: ");
	scanf("%f %f %f", &a, &b, &c);

	if (a > b + c || b > a + c || c > a + b) {
		return 0;
	}

	if (a == b && a == c)
		printf("Il triangolo e` equilatero\n");

	else if (a == b || a == c || b == c)
		printf("Il triangolo e` isoscele\n");

	else
		printf("Il triangolo e` scaleno\n");

	return 0;
}
