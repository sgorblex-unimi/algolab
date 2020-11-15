#include <stdio.h>

// da fare: seconda versione in cui trovata una lettera si scalano tutti i caratteri sopra in giù

int main() {
	int r, c;
	scanf(" %d", &r);
	scanf(" %d", &c);
	char juice[r][c];
	for (int row = 0; row < r; row++)
		for (int col = 0; col < c; col++)
			scanf(" %c", &juice[row][col]);

	for (int col = 0; col < c; col++) {
		for (int row = r - 1; row >= 0; row--) {
			if (juice[row][col] != '*')
				continue;
			for (int searchLetter = row; searchLetter >= 0; searchLetter--) {
				if (juice[searchLetter][col] != '*') {
					juice[row][col] = juice[searchLetter][col];
					juice[searchLetter][col] = '*';
					break;
				}
			}
		}
	}

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++)
			printf("%c ", juice[row][col]);
		printf("\n");
	}
	return 0;
}
