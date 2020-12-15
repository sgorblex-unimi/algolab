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

int main() {
	int size = 1;
	Interval *intervals = malloc(0);
	for (int i, v, f; scanf(" %d-%d %d\n", &i, &f, &v) == 3; intervals = realloc(intervals, (size + 1) * sizeof(Interval)), intervals[size] = malloc(sizeof(struct Interval_)), intervals[size]->i = i, intervals[size]->f = f, intervals[size++]->v = v)
		;
	heapSort((void **)(intervals + 1), size - 1, compareEndTime);
	int m[size];
	int opt = findOptimal(m, intervals, size);
	int solutionFilter[size];
	findSolution(solutionFilter, intervals, size, m);
	printf("\nTotal value: %d\nEvents:\n", opt);
	printIntervals(intervals, size, solutionFilter);
	return 0;
}
