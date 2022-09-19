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
 
const int N = 2e3 + 11;

int n, m, k; 
string s[N];
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n >> m >> k;    
    for (int i = 0; i < n; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0, cnt = 0; j < m; ++j) {
            if (s[i][j] == '.') ++cnt;
            else cnt = 0;
            if (cnt >= k) ++ans;
        }
    for (int i = 0; i < m; ++i)
        for (int j = 0, cnt = 0; j < n; ++j) {
            if (s[j][i] == '.') ++cnt;
            else cnt = 0;
            if (cnt >= k) ++ans;
        }
    cout << ans - (k == 1 ? ans / 2 : 0) << '\n';
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}