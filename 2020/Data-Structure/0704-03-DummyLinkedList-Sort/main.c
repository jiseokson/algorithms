#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int ord(LData d1, LData d2)
{
	if (d1 < d2)
		return TRUE;
	else
		return FALSE;
}

int main(void)
{
	List list;
	LData data;
	int y = 0;
	
	// 리스트 초기화 
	ListInit(&list);
	SetSortRule(&list, ord);
	
	// 리스트에 데이터 삽입 
	LInsert(&list, 1111);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	// 리스트의 각 데이터 탐색 후 출력 
	printf("현재 저장된 데이터 수 : %d\n", LCount(&list));
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	
	printf("\n\n");
	
	// 리스트에서 모든 22 탐색 후 삭제 
	printf("리스트에 저장된 모든 22 삭제\n\n"); 
	
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);
			
		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}
	
	// 리스트의 각 데이터 탐색 후 출력
	printf("현재 저장된 데이터 수 : %d\n", LCount(&list));
	 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	
	return 0;
}
