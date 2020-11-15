#include <stdbool.h>
#include <stdio.h>

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}

void farf(char *str) {
	do {
		if (isVowel(*str))
			printf("%cf%c", *str, *str);
		else
			printf("%c", *str);
	} while (*str++);
}

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		farf(argv[i]);
		printf("\n");
	}
	return 0;
}
