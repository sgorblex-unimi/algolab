/*
conversione da gradi Fahrenheit:
celsius = (fahr - 32) * 5/9
*/

#include <stdio.h>

#define FATTORE_SCALA (5.0f / 9.0f)
#define ZERO 32.0f

int main(void) {
	float fahr;
	printf("Inserisci la temperatura in gradi Fahrenheit: ");
	scanf("%f", &fahr);
	printf("Gradi Celisus equivalenti: %.1f\n", (fahr - ZERO) * FATTORE_SCALA);
	return 0;
}
