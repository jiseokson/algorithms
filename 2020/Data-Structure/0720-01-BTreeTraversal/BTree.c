#include <stdlib.h>
#include "BTree.h"

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

void make_left_subtree(BTreeNode * main, BTreeNode * sub)
{
	if (main -> left != NULL)
		free(main -> left);
		
	main -> left = sub;
}
void make_right_subtree(BTreeNode * main, BTreeNode * sub)
{
	if (main -> right != NULL)
		free(main -> right);
		
	main -> right = sub;
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

void preorder_traverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
		
	//printf("%d\n", bt -> data); // action 함수 포인터 활용 고민 
	action(bt);
	preorder_traverse(bt -> left, action);
	preorder_traverse(bt -> right, action);
}

void inorder_traverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
		
	inorder_traverse(bt -> left, action);
	action(bt);
	inorder_traverse(bt -> right, action);
}

void postorder_traverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
		
	postorder_traverse(bt -> left, action);
	postorder_traverse(bt -> right, action);
	action(bt);
}
