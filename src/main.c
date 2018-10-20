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
	// Testing the priority queue:
	
	// Getting the amount of integers in the file with the file name:
	char *filename = argv[1];
	int stringSize = strlen(filename) - 4;
	char *fnameNoExt = malloc(stringSize);
	fnameNoExt[stringSize - 1] = '\0';
	strncpy(fnameNoExt, filename, stringSize - 1);

	int amountOfItems = atoi(fnameNoExt); // Getting the amount of items in the file

	PQueue *pQueue = PQueue_Create(amountOfItems); // Creating a new priority queue

	// Opening the file that contains the integers:
	FILE *file = fopen(filename, "r");

	

	fclose(file); // Closing the file

	PQueue_Destroy(pQueue); // Destroying the priority queue
	return 0;
}