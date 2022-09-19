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
 
const int N = 1e5 + 11;

vector<int> g[N];
int nVertex, nDistance, maxDist[N], vis[N];
priority_queue<int, vector<int>, greater<int>> heap;

void dfs(int u, int k) {
    if (maxDist[u] >= k) return;
    maxDist[u] = k;
    for (auto v : g[u]) {
        heap.push(v);
        if (maxDist[v] < k - 1) {
            dfs(v, k - 1);
        }
    }
    return;
}

 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> nVertex >> nDistance;    
    for (int i = 0; i < nVertex - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    heap.push(1);
    while (!heap.empty()) {
        int vertex = heap.top();
        heap.pop();
        if (vis[vertex] == 0) {
            cout << vertex << ' ';
            dfs(vertex, nDistance);
            vis[vertex] = 1;
        }
    }

    cout << '\n';
     
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}