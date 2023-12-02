/*
 * Your task is to write a function, TreeHeight, that returns the height of the given tree.
 * The height of a tree is the number of edges on the longest path from the root node to a leaf node.
 * The height of an empty tree is considered to be -1.
 */
#include <stdlib.h>

#include "tree.h"


int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    } else {
        int lheight = 1 + TreeHeight((t)->left); //count+=1, go left
        int rheight = 1 + TreeHeight((t)->right); //count+=1, go right
        if (lheight > rheight) //compare left and right
            return lheight;
        else
            return rheight;
    }
}