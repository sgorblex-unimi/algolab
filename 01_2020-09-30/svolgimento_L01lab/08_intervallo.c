#include <stdio.h>

#define ABS(a) a >= 0 ? a : -a

int main() {
	short hh, mm, ss;
	int sec1, sec2, secdiff;
	printf("Primo orario:\t");
	scanf("%hd:%hd:%hd", &hh, &mm, &ss);
	sec1 = 3600 * hh + 60 * mm + ss;
	printf("Secodo orario:\t");
	scanf("%hd:%hd:%hd", &hh, &mm, &ss);
	sec2 = 3600 * hh + 60 * mm + ss;
	secdiff = ABS(sec1 - sec2);
	hh = secdiff / 3600;
	secdiff %= 3600;
	mm = secdiff / 60;
	ss = secdiff % 60;
	printf("Distanza:\t%02d:%02d:%02d\n", hh, mm, ss);
	return 0;
}
