#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *Key;

typedef struct item {
	Key key;
	int value;
} * Item;

typedef struct bistNode {
	Item item;
	struct bistNode *l, *r;
} * BistNode;

int cmp(Key a, Key b) { return strcmp(a, b); }

Key key(Item i) { return i->key; }

BistNode bist_newNode(Item i) {
	BistNode t = malloc(sizeof(struct bistNode));
	t->item = i;
	t->l = NULL;
	t->r = NULL;
	return t;
}

void bit_destroy(BistNode bt) {
	if (bt != NULL) {
		bit_destroy(bt->l);
		bit_destroy(bt->r);
		free(bt);
	}
};

Item bist_search(BistNode p, Key k) {
	if (!p)
		return NULL;
	int res = cmp(k, key(p->item));
	if (res == 0)
		return p->item;
	if (res < 0)
		return bist_search(p->l, k);
	return bist_search(p->r, k);
}

Item bist_search_it(BistNode p, Key k) {
	for (int res; p && (res = cmp(k, key(p->item))); p = res < 0 ? p->l : p->r)
		;
	return p ? p->item : NULL;
}

int bist_searchparent(BistNode r, Key k, BistNode *parent, BistNode *p) {
	int res;
	*parent = NULL;
	*p = r;
	if (!r)
		return -1;
	while (*p && (res = cmp(k, key((*p)->item))) != 0) {
		*parent = *p;
		*p = res < 0 ? (*p)->l : (*p)->r;
	}
	if (*p == NULL)
		return -1;
	return 0;
}

void bist_insert(BistNode *r, Item item) {
	BistNode parent, q = *r, new = bist_newNode(item);
	Key k = key(item);
	if (q == NULL) {
		*r = new;
		return;
	}
	if (bist_searchparent(*r, k, &parent, &q) == 0) {
		return;
	}
	if (cmp(k, key(parent->item)) < 0)
		parent->l = new;
	else
		parent->r = new;
}

int bist_delete(BistNode *r, Key k) {
	BistNode x, xp, s = NULL;
	if (bist_searchparent(*r, k, &xp, &x) == -1)
		return -1;
	if (x->l == NULL && x->r == NULL)
		s = NULL;
	else if (x->l == NULL || x->r == NULL)
		s = x->l != NULL ? x->l : x->r;
	else {
		BistNode sp = x;
		s = x->l;
		while (s->r) {
			sp = s;
			s = s->r;
		}
		s->r = x->r;
		if (sp->r == s) {
			sp->r = s->l;
			s->l = x->l;
		}
	}
	if (x == *r)
		*r = s;
	else if (xp->l == x)
		xp->l = s;
	else
		xp->r = s;
	bit_destroy(x);
	return 0;
}

Item bist_search2(BistNode r, Key k) {
	BistNode parent = NULL, p = NULL;
	if (bist_searchparent(r, k, &parent, &p) == 0)
		return p->item;
	else
		return NULL;
}
