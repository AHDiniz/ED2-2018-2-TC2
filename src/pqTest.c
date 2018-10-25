/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * pqTest.c: Priority Queue test file
 */

#include <stdio.h>
#include "../include/priority_queue.h"

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r"); // Opening the file

    int size = 0; // Variable that will contain the amount of items in the queue
    if (fscanf(f, "%d\n", &size) == 0) return 1; // Reading the amount of items in the queue

    PQueue *pQueue = PQueue_Create(size); // Creating a queue with a given size

    // Reading each line in the file and adding the integer to the queue:
    int num;
    while (fscanf(f, "%d\n", &num) != EOF)
        PQueue_Insert(pQueue, num);
    fclose(f);

    PQueue_Print(pQueue);
    printf("\n");

    while (!PQueue_Empty(pQueue))
    {
        int max = PQueue_RemoveFirst(pQueue);
        printf("Item removed = %d\n", max);
        PQueue_Print(pQueue);
        printf("\n");
    }

    PQueue_Destroy(pQueue);
    
    return 0;
}