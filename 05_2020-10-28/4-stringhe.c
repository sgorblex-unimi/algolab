#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *read_line(char c) {
	int size = 2, i = 0;
	char *a = malloc(size * sizeof(char));
	for (char cha; (cha = getchar()) != c; i++) {
		if (i >= size) {
			size *= 2;
			a = realloc(a, size * sizeof(char));
		}
		a[i] = cha;
	}
	if (i >= size) {
		size++;
		a = realloc(a, size * sizeof(char));
	}
	a[i] = '\0';
	return a;
}

char *read_word(void) {
	int size = 2, i = 0;
	char *a = malloc(size * sizeof(char));
	for (char cha = getchar(); isalnum(cha); i++, cha = getchar()) {
		if (i >= size) {
			size *= 2;
			a = realloc(a, size * sizeof(int));
		}
		a[i] = cha;
	}
	if (i >= size) {
		size++;
		a = realloc(a, size * sizeof(char));
	}
	a[i] = '\0';
	return a;
}

int main() {
	char *s1, *s2;
	s1 = read_line('\n');
	printf("s1: %s\n", s1);
	s2 = read_word();
	printf("s2: %s\n", s2);
	return 0;
}
