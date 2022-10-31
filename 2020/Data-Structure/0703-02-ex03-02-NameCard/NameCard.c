#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard * nc = (NameCard *)malloc(sizeof(NameCard));
	
	strcpy(nc -> name, name);
	strcpy(nc -> phone, phone);
	
	return nc;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("Name : %16s | Phone : %13s\n", pcard -> name, pcard -> phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard -> name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy(pcard -> phone, phone);
}
