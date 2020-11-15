#include <stdbool.h>
#include <stdio.h>

int main() {
	int n;
	int occurrences[10] = {};
	bool flag = false;
	scanf("%d", &n);
	for (; n; n /= 10)
		if (++occurrences[n % 10] > 1)
			flag = true;

	if (flag) {
		printf("Cifre ripetute:");
		for (int i = 0; i < 10; i++) {
			if (occurrences[i] > 1)
				printf(" %d,", i);
		}
		printf("\b \n");
	} else
		printf("Non ci sono cifre ripetute\n");
	return 0;
}
