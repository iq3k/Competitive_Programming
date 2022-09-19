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

int n; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n;
    map<string, int> ma;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        string ok = "";
        ok.pb(s[0]);
        for (int i = 1; i < sz(s); ++i) {
            if (s[i] != s[i - 1]) ok.pb(s[i]);
        }
        ++ma[ok];
    }
    LL ans = 0;
    for (auto [k, v] : ma) ans += 1LL * v * (v - 1) / 2;
    cout << ans << '\n'; 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}