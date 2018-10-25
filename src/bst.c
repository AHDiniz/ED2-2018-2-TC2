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
    if (root == NULL) return NULL;
    if (root->left != NULL) BST_Destroy(root->left); // Destroying the left subtree
    if (root->right != NULL) BST_Destroy(root->right); // Destroying the right subtree
    free(root); // Destroying the root node
    return NULL;
}

// Implementing the function that returns the node's key:
int BST_GetKey(BST *node)
{
    return node->key;
}

// Implementing the function that returns the node's right subtree:
BST *BST_GetRight(BST *node)
{
    return node->right;
}

// Implementing the function that returns the node's left subtree:
BST *BST_GetLeft(BST *node)
{
    return node->left;
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

    BST *current = root; // Current item in the tree
    BST *prev; // Previous item in the tree
    while (current != NULL) // Looping while the current node is not NULL
    {
        prev = current; // Storing the value of the current node in the loop
        // Checking the value of the key and deciding to go to the left or right subtree:
        current = (current->key > key) ? current->left : current->right;
    }
    
    // Checking where to put the new node:
    if (prev->key > key)
        prev->left = BST_Create(key);
    else
        prev->right = BST_Create(key);
    
    return true;
}

// Implementing the function that removes a node from a tree:
BST *BST_Remove(BST *root, int key)
{
    if (root == NULL) return NULL; // NULL pointer detection
    // Checking if the target is in the left subtree:
    if (key < root->key)
        root->left = BST_Remove(root->left, key); // Removing the target node
    // Checking if the target is in the right subtree:
    if (key > root->key)
        root->right = BST_Remove(root->right, key); // Removing the target node
    // Checking if the root node is the target:
    if (root->key == key)
    {
        // Checking if the target is a leaf node:
        if (root->left == NULL && root->right == NULL)
        {
            // Destroying the node and make the return be NULL:
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) // Only has the right subtree
        {
            // Making the return be the right subtree and destroying the target node:
            BST *destroy = root;
            root = root->right;
            free(destroy);
        }
        else if (root->right == NULL) // Only has the left subtree
        {
            // Analogue to the previous case:
            BST *destroy = root;
            root = root->left;
            free(destroy);
        }
        else // Has both subtrees
        {
            // Looking for the closest key to the root's in the left subtree:
            BST *prev = root->left;
            while(prev->right != NULL)
            {
                prev = prev->right;
            }
            // Switching the keys so the target node has zero or one subtree:
            root->key = prev->key;
            prev->key = key;
            // Removing the new target node:
            root->left = BST_Remove(root->left, key);
        }
    }
    return root;
}

// Implementing the function that prints a binary search tree:
void BST_Print(BST *root)
{
    printf("<%d ", root->key);
    if (root->left != NULL) BST_Print(root->left);
    if (root->right != NULL) BST_Print(root->right);
    printf(">");
}
