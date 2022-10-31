#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	
	// ����Ʈ �ʱ�ȭ 
	ListInit(&list);
	
	// ����Ʈ�� ������ ���� 
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	
	printf("���� ����� ������ �� : %d\n", LCount(&list));
	
	// ����Ʈ�� �� ������ Ž�� �� ��� 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	putchar('\n');
	
	// ����Ʈ���� ��� 22 Ž�� �� ���� 
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);
			
		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}
	
	printf("���� ����� ������ �� : %d\n", LCount(&list));
	
	// ����Ʈ�� �� ������ Ž�� �� ��� 
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	putchar('\n');
	
	return 0;
}
