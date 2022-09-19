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

int n, k, indeg[N], check[N], flag, tc, vis[N];
vector<int> g[N];
priority_queue<int> heap;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 0; i < k; ++i) {
            int u, v; cin >> u >> v;
            g[u].pb(v);
            ++indeg[v];
            check[u] = check[v] = 1;
        }
        vector<int> ans1, ans2;
        flag = -1;
        for (int i = 1; i <= n; ++i) if (indeg[i] == 0 && check[i] == 1) heap.push(i * flag);
        while (!heap.empty()) {
            int u = heap.top(); heap.pop();
            u *= flag;
            ans1.pb(u);
            for (auto v : g[u]) if (--indeg[v] == 0) heap.push(v * flag);
        }
        reverse(all(ans1));
        for (int i = 1; i <= n; ++i) 
            if (check[i] == 0) {
                while (sz(ans1) && ans1.back() < i) {
                    cout << ans1.back() << ' ';
                    ans1.pop_back();
                }
                cout << i << ' ';
            }
        while (sz(ans1)) {
            cout << ans1.back() << ' ';
            ans1.pop_back();
        }
        cout << '\n';

        for (int i = 1; i <= n; ++i) for (auto j : g[i]) ++indeg[j];
        flag = 1;
        for (int i = 1; i <= n; ++i) if (indeg[i] == 0 && check[i] == 1) heap.push(i * flag);
        while (!heap.empty()) {
            int u = heap.top(); heap.pop();
            ans2.pb(u);
            for (auto v : g[u]) if (--indeg[v] == 0) heap.push(v);
        }
        reverse(all(ans2));
        for (int i = n; i >= 1; --i) 
            if (check[i] == 0) {
                while (sz(ans2) && ans2.back() > i) {
                    cout << ans2.back() << ' ';
                    ans2.pop_back();
                }
                cout << i << ' ';
            }
        while (sz(ans2)) {
            cout << ans2.back() << ' ';
            ans2.pop_back();
        }
        cout << '\n'; 
        for (int i = 1; i <= n; ++i) {
            check[i] = 0;
            indeg[i] = 0;
            g[i].clear();
        } 
    }

    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}