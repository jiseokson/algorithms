#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _BTreeNode {
	Data data;
	struct _BTreeNode * left;
	struct _BTreeNode * right;
} BTreeNode;

BTreeNode * make_BTreeNode(void);
void        set_data      (BTreeNode * bt, Data data);

void make_left_subtree (BTreeNode * main, BTreeNode * sub);
void make_right_subtree(BTreeNode * main, BTreeNode * sub);

Data        get_data         (BTreeNode * bt);
BTreeNode * get_left_subtree (BTreeNode * bt);
BTreeNode * get_right_subtree(BTreeNode * bt);

typedef void VisitFuncPtr(BTreeNode * bt); // void (* func)(BTreeNode * bt)

void preorder_traverse (BTreeNode * bt, VisitFuncPtr action);
void inorder_traverse  (BTreeNode * bt, VisitFuncPtr action);
void postorder_traverse(BTreeNode * bt, VisitFuncPtr action);

#endif
