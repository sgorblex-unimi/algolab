#include <stdio.h>
#define n 2
#define nn (n * n)

int main() {
	int quadrato[n][n] = {{0}}, k = 1;
	int i, j, inew, jnew;

	i = 0;
	j = n / 2;
	for (k = 1; k <= nn; k++) {
		quadrato[i][j] = k;
		inew = (i == 0) ? n - 1 : i - 1;
		jnew = (j == n - 1) ? 0 : j + 1;
		if (quadrato[inew][jnew] == 0) {
			i = inew;
			j = jnew;
		} else {
			i++;
		}
	}
	for (int riga = 0; riga < n; riga++) {
		for (int colonna = 0; colonna < n; colonna++) {
			printf("%2d ", quadrato[riga][colonna]);
		}
		printf("\n");
	}

	// controllo somma righe
	//	for (int riga = 0; riga < n; riga++) {
	//		int accum = 0;
	//		for (int colonna = 0; colonna < n; colonna++) {
	//			accum += quadrato[riga][colonna];
	//		}
	//		printf(accum == 15 ? "ok\n" : "not ok\n");
	//	}
	return 0;
}
