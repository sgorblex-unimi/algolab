#include <stdio.h>

#define MAXLENSTR 30

int main() {
	char s[MAXLENSTR];
	int i, len;
	for (i = 0; i < MAXLENSTR; i++) {
		if ((s[i] = getchar()) == '.') {
			break;
		}
	}
	len = i;
	for (i = 0; i < len / 2; i++) {
		if (s[i] == '.') {
			break;
		}
		if (s[i] != s[len - i - 1]) {
			printf("Stringa non palindroma\n");
			return 1;
		};
	}
	printf("Stringa palindroma\n");
	return 0;
}
