#include <stdio.h>

int main() {
	int n, divs = 0;
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		if (n % i == 0) {
			printf("%d\n", i);
			divs++;
		}
	}
	printf("Numero divisori: %d\n", divs);
	return 0;
}
