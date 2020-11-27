#ifndef BISTREE_H
#define BISTREE_H
#include "bitree.h"

// Interface for creating and interacting with binary search trees.

// This interface is based on the one contained in Kyle Loudon's "Mastering algorithms with C", published by O'Reilly in 1999. I adapted it to work with generic binary search trees, while the original used AVLs.

typedef BiTree BisTree;

// Initializes tree. It must be called before the tree can be used in any other operation. The function pointer compare specifies a user-defined function to compare elements. This function's return value should be positive if key1 > key2, 0 if key1 = key2, and negative if key1 < key2. The destroy function pointer provides a way to free dynamically allocated data when bistree_destroy is called.
void bistree_init(BisTree *tree, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data));

// Destroys tree. No other operations are permitted after calling bistree_destroy unless bistree_init is called again. If the destroy function pointer was set to not NULL when initializing the tree, then it will be used to destroy all data related to tree's nodes.
void bistree_destroy(BisTree *tree);

// Inserts a node containing data in tree. It uses the binary search trees criteria to determine where to put the new node. Returns 0 if inserting the node is successful, -1 otherwise. It is the responsibility of the caller to manage the storage associated with data.
int bistree_insert(BisTree *tree, const void *data);

// [ NOT IMPLEMENTED YET ]
// Removes a node matching data from tree. If the destroy function pointer was set to not NULL when initializing the tree, then it will be used to destroy the data related to the removed node.
int bistree_remove(BisTree *tree, const void *data);

// Determines whether a node matches data's pointed data in tree. If a match is found, after the operation data points to the matching data in the binary search tree upon return.
int bistree_lookup(BisTree *tree, void **data);

// Evaluates to the number of nodes in tree.
#define bistree_size(tree) ((tree)->size)

#endif
