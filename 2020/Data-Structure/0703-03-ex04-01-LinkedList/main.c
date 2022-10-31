#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur  = NULL;
	
	Node * new_node = NULL;
	int read;
	
	// 데이터를 입력 
	while (1) {
		printf("자연수 입력 : ");
		scanf("%d", &read);
		if (read == 0)
			break;
			
		new_node = (Node *)malloc(sizeof(Node));
		new_node -> data = read;
		new_node -> next = NULL;
		
		/*
		if (head == NULL)
			head = new_node;
			
		else
			tail -> next = new_node;
			
		tail = new_node;
		*/
		
		if (head == NULL) {
			head = new_node;
			//tail = new_node;
			// 헤드에 추가하지 않는 경우 테일이 필요하지 않음 
		}
			
		else {
			new_node -> next = head;
			head = new_node;
		}
	}
	
	printf("\n\n");
	
	// 저장된 데이터 탐색 후 출력
	printf("전체 데이터를 탐색 후 출력.\n");
	
	if (head == NULL) {
		printf("저장된 데이터가 없습니다.\n");
	}
	
	else {
		cur = head;
		printf("%d ", cur -> data);
		
		while (cur -> next != NULL) {
			cur = cur -> next;
			printf("%d ", cur -> data);
		}
	}
	
	printf("\n\n");
	
	// 메모리 해제
	printf("저장된 모든 데이터 삭제.\n");
	
	if (head != NULL) {
		Node * del_node = head;
		Node * del_node_next = head -> next;
		
		printf("%d 삭제.\n", head -> data);
		free(del_node);
		
		while (del_node_next != NULL) {
			del_node = del_node_next;
			del_node_next = del_node_next -> next;
			
			printf("%d 삭제.\n", del_node -> data);
			free(del_node);
		 }
		 
		/*
		Node * del_node = head;
		Node * del_node_next = head -> next;
		
		while (del_node_next != NULL) {
			printf("%d 삭제.\n", del_node -> data);
			free(del_node);
			
			del_node = del_node_next;
			del_node_next = del_node_next -> next;
		}
		
		// 안 되는 이유 :
		1. 마지막에서 두 번째 항목 삭제한 후 del_next_node = NULL
		2. 마지막 항목 하나 남은 상태에서 while 탈출
		
		기능하고 바꾸든지, 바꾸고 기능하든지. << 둘의 차이 
		*/
	}

	return 0;
}
