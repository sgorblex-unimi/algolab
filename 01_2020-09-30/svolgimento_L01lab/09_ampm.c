#include <stdio.h>

int main() {
	short hh, mm;
	printf("Inserire ora in 24h:\t");
	scanf("%hd:%hd", &hh, &mm);
	if (hh > 12) {
		printf("%hd:%hd PM", (short)(hh - 12), mm);
	} else if (hh == 0) {
		printf("12:%hd AM", mm);
	} else if (hh == 12) {
		printf("12:%hd PM", mm);
	} else {
		printf("%hd:%hd AM", hh, mm);
	}
	return 0;
}
