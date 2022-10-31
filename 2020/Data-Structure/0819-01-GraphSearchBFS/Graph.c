#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"

void initGraph(ALGraph * graph, int numVertex)
{
	int i;
	
	graph -> adjacentList = (List *)malloc(sizeof(List) * numVertex);
	graph -> numVertex = numVertex;
	graph -> visitInfo = (int *)malloc(sizeof(int) * numVertex);
	memset(graph -> visitInfo, 0, sizeof(int) * numVertex);
	
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
	if (graph -> adjacentList != NULL) {
		free(graph -> adjacentList);
	}
	
	if (graph -> visitInfo != NULL)
		free(graph -> visitInfo);
}

void showGraphEdge(ALGraph * graph)
{
	int i, numVertex = graph -> numVertex;
	int currentVertex;
	
	for (i = 0; i < numVertex; i++) {
		printf("%c¿Í ¿¬°á : ", i + 'A');
		
		if (searchFirst(&(graph -> adjacentList[i]), &currentVertex)) {
			printf("%c ", currentVertex + 'A');
			while (searchNext(&(graph -> adjacentList[i]), &currentVertex))
				printf("%c ", currentVertex + 'A');
		}
		
		putchar('\n');
	}
}



BOOL visitVertex(ALGraph * graph, int vVertex)
{
	if (graph -> visitInfo[vVertex] == 0) {
		graph -> visitInfo[vVertex] = 1;
		printf("%c ", vVertex + 'A');
		return TRUE;
	}
	else
		return FALSE;
}

// BFS
void showGraphVertexBFS(ALGraph * graph, int startVertex)
{
	Queue queue;
	int visitedVertex = startVertex;
	int nextVertex;
	
	initQueue(&queue);
	
	visitVertex(graph, visitedVertex);
	
	while (searchFirst(&(graph -> adjacentList[visitedVertex]), &nextVertex)) {
		if (visitVertex(graph, nextVertex))
			enqueue(&queue, nextVertex);
			
		while (searchNext(&(graph -> adjacentList[visitedVertex]), &nextVertex)) {
			if (visitVertex(graph, nextVertex))
				enqueue(&queue, nextVertex);
		}
		
		if (isEmpty(&queue))
			break;
		else
			visitedVertex = dequeue(&queue);
	}
	
	memset(graph -> visitInfo, 0, sizeof(int) * graph -> numVertex);
}
