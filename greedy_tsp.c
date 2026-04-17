#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "greedy_tsp.h"

void greedyTSP(Graph *g, int start) {
    bool visited[MAX] = {0};
    int current = start;
    int cost = 0;

    visited[current] = true;
    printf("\nGreedy TSP Path: %d ", current);

    for(int i=0;i<g->n-1;i++) {
        int next = -1;
        int min = INT_MAX;

        for(int j=0;j<g->n;j++) {
            if(!visited[j] && g->adj[current][j] < min) {
                min = g->adj[current][j];
                next = j;
            }
        }

        if(next == -1) break;

        visited[next] = true;
        printf("-> %d ", next);
        cost += min;
        current = next;
    }

    printf("\nTotal Cost: %d\n", cost);
}
