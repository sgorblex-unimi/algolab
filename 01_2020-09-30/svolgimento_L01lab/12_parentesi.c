#include <stdio.h>

int main() {
	int open = 0, numChar = 0;
	char letter;
	while ((letter = getchar()) != '.') {
		if (letter == '(')
			open++;
		if (letter == ')')
			open--;
		if (open < 0) {
			printf("Errore al carattere %d: troppe parentesi chiuse", numChar);
			return 1;
		}
		numChar++;
	}
	if (open > 0) {
		printf("Errore al carattere %d: mancano parentesi chiuse", numChar);
		return 1;
	}
	printf("La stringa è un'espressione ben parentesizzata");
	return 0;
}
