/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * priority_queue.c: Priority Queue data structure implementation file
 */

#include "../include/priority_queue.h"
#include <stdlib.h>

// Implementing the priority queue data structure:
struct pQueue
{
    void **queue; // The array of pointers to items that represents the queue (position 0 is for the size)
};

// Implementing the function that creates a priority queue:
PQueue *PQueue_Create(int size)
{
    PQueue *pQueue = malloc(sizeof(PQueue)); // Allocating space for the queue:
    pQueue->queue = malloc(sizeof(void*) * size + 1); // Allocating space for the queue
    // Setting the amount of items in the queue:
    *(pQueue->queue[0]) = 0;
    return pQueue; // Returning the queue
}

// Implementing the function that destroys the priority queue and it's items:
PQueue *PQueue_Destroy(PQueue *pQueue, PQItem_Destroy Destroy)
{
    for (int i = 1; i < *(pQueue->queue[0]); i++)
    {
        Destroy(pQueue->queue[i]); // Destrying each item in the queue
    }
    free(pQueue->queue[0]); // Destroying the size pointer
    free(pQueue->queue); // Destroying the queue array
    free(pQueue); // Destroying the data structure
    return NULL;
}
