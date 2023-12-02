
#include "list.h"

static void swap(Node *ptr1, Node *ptr2); //swap two nodes

void reverseDLList(List l) {
    Node curr = l->first;  //set current node to the head
    while (curr != NULL) {
        swap(&(curr->prev), &(curr->next)); //swap pre and next nodes
        curr = curr->prev;  //set current to the pre
    }

    swap(&(l->first), &(l->last)); //swap the head and tail node
}

//Reference: week2a lecture page 24 "Example of pointers"
static void swap(Node *ptr1, Node *ptr2) {
    Node temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

