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

// Implementing the binary search tree node structure:
struct bst
{
    int key; // The node's key
    BST *right, *left; // Pointers to the right and left sons
};

// Implementing the function that creates a BST node:
BST *BST_Create(int key)
{
    BST *node = malloc(sizeof(BST)); // Allocating space to the node
    node->left = node->right = NULL; // Setting the subtree pointers to NULL
    node->key = key; // Setting the node's key
    return node; // Returning the pointer to the node
}

// Implementing the function that destroys a BST given it's root node:
BST *BST_Destroy(BST *root)
{
    if (root->left != NULL) BST_Destroy(root->left); // Destroying the left subtree
    if (root->right != NULL) BST_Destroy(root->right); // Destroying the right subtree
    free(root); // Destroying the root node
    return NULL;
}

// Implementing the function that tells if a node is or isn't a leaf:
bool BST_Leaf(BST *node)
{
    return node->right == NULL && node->left == NULL;
}

// Implementing the function that inserts a key to the tree:
bool BST_Insert(BST *root, int key)
{
    if (root == NULL) return false; // NULL pointer detection
    if (root->key > key) // If the given key is smaller then the root's key...
    {
        // The key will be added to the left subtree:
        if (root->left != NULL) return BST_Insert(root->left, key);
        BST *node = BST_Create(key);
        root->left = node;
        return true;
    }
    else // If the given key is smaller then or equal to the root's key...
    {
        // The key will be added to the right subtree:
        if (root->right != NULL) return BST_Insert(root->right, key);
        BST *node = BST_Create(key);
        root->right = node;
        return true;
    }
}

// TODO: remove operation implementation

// Implementing the function that removes a node from the tree:
BST *BST_Remove(BST *root, int key)
{
    if (root == NULL) return NULL; // NULL pointer detection
    if (key < root->key)
        return BST_Remove(root->left, key);
    if (key < root->key)
        return BST_Remove(root->right, key);
}
