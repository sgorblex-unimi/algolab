#include <stdbool.h>

bool isPrime(int n) {
	for (int i = n / 2; i > 1; i--) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
