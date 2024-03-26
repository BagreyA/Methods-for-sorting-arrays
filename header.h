#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int n, int *comp, int *move);

void insertionSort(int arr[], int n, int *comp, int *move);

void bubbleSort(int arr[], int n, int *comp, int *move);

void heapify(int arr[], int n, int i, int *comp, int *move);

void heapSort(int arr[], int n, int *comp, int *move);

void printArray(int arr[], int n);

void fillArray(int arr[], int n, int fillType);
