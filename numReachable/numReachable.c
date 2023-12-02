/*
 * Your task is to write a function, numReachable,
 * that returns the number of vertices that are reachable from a source vertex in the given graph,
 * including the source vertex itself.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void dfs(Graph g, int v, int *visited);


int numReachable(Graph g, int src) {
    int *visited = calloc(GraphNumVertices(g), sizeof(int));  //GraphNumVertices(g) return number of vertices in the graph
    int count = 0;
    dfs(g, src, visited);
    for(int i = 0; i < GraphNumVertices(g); i++){ //loop over the visited list
        if (visited[i] == 1){
            count+=1;
        }
    }
    free(visited);
	return count;
}

//using DFS
static void dfs(Graph g, int v, int *visited) {
    visited[v] = 1;
    for (int w = 0; w < GraphNumVertices(g); w++) { //GraphNumVertices(g) return number of vertices in the graph
        if (GraphIsAdjacent(g, v, w) && !visited[w]) { //GraphIsAdjacent(g, v, w) return if two vertices are adjacent
            dfs(g, w, visited); //recursively
        }
    }
}