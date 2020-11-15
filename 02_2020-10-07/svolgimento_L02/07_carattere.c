#include <stdio.h>

#define MAXSTRLEN 128
int main() {
	char s[MAXSTRLEN], letter;
	int i;
	for (i = 0; i < MAXSTRLEN && ((s[i] = getchar()) != '\n'); i++) {
	}
	letter = s[i - 1];
	for (i = 0; i < MAXSTRLEN && (s[i] != '\n'); i++) {
		if (s[i] != letter)
			printf("%c", s[i]);
	}
	return 0;
}
