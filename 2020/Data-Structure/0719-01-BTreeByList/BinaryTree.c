#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * make_BTreeNode(void)
{
	BTreeNode * new_node = (BTreeNode *)malloc(sizeof(BTreeNode));
	new_node -> left     = NULL;
	new_node -> right    = NULL;
}

void set_data(BTreeNode * bt, Data data)
{
	bt -> data = data;
}

Data get_data(BTreeNode * bt)
{
	return bt -> data;
}

BTreeNode * get_left_subtree(BTreeNode * bt)
{
	return bt -> left;
}

BTreeNode * get_right_subtree(BTreeNode * bt)
{
	return bt -> right;
}

void delete_tree(BTreeNode * bt)
{
	if (bt == NULL)
		return;
		
	delete_tree(bt -> left);
	delete_tree(bt -> right);
	free(bt);
}

void make_left_subtree(BTreeNode * main, BTreeNode * sub)
{
	if (main -> left != NULL)
		delete_tree(main -> left);
		
	main -> left = sub;
}
void make_right_subtree(BTreeNode * main, BTreeNode * sub)
{
	if (main -> right != NULL)
		delete_tree(main -> right);
		
	main -> right = sub;
}
