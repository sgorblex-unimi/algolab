#include <stdio.h>

// questa versione parte da un'array pronto
int valoreMancante(int len, int seq[]) {
	int a = 0;
	int b = len - 1;
	if (seq[0])
		return 0;
	while (1) {
		int c = (b + a + 1) / 2;
		if (seq[c] != c) {
			if (seq[c - 1] == c - 1)
				return c;
			else
				b = c;
		} else
			a = c;
	}
}

int main() {
	int len;
	scanf(" %d", &len);
	int seq[len];
	for (int i = 0; i < len; i++)
		scanf(" %d", &seq[i]);
	printf("Il numero mancante è %d\n", valoreMancante(len, seq));
	return 0;
}
