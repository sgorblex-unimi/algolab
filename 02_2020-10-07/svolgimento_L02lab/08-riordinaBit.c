#include <stdio.h>

int main() {
	int n;
	scanf(" %d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf(" %d", &arr[i]);

	// this is where the magic happens
	int current = arr[0];
	int zeroPointer = 0;
	int onePointer = n - 1;
	int exchange;
	while (zeroPointer < onePointer) {
		printf("current: %d\n", current);
		if (current) {
			exchange = current;
			current = arr[onePointer];
			arr[onePointer] = exchange;
			onePointer--;
		} else {
			exchange = current;
			current = arr[zeroPointer];
			arr[zeroPointer] = exchange;
			zeroPointer++;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
