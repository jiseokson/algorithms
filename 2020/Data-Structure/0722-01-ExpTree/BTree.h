#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef char BTData;

typedef struct _BTreeNode {
	BTData data;
	struct _BTreeNode * left;
	struct _BTreeNode * right;
} BTreeNode;

BTreeNode * make_BTreeNode(void);
void        set_data      (BTreeNode * bt, BTData data);

void delete_tree       (BTreeNode * bt);
void make_left_subtree (BTreeNode * main, BTreeNode * sub);
void make_right_subtree(BTreeNode * main, BTreeNode * sub);

BTData      get_data         (BTreeNode * bt);
BTreeNode * get_left_subtree (BTreeNode * bt);
BTreeNode * get_right_subtree(BTreeNode * bt); 

#endif
