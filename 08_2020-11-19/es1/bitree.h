#ifndef BITREE_H
#define BITREE_H
#include "item.h"

// incomplete type representing a binary tree node
typedef struct bit_node *Bit_node;

// constructs a new binary tree node
Bit_node bit_new(Item);

// prints the binary tree in preorder
void bit_preorder(Bit_node);

// prints the binary tree in-order
void bit_inorder(Bit_node);

// prints the binary tree in postorder
void bit_postorder(Bit_node);

// prints the binary tree in a graphic indented way
void bit_printassummary(Bit_node, int);

// converts an array of Items in a binary tree
Bit_node bit_arr2tree(Item[], int, int);

#endif
