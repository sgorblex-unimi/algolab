#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int places;
	char **books;
} Book;

// come dovrebbe funzionare la memoria qui?
Book newBook(Book b, int n) {
	b.places = n;
	if (b.books == NULL)
		b.books = calloc(n, sizeof(char *));
	else {
		b.books = realloc(b.books, n * sizeof(char *));
		for (int i = 0; i < b.places; i++) {
			b.books[i] = NULL;
		}
	}
	return b;
}

void printBook(Book b) {
	int i;
	for (i = 0; i < b.places - 1; i++) {
		printf("%2d:\t", i);
		if (b.books[i] != NULL)
			printf("%s\t", b.books[i]);
		else
			printf("[empty]\t");
		printf("\n");
	}
}

// copio la stringa o la collego e basta?
void book(Book b, int k, char *name) {
	if (k >= b.places) {
		printf("ERROR - Inexisting place\n");
		return;
	}
	if (b.books[k] != NULL) {
		printf("ERROR - Place taken\n");
		return;
	}
	b.books[k] = malloc((strlen(name) + 1) * sizeof(char));
	strcpy(b.books[k], name);
}

void cancel(Book b, int k) {
	if (k >= b.places) {
		printf("ERROR - Inexisting place\n");
		return;
	}
	if (b.books[k] == NULL) {
		printf("ERROR - Place not taken\n");
		return;
	} else
		b.books[k] = NULL;
}

void move(Book b, int from, int to) {
	if (from >= b.places || to >= b.places) {
		printf("ERROR - Inexisting place\n");
		return;
	}
	if (b.books[from] == NULL || b.books[to] != NULL) {
		printf("ERROR\n");
		return;
	}
	b.books[to] = b.books[from];
	b.books[from] = NULL;
}

char *readWord(bool *newLine) {
	int size = 3, i = 0;
	char *a = malloc(size * sizeof(char));
	char cha;
	while (isspace(cha = getchar())) {
	}
	for (; isalnum(cha); i++, cha = getchar()) {
		if (i >= size) {
			size += 5;
			a = realloc(a, size * sizeof(int));
		}
		a[i] = cha;
	}
	if (i >= size) {
		size++;
		a = realloc(a, size * sizeof(char));
	}
	a[i] = '\0';
	if (cha == '\n')
		*newLine = true;
	return a;
}

int main() {
	Book b = {0, NULL};
	bool newLine = true;
	char c;
	int num;
	int num2;
	char *str;
	while ((c = getchar()) != 'f') {
		if (isspace(c) || !newLine) {
			if (c == '\n')
				newLine = true;
			continue;
		}
		switch (c) {
			case 'b':
				scanf(" %d", &num);
				b = newBook(b, num);
				break;
			case '+':
				scanf(" %d", &num);
				str = readWord(&newLine);
				book(b, num, str);
				break;
			case '-':
				scanf(" %d", &num);
				cancel(b, num);
				break;
			case 'm':
				scanf(" %d", &num);
				scanf(" %d", &num2);
				move(b, num, num2);
				break;
			case 'p':
				printBook(b);
		}
	}
}
