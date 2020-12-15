#include <stdio.h>
#include <stdlib.h>

typedef struct Type_ {
	int w, v; // weight, value
} * Type;

void printIntArr(int arr[], int len) {
	for (int i = 0; i < len; i++)
		printf("%2d\t", i);
	printf("\n-");
	for (int i = 1; i < len; i++)
		printf("--------");
	printf("-\n");
	for (int i = 0; i < len; i++)
		printf("%2d\t", arr[i]);
	printf("\n");
}

int main() {
	Type *types = malloc(0);
	int typesNum = 0;
	printf("Capacity:\n");
	int size;
	scanf(" %d", &size);
	printf("Types ([weight value]):\n");
	for (int w, v; scanf(" %d %d\n", &w, &v) == 2; types = realloc(types, (typesNum + 1) * sizeof(Type)), types[typesNum] = malloc(sizeof(struct Type_)), types[typesNum]->w = w, types[typesNum++]->v = v)
		;
	int s[size + 1];
	for (int i = 0; i < size + 1; i++)
		s[i] = 0;
	for (int i = 0; i < typesNum; i++)
		s[types[i]->w] = types[i]->v;
	for (int i = 1; i <= size; i++) {
		if (s[i - 1] > s[i])
			s[i] = s[i - 1];
		for (int j = 0; j < typesNum; j++) {
			int candidate = s[i] + types[j]->v;
			int place = i + types[j]->w;
			if (place <= size && candidate > s[place])
				s[place] = candidate;
		}
	}
	printf("\n");
	printIntArr(s, size + 1);
	printf("\nMax total value: %d\n", s[size]);
	return 0;
}
