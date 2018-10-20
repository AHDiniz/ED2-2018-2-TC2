/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * main.c: Program's entry point
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/priority_queue.h"

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r"); // Opening the given file
	int queueSize; // This will hold the size of the priority queue
	
	fscanf(file, "%d\n", &queueSize); // Reading the first line to get the size of the queue
	printf("Amount of items = %d\n", queueSize);
	PQueue *pQueue = PQueue_Create(queueSize); // Creating the queue with the given size

	while (!feof(file))
	{
		int num; // Number that will be inserted in the queue
		fscanf(file, "%d\n", &num); // Reading the number that will be inserted
		PQueue_Insert(pQueue, num); // Inserting the number in the queue
	}
	PQueue_Print(pQueue); // Printing the queue

	fclose(file); // Closing the given file
	PQueue_Destroy(pQueue); // Destroying the queue
	return 0;
}