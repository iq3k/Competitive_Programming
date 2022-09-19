struct Node {
    int lazy;
    int val;
} node[N * 4];

void down(int id) {
    int t = node[id].lazy;
    node[id * 2].lazy += t;
    node[id * 2 + 1].lazy += t;

    node[id * 2].val += t;
    node[id * 2 + 1].val += t;

    node[id].lazy = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        node[id].val = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    node[id].val = max(node[id * 2].val, node[id * 2 + 1].val);
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return;
    }
    if (u <= l && r <= v) {
        node[id].val += val;
        node[id].lazy += val;
        return;
    }
    int m = (l + r) >> 1;
    down(id);
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    node[id].val = max(node[id * 2].val, node[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -1e9;
    }
    if (u <= l && r <= v) {
        return node[id].val;   
    }
    int m = (l + r) >> 1;
    down(id);
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}
