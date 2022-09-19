struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    // init(...) { ... }

    int sum(int x, int y) {
        int ret = 0;
        // i = (i & (i + 1)) - 1 build tu 0 -> n - 1
        for (int i = x; i >= 1; i -= i & -i)
            for (int j = y; j >= 1; j -= j & -j)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        // i = i | (i + 1) build tu 0 -> n - 1
        for (int i = x; i <= n; i += i & -i )
            for (int j = y; j <= m; j = j & -j)
                bit[i][j] += delta;
    }
};