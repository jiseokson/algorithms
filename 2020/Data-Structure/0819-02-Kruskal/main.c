#include <stdio.h>
#include "Graph.h"


int main(void)
{
	ALGraph graph;
	initGraph(&graph, 6);
	
	addEdge(&graph, A, B, 9);
	addEdge(&graph, B, C, 2);
	addEdge(&graph, A, C, 12);
	addEdge(&graph, A, D, 8);
	addEdge(&graph, D, C, 6);
	addEdge(&graph, A, F, 11);
	addEdge(&graph, F, D, 4);
	addEdge(&graph, D, E, 3);
	addEdge(&graph, E, C, 7);
	addEdge(&graph, F, E, 13);
	
	consKruskalMST(&graph);
	showGraphEdge(&graph);
	
	
	return 0;
}
