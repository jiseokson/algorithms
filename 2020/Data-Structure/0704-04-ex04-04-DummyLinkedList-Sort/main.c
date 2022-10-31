#include <stdio.h>
#include "Point.h"
#include "DLinkedList.h"

int ord(LData d1, LData d2)
{	
	if (d1 -> xpos < d2 -> xpos)
		return TRUE;
	else
		return FALSE;
}

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;
	
	// ����Ʈ �ʱ�ȭ, Point ���� 
	ListInit(&list);
	SetSortRule(&list, ord);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	// ����Ʈ�� ����� �� ������ Ž�� �� ���
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	
	putchar('\n');
	
	// xpos == 2 �� ������ ����
	printf("x��ǥ�� 2�� ������ ��� ����\n\n");
	
	compPos.xpos = 2;
	compPos.ypos = 0;
	
	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			ppos = LRemove(&list);
			free(ppos);
		}
		
		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}
	
	// ����Ʈ�� ����� �� ������ Ž�� �� ���
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	
	return 0;
}
