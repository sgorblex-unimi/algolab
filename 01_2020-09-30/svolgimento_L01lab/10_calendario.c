#include <stdio.h>

int main() {
	unsigned char mese, primoGiorno, numgiorni = 31, pos;
	printf("Numero del mese: ");
	scanf("%hhu", &mese);
	printf("Numero del giorno della settimana con cui comincia: ");
	scanf("%hhu", &primoGiorno);
	switch (mese) {
		case 2:
			numgiorni = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			numgiorni = 30;
			break;
	}
	printf("\nCalendario (assumo non bisestile):\n");
	printf("Lu  Ma  Me  Gi  Ve  Sa  Do\n");
	for (char i = 1; i < primoGiorno; i++)
		printf("    ");
	pos = primoGiorno - 1;
	for (unsigned char giorno = 1; giorno <= numgiorni; giorno++) {
		if (pos++ % 7 == 0)
			printf("\n");
		printf("%2hhu  ", giorno);
	}
	printf("\n");
	return 0;
}

// 30: 4, 6, 9, 11
// 31: 1, 3, 5, 7, 8, 10, 12
// 28: 2
