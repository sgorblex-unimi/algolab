#include <stdio.h>
#include <stdlib.h>

void printIntArr(int arr[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d: %d\n", i, arr[i]);
	printf("\n");
}

int main() {
	int *events = malloc(0), eventNum = 0, maxDuration;
	printf("Total (maximum) duration:\n");
	scanf(" %d", &maxDuration);
	printf("Durations:\n");
	for (int duration; scanf(" %d", &duration) == 1; events = realloc(events, (eventNum + 1) * sizeof(int)), events[eventNum++] = duration)
		;
	int s[maxDuration + 1][eventNum + 1];
	for (int i = 0; i <= maxDuration; i++)
		for (int j = 0; j <= eventNum; j++)
			s[i][j] = 0;
	for (int j = 1; j <= eventNum; j++)
		for (int i = 1; i <= maxDuration; i++) {
			s[i][j] = s[i][j - 1];
			int otherCoord = i - events[j - 1];
			if (otherCoord >= 0) {
				int candidate = s[otherCoord][j - 1] + events[j - 1];
				if (candidate > s[i][j])
					s[i][j] = candidate;
			}
		}
	printf("\n     |   ");
	for (int j = 0; j <= eventNum; j++)
		printf("%d\t ", j);
	printf("\n-----|--------------------------------------------\n");
	for (int i = 0; i <= maxDuration; i++) {
		printf("%2d   | ", i);
		for (int j = 0; j <= eventNum; j++)
			printf("%2d\t", s[i][j]);
		printf("\n");
	}
	int filter[eventNum];
	for (int i = maxDuration, j = eventNum; j > 0; j--) {
		if (s[i][j - 1] < s[i][j]) {
			filter[j - 1] = 1;
			i -= events[j - 1];
		} else
			filter[j - 1] = 0;
	}
	printf("\nManaged total duration: %d\nEvents:\n", s[maxDuration][eventNum]);
	for (int i = 0; i < eventNum; i++)
		if (filter[i])
			printf("%2d\t", events[i]);
	printf("\n");
	return 0;
}
