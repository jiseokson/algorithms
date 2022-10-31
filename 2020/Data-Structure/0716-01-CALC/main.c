#include <stdio.h>
#include "Eval.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	
	printf("%s = %d\n", exp1, eval(exp1));
	printf("%s = %d\n", exp2, eval(exp2));
	printf("%s = %d\n", exp3, eval(exp3));
	
	return 0;
}
