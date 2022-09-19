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

#define int LL 

int tc; 

int ok(vector<int>& a) {
    int ret = 0;
    for (int i = 0; i < sz(a); ++i) ret = ret * 10 + a[i];
    return ret;
}

int get(int v) {
    int t = v, ret = 0;
    int n = 0;
    while (t) ++n, t /= 10;
    // debug(n);
    for (int i = 1; i <= n; ++i) {
        for (int bit = 0; bit < (1LL << i); ++bit) {
            vector<int> a(i, 0);
            int t = bit;
            for (int j = 0; j < i; ++j, t /= 2) if (t % 2) a[j] = 7; else a[j] = 4;
            if (ok(a) <= v) ++ret, debug(ok(a));
        }
    }
    return ret;
}

void solve() {
    int l, r; cin >> l >> r;
    cout << get(r) - get(l - 1) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> tc;
    while (tc--) {
        solve();
    }
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}