const int N = 1e5 + 11;
const int K = 20;

int lg[N], st[N][K], n, a[N];

lg[1] = 0; 
for (int i = 2; i < N; ++i) lg[i] = lg[i / 2] + 1;

for (int i = 0; i < n; ++i) st[i][0] = a[i];

for (int j = 1; j < K; ++j) {
    for (int i = 0; i + (1 << j) <= n; ++i) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}
// get min tu l -> r
int j = lg[r - l + 1];
cout << min(st[l][j], st[r - (1 << j) + 1][j]) << '\n';