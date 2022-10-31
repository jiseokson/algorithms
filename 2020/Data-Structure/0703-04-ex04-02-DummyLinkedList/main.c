#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
} Node;

int main(void)
{	
	Node * head  = NULL;//(Node *)malloc(sizeof(Node)); // dummy 삽입 
	Node * tail  = NULL; 
	Node * cur   = NULL;
	//Node * dummy = NULL;
	
	Node * new_node = NULL;
	int read_data;
	
	// dummy node 삽입
	head = (Node *)malloc(sizeof(Node));
	head -> next = NULL;
	tail = head;
	
	/*
	// dummy node 삽입 
	dummy = (Node *)malloc(sizeof(Node));
	dummy -> data = -1;
	dummy -> next = NULL;
	
	head = dummy;
	tail = dummy;
	*/
	
	// 입력한 데이터를  리스트에 삽입 
	while (1) {
		printf("정수를 입력하세요 : ");
		scanf("%d", &read_data);
		if (read_data == 0)
			break;
			
		new_node = (Node *)malloc(sizeof(Node));
		new_node -> data = read_data;
		new_node -> next = NULL; 
		
		tail -> next = new_node;
		tail = new_node;
	}
	
	// 저장된 모든 데이터를 출력
	printf("저장된 모든 데이터를 출력합니다.\n");
	
	if (head == tail/*head -> next == NULL*/)
		printf("저장된 데이터가 없습니다.\n");
	
	else {
		cur = head;
	
		while (cur -> next != NULL) {
			cur = cur -> next;
			printf("%d ", cur -> data);
		}
	}	
	
	putchar('\n');
	
	// 모든 데이터를 삭제
	printf("저장된 모든 데이터를 삭제합니다.\n");
	
	if (head != tail/*head -> next != NULL*/) {
		Node * del_node = head;
		Node * del_node_next = head -> next;
		
		while (del_node_next != NULL) {
			del_node = del_node_next;
			del_node_next = del_node_next -> next;
			
			printf("%d 삭제\n", del_node -> data);
			free(del_node);
		}
	}
	
	free(head);
	
	return 0;
}
