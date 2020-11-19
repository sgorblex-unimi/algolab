#ifndef ITEM_H
#define ITEM_H

#ifndef CUSTOM_TYPE
#define CUSTOM_TYPE int
#endif

typedef struct item *Item;

struct item {
	CUSTOM_TYPE val;
};

#endif
