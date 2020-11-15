#define CUSTOM_TYPE int
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char token[10];
	while (scanf("%s", token) != EOF) {
		if (isdigit(token[0]))
			push(atoi(token));
		else if (strlen(token) != 1)
			break;
		else
			switch (token[0]) {
				case '+':
					push(pop() + pop());
					break;
				case '-':
					push(pop() - pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					push(pop() / pop());
			}
	}
	printf("Risultato: %d\n", pop());
	return 0;
}
