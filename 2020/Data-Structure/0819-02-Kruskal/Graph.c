#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graph.h"
#include "Stack.h"

int compareWeight(Edge e1, Edge e2)
{
	if (e1.weight >= e2.weight)
		TRUE;
	else
		FALSE;
}

void initGraph(ALGraph * graph, int numVertex)
{
	int i;
	
	graph -> adjacentList = (List *)malloc(sizeof(List) * numVertex);
	graph -> numVertex = numVertex;
	graph -> visitInfo = (int *)malloc(sizeof(int) * numVertex);
	memset(graph -> visitInfo, 0, sizeof(int) * numVertex);
	
	initHeap(&(graph -> weightHeap), compareWeight);
	
	for (i = 0; i < numVertex; i++)
		initList(&(graph -> adjacentList[i]));
}

void addEdge(ALGraph * graph, int iV, int fV, int weight)
{
	Edge newEdge = {iV, fV, weight};
	
	insertList(&(graph -> adjacentList[iV]), fV);
	insertList(&(graph -> adjacentList[fV]), iV);
	graph -> numEdge++;
	
	insertHeap(&(graph -> weightHeap), newEdge);
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
		printf("%c와 연결 : ", i + 'A');
		
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

// DFS
void showGraphVertexDFS(ALGraph * graph, int startVertex)
{
	Stack stack;
	int visitedVertex = startVertex;
	int nextVertex;
	
	initStack(&stack);
	
	visitVertex(graph, visitedVertex);
	
	while (searchFirst(&(graph -> adjacentList[visitedVertex]), &nextVertex)) {
		int visitFlag = FALSE;
		
		if (visitVertex(graph, nextVertex)) {
			push(&stack, visitedVertex);
			visitedVertex = nextVertex;
			visitFlag = TRUE;
		} else {
			while (searchNext(&(graph -> adjacentList[visitedVertex]), &nextVertex)) {
				if (visitVertex(graph, nextVertex)) {
					push(&stack, visitedVertex);
					visitedVertex = nextVertex;
					visitFlag = TRUE;
					break;
				}
			}
		}
		
		if (visitFlag == FALSE) {
			if (isStackEmpty(&stack))
				break;
			else
				visitedVertex = pop(&stack);
		}
	}
	
	memset(graph -> visitInfo, 0, sizeof(int) * graph -> numVertex);
}


void removeWayEdge(ALGraph * graph, int iV, int fV)
{
	int edge;
	
	if (searchFirst(&(graph -> adjacentList[iV]), &edge)) {
		if (edge == fV) {
			removeList(&(graph -> adjacentList[iV]));
			return;
		}
		
		while (searchNext(&(graph -> adjacentList[iV]), &edge)) {
			if (edge == fV) {
				removeList(&(graph -> adjacentList[iV]));
				return;
			}
		}
	}
}

void removeEdge(ALGraph * graph, int iV, int fV)
{
	removeWayEdge(graph, iV, fV);
	removeWayEdge(graph, fV, iV);
	graph -> numEdge--;
}

void recoverEdge(ALGraph * graph, int iV, int fV, int weight)
{
	insertList(&(graph -> adjacentList[fV]), fV);
	insertList(&(graph -> adjacentList[iV]), iV);
	graph -> numEdge++;
}


int isConnVertex(ALGraph * graph, int v1, int v2)
{
	Stack stack;
	int visitedVertex = v1;
	int nextVertex;
	
	initStack(&stack);
	visitVertex(graph, visitedVertex);
	push(&stack, visitedVertex);
	
	while (searchFirst(&(graph -> adjacentList[visitedVertex]), &nextVertex)) {
		int visitFlag = FALSE;
		
		if (nextVertex == v2) {
			memset(graph -> visitInfo, 0, sizeof(int) * graph -> numVertex);
			return TRUE;
		}
		
		if (visitVertex(graph, nextVertex)) {
			push(&stack, visitedVertex);
			visitedVertex = nextVertex;
			visitFlag = TRUE;
		}
		else {
			while (searchNext(&(graph -> adjacentList[visitedVertex]), &nextVertex)) {
				if (nextVertex == v2) {
					memset(graph -> visitInfo, 0, sizeof(int) * graph -> numVertex);
					return TRUE;
				}
				
				if (visitVertex(graph, nextVertex)) {
					push(&stack, visitedVertex);
					visitedVertex = nextVertex;
					visitFlag = TRUE;
					break;
				}
			}
		}
	}
}

void consKruskalMST(ALGraph * graph)
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;
	
	// 완성될 때까지 
	while (graph -> numEdge + 1 > graph -> numVertex) {
		edge = deleteHeap(&(graph -> weightHeap));
		removeEdge(graph, edge.v1, edge.v2);//
		
		if (!isConnVertex(graph, edge.v1, edge.v2)) {
			recoverEdge(graph, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
		
		for (i = 0; i < eidx; i++)
			insertHeap(&(graph -> weightHeap), recvEdge[i]);
	}
}
