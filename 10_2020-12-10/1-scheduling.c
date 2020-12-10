#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a > b ? a : b)

typedef struct Interval_ {
	int i, f, v;
} * Interval;

int compareEndTime(const void *int1, const void *int2) {
	return ((Interval)int1)->f - ((Interval)int2)->f;
}

int p(Interval arr[], int j) {
	for (int i = j; i > 0; i--)
		if (arr[i]->f <= arr[j]->i)
			return i;
	return 0;
}

int findOptimal(int m[], Interval arr[], int len) {
	m[0] = 0;
	for (int j = 1; j < len; j++)
		m[j] = max(arr[j]->v + m[p(arr, j)], m[j - 1]);
	return m[len - 1];
}

void findSolution(int res[], Interval intervals[], int len, int m[]) {
	for (int j = len - 1; j > 0;) {
		int pJ = p(intervals, j);
		if (intervals[j]->v + m[pJ] >= m[j - 1]) {
			res[j] = 1;
			for (int i = j - 1; i > pJ; i--)
				res[i] = 0;
			j = pJ;
		} else {
			res[j] = 0;
			j--;
		}
	}
}

void printIntervals(Interval arr[], int len, int filter[]) {
	for (int i = 1; i < len; i++)
		if (filter[i])
			printf("%d-%d %d\n", arr[i]->i, arr[i]->f, arr[i]->v);
}

#define MAXARRLEN 30

int main() {
	int size;
	Interval intervals[MAXARRLEN];
	for (int i = 0; i < MAXARRLEN; i++)
		intervals[i] = malloc(sizeof(struct Interval_));
	for (size = 1; scanf("%d-%d %d\n", &(intervals[size]->i), &(intervals[size]->f), &(intervals[size]->v)) != EOF && size < 30; size++)
		;
	heapSort((void **)intervals, size, compareEndTime);
	int m[size];
	int opt = findOptimal(m, intervals, size);
	int solutionFilter[size];
	findSolution(solutionFilter, intervals, size, m);
	printf("Total value: %d\n", opt);
	printIntervals(intervals, size, solutionFilter);
	return 0;
}
