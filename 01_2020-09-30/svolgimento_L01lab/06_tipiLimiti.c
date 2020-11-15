#include <limits.h>
#include <stdio.h>

int main() {
	printf("short:\n\tsize:\t%lu\n\tmin:\t%d\n\tmax:\t%d\n\n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("int:\n\tsize:\t%lu\n\tmin:\t%d\n\tmax:\t%d\n\n", sizeof(int), INT_MIN, INT_MAX);
	printf("long:\n\tsize:\t%lu\n\tmin:\t%ld\n\tmax:\t%ld\n\n", sizeof(long), LONG_MIN, LONG_MAX);
	printf("float:\n\tsize:\t%lu\n\n", sizeof(float));
	printf("double:\n\tsize:\t%lu\n\n", sizeof(double));
	printf("long double:\n\tsize:\t%lu\n\n", sizeof(long double));
	printf("char:\n\tsize:\t%lu\n\tmin:\t%d\n\tmax:\t%d\n\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	return 0;
}
