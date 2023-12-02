/*
 Your task is to write a function, BSTreeInsert, that inserts a given value into a BST,
 if it does not already exist in the BST, and returns the root of the updated BST.
 The insertion should be performed using normal leaf insertion. Do not rebalance the tree.
 If the value already exists in the BST, the function should do nothing.
 */
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"
static BSTree newBSTNode(int val);

//returns the root of the updated BST.
BSTree BSTreeInsert(BSTree t, int val) {
    if (t == NULL) {
        return newBSTNode(val); //empty tree, so make a new node

    }

    if (val < t->value) { //locate in left subtree
        t->left = BSTreeInsert(t->left, val); //assign the node to t->left since we need to return a tree node

    } else if (val > t->value) { //locate in right subtree
        t->right = BSTreeInsert(t->right, val);//assign the node to t->right since we need to return a tree node

    }
    return t;
}

//normally from Tree.h
static BSTree newBSTNode(int val) {
    BSTree t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "couldn't allocate node\n");
        exit(EXIT_FAILURE);
    }

    t->value = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}