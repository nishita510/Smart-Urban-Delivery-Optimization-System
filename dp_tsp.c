#include <stdio.h>
#include <limits.h>
#include "dp_tsp.h"

int dp[20][1<<20];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tspUtil(Graph *g, int mask, int pos) {
    if(mask == (1 << g->n) - 1)
        return g->adj[pos][0];

    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INT_MAX;

    for(int city=0; city<g->n; city++) {
        if(!(mask & (1<<city))) {
            int newAns = g->adj[pos][city] +
                         tspUtil(g, mask | (1<<city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}

int tspDP(Graph *g) {
    for(int i=0;i<20;i++)
        for(int j=0;j<(1<<20);j++)
            dp[i][j] = -1;

    return tspUtil(g, 1, 0);
}
