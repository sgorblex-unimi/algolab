#include "libpsgraph.h"
#include <stdio.h>

void koch(int complexity, int dimension) {
	if (!complexity) {
		draw(dimension);
	} else {
		complexity--;
		koch(complexity, dimension / 3);
		turn(-60);
		koch(complexity, dimension / 3);
		turn(120);
		koch(complexity, dimension / 3);
		turn(-60);
		koch(complexity, dimension / 3);
	}
}

void fiocco(int complexity, int dimension) {
	koch(complexity, dimension);
	turn(120);
	koch(complexity, dimension);
	turn(120);
	koch(complexity, dimension);
}

int main() {
	int complexity, dimension;
	printf("Inserire la complessità: ");
	scanf(" %d", &complexity);
	printf("Inserire la dimensione: ");
	scanf(" %d", &dimension);
	start("koch.ps");
	fiocco(complexity, dimension);
	end();
	return 0;
}
