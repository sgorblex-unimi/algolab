#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int i = n / 2;
	while (i > 1) {
		if (n % i == 0)
			break;
		i--;
	}
	if (i == 1)
		printf("Il numero è primo\n");
	else
		printf("Il numero non è primo\n");
	return 0;
}
