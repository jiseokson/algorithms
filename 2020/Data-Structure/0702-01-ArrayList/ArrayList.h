#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#define TRUE  1
#define FALSE 0

#define LIST_LEN 100
typedef int LData;

typedef struct {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInint(List *plist);
void Linsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif
