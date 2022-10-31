#include <stdio.h>
#include <stdlib.h>
#include "BinSearchTree.h"

void initBinSearchTree(Node ** root)
{
	*root = NULL;
}

void insertBinSearchTree(Node ** root, Data data)
{
	Node * parentNode  = NULL;
	Node * currentNode = *root;
	
	while (currentNode != NULL) {
		parentNode = currentNode;
		
		if (data < getData(currentNode))
			currentNode = getLeftSubTree(currentNode);
		else
			currentNode = getRightSubTree(currentNode);
	}
	
	Node * newNode = makeNode();
	setData(newNode, data);
	
	if (parentNode != NULL) {
		if (data < getData(parentNode))
			makeLeftSubTree(parentNode, newNode);
		else
			makeRightSubTree(parentNode, newNode);
	}
	else
		*root = newNode;
}

Node * searchBinSearchTree(Node * root, Data target)
{
	Node * parentNode  = NULL;
	Node * currentNode = root;
	Node * returnNode;
	
	while (currentNode != NULL) {
		if (getData(currentNode) == target)
			break;
			
		parentNode = currentNode;
		
		if (target < getData(parentNode))
			currentNode = getLeftSubTree(parentNode);
		else
			currentNode = getRightSubTree(parentNode);
	}
	
	return currentNode;
}

Node * deleteBinSearchTree(Node ** root, Data target)
{
	Node * tempRoot = makeNode();
	Node * delNode;
	makeRightSubTree(tempRoot, *root);
	
	// for search
	Node * parentNode  = tempRoot;
	Node * currentNode = *root;
	
	while (currentNode != NULL) {
		Data currentNodeData = getData(currentNode);
		
		if (currentNodeData == target)
			break;
			
		parentNode = currentNode;
		
		if (target < currentNodeData)
			currentNode = getLeftSubTree(currentNode);
		else
			currentNode = getRightSubTree(currentNode);
	}
	
	if (currentNode == NULL) {
		free(tempRoot);
		return NULL;
	}
		
	// 단말노드 
	if (getLeftSubTree(currentNode) == NULL && getRightSubTree(currentNode) == NULL) {
		if (getLeftSubTree(parentNode) == currentNode)
			delNode = makeLeftSubTree(parentNode, NULL);
		else
			delNode = makeRightSubTree(parentNode, NULL);
	}
	
	// 자식노드 1개  
	else if (getLeftSubTree(currentNode) == NULL || getRightSubTree(currentNode) == NULL) {
		Node * childNode;
		
		// find childNode 
		if (getLeftSubTree(currentNode) != NULL)
			childNode = getLeftSubTree(currentNode);
		else
			childNode = getRightSubTree(currentNode);
		
		if (getLeftSubTree(parentNode) == currentNode)
			delNode = makeLeftSubTree(parentNode, childNode);
		else
			delNode = makeRightSubTree(parentNode, childNode);
	}
	
	// 자식노드 2개 
	else {
		Node * referedParentNode = currentNode;
		Node * referedNode = getRightSubTree(referedParentNode);
		
		while (getLeftSubTree(referedNode) != NULL) {
			referedParentNode = referedNode;
			referedNode       = getLeftSubTree(referedNode);
		}
		
		delNode = makeNode();
		setData(delNode,     getData(currentNode));
		setData(currentNode, getData(referedNode));
		
		if (getLeftSubTree(referedParentNode) == referedNode)
			makeLeftSubTree(referedParentNode, getRightSubTree(referedNode));
		else
			makeRightSubTree(referedParentNode, getRightSubTree(referedNode));
	}
	
	if (getRightSubTree(tempRoot) != *root);
		*root = getRightSubTree(tempRoot);
		
	free(tempRoot);
	return delNode;
}
