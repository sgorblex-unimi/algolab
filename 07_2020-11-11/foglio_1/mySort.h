#ifndef MYSORT_H
#define MYSORT_H

// Print each element of arr to stdout
void printArr(int arr[], int len);

// Swap arr elements of indexes i and j
void swapArr(int arr[], int i, int j);

// Sort arr by selection
void selectionSort(int arr[], int len);

// Sort arr by merge
void mergeSort(int arr[], int begin, int end);

#endif
