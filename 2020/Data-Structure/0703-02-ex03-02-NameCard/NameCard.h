#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#define NAME_LEN  16
#define PHONE_LEN 12

typedef struct {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

NameCard * MakeNameCard(char * name, char * phone);
void ShowNameCardInfo(NameCard * pcard);
int NameCompare(NameCard * pcard, char * name);
void ChangePhoneNumber(NameCard * pcard, char * phone);

#endif
