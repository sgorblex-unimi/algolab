#include <math.h>
#include <stdio.h>

typedef struct {
	float x, y;
} Punto;

typedef struct {
	Punto p1;
	Punto p2;
} Rettangolo;

typedef struct {
	Punto centro;
	float raggio;
} Cerchio;

int main(void) {

	float b, h, area, duep;
	Rettangolo r;

	printf("RETTANGOLO:\n");
	printf("Inserisci le coordinate del punto in basso a sinistra\n");
	scanf("%f%f", &r.p1.x, &r.p1.y);
	printf("Inserisci le coordinate del punto in alto a destra\n");
	scanf("%f%f", &r.p2.x, &r.p2.y);
	b = r.p2.x - r.p1.x;
	h = r.p2.y - r.p1.y;
	area = b * h;
	duep = 2 * (b + h);
	printf("L'area del rettangolo vale %f, il perimetro vale %f\n", area, duep);

	Cerchio cer;
	printf("Inserisci le coordinate del centro del cerchio\n");
	scanf("%f%f", &cer.centro.x, &cer.centro.y);
	printf("Inserisci il raggio del cerchio\n");
	scanf("%f", &cer.raggio);
	printf("Circonferenza:\t%f\nArea:\t%f", M_PI * 2 * cer.raggio, M_PI * cer.raggio * cer.raggio);
	return 0;
}
