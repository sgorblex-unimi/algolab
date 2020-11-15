#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = n / 2; i > 1; i--) {
		if (n % i == 0)
			break;
	}
	if (i == 1)
		printf("Il numero è primo\n");
	else
		printf("Il numero non è primo\n");
	return 0;
}
