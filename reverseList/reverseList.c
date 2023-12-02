
#include "list.h"

void listReverse(List l) {
    Node prev = NULL;
    Node curr = l->head;
    while (curr != NULL) {
        Node temp = curr; //store the current node
        curr = curr->next; //current node == move to the next
        temp->next = prev; //let the next point to the pre
        prev = temp; //move to the end
    }
    l->head = prev; // set the head to the new first(old last)

}

