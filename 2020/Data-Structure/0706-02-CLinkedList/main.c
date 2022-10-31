#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	int data, i, nodeNum;
	
	// 리스트 초기화와 데이터 삽입
	// -> 1 -> 2 -> 3 -> 4 -> 5(tail) -> 
	ListInit(&list);
	
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	// 리스트 3회 순환, 출력 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		for (i = 0; i < LCount(&list) * 3 - 1; i++) {
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	
	putchar('\n');
	
	// 모든 2의 배수 삭제
	nodeNum = LCount(&list);
	
	if (nodeNum != 0) {
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);
			
		for (i = 0; i< nodeNum - 1; i++) {
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}
	
	// 전체 데이터 출력
	nodeNum= LCount(&list);
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		for (i = 0; i < nodeNum - 1; i++) {
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}  
	
	return 0;
}
