#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

void initGraph(ALGraph * graph, int numVertex)
{
	int i;
	
	graph -> adjacentList = (List *)malloc(sizeof(List) * numVertex);
	graph -> numVertex = 0;
	
	for (i = 0; i < numVertex; i++)
		initList(&(graph -> adjacentList[i]));
}

void addEdge(ALGraph * graph, int iV, int fV)
{
	insertList(&(graph -> adjacentList[iV]), fV);
	insertList(&(graph -> adjacentList[fV]), iV);
	graph -> numEdge++;
}

void destroyGraph(ALGraph * graph)
{
	if (graph -> adjacentList != NULL)
		free(graph -> adjacentList);
}

void showGraphEdgeInfo(ALGraph * graph)
{
	int i, numVertex = graph -> numVertex;
	int currentVertex;
	
	for (i = 0; i < numVertex; i++) {
		printf("%c¿Í ¿¬°á : ", i + 'A');
		
		if (searchFirst(&(graph -> adjacentList[i]), &currentVertex)) {
			printf("%c ", currentVertex + 'A');
			while (searchFirst(&(graph -> adjacentList[i]), &currentVertex))
				printf("%c ", currentVertex + 'A');
		}
		
		putchar('\n');
	}
}
