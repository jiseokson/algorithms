#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;
	
	// 리스트 초기화, 데이터 삽입
	ListInit(&list);
	
	pcard = MakeNameCard("Walter White", "010-1221-2222");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("Jessy Pinkman", "010-2345-1111");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("Flyn White", "010-8744-9377");
	LInsert(&list, pcard);
	
	// 특정 이름으로 탐색 후 출력
	printf("Flyn White 탐색\n");
	
	if (LFirst(&list, &pcard)) {
		
		if (!NameCompare(pcard, "Flyn White"))
			ShowNameCardInfo(pcard);
		
		while (LNext(&list, &pcard)) {
			
			if (!NameCompare(pcard, "Flyn White"))
				ShowNameCardInfo(pcard);
				
		}
		
	}
	
	putchar('\n');
	
	// 특정 이름으로 탐색 후 전화번호 수정
	printf("Jessy Pinkman의 전화번호 수정\n");
	
	if (LFirst(&list, &pcard)) {
		
		if (!NameCompare(pcard, "Jessy Pinkman"))
			ChangePhoneNum(pcard, "010-0000-0000");
		
		while (LNext(&list, &pcard)) {
			
			if (!NameCompare(pcard, "Jessy Pinkman"))
				ChangePhoneNum(pcard, "010-0000-0000");
				
		}
		
	}
	
	putchar('\n');
	
	// 특정 이름으로 탐색 후 정보를 삭제
	printf("Walter White 정보 삭제\n");
	
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
	
	// 남아있는 모든 사람의 정보를 출력
	printf("저장된 전체 데이터 출력\n");
	
	if (LFirst(&list, &pcard)) {
		
		ShowNameCardInfo(pcard);
				
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
			
	}
	
	putchar('\n');
	
	return 0;
}
