#include <stdio.h>
#include <stdlib.h>
#include "BinSearchTree.h"

void showAll(BinTreeNode * bt)
{
	if (bt != NULL) {
		showAll(getLeftSubTree(bt));
		printf("%d ", getBinTreeNodeData(bt));
		showAll(getRightSubTree(bt));
	}
}

int main(void)
{
	BinTreeNode * root;
	BinTreeNode * targetNode;
	
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
	
	showAll(root);
	putchar('\n');
	
	targetNode = deleteBinSearchTree(&root, 8);
	free(targetNode);
	
	showAll(root);
	putchar('\n');
	
	return 0;
}
