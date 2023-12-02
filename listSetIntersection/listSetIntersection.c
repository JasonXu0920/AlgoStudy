/*
 Your task is to write a function, listSetIntersection,
 that takes two lists representing two sets and returns a new list that represents the intersection of those sets.
 For example, if the two lists are [4, 3, 1, 7, 6] and [3, 2, 5, 1, 6], you should return a list containing the elements 1, 3, and 6.
 The result list does not have to be ordered in any particular way
 */
#include "list.h"

static void append(List l, int val);
static bool notin(List l, int val);

List listSetIntersection(List s1, List s2) {
	List s3 = newList();
    for(Node n = s1->head; n != NULL; n = n->next){ //loop over s1
        for(Node m = s2->head; m != NULL; m = m->next){ //loop over s2
            if (n->value == m->value && notin(s3, n->value)){ //if values equals and not duplicate
                append(s3, n->value);
            }
        }
    }

    return s3;
}

//add a newnode to a list
static void append(List l, int val){
    Node n = newNode(val);
    n->next = l->head;
    l->head = n;
}


static bool notin(List l, int val){
    for (Node curr = l->head; curr != NULL; curr = curr->next) { //loop current s3
        if (curr->value == val) { //the value already in
            return false;
        }
    }
    return true;
}