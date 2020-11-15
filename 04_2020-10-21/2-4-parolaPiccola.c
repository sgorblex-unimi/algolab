#include <stdio.h>
#include <string.h>

int smallest_word_index(char *s[], int n) {
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (strcmp(s[i], s[res]) < 0)
			res = i;
	}
	return res;
}

char **smallest_word_address(char *s[], int n) {
	return &s[smallest_word_index(s, n)];
}

int main(int argc, char *argv[]) {
	printf("via index: %s\n", argv[smallest_word_index(argv + 1, argc - 1) + 1]);
	printf("via address: %s\n", *smallest_word_address(argv + 1, argc - 1));
	return 0;
}
