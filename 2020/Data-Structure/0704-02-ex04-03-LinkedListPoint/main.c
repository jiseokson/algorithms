#include <stdio.h>
#include "Point.h"
#include "DLinkedList.h"

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;
	
	// 리스트 초기화, Point 삽입 
	ListInit(&list);
	//SetSortRule(&list, ord);
	
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
	
	// 리스트에 저장된 각 데이터 탐색 후 출력
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	putchar('\n');
	
	// xpos == 2 인 데이터 삭제 
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
	
	// 리스트에 저장된 각 데이터 탐색 후 출력	
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	
	return 0;
}
