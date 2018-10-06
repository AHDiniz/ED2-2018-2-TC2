/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * heap.h: Heap data structure header file
 */

#ifndef PRIORITY_QUEUE_H_

#define PRIORITY_QUEUE_H_

// Definition of the priority queue data type:
typedef struct priorityQueue PriorityQueue;

/**
 * Function that creates a priority queue:
 * 
 * Inputs: the amount of items that the priority queue will have
 * Output: pointer to the DYNAMICALLY ALLOCATED priority queue
 * Condition: size that is appropriate to the computer's memory
 * Side effects: the priority queue is DYNAMICALLY ALLOCATED, REMEMBER TO DESTROY IT WHEN IT'S NOT BEING USED ANYMORE!!!
 */
PriorityQueue *PQueue_Create(int size);

/**
 * Function that destroys a priority queue:
 * 
 * Inputs: pointer to the priority queue
 * Output: none
 * Conditions: existent and allocated priority queue
 * Side effects: the pointer will point to NULL
 */
PriorityQueue *PQueue_Destroy(ProrityQueue *priorityQueue);

/** */

#endif // PRIORITY_QUEUE_H_
