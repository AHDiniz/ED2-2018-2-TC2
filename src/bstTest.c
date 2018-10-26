/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * bstTest.c: Binary Search Tree test file
 */

#include "../include/bst.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r"); // Opening the given file
    
    BST *tree = NULL; // Creating a new binary search tree

    int num = 0;
    // Reading the file while it's still possible:
    while (fscanf(file, "%d\n", &num) != EOF)
    {
        if (tree == NULL) // If the tree was not created properly...
            tree = BST_Create(num); // The tree will be created
        else // Otherwise...
            BST_Insert(tree, num); // The number will be inserted in the tree
    }
    fclose(file);

    BST_Print(tree); // Printing the tree
    printf("\n");

    printf("Is the tree a lead node? %s\n", (BST_Leaf(tree)) ? "Yes" : "No");

    int removed = num;

    printf("Insert the value that will be removed from the tree:\n");
    scanf("%d", &removed);

    tree = BST_Remove(tree, removed);

    BST_Print(tree); // Printing the tree
    printf("\n");

    printf("Item removed = %d\n", removed);

    BST_Destroy(tree); // Destroying the tree

    return 0;
}
