
#include "list.h"


int listDeleteLargest(List l) {
    // Find max
    Node max = l->head;
    for (Node curr = l->head; curr != NULL; curr = curr->next) {
        if (curr->value > max->value) {
            max = curr;
        }
    }
    int largest = max->value; //store the max value for return

    // Delete it from the list
    if (max == l->head) {
        l->head = l->head->next; //max is the head, point the head to next
    } else {
        Node prev = l->head;
        while (prev->next != max) { //search for the first ouccrance of max value
            prev = prev->next;
        }
        prev->next = prev->next->next; //pre.next point to the next.next which skip the max value
    }
    free(max);

    return largest;
}
