#include <stdio.h>
#include <string.h>

typedef char *String;

int smallest_word_index(String s[], int n) {
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (strcmp(s[i], s[res]) < 0)
			res = i;
	}
	return res;
}

String *smallest_word_address(String s[], int n) {
	return &s[smallest_word_index(s, n)];
}

int main(int argc, String argv[]) {
	printf("via index: %s\n", argv[smallest_word_index(argv + 1, argc - 1) + 1]);
	printf("via address: %s\n", *smallest_word_address(argv + 1, argc - 1));
	return 0;
}
