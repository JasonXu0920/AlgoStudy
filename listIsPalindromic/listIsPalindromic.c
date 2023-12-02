/*
 *Your task is to write a function, listIsPalindromic,
 * that determines whether the sequence of values in a given doubly linked list is palindromic.
 * A sequence of values is palindromic if it reads the same backwards as forwards.
 * For example, the sequence [1, 2, 3, 2, 1] is palindromic, whereas the sequence [1, 2, 3, 4] is not.
 * The function should return true if the sequence of values in the linked list is palindromic, and false otherwise.
 * Your function should not modify the list.
 */
#include "list.h"

//using double linked list
bool listIsPalindromic(List l) {
    Node curr1 = l->first; //first node
    Node curr2 = l->last;  //last node
    while (curr1 != NULL) {
        if (curr1->value != curr2->value) { // check if the first == last
            return false;
        }
        curr1 = curr1->next; // check if first+1 == last -1
        curr2 = curr2->prev;
    }
    return true; //all checked
}
