#ifndef BITREE_H
#define BITREE_H
#include <stdlib.h>

// Interface for creating and interacting with binary trees.

// This interface is based on the one contained in Kyle Loudon's "Mastering algorithms with C", published by O'Reilly in 1999. I added functions to perform ordered visit and conversion from an array.

typedef struct BiTreeNode_ {
	void *data;
	struct BiTreeNode_ *left;
	struct BiTreeNode_ *right;
} BiTreeNode;

typedef struct BiTree_ {
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	BiTreeNode *root;
} BiTree;

// Initializes tree. It must be called before the tree can be used in any other operation. The destroy function pointer provides a way to free dynamically allocated data when bistree_destroy is called.
void bitree_init(BiTree *tree, void (*destroy)(void *data));

// Destroys tree. No other operations are permitted after calling bistree_destroy unless bistree_init is called again. If the destroy function pointer was set to not NULL when initializing the tree, then it will be used to destroy all data related to tree's nodes.
void bitree_destroy(BiTree *tree);

//  Inserts a node containing data as the left child of node in tree or as the root if node is NULL. Returns 0 if inserting the node is successful, -1 otherwise. It is the responsibility of the caller to manage the storage associated with data.
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data);

//  Inserts a node containing data as the right child of node in tree or as the root if node is NULL. Returns 0 if inserting the node is successful, -1 otherwise. It is the responsibility of the caller to manage the storage associated with data.
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data);

// Removes the subtree of tree rooted at the left child of node. If node is NULL, all nodes in the tree are removed. If the destroy function pointer was set to not NULL when initializing the tree, then it will be used to destroy all data related to the subtree's nodes.
void bitree_rem_left(BiTree *tree, BiTreeNode *node);

// Removes the subtree of tree rooted at the right child of node. If node is NULL, all nodes in the tree are removed. If the destroy function pointer was set to not NULL when initializing the tree, then it will be used to destroy all data related to the subtree's nodes.
void bitree_rem_right(BiTree *tree, BiTreeNode *node);

// Merges left and right as subtrees of merge. After the operation merge's root node will contain data and left and right will be destroyed.
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

// Executes the operation given by the function pointer action on the data of each of the nodes of tree, with the in-oder pattern. If action returns a value different from 0 at any point, the visit exits immediately with the return value -1, otherwise it will be 0.
int bitree_inorder(BiTree *tree, int (*action)(void *data));

// Executes the operation given by the function pointer action on the data of each of the nodes of tree, with the preorder pattern. If action returns a value different from 0 at any point, the visit exits immediately with the return value -1, otherwise it will be 0.
int bitree_preorder(BiTree *tree, int (*action)(void *data));

// Executes the operation given by the function pointer action on the data of each of the nodes of tree, with the postorder pattern. If action returns a value different from 0 at any point, the visit exits immediately with the return value -1, otherwise it will be 0.
int bitree_postorder(BiTree *tree, int (*action)(void *data));

// Constructs tree (already initialized and empty) so that its nodes contain the values from the array arr, of size len. In the result the node containing the entry of array index i will have its children containing the data of array index 2*i+1 (left) and 2*i+2 (right). Returns -1 if an error occurred, 0 otherwise.
int bitree_fromarr(BiTree *tree, void **arr, int len);

// Evaluates to the number of nodes in tree.
#define bitree_size(tree) ((tree)->size)

// Evaluates to tree's root node.
#define bitree_root(tree) ((tree)->root)

// Returns 1 if node marks the end of a branch, 0 otherwise.
#define bitree_is_eob(node) ((node) == NULL)

// Returns 1 if node is a leaf node, 0 otherwise.
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)

// Evaluates to the data stored in node.
#define bitree_data(node) ((node)->data)

// Evaluates to a pointer to the left child of node.
#define bitree_left(node) ((node)->left)

// Evaluates to a pointer to the right child of node.
#define bitree_right(node) ((node)->right)

#endif
