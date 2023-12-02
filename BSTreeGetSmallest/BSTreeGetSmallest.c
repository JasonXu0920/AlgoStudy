/*
 *Your task is to write a function, BSTreeGetSmallest,
 * that returns a pointer to the node containing the smallest value in the given BST.
 * If the tree is empty, return NULL.
 */
#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t) {
    if (t == NULL) {
        return NULL;
    } else if (t->left == NULL) { //no left subtree, so root is the smallest
        return t;
    } else {
        return BSTreeGetSmallest(t->left); //go left subtree till reach the end
    }
}

