#include <stdio.h>
#include "assignment.h"

void assignDeliveries(int nodes, int agents) {
    printf("\nAssignments:\n");

    for(int i=0;i<agents;i++) {
        printf("Agent %d: ", i);
        for(int j=0;j<nodes;j++) {
            if(j % agents == i)
                printf("%d ", j);
        }
        printf("\n");
    }
}
