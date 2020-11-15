#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM_X 10
#define DIM_Y 10

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

char campo[DIM_X][DIM_Y];

bool isPossible(int direction, int y, int x) {
	switch (direction) {
		case UP:
			if (y == 0 || campo[y - 1][x] != '.')
				return false;
			break;
		case RIGHT:
			if (x == DIM_X - 1 || campo[y][x + 1] != '.')
				return false;
			break;
		case DOWN:
			if (y == DIM_Y - 1 || campo[y + 1][x] != '.')
				return false;
			break;
		case LEFT:
			if (x == 0 || campo[y][x - 1] != '.')
				return false;
			break;
	}
	return true;
}

int main() {
	srand(time(NULL));
	for (int row = 0; row < DIM_X; row++)
		for (int col = 0; col < DIM_Y; col++)
			campo[row][col] = '.';

	int x = 0, y = 0;
	for (char passo = 'A'; passo <= 'Z'; passo++) {
		campo[y][x] = passo;
		int movement = rand() % 4;
		if (!isPossible(movement, y, x)) {
			int candidateMovement;
			for (candidateMovement = 0; candidateMovement < 4; candidateMovement++)
				if (isPossible(candidateMovement, y, x)) {
					movement = candidateMovement;
					break;
				}
			if (candidateMovement == 4)
				break;
		}
		switch (movement) {
			case UP:
				y--;
				break;
			case RIGHT:
				x++;
				break;
			case DOWN:
				y++;
				break;
			case LEFT:
				x--;
				break;
		}
	}

	for (int row = 0; row < DIM_X; row++) {
		for (int col = 0; col < DIM_Y; col++)
			printf("%c ", campo[row][col]);
		printf("\n");
	}
	return 0;
}
