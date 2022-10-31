#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int myHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table table;
	Person * newPerson;
	Person * targetPerson;
	Person * delPerson;
	
	initTable(&table, myHashFunc);
	
	// �ؽ� ���̺� ���� 
	newPerson = makePersonData(20120003, "Lee", "Seoul");
	insertTable(&table, getSSN(newPerson), newPerson);
	
	newPerson = makePersonData(20120012, "Kim", "Jeju");
	insertTable(&table, getSSN(newPerson), newPerson);
	
	newPerson = makePersonData(20120017, "Son", "SungNam");
	insertTable(&table, getSSN(newPerson), newPerson);
	
	// �ؽ� ���̺� Ž��
	targetPerson = searchTable(&table, 20120003);
	if (targetPerson != NULL)
		showPersonInfo(targetPerson);
	putchar('\n');
		
	targetPerson = searchTable(&table, 20120012);
	if (targetPerson != NULL)
		showPersonInfo(targetPerson);
	putchar('\n');
		
	targetPerson = searchTable(&table, 20120017);
	if (targetPerson != NULL)
		showPersonInfo(targetPerson);
	putchar('\n');
		
	// �ؽ� ���̺� ����
	delPerson = deleteTable(&table, 20120003);
	if (delPerson != NULL)
		free(delPerson);
	
	delPerson = deleteTable(&table, 20120012);
	if (delPerson != NULL)
		free(delPerson);
		
	delPerson = deleteTable(&table, 20120017);
	if (delPerson != NULL)
		free(delPerson);
	
	return 0;
}
