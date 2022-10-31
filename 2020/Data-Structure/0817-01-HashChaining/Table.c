#include <stdio.h>
#include "Table.h"
#include "LinkedList.h"

void initTable(Table * table, HashFunction * hashFunction)
{
	int i;
	for (i = 0; i < MAX_TABLE; i++) {
		(table -> slotList[i]).status = EMPTY;
		initList(&(table -> slotList[i]));
	}
	table -> hashFunction = hashFunction;
}

void insertTable(Table * table, Key key, Value value)
{
	int hashValue = table -> hashFunction(key);
	insertList(&(table -> slotList[hashValue]), (Slot){key, value});
	(table -> slotList[hashValue]).status = INUSE;
	/*(table -> slotTable[hashValue]).key = key;
	(table -> slotTable[hashValue]).value = value;
	(table -> slotTable[hashValue]).status = INUSE;*/
}

Value searchTable(Table * table, Key key)
{
	int hashValue = table -> hashFunction(key);
	
	if ((table -> slotList[hashValue]).status == INUSE) {
		Slot currentSlot;
		
		if (searchFirst(&(table -> slotList[hashValue]), &currentSlot)) {
			if (currentSlot.key == key)
				return currentSlot.value;
				
			while (searchNext(&(table -> slotList[hashValue]), &currentSlot)) {
				if (currentSlot.key == key)
					return currentSlot.value;
			}
		}
	}
		//return (table -> slotTable[hashValue]).value;
	return NULL;
}

Value deleteTable(Table * table, Key key)
{
	int hashValue = table -> hashFunction(key);
	
	if ((table -> slotList[hashValue]).status == INUSE) {
		Slot currentSlot;
		
		if (searchFirst(&(table -> slotList[hashValue]), &currentSlot)) {
			if (currentSlot.key == key) {
				return removeList(&(table -> slotList[hashValue])).value;
			}
				
			while (searchNext(&(table -> slotList[hashValue]), &currentSlot)) {
				if (currentSlot.key == key)
					return removeList(&(table -> slotList[hashValue])).value;
			}
		}
		
		if (countList(&(table -> slotList[hashValue])) == 0)
			(table -> slotList[hashValue]).status = DELETED;
		
	}
	
	return NULL;
}
