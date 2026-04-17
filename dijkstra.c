#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "dijkstra.h"

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index;

    for(int v=0; v<n; v++) {
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(Graph *g, int start) {
    int dist[MAX];
    bool visited[MAX] = {0};

    for(int i=0;i<g->n;i++)
        dist[i] = INT_MAX;

    dist[start] = 0;

    for(int count=0; count<g->n-1; count++) {
        int u = minDistance(dist, visited, g->n);
        visited[u] = true;

        for(int v=0; v<g->n; v++) {
            if(!visited[v] && g->adj[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + g->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    printf("\nDijkstra Distances:\n");
    for(int i=0;i<g->n;i++)
        printf("Node %d -> %d\n", i, dist[i]);
}
