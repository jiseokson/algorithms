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
	printf("주민등록번호 : %d\n", person -> ssn);
	printf("이름 : %s\n", person -> name);
	printf("주소 : %s\n", person -> address);
}
