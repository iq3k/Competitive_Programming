/*-----------------------------------

------------------------------------*/
#include<bits/stdc++.h>
 
using namespace std;
using LL = long long;
#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(a) int(a.size())
void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
    cout << H << ' ';
    debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
 
const int N = 1e3 + 11;

int n, k, a[N]; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> ans(n + 11); 
    for (int K = 1; K <= N; ++K) {
        vector<vector<int>> t;
        int cur = K; 
        for (int i = 0; i < n; ++i, cur += k) if (a[i] != cur) t.pb({a[i] > cur, i, abs(a[i] - cur)});
        if (sz(t) < sz(ans)) {
            ans = t; 
        }
    }
    cout << sz(ans) << '\n';
    for (auto i : ans) 
        cout << (i[0] ? '-' : '+') << ' ' << i[1] + 1 << ' ' << i[2] << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}