#include <stdio.h>
int nextCollatz(int n) {
	if (n % 2)
		return 3 * n + 1;
	return n / 2;
}

int main() {
	int n, lun = 1;
	scanf(" %d", &n);
	printf("%d ", n);
	while (n != 1) {
		n = nextCollatz(n);
		printf("%d ", n);
		lun++;
	}
	printf("\nLunghezza: %d\n", lun);

	return 0;
}
