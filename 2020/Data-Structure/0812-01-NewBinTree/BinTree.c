#include <stdlib.h>
#include "BinTree.h"

inline Node * makeNode(void)
{
	Node * newNode   = (Node *)malloc(sizeof(Node));
	newNode -> left  = NULL;
	newNode -> right = NULL;
}

inline void setData(Node * node, Data data)
{
	node -> data = data;
}

inline Node * makeLeftSubTree(Node * mainTree, Node * subTree)
{
	Node * deletedTree = mainTree -> left;
	mainTree -> left   = subTree;
	return deletedTree;
}

inline Node * makeRightSubTree(Node * mainTree, Node * subTree)
{
	Node * deletedTree = mainTree -> right;
	mainTree -> right  = subTree;
	return deletedTree;
}

inline Data getData(Node * node)
{
	return node -> data;
}

inline Node * getLeftSubTree(Node * binTree)
{
	return binTree -> left;
}

inline Node * getRightSubTree(Node * binTree)
{
	return binTree -> right;
}
