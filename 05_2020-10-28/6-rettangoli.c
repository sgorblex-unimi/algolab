#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
} Punto;

typedef struct {
	Punto p1;
	Punto p2;
} Rettangolo;

Rettangolo *makeRettangolo() {
	Rettangolo *res = malloc(sizeof(Rettangolo));
	printf("Inserisci le coordinate del punto in basso a sinistra\n");
	scanf("%f%f", &res->p1.x, &res->p1.y);
	printf("Inserisci le coordinate del punto in alto a destra\n");
	scanf("%f%f", &(*res).p2.x, &(*res).p2.y);
	return res;
}

int main(void) {

	float b, h, area, duep;

	printf("RETTANGOLO:\n");
	Rettangolo *r = makeRettangolo();
	b = (*r).p2.x - (*r).p1.x;
	h = (*r).p2.y - (*r).p1.y;
	area = b * h;
	duep = 2 * (b + h);
	printf("L'area del rettangolo vale %f, il perimetro vale %f\n", area, duep);
	return 0;
}
