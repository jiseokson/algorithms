#include <stdio.h>
#include <stdlib.h>
#include "BinSearchTree.h"



/*
R

L
*/
void showBinTree(Node * bt, int level, int parent)
{
	if (bt == NULL)
		return;
		
	showBinTree(getRightSubTree(bt), level + 1, getData(bt));
	
	int i;
	
	for (i = 0; i < level; i++)
		printf("              ");
	printf("[%d]\n",getData(bt));
	
	for (i = 0; i < level; i++)
		printf("              ");
	printf("parent = %d\n", parent);
	
	for (i = 0; i < level; i++)
		printf("              ");
	printf("heightDiff = %d\n", getHeightDifference(bt));
	
	showBinTree(getLeftSubTree(bt), level + 1, getData(bt));
}

int main(void)
{
	Node * root;
	Node * targetNode;
	Node * delNode;
	
	initBinSearchTree(&root);
	insertBinSearchTree(&root, 5);
	insertBinSearchTree(&root, 8);
	insertBinSearchTree(&root, 1);
	insertBinSearchTree(&root, 6);
	insertBinSearchTree(&root, 4);
	insertBinSearchTree(&root, 9);
	insertBinSearchTree(&root, 3);
	insertBinSearchTree(&root, 2);
	insertBinSearchTree(&root, 7);
	
	showBinTree(root, 0, 0);
	printf("\n\n");
	
	targetNode = searchBinSearchTree(root, 8);
	printf("search = %d", getData(targetNode));
	printf("\n\n");
	
	delNode = deleteBinSearchTree(&root, 4);
	printf("del = %d\n", getData(delNode));
	showBinTree(root, 0, 0);
	printf("\n\n");
	free(delNode);
	
	targetNode = searchBinSearchTree(root, 6);
	printf("search = %d", getData(targetNode));
	printf("\n\n");
	
	return 0;
}
