#include <stdio.h>
#include "BTree.h"
#include "ExpTree.h"

int main(void)
{
	char pexp[] = "12+3*4/";
	BTreeNode * exp_tree = make_exp_tree(pexp);
	
	show_infix_exp(exp_tree);
	printf("= %d\n", eval_exp_tree(exp_tree));
	
	return 0;
}
