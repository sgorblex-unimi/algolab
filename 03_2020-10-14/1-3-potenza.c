#include <stdio.h>

int powInt(int b, int e) {
	if (e == 0)
		return 1;
	return b * powInt(b, e - 1);
}

int main() {
	int b, e;
	scanf(" %d", &b);
	scanf(" %d", &e);
	printf("b^e: %d\n", powInt(b, e));
	return 0;
}
