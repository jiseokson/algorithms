#ifndef __EMPLOYEE_INFO_H__
#define __EMPLOYEE_INFO_H__

#include "CLinkedList.h"

typedef struct _EmployeeInfo {
	int id;
	char name[30];
} EmployeeInfo;

EmployeeInfo * make_info(char name[], int id);
EmployeeInfo * get_after(List * plist, char name[], int day);

#endif
