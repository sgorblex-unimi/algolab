#ifndef BITREE_H
#define BITREE_H
#include "item.h"

typedef struct bit_node *Bit_node;

Bit_node bit_new(Item);
void bit_preorder(Bit_node);
void bit_inorder(Bit_node);
void bit_postorder(Bit_node);

void bit_printassummary(Bit_node, int);

Bit_node bit_arr2tree(Item[], int, int);

#endif
