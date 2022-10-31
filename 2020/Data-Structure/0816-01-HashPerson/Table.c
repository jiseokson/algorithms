#include <stdio.h>
#include "Table.h"

void initTable(Table * table, HashFunction * hashFunction)
{
	int i;
	for (i = 0; i < MAX_TABLE; i++) {
		(table -> slotTable[i]).status = EMPTY;
	}
	table -> hashFunction = hashFunction;
}

void insertTable(Table * table, Key key, Value value)
{
	int hashValue = table -> hashFunction(key);
	(table -> slotTable[hashValue]).key = key;
	(table -> slotTable[hashValue]).value = value;
	(table -> slotTable[hashValue]).status = INUSE;
}

Value searchTable(Table * table, Key key)
{
	int hashValue = table -> hashFunction(key);
	
	if ((table -> slotTable[hashValue]).status == INUSE)
		return (table -> slotTable[hashValue]).value;
	else
		return NULL;
}

Value deleteTable(Table * table, Key key)
{
	int hashValue = table -> hashFunction(key);
	
	if ((table -> slotTable[hashValue]).status == INUSE) {
		(table -> slotTable[hashValue]).status = DELETED;
		return (table -> slotTable[hashValue]).value;
	}
	else
		return NULL;
}
