/*
 * DOMANDE
 * 1. no;
 * 2. il singolo carattere per aggiornare la relativa statistica;
 * 3. 3, non credo
 * 4. non cresce
 * 5. 
 */

#include <ctype.h>
#include <stdio.h>

void printAsterisk(int n) {
	for (; n > 0; n--)
		printf("*");
}

int main() {
	short occurrences[26] = {};
	char c;
	while ((c = getchar()) != '.') {
		if (islower(c))
			occurrences[c - 'a']++;
		if (isupper(c))
			occurrences[c - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (occurrences[i]) {
			printf("%c ", 'A' + i);
			printAsterisk(occurrences[i]);
			printf("\n");
		}
	}
	return 0;
}
