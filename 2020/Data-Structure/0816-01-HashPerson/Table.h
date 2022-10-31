#ifndef _TABLE_H_
#define _TABLE_H_

#include "Slot.h"

#define MAX_TABLE 100

typedef int HashFunction(Key key);

typedef struct _Table {
	Slot           slotTable[MAX_TABLE];
	HashFunction * hashFunction;
} Table;

void  initTable  (Table * table, HashFunction * hashFunction);
void  insertTable(Table * table, Key key, Value value);
Value searchTable(Table * table, Key key);
Value deleteTable(Table * table, Key key);

#endif
