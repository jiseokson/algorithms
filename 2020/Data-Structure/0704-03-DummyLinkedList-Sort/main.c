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
	
	// ����Ʈ �ʱ�ȭ 
	ListInit(&list);
	SetSortRule(&list, ord);
	
	// ����Ʈ�� ������ ���� 
	LInsert(&list, 1111);
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
	
	printf("\n\n");
	
	// ����Ʈ���� ��� 22 Ž�� �� ���� 
	printf("����Ʈ�� ����� ��� 22 ����\n\n"); 
	
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
	
	return 0;
}
