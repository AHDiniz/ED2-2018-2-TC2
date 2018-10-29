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
                first = PQueue_RemoveFirst(bins);
                PQueue_Insert(bins, first + weights[i]);
            }
            else PQueue_Insert(bins, weights[i]); // If the weight doesn't fit, create new bin
        }
    }
    // PQueue_Print(bins);
    int result = PQueue_GetSize(bins);
    PQueue_Destroy(bins);
    return result;
}

/**
 * Function that looks for the node with the smallest empty space that can fit the current weight
 * 
 * Inputs: pointer to the tree's root, the weight and the limit
 * Output: pointer to the best node or NULL
 * Conditions: existent and allocated tree
 * Side effects: new nodes might be added to the tree
 */
static BST *FindBestNode(BST *root, int weight, int limit)
{
    if (root == NULL) return NULL;
    if (weight + BST_GetKey(root) <= limit) // If the weight fits in the node
    {
        // Getting the best node:
        BST *best = FindBestNode(BST_GetRight(root), weight, limit);
        if (best == NULL) return root; // If the current bin is the best one, return it
        else if (weight + BST_GetKey(best) <= limit) return best; // If it fits in the bin, return it
        else return root; // Otherwise, return current bin
    }
    else return FindBestNode(BST_GetLeft(root), weight, limit); // Otherwise, search best bin in the left subtree
}

// Implementing the best fit heuristic:
int BestFit(int *weights, int length, int limit)
{
    BST *bins = BST_Create(weights[0]); // Creating a new binary search tree to represent the bins
    int size = 1; // The amount of bins used

    for (int i = 1; i < length; i++) // For each weight given
    {
        BST *best = FindBestNode(bins, weights[i], limit); // Getting the best bin
        if (best == NULL) // if the bin found is NULL (the weight doesn't fit in any bin)...
        {
            // Create a new bin:
            bins = BST_Insert(bins, weights[i]);
            size++;
        }
        else // If it does...
        {
            // Remove, updated and reinsert the best bin:
            int bin = BST_GetKey(best);
            bins = BST_Remove(bins, bin);
            bins = BST_Insert(bins, bin + weights[i]);
        }
    }
    
    return size; // Returning the amount of bins used
}
