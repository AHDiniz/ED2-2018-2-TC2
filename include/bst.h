/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * bst.h: Binary Search Tree header file
 */

#ifndef BST_H_
#define BST_H_

#include <stdbool.h>

// Defining the binary search tree data type
typedef struct bst BST;

/**
 * Function that creates a new binary search tree node
 * 
 * Input: the node's key
 * Output: pointer to the tree node
 * Conditions: valid key to the context
 * Side effects: node DYNAMICALLY ALLOCATED
 */
BST *BST_Create(int key);

/**
 * Function that destroys a search tree given it's root node
 * 
 * Input: pointer to the root node of the tree
 * Output: NULL
 * Conditions: existent and allocated tree
 * Side effects: the structure is cleared from memory
 */
BST *BST_Destroy(BST *root);

/**
 * Function that checks if a given node is a leaf
 * 
 * Input: pointer to the node
 * Output: boolean that tells if the node is or isn't a leaf
 * Conditions: existent and allocated node
 * Side effects: none
 */
bool BST_Leaf(BST *node);

/**
 * Function that inserts a key to a BST
 * 
 * Inputs: pointer to the root node of the tree and the key that will be added
 * Output: bool that tells if the operation was or wasn't a success
 * Conditions: existent and allocated root node
 * Side effects: a new node will be created to the given key
 */
bool BST_Insert(BST *root, int key);

// TODO: remove operation's prototype

#endif // BST_H_
