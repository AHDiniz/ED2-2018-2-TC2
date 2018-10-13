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

// Auxiliar functions:

/**
 * Function that brings a item up to the heap:
 * 
 * Inputs: pointer to the queue, to the item and the value of the key
 * Output: none
 * Conditions: existent and allocated queue and item, valid key
 * Side effects: the position of some items will be changed
 */
static void PQueue_SwimUp(PQueue *pQueue, void *item, int pos, PQItem_Switch Switch, PQItem_Compare Cmp);

/**
 * Function that brings a item down to the heap:
 * 
 * Inputs: pointer to the queue and the position of the item
 */

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

// Implementing the function that tells if the queue is empty:
bool PQueue_Empty(PQueue *pQueue)
{
    return (int)(*(pQueue->queue[0])) == 0;
}

// Implementing the function that returns the size of the queue:
int PQueue_GetSize(PQueue *pQueue)
{
    return (int)(*(pQueue->queue[0]));
}

// Implementing the function that inserts an item with a certain key:
bool PQueue_Insert(PQueue *pQueue, void *item, PQItem_Switch Switch, PQItem_Compare Cmp)
{
    pQueue->queue[0]++;
    pQueue->queue[pQueue->queue[0]] = item;
    PQueue_SwimUp(pQueue, item, pQueue->queue[0], Switch, Cmp);
}

static void PQueue_SwimUp(PQueue *pQueue, void *item, int pos, PQItem_Switch Switch, PQItem_Compare Cmp)
{
    while (pos > 1 && Cmp(pQueue->queue[pos / 2], pQueue->queue[pos]) < 0)
    {
        Switch(pQueue->queue[pos], pQueue->queue[pos / 2]);
        k /= 2;
    }
}

// Implementing the function that returns the most important item in the queue:
void *PQueue_GetFirst(PQueue *pQueue)
{
    return pQueue->queue[1];
}

// Implementing the function that removes and returns the most important item in the queue:
void *PQueue_RemoveFirst(PQueue *pQueue)
{

}

// Implementing the function that changes the key of an item in the queue:
int PQueue_ChangeKey(PQueue *pQueue, void *item, int key, PQItem_Compare Cmp)
{

}
