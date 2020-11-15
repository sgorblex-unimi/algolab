#include <math.h>
#include <stdio.h>

int main() {
	float a, b, c, delta;
	printf("inserire i tre coefficienti a, b, c: ");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		printf("radici (immaginarie): %fi, -%fi\n", (-b + sqrt(-delta)) / (2 * a), (-b + sqrt(-delta)) / (2 * a));
	else if (delta == 0) {
		printf("radice reale a molteplicità doppia: %f\n", -b / (2 * a));
	} else
		printf("radici reali: %f, %f\n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
	return 0;
}
