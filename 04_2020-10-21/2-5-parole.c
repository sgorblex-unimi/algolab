#include <stdio.h>
#include <string.h>

void smallest_largest(char *s[], int n, char **smallest, char **largest) {
	*smallest = s[0];
	*largest = s[0];
	for (int i = 1; i < n; i++) {
		if (strcmp(s[i], *smallest) < 0) {
			*smallest = s[i];
		}
		if (strcmp(s[i], *largest) > 0) {
			*largest = s[i];
		}
	}
}

int main(int argc, char **argv) {
	char *smallest, *largest;
	smallest_largest(argv + 1, argc - 1, &smallest, &largest);
	printf("smallest: %s\n", smallest);
	printf("largest: %s\n", largest);
	return 0;
}
