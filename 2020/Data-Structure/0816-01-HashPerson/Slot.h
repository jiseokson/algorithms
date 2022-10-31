#ifndef _SLOT_H_
#define _SLOT_H_

#include "Person.h"

typedef int      Key;
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _Slot {
	      Key        key;
	      Value      value;
	enum  SlotStatus status;
} Slot;

#endif
