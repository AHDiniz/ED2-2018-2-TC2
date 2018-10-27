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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXCH(a, b) { int t = (a); (a) = (b); (b) = t; }

// Implementing the priority queue data structure:
struct pQueue
{
    int *queue; // The array of pointers to items that represents the queue (position 0 is for the size)
    int limit; // The maximum amount of items that the queue can hold
};

/**
 * Function that fixes the value of a key upwards
 * 
 * Inputs: pointer to the queue and the position that must be fixed
 * Output: none
 * Conditions: existent and allocated queue and valid position
 * Side effects: the queue is reorganized
 */
static void FixUp(PQueue *pQueue, int pos)
{
    while (pos > 1 && pQueue->queue[pos / 2] > pQueue->queue[pos])
    {
        EXCH(pQueue->queue[pos / 2], pQueue->queue[pos]);
        pos /= 2;
    }
}

/**
 * Function that fixes the value of a key downwards
 * 
 * Inputs: pointer to the queue and the position that must be fixed
 * Output: none
 * Conditions: existent and allocated queue and valid position
 * Side effects: the queue is reorganized
 */
static void FixDown(PQueue *pQueue, int pos)
{
    int size = PQueue_GetSize(pQueue);
    while (2 * pos < size)
    {
        int j = 2 * pos;
        // If the 2k pos. son is bigger then the 2k+1 pos. son, the 2k+1 pos. son will be exchanged with the current item
        if (j < size && pQueue->queue[j] > pQueue->queue[j + 1]) j++;
        // If the current item and the son are equal, the operation can stop
        if (pQueue->queue[pos] <= pQueue->queue[j]) break;
        EXCH(pQueue->queue[pos], pQueue->queue[j]); // Exchanging the son and the father
        pos = j;
    }
}

// Implementing the function that creates the priority queue:
PQueue *PQueue_Create(int size)
{
    PQueue *pQueue = malloc(sizeof(PQueue)); // Allocating space to the priority queue
    pQueue->queue = malloc(sizeof(int) * size + 1); // Allocating space to the queue's array
    pQueue->queue[0] = 0; // Setting the current amount of items in the queue
    pQueue->limit = size; // Storing the maximum amount of items that the queue can have
    return pQueue; // Returning the queue
}

// Implementing the function that destroys the priority queue:
PQueue *PQueue_Destroy(PQueue *pQueue)
{
    free(pQueue->queue); // Destroying the queue's array
    free(pQueue); // Destroying the queue
    return NULL;
}

// Implementing the function that tells if the queue is empty:
bool PQueue_Empty(PQueue *pQueue)
{
    return pQueue->queue[0] == 0; // Checking if there are items in the queue:
}

// Implementing the function that returns the size of the queue:
int PQueue_GetSize(PQueue *pQueue)
{
    return pQueue->queue[0]; // Returing the size of the queue
}

// Implementing the function that inserts an item in the queue:
bool PQueue_Insert(PQueue *pQueue, int item)
{
    int top = ++pQueue->queue[0]; // Incrementing the size of the queue
    if (top > pQueue->limit) // Checking if the size is valid
    {
        // If it isn't, then the size will be decremented and the operation will return false:
        pQueue->queue[0]--;
        return false;
    }
    pQueue->queue[top] = item; // Putting the item in the queue
    // Fixing the position of the item:
    FixUp(pQueue, top);
    return true;
}

// Implementing the function that gets the most important item in the queue: 
int PQueue_GetFirst(PQueue *pQueue)
{
    return pQueue->queue[1]; // Returning the item without removing it
}

// Implementing the function that removes the most important item in the queue:
int PQueue_RemoveFirst(PQueue *pQueue)
{
    int size = --pQueue->queue[0]; // Updating the queue's size
    if (size < 0) // Checking if the size is valid
    {
        // If it isn't then it will be fixed and the operation will return 0:
        pQueue->queue[0]++;
        return 0;
    }
    int min = pQueue->queue[1]; // Getting the most important item in the queue
    EXCH(pQueue->queue[1], pQueue->queue[pQueue->queue[0] + 1]); // Putting it in a position that "isn't in the queue anymore" (the size was updated to not reach this position)
    FixDown(pQueue, 1);
    return min; // Returing the most important item
}

// Implementing the function that changes the key of a given item:
void PQueue_ChangeKey(PQueue *pQueue, int prevKey, int newKey)
{
    int i;
    for (i = 1; i < PQueue_GetSize(pQueue) - 1; i++)
    {
        if (pQueue->queue[i] == prevKey)
        {
            pQueue->queue[i] = newKey;
            break;
        }
    }
    if (prevKey > newKey) FixUp(pQueue, i);
    else FixDown(pQueue, i);
}

// Implementing the function that prints the queue:
void PQueue_Print(PQueue *pQueue)
{
    printf("Amount of items = %d\n", pQueue->queue[0]);
    int level = 0;
    printf("Level = %d: ", level);
    for (int i = 1; i <= pQueue->queue[0]; i++)
    {
        if (i == pow(2, level + 1))
        {
            level++;
            printf("\nLevel = %d: ", level);
        }
        printf("%d ", pQueue->queue[i]);
    }
    printf("\n");
}
