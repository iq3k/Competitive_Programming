#include<bits/stdc++.h>
 
using namespace std;
using LL = long long;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(a) int(a.size())
void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
    cout << H << ' ';
    debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
 
const int N = 3e5 + 11;

vector<int> g[N], vis(N);
int n, m;

void dfs(int v) {
    if (v == n) return;
    vis[v] = 1;
    for (auto u : g[v]) if (vis[u] == 0) dfs(u); 
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    } 
    dfs(n - 1); 
    for (int i = 1; i <= n; ++i) if (vis[i]) cout << 'B'; else cout << 'A';
    cout << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}