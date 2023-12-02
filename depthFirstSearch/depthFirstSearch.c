/*
 * Your task is to write a function, depthFirstSearch,
 * that performs a depth first search on a graph starting at the given vertex.
 * It should print out the vertices as they are visited.
 * If a vertex has multiple neighbours, visit the neighbour with the smallest vertex number first.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void dfs(Graph g, int v, int *visited);

void depthFirstSearch(Graph g, int src) {
    int *visited = calloc(GraphNumVertices(g), sizeof(int));  //GraphNumVertices(g) return number of vertices in the graph
    dfs(g, src, visited);// passing the graph, src and visited list
    free(visited);
}

static void dfs(Graph g, int v, int *visited) {
    printf("%d ", v);
    visited[v] = 1; //set the v to be visited
    for (int w = 0; w < GraphNumVertices(g); w++) { //GraphNumVertices(g) return number of vertices in the graph
        if (GraphIsAdjacent(g, v, w) && !visited[w]) { //if two vertices are adjacent and w is not visited
            dfs(g, w, visited); //recursive
        }
    }
}