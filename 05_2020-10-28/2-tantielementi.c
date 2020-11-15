#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t n) {
	void *p;
	p = malloc(n);
	if (p == NULL) {
		printf(".....\n");
		exit(EXIT_FAILURE);
	}

	return p;
}

int *read_n(int *num) {
	int *a, i;
	scanf("%d", num);

	a = my_malloc(*num * sizeof(int));
	for (i = 0; i < *num; i++) {
		scanf("%d", &a[i]);
	}

	return a;
}

int main() {
	int n, *a;
	a = read_n(&n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
