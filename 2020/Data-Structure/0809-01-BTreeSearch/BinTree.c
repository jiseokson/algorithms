#include <stdlib.h>
#include "BinTree.h"

inline BinTreeNode * makeBinTreeNode(void)
{
	BinTreeNode * newNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	newNode -> left       = NULL;
	newNode -> right      = NULL;
}

inline void setBinTreeNodeData(BinTreeNode * binTreeNode, BinTreeNodeData data)
{
	binTreeNode -> data = data;
}

inline BinTreeNode * makeLeftSubTree(BinTreeNode * mainTree, BinTreeNode * subTree)
{
	BinTreeNode * deletedTree = mainTree -> left;
	mainTree -> left          = subTree;
	return deletedTree;
}

inline BinTreeNode * makeRightSubTree(BinTreeNode * mainTree, BinTreeNode * subTree)
{
	BinTreeNode * deletedTree = mainTree -> right;
	mainTree -> right         = subTree;
	return deletedTree;
}

inline BinTreeNodeData getBinTreeNodeData(BinTreeNode * binTreeNode)
{
	return binTreeNode -> data;
}

inline BinTreeNode * getLeftSubTree(BinTreeNode * binTree)
{
	return binTree -> left;
}

inline BinTreeNode * getRightSubTree(BinTreeNode * binTree)
{
	return binTree -> right;
}
