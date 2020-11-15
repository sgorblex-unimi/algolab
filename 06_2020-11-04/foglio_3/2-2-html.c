#define CUSTOM_TYPE char *
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tagMatch(char *open, char *close) {
	return !strcmp(++open, close + 2);
}

int main() {
	char token[10];
	while (scanf("%s", token) != EOF) {
		int len = strlen(token);
		if (len > 2 && token[0] == '<' && token[len - 1] == '>') {
			if (token[1] != '/') {
				char *t = malloc(10 * sizeof(char));
				strcpy(t, token);
				push(t);
			} else if (is_empty() || !tagMatch(pop(), token)) {
				printf("Documento non ben formato\n");
				return 0;
			}
		}
	}
	if (is_empty())
		printf("Documento ben formato\n");
	else {
		printf("Documento non ben formato\n");
	}
	return 0;
}
