#define CUSTOM_TYPE char
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char token[10];
	while (scanf("%s", token) != EOF) {
		if (isdigit(token[0]))
			printf("%s ", token);
		else if (strlen(token) != 1)
			return 1;
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
			push(token[0]);
		else if (token[0] == ')')

			printf("%c ", pop());
	}
	printf("%c\n", pop());
	return 0;
}
