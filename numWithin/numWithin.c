/*
 * Your task is to write a function, numWithin,
 * that determines the number of vertices that are within a given distance of the given source vertex.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

static int *getDistances(Graph g, int src);
static int *bfs(Graph g, int src);

int numWithin(Graph g, int src, int dist) {
    int *distances = getDistances(g, src); //list of distance from src of all reachable vertices

    int count = 0;
    for (int v = 0; v < GraphNumVertices(g); v++) {
        if (distances[v] >= 0 && distances[v] <= dist) { //loop over the distances list to count >0 && < limit distance
            count++;
        }
    }

    free(distances);
    return count;
}

// gets the distances of all vertices from src
static int *getDistances(Graph g, int src) {
    int *pred = bfs(g, src); //pred list

    int nV = GraphNumVertices(g);
    int *distances = malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) {
        if (pred[v] == -1) {
            distances[v] = -1; //not visited
        } else {
            int distance = 0;
            int curr = v;
            while (curr != src) {
                distance++;
                curr = pred[curr]; //set the curr to its previous vertex till reach the src
            }
            distances[v] = distance; //store the distance values
        }
    }

    free(pred);
    return distances;
}

// performs a bfs starting at src and returns an array of predecessors
static int *bfs(Graph g, int src) {
    int nV = GraphNumVertices(g);
    int *pred = malloc(nV * sizeof(int));
    for (int i = 0; i < nV; i++) {
        pred[i] = -1;
    }
    pred[src] = src;

    Queue q = QueueNew();
    QueueEnqueue(q, src);
    while (!QueueIsEmpty(q)) {
        int curr = QueueDequeue(q);
        for (int next = 0; next < nV; next++) {
            if (GraphIsAdjacent(g, curr, next) && pred[next] == -1) {
                pred[next] = curr;
                QueueEnqueue(q, next);
            }
        }
    }
    QueueFree(q);

    return pred;
}
