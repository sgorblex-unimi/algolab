#include <stdio.h>

int total;

void printPoles(char poles[3][total]) {
	for (int pole = 0; pole < 3; pole++) {
		for (int place = 0; place < total; place++)
			if (poles[pole][place] != '-')
				printf("%c", poles[pole][place]);
		if (pole != 2)
			printf(", ");
	}
	printf("\n");
}

void movePoles(char poles[3][total], int from, int to) {
	int placeFrom;
	for (placeFrom = total - 1; poles[from][placeFrom] == '-'; placeFrom--) {
	}
	int placeTo;
	for (placeTo = total - 1; poles[to][placeTo] == '-' && placeTo >= 0; placeTo--) {
	}
	poles[to][placeTo + 1] = poles[from][placeFrom];
	poles[from][placeFrom] = '-';
}

void hanoi(char poles[3][total], int n, int from, int temp, int to) {
	if (n == 1) {
		movePoles(poles, from, to);
		printPoles(poles);
	} else {
		hanoi(poles, n - 1, from, to, temp);
		movePoles(poles, from, to);
		printPoles(poles);
		hanoi(poles, n - 1, temp, from, to);
	}
}

int main() {
	printf("Inserisci il numero di dischi: ");
	scanf(" %d", &total);
	char poles[3][total];
	for (int place = 0; place < total; place++)
		poles[0][place] = 'A' + place;

	for (int pole = 1; pole < 3; pole++)
		for (int place = 0; place < total; place++)
			poles[pole][place] = '-';

	printPoles(poles);
	hanoi(poles, total, 0, 1, 2);
	return 0;
}
