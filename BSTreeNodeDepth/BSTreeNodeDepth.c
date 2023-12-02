/*
 * Your task is to write a function, BSTreeNodeDepth,
 * that returns the depth of the node containing the given key in the tree if it exists, or -1 otherwise.
 */
#include <stdlib.h>

#include "BSTree.h"


int BSTreeNodeDepth(BSTree t, int key) {
    if (t == NULL) {
        return -1;
    } else if (key == t->value) { //value == root
        return 0;
    } else if (key < t->value) { // value in left subtree
        int depth = BSTreeNodeDepth(t->left, key); //go left
        return (depth == -1 ? -1 : depth + 1); //found or not found
    } else { //value in right subtree
        int depth = BSTreeNodeDepth(t->right, key); //go right
        return (depth == -1 ? -1 : depth + 1); //found or not found
    }
}