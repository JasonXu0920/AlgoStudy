/*
 Your task is to write a function, BSTreePostfix,
 that prints out the values of the given BST in postfix order. left -right - root
 The values should be printed out space-separated on a single line.
 */
#include <stdio.h>

#include "BSTree.h"

//left -right - root
void BSTreePostfix(BSTree t) {
    if (t != NULL) {
        BSTreePostfix(t->left); //go left
        BSTreePostfix(t->right); //go right
        printf("%d ", t->value);//root
    }
}


