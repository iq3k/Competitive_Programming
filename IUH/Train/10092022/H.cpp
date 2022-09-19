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
 
const int N = 5e3 + 11;

int par[N], a[N][N], n;
priority_queue<pair<int, pair<int, int>>> heap;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

bool merge(int x, int y) {
    if ((x = root(x)) == (y = root(y))) {
        return true;
    }
    if (par[y] < par[x]) {
        swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
    return false;
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
    
    cin >> n; 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) if (i % 2 != j % 2) heap.push({-a[i][j], {i, j}});
    }
    for (int i = 1; i <= n; ++i) par[i] = -1;
    LL ans = 0; 
    while (!heap.empty()) {
        auto v = heap.top(); heap.pop();
        if (merge(v.se.fi, v.se.se));
        else ans += -v.fi;
    } 

    cout << ans << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}