#include <ctype.h>
#include <stdio.h>

#define STRMAXLEN 100

char *maiuscolo(char *stringa) {
	for (char *cha = stringa; *cha; cha++)
		*cha = toupper(*cha);
	return stringa;
}

int main() {
	char stringa[STRMAXLEN];
	int i = 0;
	do {
		stringa[i] = getchar();
	} while (stringa[i++] != '\n');
	stringa[i] = '\0';
	printf("%s\n", maiuscolo(stringa));
	return 0;
}

// 3. array di char per allocare memoria;
