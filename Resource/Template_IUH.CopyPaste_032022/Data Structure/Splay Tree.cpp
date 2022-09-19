template<typename T> struct Node {
	Node<T> *p, *ch[2];
	T value;
	int size;
	Node() {
		SET(value, 0);
		p = ch[0] = ch[1] = NULL;
		size = 1;
	}
	Node(T v) {
		value = v;
		p = ch[0] = ch[1] = NULL;
		size = 1;
	}
};
template<typename T> inline int getSize(Node<T> *node) {
	return (node ? node->size : 0);
}
template<typename T> struct SplayTree {
	Node<T> *root;
	SplayTree() {
		root = NULL;
	}
	void dig(Node<T> *node) {
		if (node) {
			dig(node->ch[0]);
			cout << node->value << " ";
			dig(node->ch[1]);
		}
	}
	void dump(Node<T> *node = NULL) {
		Node<T> *w = (node ? node : root);
		dig(w);
		cout << endl;
	}
	void rotate(Node<T> *node, int b) {
		Node<T> *c = node->ch[b], *cc = (c ? c->ch[1 - b] : NULL);
		if (!c) return;

		Node<T> *dad = node->p;
		if (!dad) {
			root = c;
		} else {
			dad->ch[0] == node ? dad->ch[0] = c : dad->ch[1] = c;
		}

		node->size += getSize(cc) - getSize(c);
		c->size += getSize(node) - getSize(cc);

		c->p = dad;
		node->p = c;
		c->ch[1 - b] = node;
		node->ch[b] = cc;
		if (cc) cc->p = node;
	}
	void splay(Node<T> *node) {
		while (node->p != NULL) {
			Node<T> *dad = node->p, *gra = (dad ? dad->p : NULL);
			int a = (node == dad->ch[1]);
			if (!gra) {
				rotate(dad, a);
			} else {
				int b = (dad == gra->ch[1]);
				if (a == b) {
					rotate(gra, a);
					rotate(dad, a);
				} else {
					rotate(dad, a);
					rotate(gra, b);
				}
			}
		}
		root = node;
	}
	Node<T> *find(int index, Node<T> *where = NULL) {
		Node<T> *w = (where ? where : root);
		if (index > getSize(w)) {
			return NULL;
		}

		int leftSize = getSize(w->ch[0]);
		if (index <= leftSize) {
			return find(index, w->ch[0]);
		}
		index -= leftSize + 1;
		return (index ? find(index, w->ch[1]) : w);
	}
	void insert(T value, int index, Node<T> *where = NULL) {
		Node<T> *w = (where ? where : root);
		Node<T> *newNode = new Node<T>(value);
		if (index > getSize(w)) {
			if (root == NULL){
				root = newNode;
				return;
			}

			Node<T> *pos = root;
			for (; pos->ch[1] != NULL; pos = pos->ch[1]);
			newNode->p = pos;
			for (Node<T> *x = pos; x != NULL; x->size++, x = x->p);
			splay(pos->ch[1] = newNode);
			return;
		}

		Node<T> *pos = find(index, w);
		if (!pos->ch[0]) {
			newNode->p = pos;
			for (Node<T> *x = pos; x != NULL; x->size++, x = x->p);
			splay(pos->ch[0] = newNode);
		} else {
			for (pos = pos->ch[0]; pos->ch[1] != NULL; pos = pos->ch[1]);
			newNode->p = pos;
			for (Node<T> *x = pos; x != NULL; x->size++, x = x->p);
			splay(pos->ch[1] = newNode);
		}
	}
	void erase(Node<T> *node) {
		int v[2] = {node->ch[0] != NULL, node->ch[1] != NULL};
		Node<T> *dad = node->p;
		if (!v[0] && !v[1]){
			if (dad){
				if (dad->ch[0] == node) {
					dad->ch[0] = NULL;
				} else {
					dad->ch[1] = NULL;
				}
				for (Node<T> *x = dad; x != NULL; x->size--, x = x->p);
				splay(dad);
			} else {
				root = NULL;
			}
			delete node;
			return;
		}
		Rep(i, 2) {
			if (!v[i]) continue;
			Node<T> *pos = node->ch[i], *uNode;
			for (; pos->ch[1 - i] != NULL; pos = pos->ch[1 - i]);
			node->value = pos->value;
			if (pos == node->ch[i]){
				node->ch[i] = pos->ch[i];
				uNode = node;
			} else {
				uNode = pos->p;
				uNode->ch[1 - i] = pos->ch[i];
			}
			if (pos->ch[i]) (pos->ch[i])->p = uNode;
			delete pos;
			for (pos = uNode; pos != NULL; pos->size--, pos = pos->p);
			if (dad) splay(dad);
			break;
		}
	}
};

