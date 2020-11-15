#include <ctype.h>
#include <stdio.h>

int main() {
	short occurrences[26] = {};
	char c;

	// formato: "parola parola\n"
	while ((c = getchar()) != ' ') {
		if (islower(c))
			occurrences[c - 'a']++;
		if (isupper(c))
			occurrences[c - 'A']++;
	}
	while ((c = getchar()) != '\n') {
		if (islower(c))
			occurrences[c - 'a']--;
		if (isupper(c))
			occurrences[c - 'A']--;
	}
	for (int i = 0; i < 26; i++) {
		if (occurrences[i]) {
			printf("Le parole non sono anagrammi.\n");
			return 1;
		}
	}
	printf("Le parole sono anagrammi.\n");
	return 0;
}
