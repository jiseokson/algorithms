#ifndef __EXPTREE_H__
#define __EXPTREE_H__

BTreeNode * make_exp_tree(char postfix_exp[]);
int         eval_exp_tree(BTreeNode * bt);

void show_prefix_exp (BTreeNode * bt);
void show_infix_exp  (BTreeNode * bt);
void show_postfix_exp(BTreeNode * bt);

#endif
