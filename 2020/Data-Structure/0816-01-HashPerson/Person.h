#ifndef _PERSON_H_
#define _PERSON_H_

#define STR_LEN 50

typedef struct _Person {
	int  ssn;
	char name[STR_LEN];
	char address[STR_LEN];
} Person;


Person * makePersonData(int ssn, char name[], char address[]);
int      getSSN        (Person * person);
void     showPersonInfo(Person * person);

#endif
