#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;
	
	// ����Ʈ �ʱ�ȭ, ������ ����
	ListInit(&list);
	
	pcard = MakeNameCard("Walter White", "010-1221-2222");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("Jessy Pinkman", "010-2345-1111");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("Flyn White", "010-8744-9377");
	LInsert(&list, pcard);
	
	// Ư�� �̸����� Ž�� �� ���
	printf("Flyn White Ž��\n");
	
	if (LFirst(&list, &pcard)) {
		
		if (!NameCompare(pcard, "Flyn White"))
			ShowNameCardInfo(pcard);
		
		while (LNext(&list, &pcard)) {
			
			if (!NameCompare(pcard, "Flyn White"))
				ShowNameCardInfo(pcard);
				
		}
		
	}
	
	putchar('\n');
	
	// Ư�� �̸����� Ž�� �� ��ȭ��ȣ ����
	printf("Jessy Pinkman�� ��ȭ��ȣ ����\n");
	
	if (LFirst(&list, &pcard)) {
		
		if (!NameCompare(pcard, "Jessy Pinkman"))
			ChangePhoneNum(pcard, "010-0000-0000");
		
		while (LNext(&list, &pcard)) {
			
			if (!NameCompare(pcard, "Jessy Pinkman"))
				ChangePhoneNum(pcard, "010-0000-0000");
				
		}
		
	}
	
	putchar('\n');
	
	// Ư�� �̸����� Ž�� �� ������ ����
	printf("Walter White ���� ����\n");
	
	if (LFirst(&list, &pcard)) {
		
		if (!NameCompare(pcard, "Walter White")) {
			
			pcard = LRemove(&list);
			free(pcard);
			
		}
		
		while (LNext(&list, &pcard)) {
			
			if (!NameCompare(pcard, "Walter White")) {
				
				pcard = LRemove(&list);
				free(pcard);
				
			}
			
		}
		
	}
	
	putchar('\n');
	
	// �����ִ� ��� ����� ������ ���
	printf("����� ��ü ������ ���\n");
	
	if (LFirst(&list, &pcard)) {
		
		ShowNameCardInfo(pcard);
				
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
			
	}
	
	putchar('\n');
	
	return 0;
}
