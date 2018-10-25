/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * main.c: Program's entry point
 * 
 * TODO: Fix the Worst Fit heuristic
 * TODO: test the BST data structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/fit.h"

#define LIMIT 1000000

int Cmp(const void *a, const void *b);

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r"); // Opening the given file
	int length; // This will hold the amount of weights in the file
	int res = fscanf(file, "%d\n", &length); // Reading the first line to get the length
	if (res == 0) return 1; // Checking if the reading operation worked

	int *weights = malloc(sizeof(int) * length); // Creating the weights array
	int i = 0; // Array position counter
	while (!feof(file)) // While the file is not over...
	{
		int num; // Number that will be inserted in the queue
		if (fscanf(file, "%d\n", &num) == 0) break; // Reading the number that will be inserted
		// Putting the number in the array if the limit is respected:
		if (i < length)
			weights[i] = num;
		i++;
	}
	fclose(file); // Closing the given file

	// Creating the decreasing ordered array:
	int *wSort = malloc(sizeof(int) * length); // Allocating the array that will be sorted
	for (i = 0; i < length; i ++) wSort[i] = weights[i]; // Copying the original array into the new one
	qsort(wSort, length, sizeof(int), Cmp); // Sorting the new array
	
	// Applying the worst fit heuristic:
	printf("%d\n", WorstFit(weights, length, LIMIT));
	// Applying the best fit heuristic:
	printf("%d\n", BestFit(weights, length, LIMIT));
	// Applying the decreasing worst fit heuristic:
	printf("%d\n", WorstFit(wSort, length, LIMIT));
	// Applying the decreasing best fit heuristic:
	printf("%d\n", BestFit(wSort, length, LIMIT));

	free(weights);
	free(wSort);

	return 0;
}

int Cmp(const void *a, const void *b)
{
	int *numA = (int *)a;
	int *numB = (int *)b;
	return (*numA - *numB);
}
