#include "../include/fit.h"
#include "../include/priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

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

// TODO: implement the best fit heuristic
