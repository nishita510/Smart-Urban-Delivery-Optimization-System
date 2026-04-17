#ifndef GRAPH_H
#define GRAPH_H

#define MAX 100

typedef struct {
    int adj[MAX][MAX];
    int n;
} Graph;

void initGraph(Graph *g, int n);
void addEdge(Graph *g, int u, int v, int w);
void printGraph(Graph *g);

#endif
