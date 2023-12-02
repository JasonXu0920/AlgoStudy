/*
 Your task is to write a function, listSetUnion,
 that takes two lists representing two sets and returns a new list that represents the union of those sets.
 For example, if the two lists are [4, 3, 1, 7, 6] and [3, 2, 5, 1, 6],
 you should return a list containing the elements 1, 2, 3, 4, 5, 6, and 7.
 The result list does not have to be ordered in any particular way.
 Since the input lists represent sets, you can assume they do not contain any duplicate elements.
 Your function must not modify the input lists.
 */

#include "list.h"

static void listPrepend(List l, int val);
static bool inList(List l, int val);

List listSetUnion(List s1, List s2) {
    List s3 = newList(); //create a new list

    for (Node curr = s1->head; curr != NULL; curr = curr->next) { //loop  the s1
        listPrepend(s3, curr->value); //copy the values from s1 to s3
    }
    for (Node curr = s2->head; curr != NULL; curr = curr->next) { // loop  the s2
        if (!inList(s3, curr->value)) {  //check if the value in the s3, do not contain any duplicate elements
            listPrepend(s3, curr->value);
        }
    }

    return s3;
}

static void listPrepend(List l, int val) {
    Node n = newNode(val);  //make a new node with the value
    n->next = l->head;   //connect the node.next to current list head
    l->head = n;         //set the list head to new node
}

static bool inList(List l, int val) {
    for (Node curr = l->head; curr != NULL; curr = curr->next) { //loop current s3
        if (curr->value == val) { //the value already in
            return true;
        }
    }
    return false;
}