#include <stdlib.h>
#include <string.h>
#include "Person.h"

Person * makePersonData(int ssn, char name[], char address[])
{
	Person * newPerson = (Person *)malloc(sizeof(Person));
	newPerson -> ssn = ssn;
	strcpy(newPerson -> name, name);
	strcpy(newPerson -> address, address);
	return newPerson;
}

int getSSN(Person * person)
{
	return person -> ssn;
}

void showPersonInfo(Person * person)
{
	printf("�ֹε�Ϲ�ȣ : %d\n", person -> ssn);
	printf("�̸� : %s\n", person -> name);
	printf("�ּ� : %s\n", person -> address);
}
