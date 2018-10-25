/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * fit.c: Bin Packing implementation file
 */

#include "../include/fit.h"
#include "../include/priority_queue.h"
#include "../include/bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Implementing the worst fit heuristic:
int WorstFit(int *weights, int length, int limit)
{
    PQueue *bins = PQueue_Create(length); // Creating a new priority queue to hold the bins
    
    for (int i = 0; i < length; i++) // Looping for every weight given
    {
        if (PQueue_Empty(bins)) // Checking if the queue is empty
            PQueue_Insert(bins, weights[i]);
        else
        {
            // Getting the bin with the biggest empty space:
            int first = PQueue_GetFirst(bins);
            
            // Checking if the weight fits in the bin:
            if (first + weights[i] <= limit)
            {
                first = PQueue_RemoveFirst(bins); // Removing the bin with the biggest empty space from the queue
                PQueue_Insert(bins, weights[i] + first);
            }
            else PQueue_Insert(bins, weights[i]); // If the weight doesn't fit, create new bin
        }
    }

    int result = PQueue_GetSize(bins);
    PQueue_Destroy(bins);
    return result;
}

/**
 * Function that looks for the node with the smallest empty space that can fit the current weight
 * 
 * Inputs: pointer to the current node, the weight, the limit and the pointer to the tree
 * Output: a boolean that tells if the node was found
 * Conditions: existent and allocated tree
 * Side effects: new nodes might be added to the tree
 */
static bool FindBestNode(BST *bin, int weight, int limit, BST *tree)
{
    return false;
}

// Implementing the best fit heuristic:
int BestFit(int *weights, int length, int limit)
{
    return 0;
}
