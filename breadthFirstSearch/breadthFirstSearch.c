/*
 * Your task is to write a function, breadthFirstSearch,
 * that performs a breadth first search on a graph starting at the given vertex.
 * It should print out the vertices as they are visited.
 * If a vertex has multiple neighbours, visit the neighbour with the smallest vertex number first.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
    int *visited = calloc(GraphNumVertices(g), sizeof(int)); //GraphNumVertices(g) return number of vertices in the graph
    visited[src] = 1; //set source to 1 in visited list

    Queue q = QueueNew(); //create a empty queue, front, back and size
    QueueEnqueue(q, src);// Add an item to the end of the queue

    while (!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);// Remove an item from the front of the queue and return it
        printf("%d ", v);
        for (Vertex w = 0; w < GraphNumVertices(g); w++) { //loop over all vertices
            if (GraphIsAdjacent(g, v, w) && !visited[w]) { // if v and w are adjacent and w is not visited
                QueueEnqueue(q, w);// Add an item to the end of the queue
                visited[w] = 1; //set the w to visited
            }
        }
    }

    QueueFree(q);
    free(visited);
}


