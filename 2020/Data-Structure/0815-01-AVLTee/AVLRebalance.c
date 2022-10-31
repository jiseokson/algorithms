#include <stdio.h>
#include "AVLRebalance.h"

int getHeight(Node * binTree)
{
	if (binTree == NULL)
		return 0;
	
	int leftHeight  = getHeight(getLeftSubTree(binTree));
	int rightHeight = getHeight(getRightSubTree(binTree));
	
	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

int getHeightDifference(Node * binTree)
{
	if (binTree == NULL)
		return 0;
		
	int leftHeight  = getHeight(getLeftSubTree(binTree));
	int rightHeight = getHeight(getRightSubTree(binTree));
	return leftHeight - rightHeight;
}

Node * rotateLL(Node * binTree)
{
	Node * parentNode = binTree;
	Node * childNode  = getLeftSubTree(parentNode);
	
	makeLeftSubTree(parentNode, getRightSubTree(childNode));
	makeRightSubTree(childNode, parentNode);
	
	return childNode;
}

Node * rotateRR(Node * binTree)
{
	Node * parentNode = binTree;
	Node * childNode  = getRightSubTree(parentNode);
	
	makeRightSubTree(parentNode, getLeftSubTree(childNode));
	makeLeftSubTree(childNode, parentNode);
	
	return childNode;
}

Node * rotateLR(Node * binTree)
{
	Node * parentNode = binTree;
	Node * childNode = getLeftSubTree(binTree);
	
	makeLeftSubTree(parentNode, rotateRR(childNode));
	return rotateLL(parentNode);
}

Node * rotateRL(Node * binTree)
{
	Node * parentNode = binTree;
	Node * childNode = getRightSubTree(binTree);
	
	makeRightSubTree(parentNode, rotateLL(childNode));
	return rotateRR(parentNode);
}

Node * rebalance(Node * binTree)
{
	int heightDifference = getHeightDifference(binTree);
	
	if (heightDifference >= 2) {
		if (getHeightDifference(getLeftSubTree(binTree)) > 0)
			binTree = rotateLL(binTree);
		else
			binTree = rotateLR(binTree);
	}
	
	else if (heightDifference <= -2) {
		if (getHeightDifference(getRightSubTree(binTree)) < 0)
			binTree = rotateRR(binTree);
		else
			binTree = rotateRL(binTree);
	}
	
	return binTree;
}
