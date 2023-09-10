#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode * bt1 = make_BTreeNode();
	BTreeNode * bt2 = make_BTreeNode();
	BTreeNode * bt3 = make_BTreeNode();
	BTreeNode * bt4 = make_BTreeNode();
	
	set_data(bt1, 1);
	set_data(bt2, 2);
	set_data(bt3, 3);
	set_data(bt4, 4);
	
	make_left_subtree(bt1, bt2);
	make_right_subtree(bt1, bt3);
	make_left_subtree(bt2, bt4);
	
	/*
	    1
	  2   3
	4
	*/
	
	printf("%d\n", get_data(bt1));
	printf("%d\n", get_data(get_left_subtree(get_left_subtree(bt1))));
	
	return 0;
}