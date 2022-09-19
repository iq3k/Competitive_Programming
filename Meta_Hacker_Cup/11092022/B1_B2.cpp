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
 
const int N = 5e5 + 11;
const LL M = 1e9 + 7;

LL tc, x[N], y[N], xQ[N], yQ[N], sumX, sumY, sumXY, n, q;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    // #ifdef ONLINEJUDGE
        freopen("input.txt", "r",stdin);
        freopen("output.txt", "w",stdout);
    // #endif
 
    cin >> tc;
    for (int T = 1; T <= tc; ++T) {
        cout << "Case #" << T << ": ";
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        sumX = 0, sumY = 0, sumXY = 0;
        LL ans = 0;
        for (int i = 0; i < n; ++i) sumX = (sumX + x[i]) % M, sumY = (sumY + y[i]) % M, sumXY = (sumXY + (x[i] * x[i]) % M + (y[i] * y[i]) % M) % M;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            LL x1, y1; cin >> x1 >> y1;
            ans = (ans + (((n * (((x1 * x1) % M + (y1 * y1) % M))) % M - ((2 * x1 * sumX) % M) - ((2 * y1 * sumY) % M) + sumXY) + M * M) % M) % M;
            // debug(ans);
        }
        cout << ans << '\n';
    } 
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}