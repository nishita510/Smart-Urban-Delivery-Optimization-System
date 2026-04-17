#include <stdio.h>
#include "graph.h"

void initGraph(Graph *g, int n) {
    g->n = n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g->adj[i][j] = (i == j) ? 0 : 99999;
}

void addEdge(Graph *g, int u, int v, int w) {
    g->adj[u][v] = w;
    g->adj[v][u] = w;
}

void printGraph(Graph *g) {
    for(int i=0;i<g->n;i++) {
        for(int j=0;j<g->n;j++)
            printf("%5d ", g->adj[i][j]);
        printf("\n");
    }
}
