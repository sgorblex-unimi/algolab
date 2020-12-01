#include "../include/bistree.h"
#include <stdlib.h>
#include <string.h>

void bistree_init(BisTree *tree, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data)) {
	// Initialize the tree.
	bitree_init(tree, destroy);
	tree->compare = compare;
	return;
}

void bistree_destroy(BisTree *tree) {
	// Destroy all nodes in the tree.
	bitree_destroy(tree);
	// No operations are allowed now, but clear the structure as a precaution.
	return;
}

static int lookup(BisTree *tree, BiTreeNode *node, void **data) {
	int cmpval, retval;
	if (bitree_is_eob(node)) {
		// Return that the data was not found.
		return -1;
	}
	cmpval = tree->compare(*data, bitree_data(node));
	if (cmpval < 0) {
		// Move to the left.
		retval = lookup(tree, bitree_left(node), data);
	} else if (cmpval > 0) {
		// Move to the right.
		retval = lookup(tree, bitree_right(node), data);
	} else {
		// Pass back the data from the tree.
		*data = bitree_data(node);
		retval = 0;
	}
	return retval;
}

int bistree_lookup(BisTree *tree, void **data) {
	return lookup(tree, bitree_root(tree), data);
}

static int insert(BisTree *tree, BiTreeNode *node, const void *data) {
	int cmpval, retval;
	// Insert the data into the tree.
	if (bitree_is_eob(node)) {
		// Handle insertion into an empty tree.
		return bitree_ins_left(tree, node, data);
	} else {
		// Handle insertion into a tree that is not empty.
		cmpval = tree->compare(data, bitree_data(node));
		if (cmpval < 0) {
			// Move to the left.
			if (bitree_is_eob(bitree_left(node))) {
				if (bitree_ins_left(tree, node, data) != 0)
					return -1;
			} else {
				if ((retval = insert(tree, bitree_left(node), data)) != 0) {
					return retval;
				}
			}
		} else {
			// Move to the right.
			if (bitree_is_eob(bitree_right(node))) {
				if (bitree_ins_right(tree, node, data) != 0)
					return -1;
			} else {
				if ((retval = insert(tree, bitree_right(node), data)) != 0) {
					return retval;
				}
			}
		}
	}
	return 0;
}

int bistree_insert(BisTree *tree, const void *data) {
	return insert(tree, bitree_root(tree), data);
}

int bistree_remove(BisTree *tree, const void *data) {
	BiTreeNode *node = bitree_root(tree), *parent = NULL;
	int cmpval;
	// Look for a node with the specified data and its parent.
	while (!bitree_is_eob(node) && (cmpval = tree->compare(data, bitree_data(node)))) {
		parent = node;
		if (cmpval < 0)
			node = bitree_left(node);
		else
			node = bitree_right(node);
	}
	// Case node not found
	if (bitree_is_eob(node))
		return -1;
	// Case node found
	tree->size--;
	if (bitree_is_eob(bitree_left(node))) {
		// No left child: substitute node with its right child
		if (!bitree_is_eob(parent)) {
			cmpval = tree->compare(bitree_data(node), bitree_data(parent));
			if (cmpval < 0)
				// Node is a left child
				bitree_left(parent) = bitree_right(node);
			else
				// Node is a right child
				bitree_right(parent) = bitree_right(node);
		} else
			// Node is the root
			tree->root = bitree_right(bitree_root(tree));
		if (tree->destroy != NULL) {
			// Call a user-defined function to free dynamically allocated data.
			tree->destroy((node)->data);
		}
		free(node);
	} else if (bitree_is_eob(bitree_right(node))) {
		// No right child: substitute node with its left child
		if (!bitree_is_eob(parent)) {
			cmpval = tree->compare(bitree_data(node), bitree_data(parent));
			if (cmpval < 0)
				// Node is a left child
				bitree_left(parent) = bitree_left(node);
			else
				// Node is a right child
				bitree_right(parent) = bitree_left(node);
		} else
			// Node is the root
			tree->root = bitree_left(bitree_root(tree));
		if (tree->destroy != NULL) {
			// Call a user-defined function to free dynamically allocated data.
			tree->destroy((node)->data);
		}
		free(node);
	} else {
		// Has both children: substitute it with the greatest element in its left subtree
		BiTreeNode *greatestParent = node, *greatest = bitree_left(node);
		// Find greatest
		while (!bitree_is_eob(bitree_right(greatest))) {
			greatestParent = greatest;
			greatest = bitree_right(greatest);
		}
		if (tree->destroy != NULL) {
			// Call a user-defined function to free dynamically allocated data.
			tree->destroy((node)->data);
		}
		// Substitute the data
		bitree_data(node) = bitree_data(greatest);
		if (greatestParent == node)
			// Greatest is the left child of node
			bitree_left(node) = bitree_left(greatest);
		else
			// Greatest is a right child
			bitree_right(greatestParent) = bitree_left(greatest);
		free(greatest);
	}
	return 0;
}
