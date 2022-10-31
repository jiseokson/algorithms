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
	
	// �����͸� �Է� 
	while (1) {
		printf("�ڿ��� �Է� : ");
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
			// ��忡 �߰����� �ʴ� ��� ������ �ʿ����� ���� 
		}
			
		else {
			new_node -> next = head;
			head = new_node;
		}
	}
	
	printf("\n\n");
	
	// ����� ������ Ž�� �� ���
	printf("��ü �����͸� Ž�� �� ���.\n");
	
	if (head == NULL) {
		printf("����� �����Ͱ� �����ϴ�.\n");
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
	
	// �޸� ����
	printf("����� ��� ������ ����.\n");
	
	if (head != NULL) {
		Node * del_node = head;
		Node * del_node_next = head -> next;
		
		printf("%d ����.\n", head -> data);
		free(del_node);
		
		while (del_node_next != NULL) {
			del_node = del_node_next;
			del_node_next = del_node_next -> next;
			
			printf("%d ����.\n", del_node -> data);
			free(del_node);
		 }
		 
		/*
		Node * del_node = head;
		Node * del_node_next = head -> next;
		
		while (del_node_next != NULL) {
			printf("%d ����.\n", del_node -> data);
			free(del_node);
			
			del_node = del_node_next;
			del_node_next = del_node_next -> next;
		}
		
		// �� �Ǵ� ���� :
		1. ���������� �� ��° �׸� ������ �� del_next_node = NULL
		2. ������ �׸� �ϳ� ���� ���¿��� while Ż��
		
		����ϰ� �ٲٵ���, �ٲٰ� ����ϵ���. << ���� ���� 
		*/
	}

	return 0;
}
