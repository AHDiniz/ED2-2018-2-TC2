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
    PQueue *bins = PQueue_Create(length); // Creating the bins priority queue
    for (int i = 0; i < length; i++) // For each weight given
    {
        // If the queue is empty, the weight will be simply inserted to the queue:
        if (PQueue_GetSize(bins) == 0)
        {
            PQueue_Insert(bins, weights[i]);
            continue;
        }
        int first = PQueue_RemoveFirst(bins); // Getting the bin with the biggest empty space
        if (first + weights[i] > limit) // If the weight doesn't fit in the bin...
        {
            // The removed bin will be readded to the queue:
            PQueue_Insert(bins, first);
            // And a new bin will be created to the given weight:
            PQueue_Insert(bins, weights[i]);
        }
        else // If the weight fits in the bin...
        {
            PQueue_Insert(bins, first + weights[i]); // The weight will be added to the bin
        }
    }
    int size = PQueue_GetSize(bins); // Getting the size of the queue
    PQueue_Destroy(bins); // Destroying the bin queue
    return size;
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
    bool result = false; // Return boolean
    if (bin == NULL) return result; // NULL pointer detection
    
    BST *current = bin; // Points to the current node in the BST
    BST *previous; // Points to the node pointed in the previous iteration of the loop

    while (current != NULL)
    {
        previous = current; // Storing this iterantion's node
        // If the weight fits in the current node, check bigger values. Otherwise, check smaller:
        current = (BST_GetKey(current) + weight <= limit) ? BST_GetRight(current) : BST_GetLeft(current);
    }

    // If the weight fits in the last not null node found:
    if (BST_GetKey(previous) + weight <= limit)
    {
        result = true; // The best node was found
        int bin = BST_GetKey(previous);
        BST_Remove(tree, bin); // Removing the best node from the tree
        BST_Insert(tree, bin + weight); // Inserting the updated bin to the tree
    }
    else result = false; // Otherwise, a new bin must be created

    return result;
}

// Implementing the best fit heuristic:
int BestFit(int *weights, int length, int limit)
{
    BST *bins = BST_Create(weights[0]); // Creating the binary search tree with the first weight in the array
    int size = 1; // The amount of bins created
    for (int i = 1; i < length; i++) // Checking each weight given
    {
        if (!FindBestNode(bins, weights[i], limit, bins)) // Is there's no node that can fit the weight...
        {
            // A new bin is created:
            BST_Insert(bins, weights[i]);
            size++;
        }
    }
    BST_Destroy(bins);
    return size;
}
