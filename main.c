#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"
#include "dijkstra.h"
#include "greedy_tsp.h"
#include "dp_tsp.h"
#include "assignment.h"
#include "utils.h"

int main() {
    srand(time(0));

    Graph g;
    int n = 5;
    int agents = 2;

    initGraph(&g, n);
    generateGraph(&g);

    printf("Graph:\n");
    printGraph(&g);

    dijkstra(&g, 0);

    greedyTSP(&g, 0);

    printf("\nOptimal TSP Cost (DP): %d\n", tspDP(&g));

    assignDeliveries(n, agents);

    return 0;
}
