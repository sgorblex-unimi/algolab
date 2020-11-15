#include <stdio.h>

#define ABS(a) (a > 0 ? a : -a)

int main() {
	char c1, c2, diff;
	scanf("%c %c", &c1, &c2);
	diff = c1 - c2;
	printf("Distanza alfabetica: %d", ABS(diff));
	return 0;
}
