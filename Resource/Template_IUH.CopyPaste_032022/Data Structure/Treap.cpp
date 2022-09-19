struct treap {
	int key, prio, size;
	treap *l, *r;
	treap() {
		key = prio = 0; size = 1;
		l = r = 0;
	}
	treap(int _key, int _prio, treap* _l, treap* _r) {
		key = _key; prio = _prio; size = 1;
		l = _l; r = _r;
		if (l) size += l->size;
		if (r) size += r->size;
	}
};
int seed;
inline int randPrio() {
	seed = (seed * 1001 + 100621) % 999983;
	return seed;
}
inline int size(treap* &t) {
	return t ? t->size : 0;
}
inline int prio(treap* &t) {
	return t ? t->prio : -1;
}
inline void upd(treap* &t) {
	t->size = size(t->l) + size(t->r) + 1;
}
treap* search(treap* &t, int pos) {
	if (pos == size(t->l) + 1) return t;
	if (pos <= size(t->l)) return search(t->l, pos);
	return search(t->r, pos - size(t->l) - 1);
}
inline void rotl(treap* &t) {
	treap* l = t->l; t->l = l->r; l->r = t; t = l;
	upd(t->r); upd(t);
}
inline void rotr(treap* &t) {
	treap* r = t->r; t->r = r->l; r->l = t; t = r;
	upd(t->l); upd(t);
}
inline void balance(treap* &t) {
	if (prio(t->l) > t->prio) rotl(t);
		else if (prio(t->r) > t->prio)
			rotr(t);
}
void insert(treap* &t, int key, int prio, int pos) {
	if (!t) {
		t = new treap(key, prio, 0, 0);
		return;
	}
	t->size++;
	if (pos > size(t))
		insert(t->r, key, prio, pos);
	else if (pos <= size(t->l) + 1)
		insert(t->l, key, prio, pos);
	else insert(t->r, key, prio, pos - size(t->l) - 1);
	balance(t);
}
treap* merge(treap* l, treap* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->prio < r->prio) {
		treap* t = merge(l, r->l);
		return new treap(r->key, r->prio, t, r->r);
	} else {
		treap* t = merge(l->r, r);
		return new treap(l->key, l->prio, l->l, t);
	}
}
void erase(treap* &t, int pos) {
	if (pos == size(t->l) + 1) {
		if (!t->l && !t->r) {
			delete t;
			t = 0;
		} else
			t = merge(t->l, t->r);
		return;
	}
	t->size--;
	if (pos <= size(t->l)) erase(t->l, pos);
		else erase(t->r, pos - size(t->l) - 1);
}

inline void split(treap* t, treap* &l, treap* &r, int pos) {
	insert(t, -1, INF, pos);
	l = t->l; r = t->r;
	delete t;
}

void dump(treap* node) {
	if (node) {
		dump(node->l);
		/* TODO */
		dump(node->r);
	}
}

