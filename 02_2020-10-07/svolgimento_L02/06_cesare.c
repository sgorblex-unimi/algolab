#include <ctype.h>
#include <stdio.h>

#define MAXSTRLEN 128

int main() {
	char s[MAXSTRLEN];
	printf("Stringa: ");
	for (int i = 0; i < MAXSTRLEN && ((s[i] = getchar()) != '.'); i++) {
	}
	int key;
	printf("Chiave: ");
	scanf("%d", &key);
	for (int i = 0; i < MAXSTRLEN && s[i] != '.'; i++) {
		if (isupper(s[i])) {
			printf("%c", (s[i] - 'A' + key) % 26 + 'A');
		}
	}
	printf("\n");
	return 0;
}
