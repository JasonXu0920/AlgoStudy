/*
 * Your task is to write a function, hasCycle,
 * that determines whether or not the given graph contains a cycle.
 * It should return true if the graph contains a cycle, and false otherwise.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

static bool doHasCycle(Graph g, int v, int prev, bool *visited);

bool hasCycle(Graph g) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool)); //visited list

    for (int v = 0; v < GraphNumVertices(g); v++) { //loop over all vertices to check if there is a cycle
        if (!visited[v]) {
            if (doHasCycle(g, v, v, visited)) { // passing the vertex as both src and dest(cycle)
                //free(visited);
                return true;
            }
        }
    }

    //free(visited);
    return false;
}

static bool doHasCycle(Graph g, int v, int prev, bool *visited) {
    visited[v] = true;
    for (int w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w)) { //check if two vertices are adjacent
            if (visited[w]) {
                if (w != prev) {
                    return true;
                }
            } else {
                if (doHasCycle(g, w, v, visited)) {
                    return true;
                }
            }
        }
    }
    return false;
}


