#include <stdio.h>
#include "Point.h"

void SetPointPos(Point *ppos, int xpos, int ypos)
{
	ppos -> xpos = xpos;
	ppos -> ypos = ypos;
}

void ShowPointPos(Point *ppos)
{
	printf("x = %d, y = %d\n", ppos -> xpos, ppos -> ypos);
}

int PointComp(Point *ppos1, Point *ppos2)
{
	int x1 = ppos1 -> xpos, y1 = ppos1 -> ypos;
	int x2 = ppos2 -> xpos, y2 = ppos2 -> ypos;
	
	if (x1 == x2 && y1 == y2)
		return 0;
		
	else if (x1 == x2)
		return 1;
		
	else if (y1 == y2)
		return 2;
		
	else
		return -1;
}
