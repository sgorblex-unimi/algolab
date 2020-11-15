#include <stdio.h>
#include <stdlib.h>

int latoCristallo(int t) {
	if (t == 0)
		return 1;
	return 1 + 2 * latoCristallo(t - 1);
}

char **creaMatrice(int n) {
	char **matr = malloc(n * sizeof(char *));
	for (int row = 0; row < n; row++) {
		matr[row] = malloc(n * sizeof(char));
		for (int col = 0; col < n; col++)
			matr[row][col] = '.';
	}
	return matr;
}

// versione non frastagliata?
// char **creaMatrice(int n) {
// 	char **matr = malloc(n * n * sizeof(char));
// 	for (int row = 0; row < n; row++)
// 		for (int col = 0; col < n; col++)
// 			matr[row][col] = '.';
// 	return matr;
// }
// andrebbe adattato anche liberaMatrice

void stampaMatrice(char **m, int n) {
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++)
			printf("%c", m[row][col]);
		printf("\n");
	}
}

void copiaSottoMatrice(char **m, int l, int r0, int c0, int r1, int c1) {
	for (int row = 0; row < l; row++)
		for (int col = 0; col < l; col++)
			m[r1 + row][c1 + col] = m[r0 + row][c0 + col];
}

void crist(char **m, int r0, int c0, int l) {
	if (l == 1)
		m[r0][c0] = '*';
	else {
		int med = (l - 1) / 2;
		m[r0 + med][c0 + med] = '*';
		crist(m, r0, c0, l / 2);
		crist(m, r0, c0 + med + 1, l / 2);
		crist(m, r0 + med + 1, c0, l / 2);
		crist(m, r0 + med + 1, c0 + med + 1, l / 2);
	}
}

void cristallo(char **m, int l) { crist(m, 0, 0, l); }

void liberaMatrice(char **m, int l) {
	for (int row = 0; row < l; row++)
		free(m[row]);
	free(m);
}

int main() {
	char **matrix;
	int t, lato;
	scanf("%d", &t);
	if (t >= 0) {
		lato = latoCristallo(t);
		matrix = creaMatrice(lato);
		cristallo(matrix, lato);
		stampaMatrice(matrix, lato);
		liberaMatrice(matrix, lato);
	}
	return 0;
}
