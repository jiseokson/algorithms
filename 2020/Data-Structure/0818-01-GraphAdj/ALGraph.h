#ifndef _ALGRAPH_H_
#define _ALGRAPH_H_

#include "LinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ALGraph {
	int          numVertex;
	int          numEdge;
	LinkedList * adjacentList;
} ALGraph;

void initGraph(ALGraph * graph, int numVertex);
void addEdge(ALGraph * graph, int iV, int fV);
void destroyGraph(ALGraph * graph);
void showGraphEdgeInfo(ALGraph * graph);

#endif
