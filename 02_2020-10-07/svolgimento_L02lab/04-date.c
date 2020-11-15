#include <stdio.h>
#define MAXDATE 100

typedef struct {
	int anno, mese, giorno;
} Data;

int main() {
	Data date[MAXDATE];
	Data riferimento;
	for (int i = 0; i < MAXDATE; i++) {
		scanf("%d/%d/%d\n", &date[i].giorno, &date[i].mese, &date[i].anno);
		if (!(date[i].giorno + date[i].mese + date[i].anno))
			break;
	}
	scanf("%d/%d/%d\n", &riferimento.giorno, &riferimento.mese, &riferimento.anno);
	for (int i = 0; i < MAXDATE; i++) {
		if (!(date[i].giorno + date[i].mese + date[i].anno))
			break;
		if (date[i].anno < riferimento.anno || (date[i].anno == riferimento.anno && (date[i].mese < riferimento.mese || (date[i].mese == riferimento.mese && date[i].giorno < riferimento.giorno))))
			printf("%02d/%02d/%04d\n", date[i].giorno, date[i].mese, date[i].anno);
	}
	return 0;
}
