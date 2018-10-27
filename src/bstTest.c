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
    FILE *file = fopen(argv[1], "r"); // Opening the file with the data about the tree:

    BST *tree = NULL; // Tree pointer

    int num = 0;
    while (!feof(file))
    {
        fscanf(file, "%d\n", &num);
        tree = BST_Insert(tree, num);
    }

    // Printing the tree:
    BST_Print(tree);
    printf("\n");

    // Removing an item:
    printf("Which number you would like to remove?\n");
    scanf("%d", &num);
    tree = BST_Remove(tree, num);

    // Printing the tree:
    BST_Print(tree);
    printf("\n");

    tree = BST_Destroy(tree);

    fclose(file);

    return 0;
}
