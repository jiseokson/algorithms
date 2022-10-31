#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "LinkedList.h"

typedef enum _Vertex {
	A, B, C, D, E, F, G
} Vertex;

typedef struct _ALGraph {
	int          numVertex;
	int          numEdge;
	LinkedList * adjacentList;
	int        * visitInfo;
} ALGraph;

void initGraph    (ALGraph * graph, int numVertex);
void addEdge      (ALGraph * graph, int iV, int fV);
void destroyGraph (ALGraph * graph);
void showGraphEdge(ALGraph * graph);

// DFS
void showGraphVertexDFS(ALGraph * graph, int startVertex);

#endif
