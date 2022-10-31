#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
} Node;

int main(void)
{	
	Node * head  = NULL;//(Node *)malloc(sizeof(Node)); // dummy ���� 
	Node * tail  = NULL; 
	Node * cur   = NULL;
	//Node * dummy = NULL;
	
	Node * new_node = NULL;
	int read_data;
	
	// dummy node ����
	head = (Node *)malloc(sizeof(Node));
	head -> next = NULL;
	tail = head;
	
	/*
	// dummy node ���� 
	dummy = (Node *)malloc(sizeof(Node));
	dummy -> data = -1;
	dummy -> next = NULL;
	
	head = dummy;
	tail = dummy;
	*/
	
	// �Է��� �����͸�  ����Ʈ�� ���� 
	while (1) {
		printf("������ �Է��ϼ��� : ");
		scanf("%d", &read_data);
		if (read_data == 0)
			break;
			
		new_node = (Node *)malloc(sizeof(Node));
		new_node -> data = read_data;
		new_node -> next = NULL; 
		
		tail -> next = new_node;
		tail = new_node;
	}
	
	// ����� ��� �����͸� ���
	printf("����� ��� �����͸� ����մϴ�.\n");
	
	if (head == tail/*head -> next == NULL*/)
		printf("����� �����Ͱ� �����ϴ�.\n");
	
	else {
		cur = head;
	
		while (cur -> next != NULL) {
			cur = cur -> next;
			printf("%d ", cur -> data);
		}
	}	
	
	putchar('\n');
	
	// ��� �����͸� ����
	printf("����� ��� �����͸� �����մϴ�.\n");
	
	if (head != tail/*head -> next != NULL*/) {
		Node * del_node = head;
		Node * del_node_next = head -> next;
		
		while (del_node_next != NULL) {
			del_node = del_node_next;
			del_node_next = del_node_next -> next;
			
			printf("%d ����\n", del_node -> data);
			free(del_node);
		}
	}
	
	free(head);
	
	return 0;
}
