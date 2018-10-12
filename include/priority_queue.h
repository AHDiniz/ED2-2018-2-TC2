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

// Definition of the item comparision callback:
typedef (int) (*PQItem_Compare) (void *, void *);

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
 * Inputs: pointer to the priority queue, pointer to the item, the priority that the item will have
 * Output: an boolean that tells if the operation was or wasn't a success
 * Conditions: the queue and the item must exist and be allocated and the key must be a valid one (depends on the context)
 * Side effects: a new item is added to the queue
 */
bool PQueue_Insert(PQueue *pQueue, void *item, int priority);

/**
 * Function that returns the item with the most important priority in the queue
 * 
 * Input: pointer to the queue
 * Output: pointer to the most important item
 * Conditions: the queue must be existent and allocated
 * Side effects: none
 */
void *PQueue_GetFirst(PQueue *pQueue);

/**
 * Function that removes the most important item from the queue
 * 
 * Input: pointer to the queue
 * Ouput: pointer to the most important item
 * Conditions: the queue must be existent and allocated
 * Side effects: the item is removed from the queue
 */
void *PQueue_RemoveFirst(PQueue *pQueue);

/**
 * Function that changes the key from a given item:
 * 
 * Inputs: pointers to the queue, the item and the item comparision function and the item's new key
 * Output: an integer that tells if the operation was or wasn't a success
 * Conditions: existent and allocated queue and item, existent function and valid key (the last depends on the context)
 * Side effects: the target item's key is changed to the entry key
 */
int PQueue_ChangeKey(PQueue *pQueue, void *item, int key, PQItem_Compare Cmp);

#endif // PRIORITY_QUEUE_H_
