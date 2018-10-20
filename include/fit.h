/**
 * ED2-2018-2-TC2: Creating a heuristic for the Bin Packing Problem
 * 
 * Author: Alan Herculano Diniz
 * 
 ****************************************************************** 
 *
 * fit.h: Bin Packing header file
 */

#ifndef FIT_H_
#define FIT_H_

/**
 * Function that implements the worst fit heuristic
 * 
 * Inputs: array of weights, the length of the array and the size of each bin
 * Output: the amount of bins created
 * Conditions: existent and allocated array and correct length
 * Side effects: a priority queue will be created to solve the problem
 */
int WorstFit(int *weights, int length, int limit);


#endif // FIT_H_
