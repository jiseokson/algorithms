#include <stdio.h>
#include "CLinkedList.h"
#include "EmployeeInfo.h"

int main(void)
{
	List list;
	EmployeeInfo * info;
	
	ListInit(&list);
	
	info = make_info("Amy", 1000);
	LInsert(&list, info);
	
	info = make_info("Benedict", 2380);
	LInsert(&list, info);
	
	info = make_info("Charlie", 3707);
	LInsert(&list, info);
	
	info = get_after(&list, "Amy", 10);
	printf("[%s, %d]\n", info -> name, info -> id);
	
	return 0;
}
