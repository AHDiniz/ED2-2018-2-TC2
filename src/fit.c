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
 * Output: a boolean that tells if the node was found
 * Conditions: existent and allocated tree
 * Side effects: new nodes might be added to the tree
 */
static bool FindBestNode(BST *root, int weight, int limit)
{
    bool result = false; // Tells if the operation was or wasn't a success
    
    BST *current = root; // Points to the node of the current iteration of the loop
    BST *previous; // Points to the node of the previous iteration of the loop

    while (current != NULL && BST_GetKey(current) + weight <= limit) // While the tree is still "walkable" (if that exists ¯\_(ツ)_/¯)...
    {
        previous = current; // Storing the value of the iteration's node
        current = BST_GetRight(current); // Going to the right subtree if the weight fits in the node
    }
    current = previous; // Fixing the value of the current node (in the end of the loop current is NULL)

    if (current == NULL) return false;

    int key = BST_GetKey(current);
    if (key + weight <= limit) // If the weight fits in the current bin...
    {
        BST_Remove(root, key); // Removing the best node
        BST_Insert(root, key + limit); // Readding the updated node
        result = true; // The best node was found
    }
    else
    {
        while (current != NULL && BST_GetKey(current) + weight <= limit) // While the tree is still "walkable" (if that exists ¯\_(ツ)_/¯)...
        {
            previous = current; // Storing the value of the iteration's node
            current = BST_GetLeft(current); // Going to the right subtree if the weight fits in the node
        }
        current = previous;

        key = BST_GetKey(current);
        if (key + weight <= limit) // If the weight fits in the current bin...
        {
            BST_Remove(root, key); // Removing the best node
            BST_Insert(root, key + limit); // Readding the updated node
            result = true; // The best node was found
        }
        else result = false;
    }

    return result;
}

// Implementing the best fit heuristic:
int BestFit(int *weights, int length, int limit)
{
    BST *bins = BST_Create(weights[0]); // Creating a new binary search tree to represent the bins
    int size = 0; // The amount of bins used

    for (int i = 0; i < length; i++)
    {
        // Looking for the bin with the smallest empty space where the wieght fits:
        if (!FindBestNode(bins, weights[i], limit)) // If it doesn't...
        {
            BST_Insert(bins, weights[i]); // Insert the weight in the bins
            size++; // The size increased
        }
    }
    
    return size;
}
