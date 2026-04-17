#include <stdlib.h>
#include "utils.h"
#include "graph.h"

void generateGraph(Graph *g) {
    for(int i=0;i<g->n;i++) {
        for(int j=i+1;j<g->n;j++) {
            int w = rand()%20 + 1;
            addEdge(g, i, j, w);
        }
    }
}
