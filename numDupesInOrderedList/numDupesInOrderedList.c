
#include "list.h"



int numDupesInOrderedList(List l) {
	Node curr = l->head;
    int count = 0;
	while (curr->next != NULL){
	    if (curr->value == curr->next->value){ //if curr value == next value, count++
	        count++;
	    }
	    curr = curr->next;
	}
	return count;
}
