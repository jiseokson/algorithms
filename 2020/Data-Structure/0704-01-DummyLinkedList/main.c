#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

// ch3 main �ڵ�� ���� 
int main(void)
{
	List list;
	LData data;
	
	// ����Ʈ �ʱ�ȭ 
	ListInit(&list);
	
	// ����Ʈ�� ������ ���� 
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	// ����Ʈ�� �� ������ Ž�� �� ��� 
	printf("���� ����� ������ �� : %d\n", LCount(&list));
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	
	putchar('\n');
	
	// ����Ʈ���� ��� 22 Ž�� �� ���� 
	printf("����Ʈ�� ����� ��� 22����\n"); 
	
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);
			
		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}
	
	// ����Ʈ�� �� ������ Ž�� �� ���
	printf("���� ����� ������ �� : %d\n", LCount(&list));
	 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	
	putchar('\n');
	
	return 0;
}
