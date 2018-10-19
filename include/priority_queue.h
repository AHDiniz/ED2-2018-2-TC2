/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * priority_queue.h: Priority Queue data structure header file
 */

#ifndef PRIORITY_QUEUE_H_

#define PRIORITY_QUEUE_H_

#include <stdbool.h>

// Definition of the priority queue data type:
typedef struct pQueue PQueue;

/**
 * Function that creates a priority queue:
 * 
 * Inputs: the amount of items that the priority queue will have
 * Output: pointer to the DYNAMICALLY ALLOCATED priority queue
 * Condition: size that is appropriate to the computer's memory
 * Side effects: the priority queue is DYNAMICALLY ALLOCATED, REMEMBER TO DESTROY IT WHEN IT'S NOT BEING USED ANYMORE!!!
 */
PQueue *PQueue_Create(int size);

/**
 * Function that destroys a priority queue:
 * 
 * Inputs: pointer to the priority queue
 * Output: none
 * Conditions: existent and allocated priority queue
 * Side effects: the pointer will point to NULL
 */
PQueue *PQueue_Destroy(PQueue *pQueue);

/**
 * Function that checks if the queue is empty
 * 
 * Input: pointer to the queue
 * Output: boolean that tells if the queue is or isn't empty
 * Conditions: existent and allocated queue
 * Side effects: none
 */
bool PQueue_Empty(PQueue *pQueue);

/**
 * Function that returns the size of the given queue
 * 
 * Input: pointer to the queue
 * Output: amount of items in the queue
 * Conditions: existent and allocated queue
 * Side effects: none
 */
int PQueue_GetSize(PQueue *pQueue);

/**
 * Function that inserts a item with certain priority in the queue:
 * 
 * Inputs: pointer to the priority queue, the item
 * Output: an boolean that tells if the operation was or wasn't a success
 * Conditions: the queue and the item must exist and be allocated and the key must be a valid one (depends on the context)
 * Side effects: a new item is added to the queue
 */
bool PQueue_Insert(PQueue *pQueue, int item);

/**
 * Function that returns the item with the most important priority in the queue
 * 
 * Input: pointer to the queue
 * Output: pointer to the most important item
 * Conditions: the queue must be existent and allocated
 * Side effects: none
 */
int PQueue_GetFirst(PQueue *pQueue);

/**
 * Function that removes the most important item from the queue
 * 
 * Input: pointer to the queue
 * Ouput: pointer to the most important item
 * Conditions: the queue must be existent and allocated
 * Side effects: the item is removed from the queue
 */
int PQueue_RemoveFirst(PQueue *pQueue);

#endif // PRIORITY_QUEUE_H_
