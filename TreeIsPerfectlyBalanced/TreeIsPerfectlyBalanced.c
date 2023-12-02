/*
 * Your task is to write a function, TreeIsPerfectlyBalanced,
 * that determines whether a given tree is perfectly balanced.
 * A tree is perfectly balanced if, for every node, the difference in size between its left and right subtrees does not exceed 1.
 * The function should return true if the tree is perfectly balanced, and false otherwise.
 */
#include <stdlib.h>


#include "tree.h"
static int TreeSize(Tree t);

bool TreeIsPerfectlyBalanced(Tree t) {
    if (t == NULL){
        return true;
    }
	int lcount = TreeSize(t->left); //return the size of left subtree
    int rcount = TreeSize(t->right); //return the size of right subtree
	if (abs(lcount - rcount) > 1){ //check
        return false;
	} else {
        return TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right); //check all right and left subtrees with their subtrees
	}

}

static int TreeSize(Tree t) {
    if (t == NULL) { //base case
        return 0;
    } else {
        return 1 + TreeSize(t->left) + TreeSize(t->right); // 1 + left + right
    }
}