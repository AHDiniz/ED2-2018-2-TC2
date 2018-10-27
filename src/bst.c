/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * bst.c: Binary Search Tree implementation file
 */

#include "../include/bst.h"
#include <stdlib.h>
#include <stdio.h>

// Implementing the binary search tree data type:
struct bst
{
    int key;
    BST *left, *right;
};

// Implementing the binary search tree creation function:
BST *BST_Create(int key)
{
    BST *node = malloc(sizeof(BST));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Implementing the binary search tree destruction function:
BST *BST_Destroy(BST *tree)
{
    if (tree == NULL) return NULL;
    tree->left = BST_Destroy(tree->left);
    tree->right = BST_Destroy(tree->right);
    free(tree);
    return NULL;
}

// Implementing the node's key getter:
int BST_GetKey(BST *node)
{
    return node->key;
}

// Implementing the node's left subtree getter:
BST *BST_GetLeft(BST *node)
{
    return node->left;
}

// Implementing the node's right subtree getter:
BST *BST_GetRight(BST *node)
{
    return node->right;
}

// Implementing the function that tells if a node is a leaf:
bool BST_Leaf(BST *node)
{
    return node->left == NULL && node->right == NULL;
}

// Implementing the function that searches for a node in the tree:
BST *BST_Search(BST *tree, int key)
{
    if (tree == NULL) return NULL; // NULL pointer detection
    
    BST* target; // The target node of the iteration
    
    // Starting from the root node given, if the key is smaller then the current's, go left, else, go right:
    for (target = tree; target != NULL && key != target->key; target = (key < target->key) ? target->left : target->right);
    
    return target;
}

// Implementing the function that inserts an item in the tree:
BST *BST_Insert(BST *tree, int key)
{
    if (tree == NULL) return BST_Create(key); // NULL pointer detection
    
    if (key < tree->key) // If the node must be in the left subtree...
        tree->left = BST_Insert(tree->left, key); // Decide if it must be created or can go deeper
    else // If the node must be in the right subtree...
        tree->right = BST_Insert(tree->right, key); // Decide if it must be created or must go deeper
    
    return tree;
}

BST *BST_Remove(BST *tree, int key)
{
    if (tree == NULL) return NULL; // NULL pointer detection

    // If the current node is not the target:
    if (key < tree->key)
        tree->left = BST_Remove(tree->left, key);
    else if (key > tree->key)
        tree->right = BST_Remove(tree->right, key);
    else // If the current node is the target node..
    {
        if (BST_Leaf(tree)) // If the target is a leaf node, destroy the node:
        {
            free(tree);
            tree = NULL;
        }
        else if (tree->left == NULL) // If the target only has the right subtree:
        {
            // Remove the node and make the return be the right subtree:
            BST *target = tree;
            tree = tree->right;
            free(target);
        }
        else if (tree->right == NULL) // If the target only has the left subtree:
        {
            // Remove the node and make the return be the right subtree:
            BST *target = tree;
            tree = tree->left;
            free(target);
        }
        else // If the target has both of the subtrees:
        {
            // Looking for the node that has the closest key to the target's in the left subtree:
            BST *newTarget = tree->left;
            while (newTarget->right != NULL) newTarget = newTarget->right;

            // Switching the keys of the current target and the new target:
            tree->key = newTarget->key;
            newTarget->key = key;

            // Removing the new target from the tree:
            tree->left = BST_Remove(tree->left, key);
        }
    }

    return tree;
}

// Implementing the function that prints the tree:
void BST_Print(BST *tree)
{
    if (tree == NULL) return;
    printf("<%d ", tree->key);
    BST_Print(tree->left);
    BST_Print(tree->right);
    printf(">");
}
