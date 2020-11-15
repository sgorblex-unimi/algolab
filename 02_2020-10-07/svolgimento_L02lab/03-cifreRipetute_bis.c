#include <stdio.h>

int main() {
	int n;
	int occurrences[10] = {};
	scanf("%d", &n);
	for (; n; n /= 10)
		occurrences[n % 10]++;

	int i;
	for (i = 0; i < 10; i++) {
		if (occurrences[i] > 1) {
			printf("Cifre ripetute: %d", i);
			i++;
			break;
		}
	}
	while (i < 10) {
		if (occurrences[i] > 1)
			printf(", %d", i);
		i++;
	}
	printf("\n");
	return 0;

	// rimane il problema di stampare "Non ci sono cifre ripetute", quindi è meglio la prima versione.
}
