#include <stdlib.h>
#include <string.h>
#include "EmployeeInfo.h"
#include "CLinkedList.h"

EmployeeInfo * make_info(char name[], int id)
{
	EmployeeInfo * new_info = (EmployeeInfo *)malloc(sizeof(EmployeeInfo));
	new_info -> id = id;
	strcpy(new_info -> name, name);
	
	return new_info;
}

EmployeeInfo * get_after(List * plist, char name[], int day)
{
	EmployeeInfo * info;
	int i, num_node = LCount(plist);
	
	if (!LFirst(plist, &info))
		return NULL;
	
	for (i = 1; i < num_node && strcmp(name, info -> name); i++)
		LNext(plist, &info);
	
	for (i = 0; i < day; i++)
		LNext(plist, &info);
		
	return info;
}
