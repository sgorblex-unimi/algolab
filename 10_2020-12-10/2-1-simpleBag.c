#include <stdio.h>
#include <stdlib.h>

typedef struct Type_ {
	int w, v; // weight, value
} * Type;

void printIntArr(int arr[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d: %d\n", i, arr[i]);
	printf("\n");
}

#define MAXARRLEN 30

int main() {
	Type types[MAXARRLEN];
	int w, v;
	int typesNum;
	printf("Capacity:\n");
	int size = 0;
	scanf(" %d", &size);
	printf("Types ([weight value]):\n");
	for (typesNum = 0; scanf(" %d %d", &w, &v) != EOF; typesNum++) {
		types[typesNum] = malloc(sizeof(struct Type_));
		types[typesNum]->w = w;
		types[typesNum]->v = v;
	}
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
			if (candidate > s[place])
				s[place] = candidate;
		}
	}
	// printIntArr(s, size + 1);
	printf("Max total value: %d\n", s[size]);
	return 0;
}
