#include <stdio.h>
#include "Graph.h"

int main(void)
{
	ALGraph graph;
	initGraph(&graph, 7);
	
	addEdge(&graph, A, B);
	addEdge(&graph, A, D);
	addEdge(&graph, B, C);
	addEdge(&graph, D, C);
	addEdge(&graph, D, E);
	addEdge(&graph, E, F);
	addEdge(&graph, E, G);
	
	showGraphEdge(&graph);
	
	showGraphVertexBFS(&graph, A);
	putchar('\n');
	
	showGraphVertexBFS(&graph, B);
	putchar('\n');
	
	showGraphVertexBFS(&graph, C);
	putchar('\n');
	
	showGraphVertexBFS(&graph, D);
	putchar('\n');
	
	return 0;
}
