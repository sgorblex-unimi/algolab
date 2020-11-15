#include <stdio.h>

void scambia(int *val1, int *val2) {
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

int main() {
	int val1, val2;
	scanf(" %d", &val1);
	scanf(" %d", &val2);
	scambia(&val1, &val2);
	printf("val1: %d,\tval2: %d\n", val1, val2);
	return 0;
}
