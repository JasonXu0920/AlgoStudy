/*
 * Your task is to write a function, BSTreeGetKth,
 * that returns the k'th smallest value in the given BST.
 * You can assume that k is between 0 and N - 1, where N is the size of the tree.
 */
#include <stdlib.h>

#include "BSTree.h"

static int BSTreeSize(BSTree t);//get the # nodes in the tree programs 3a

int BSTreeGetKth(BSTree t, int k) { //given the tree and K value
    int leftSize = BSTreeSize(t->left); //return the size of left tree
    if (k == leftSize) { //K is the root node, so return root node
        return t->value;
    } else if (k < leftSize) { //locate in the left subtree
        return BSTreeGetKth(t->left, k);
    } else {
        return BSTreeGetKth(t->right, k - leftSize - 1); //locate in the right subtree, new K = old K - root - leftsize
    }
}

static int BSTreeSize(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + BSTreeSize(t->left) + BSTreeSize(t->right);
    }
}