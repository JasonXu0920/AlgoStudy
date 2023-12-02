/*
 * Your task is to write a function, furthestReachable,
 * that returns the furthest vertex that is reachable from a given source vertex.
 * If there are multiple furthest vertices, return the one with the largest vertex number.
 * If the source vertex is not connected to any other vertices, return the source vertex.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"  //bfs


static int *getDistances(Graph g, int src);
static int *bfs(Graph g, int v);

int furthestReachable(Graph g, int src) {
    int *dist = getDistances(g, src); //list of distances from the src

    int furthest = src; //If the source vertex is not connected to any other vertices, return the source vertex.
    for (int v = 0; v < GraphNumVertices(g); v++) {
        if (dist[v] != -1 && dist[v] >= dist[furthest]) { //compare the distance
            furthest = v;  //assign the furthest index of vertex
        }
    }

    return furthest;
}

// gets the distances of all vertices from src
static int *getDistances(Graph g, int src) {
    int *pred = bfs(g, src); //visited list - using BFS queue

    int nV = GraphNumVertices(g); //number of vertices
    int *distances = malloc(nV * sizeof(int));
    for (int v = 0; v < nV; v++) { //loop over all vertices
        if (pred[v] == -1) {
            distances[v] = -1; //not visited
        } else {
            int distance = 0;
            int curr = v; //set current to the vertex
            while (curr != src) {
                distance++;
                curr = pred[curr];//set the curr to the previous vertices till reach the src
            }
            distances[v] = distance; //assign the reachable vertices with their value of distance
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
        pred[i] = -1; //intialise the value for pred
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