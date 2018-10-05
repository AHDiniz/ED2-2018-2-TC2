/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * heap.h: Heap data structure header file
 */

#ifndef HEAP_H_

#define HEAP_H_

// Definition of the heap data type:
typedef struct heap Heap;

/**
 * Function that creates a heap:
 * 
 * Inputs: the amount of items that the heap will have
 * Output: pointer to the DYNAMICALLY ALLOCATED heap
 * Condition: size that is appropriate to the computer's memory
 * Side effects: the heap is DYNAMICALLY ALLOCATED, REMEMBER TO DESTROY IT WHEN IT'S NOT BEING USED ANYMORE!!!
 */
Heap *Heap_Create(int size);

/**
 * Function that destroys a heap:
 * 
 * Inputs: pointer to the heap
 * Output: none
 * Conditions: existent and allocated heap
 * Side effects: the pointer will point to NULL
 */
Heap *Heap_Destroy(Heap *heap);

#endif // HEAP_H_
