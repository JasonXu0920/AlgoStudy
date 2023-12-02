
#include "list.h"

static bool listIsAscending(Node n);
static bool listIsDescending(Node n);

bool listIsOrdered(List l) {
    return listIsAscending(l->head) ||   //check increasing order
           listIsDescending(l->head);    // check decreasing order
}

static bool listIsAscending(Node n) {    //passing the head
    if (n == NULL || n->next == NULL) {
        return true;  //iteration to the end of the list, so true
    } else {
        return n->value <= n->next->value &&  //current value<next value, then go next recursively
               listIsAscending(n->next);
    }
}

static bool listIsDescending(Node n) {   //passing the head
    if (n == NULL || n->next == NULL) {
        return true; //iteration to the end of the list, so true
    } else {
        return n->value >= n->next->value &&  //current value>next value, then go next recursively
               listIsDescending(n->next);
    }
}
