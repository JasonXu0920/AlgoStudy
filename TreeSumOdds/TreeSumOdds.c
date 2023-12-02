/*
 * Your task is to write a function, TreeSumOdds,
 *     that returns the sum of all of the odd values in the given tree.
 */
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t) {
    if (t == NULL) {
        return 0;
    } else if (t->value % 2 != 0) { //current value is odd
        return t->value + TreeSumOdds(t->left) + TreeSumOdds(t->right); // add to sum and go to left and right
    } else {
        return TreeSumOdds(t->left) + TreeSumOdds(t->right); // go to left and right
    }
}
