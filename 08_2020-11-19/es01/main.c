#include "bitree.h"
#include "item.h"
#include <debug.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRLEN 15

Item *randomArr(int size) {
	Item *a = malloc(size * sizeof(Item));
	for (int i = 0; i < size; i++) {
		a[i]->val = rand() % 1000;
	}
	return a;
}

Item newItem(int v) {
	Item res = malloc(sizeof(Item));
	res->val = v;
	return res;
}

int main() {
	srand(time(NULL));
	Item *a = malloc(ARRLEN * sizeof(Item));
	// Item *a= randomArr(ARRLEN);
	a[0] = newItem(3);
	a[1] = newItem(1);
	a[2] = newItem(2);
	a[3] = newItem(1);
	a[4] = newItem(2);
	a[5] = newItem(1);
	a[6] = newItem(2);
	a[7] = newItem(1);
	a[8] = NULL;
	a[9] = NULL;
	a[10] = NULL;
	a[11] = newItem(1);
	a[12] = newItem(2);
	a[13] = newItem(1);
	a[14] = newItem(2);
	Bit_node t = bit_arr2tree(a, ARRLEN, 0);
	bit_printassummary(t, 0);
	bit_preorder(t);
	printf("\n");
	bit_inorder(t);
	printf("\n");
	bit_postorder(t);
	printf("\n");
	return 0;
}

/*
 * a[00]=newItem(3);
 * a[01]=newItem(1);
 * a[02]=newItem(2);
 * a[03]=newItem(1);
 * a[04]=newItem(2);
 * a[05]=newItem(1);
 * a[06]=newItem(2);
 * a[7]=NULL;
 * a[8]=newItem(2);
 * a[9]=NULL;
 * a[10]=NULL;
 * a[11]=newItem(1);
 * a[12]=newItem(2);
 * a[13]=newItem(1);
 * a[14]=newItem(2);
 */

/*
 * 3 (0)
 * ├── 1 (1)
 * │   ├── 1 (3)
 * │   │   ├── NOPE (7)
 * │   │   └── 2 (8)
 * │   └── 2 (4)
 * └── 2 (2)
 *     ├── 1 (5)
 *     │   ├── 1 (11)
 *     │   └── 2 (12)
 *     └── 2 (6)
 *         ├── 1 (13)
 *         └── 2 (14)
 */
