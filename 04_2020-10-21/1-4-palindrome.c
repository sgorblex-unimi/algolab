#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(const char *str) {
	int len = strlen(str);
	const char *last = str + len - 1;
	while (last > str)
		if (*str++ != *last--)
			return false;
	return true;
}

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		printf("%s:\t", argv[i]);
		if (isPalindrome(argv[i]))
			printf("palindrome\n");
		else
			printf("not palindrome\n");
	}
	return 0;
}
