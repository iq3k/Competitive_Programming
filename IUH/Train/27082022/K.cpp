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
 
const int N = 6e4 + 11;

int dp[N], k, q, a[N];
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    
	cin >> k >> q; 
	for (int i = 1; i <= q; ++i) cin >> a[i];
	const int INF = 1e9;
	for (int i = 1; i < N; ++i) dp[i] = INF;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= q; ++j) {
			if (a[j] <= i) dp[i] = min(dp[i], dp[i - a[j]] + 1);
		}
	}
	for (int i = N - 1, cnt = 0; i >= 1; --i)
		if (dp[i] == INF) ++cnt, dp[i] = cnt; 
		else cnt = 0, dp[i] = 0;
	for (int i = 0; i < k; ++i) {
		int t; cin >> t;
		cout << dp[t] << '\n';
	}
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}