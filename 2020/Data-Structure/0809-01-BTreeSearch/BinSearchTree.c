#include <stdio.h>
#include <stdlib.h>
#include "BinSearchTree.h"

inline void initBinSearchTree(BinTreeNode ** root)
{
	*root = NULL;
}

inline BinTreeNodeData getBinSearchTreeNodeData(BinTreeNode * binSearchTreeNode)
{
	return getBinTreeNodeData(binSearchTreeNode);
}

void insertBinSearchTree(BinTreeNode ** root, BinTreeNodeData data)
{
	BinTreeNode * parentNode  = NULL;
	BinTreeNode * currentNode = *root;
	BinTreeNode * newNode     = NULL;
	
	while (currentNode != NULL) {
		BinTreeNodeData currentNodeData = getBinTreeNodeData(currentNode);
		if (currentNodeData == data)
			return;
			
		parentNode = currentNode;
		
		if (data < currentNodeData)
			currentNode = getLeftSubTree(currentNode);
		else
			currentNode = getRightSubTree(currentNode);
	}
	
	newNode = makeBinTreeNode();
	setBinTreeNodeData(newNode, data);
	
	if (parentNode != NULL) {
		if (data < getBinTreeNodeData(parentNode))
			makeLeftSubTree(parentNode, newNode);
		else
			makeRightSubTree(parentNode, newNode);
	}
	else
		*root = newNode;
}

BinTreeNode * searchBinSearchTree(BinTreeNode * root, BinTreeNodeData target)
{
	BinTreeNode * currentNode = root;
	
	while (currentNode != NULL) {
		BinTreeNodeData currentNodeData = getBinTreeNodeData(currentNode);
		
		if (currentNodeData == target)
			return currentNode;
		else if (target < currentNodeData)
			currentNode = getLeftSubTree(currentNode);
		else
			currentNode = getRightSubTree(currentNode);
	}
	
	return NULL;
}

inline void deleteLeftSubTree(BinTreeNode * bt)
{
	bt -> left = NULL;
}

inline void deleteRightSubTree(BinTreeNode * bt)
{
	bt -> right = NULL;
}

BinTreeNode * deleteBinSearchTree(BinTreeNode ** root, BinTreeNodeData target)
{
	BinTreeNode * virtualRoot = makeBinTreeNode();
	BinTreeNode * parentNode  = NULL;
	BinTreeNode * targetNode  = *root;
	
	makeRightSubTree(virtualRoot, *root);
	
	// search target node & parent of it.
	while (targetNode != NULL && getBinTreeNodeData(targetNode) != target) {
		parentNode = targetNode;
		
		if (target < getBinTreeNodeData(targetNode))
			targetNode = getLeftSubTree(targetNode);
		else
			targetNode = getRightSubTree(targetNode);
	}
	
	// target node doesn't exist
	if (targetNode == NULL)
		return NULL;
		
	// 단말노드인 경우
	if (getLeftSubTree(targetNode) == NULL && getRightSubTree(targetNode) == NULL) {
		if (getLeftSubTree(parentNode) == targetNode)
			deleteLeftSubTree(parentNode);
		else
			deleteRightSubTree(parentNode);
	}
	
	// 자식노드가 1개있는 경우
	else if (getLeftSubTree(targetNode) == NULL || getRightSubTree(targetNode) == NULL) {
		BinTreeNode * targetChildrenNode;
		
		if (getLeftSubTree(targetNode) != NULL)
			targetChildrenNode = getLeftSubTree(parentNode);
		else
			targetChildrenNode = getRightSubTree(parentNode);
		
		if (getLeftSubTree(parentNode) == targetNode)
			makeLeftSubTree(parentNode, targetChildrenNode);
		else
			makeRightSubTree(parentNode, targetChildrenNode);
	}
	
	// 자식노드가 2개있는 경우
	else {
		BinTreeNode * replacementParentNode = targetNode;
		BinTreeNode * replacementNode       = getRightSubTree(targetNode);
		
		while (getLeftSubTree(replacementNode) != NULL) {
			replacementParentNode = replacementNode;
			replacementNode = getLeftSubTree(replacementNode);
		}
		
		BinTreeNodeData targetData= getBinTreeNodeData(targetNode);
		setBinTreeNodeData(targetNode, getBinTreeNodeData(replacementNode));
		
		if (getLeftSubTree(replacementParentNode) == replacementNode)
			makeLeftSubTree(replacementParentNode, getRightSubTree(replacementNode));
		else
			makeRightSubTree(replacementParentNode, getRightSubTree(replacementNode));
			
		targetNode = replacementNode;
		setBinTreeNodeData(targetNode, targetData);
	}
	
	if (getRightSubTree(virtualRoot) == *root)
		*root = getRightSubTree(virtualRoot);
	
	free(virtualRoot);
	return targetNode;
}
