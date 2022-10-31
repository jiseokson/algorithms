#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	
	// 리스트 초기화 
	ListInit(&list);
	
	// 리스트에 데이터 삽입 
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	printf("현재 저장된 데이터 수 : %d\n", LCount(&list));
	
	// 리스트의 각 데이터 탐색 후 출력 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	putchar('\n');
	
	// 리스트에서 모든 22 탐색 후 삭제 
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);
			
		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}
	
	printf("현재 저장된 데이터 수 : %d\n", LCount(&list));
	
	// 리스트의 각 데이터 탐색 후 출력 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	putchar('\n');
	
	return 0;
}
