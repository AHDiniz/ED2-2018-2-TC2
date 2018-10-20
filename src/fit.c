#include "../include/fit.h"
#include "../include/priority_queue.h"
#include <stdlib.h>

// Implementing the worst fit heuristic:
int WorstFit(int *weights, int length, int limit)
{
    PQueue *bins = PQueue_Create(length); // Creating the bins priority queue
    for (int i = 0; i < length; i++) // For each weight given
    {
        // If the queue is empty, the weight will be simply inserted to the queue:
        if (PQueue_GetSize(pQueue) == 0)
            PQueue_Insert(pQueue, weights[i]);
        int first = PQueue_RemoveFirst(pQueue); // Getting the bin with the biggest empty space
        if (first + weights[i] > limit) // If the weight doesn't fit in the bin...
        {
            // The removed bin will be readded to the queue:
            PQueue_Insert(bins, min);
            // And a new bin will be created to the given weight:
            PQueue_Insert(pQueue, weights[i]);
        }
        else // If the weight fits in the bin...
            PQueue_Insert(pQueue, min + weights[i]); // The weight will be added to the bin
    }
    int size = PQueue_GetSize(pQueue); // Getting the size of the queue
    PQueue_Destroy(pQueue); // Destroying the bin queue
    return size;
}
