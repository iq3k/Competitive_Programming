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

int tc, a[N]; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<vector<int>> s3;
        s3.pb({a[1]});
        for (int i = 2; i <= n; ++i) {
            if (a[i] % 2 == a[i - 1] % 2) s3.back().pb(a[i]);
            else s3.pb({a[i]});
        }
        int ans = 0, tot = 0;
        for (auto i : s3) {
            sort(all(i)); 
            for (int j = sz(i) - 1; j >= 0 && j >= sz(i) - k; --j) ans += i[j];
        }
        // tot = 0;
        // for (int i = 1; i <= n; ++i) {
        //     if (i < k) tot += a[i];
        //     else {
        //         tot += a[i];
        //         tot -= a[i - k];
        //         ans = max(ans, tot);
        //     }
        // }
        cout << ans << '\n';
    }
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}