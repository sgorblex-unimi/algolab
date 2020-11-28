#include "../include/bitree.h"
#include <stdlib.h>
#include <string.h>

void bitree_init(BiTree *tree, void (*destroy)(void *data)) {
	// Initialize the binary tree.
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;
	return;
}

void bitree_destroy(BiTree *tree) {
	// Remove all the nodes from the tree.
	bitree_rem_left(tree, NULL);
	// No operations are allowed now, but clear the structure as a precaution.
	memset(tree, 0, sizeof(BiTree));
	return;
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data) {
	BiTreeNode *new_node, **position;
	// Determine where to insert the node
	if (node == NULL) {
		// Allow insertion at the root only in an empty tree.
		if (bitree_size(tree) > 0)
			return -1;
		position = &tree->root;
	} else {
		// Normally allow insertion only at the end of a branch.
		if (bitree_left(node) != NULL)
			return -1;
		position = &node->left;
	}
	// Allocate storage for the node.
	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
		return -1;
	// Insert the node into the tree.
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;
	// Adjust the size of the tree to account for the inserted node.
	tree->size++;
	return 0;
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data) {
	BiTreeNode *new_node, **position;
	// Determine where to insert the node.
	if (node == NULL) {
		// Allow insertion at the root only in an empty tree.
		if (bitree_size(tree) > 0)
			return -1;
		position = &tree->root;
	} else {
		// Normally allow insertion only at the end of a branch.
		if (bitree_right(node) != NULL)
			return -1;
		position = &node->right;
	}
	// Allocate storage for the node.
	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
		return -1;
	// Insert the node into the tree.
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;
	// Adjust the size of the tree to account for the inserted node.
	tree->size++;
	return 0;
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node) {
	BiTreeNode
	    **position;
	// Do not allow removal from an empty tree.
	if (bitree_size(tree) == 0)
		return;
	// Determine where to remove nodes.
	if (node == NULL)
		position = &tree->root;
	else
		position = &node->left;
	// Remove the nodes.
	if (*position != NULL) {
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);
		if (tree->destroy != NULL) {
			// Call a user-defined function to free dynamically allocated data.
			tree->destroy((*position)->data);
		}
		free(*position);
		*position = NULL;
		// Adjust the size of the tree to account for the removed node.
		tree->size--;
	}
	return;
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node) {
	BiTreeNode
	    **position;
	// Do not allow removal from an empty tree.
	if (bitree_size(tree) == 0)
		return;
	// Determine where to remove nodes.
	if (node == NULL)
		position = &tree->root;
	else
		position = &node->right;
	// Remove the nodes.
	if (*position != NULL) {
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);
		if (tree->destroy != NULL) {
			// Call a user-defined function to free dynamically allocated data.
			tree->destroy((*position)->data);
		}
		free(*position);
		*position = NULL;
		// Adjust the size of the tree to account for the removed node.
		tree->size--;
	}
	return;
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data) {
	// Initialize the merged tree.
	bitree_init(merge, left->destroy);
	// Insert the data for the root node of the merged tree.
	if (bitree_ins_left(merge, NULL, data) != 0) {
		bitree_destroy(merge);
		return -1;
	}
	// Merge the two binary trees into a single binary tree.
	bitree_root(merge)->left = bitree_root(left);
	bitree_root(merge)->right = bitree_root(right);
	// Adjust the size of the new binary tree.
	merge->size = merge->size + bitree_size(left) + bitree_size(right);
	// Do not let the original trees access the merged nodes.
	left->root = NULL;
	left->size = 0;
	right->root = NULL;
	right->size = 0;
	return 0;
}

static int inorder(BiTreeNode *node, int (*action)(void *data)) {
	if (bitree_is_eob(node))
		return 0;
	inorder(node->left, action);
	if (action(node->data))
		return -1;
	inorder(node->right, action);
	return 0;
}

int bitree_inorder(BiTree *tree, int (*action)(void *data)) {
	return inorder(tree->root, action);
}

static int preorder(BiTreeNode *node, int (*action)(void *data)) {
	if (bitree_is_eob(node))
		return 0;
	if (action(node->data))
		return -1;
	preorder(node->left, action);
	preorder(node->right, action);
	return 0;
}

int bitree_preorder(BiTree *tree, int (*action)(void *data)) {
	return preorder(tree->root, action);
}

static int postorder(BiTreeNode *node, int (*action)(void *data)) {
	if (bitree_is_eob(node))
		return 0;
	postorder(node->left, action);
	postorder(node->right, action);
	if (action(node->data))
		return -1;
	return 0;
}

int bitree_postorder(BiTree *tree, int (*action)(void *data)) {
	return postorder(tree->root, action);
}

static int fromarr(BiTree *tree, BiTreeNode *node, void **arr, int arrsize, int index) {
	const int leftindex = 2 * index + 1;
	if (leftindex < arrsize && arr[leftindex] != NULL) {
		if (bitree_ins_left(tree, node, arr[leftindex]))
			return -1;
		if (fromarr(tree, node->left, arr, arrsize, leftindex))
			return -1;
	}
	const int rightindex = 2 * index + 2;
	if (rightindex < arrsize && arr[rightindex] != NULL) {
		if (bitree_ins_right(tree, node, arr[rightindex]))
			return -1;
		if (fromarr(tree, node->right, arr, arrsize, rightindex))
			return -1;
	}
	return 0;
}

int bitree_fromarr(BiTree *tree, void **arr, int arrsize) {
	if (bitree_size(tree) > 0 || arrsize < 1)
		return -1;
	if (arr[0] == NULL)
		return 0;
	if (bitree_ins_left(tree, NULL, arr[0]))
		return -1;
	return fromarr(tree, tree->root, arr, arrsize, 0);
}
