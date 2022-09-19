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
 
const int N = 1e5 + 11;

LL n, S, a[N], b[N], ans1, ans2, l, r, m; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
   	cin >> n >> S;
   	for (int i = 1; i <= n; ++i) cin >> a[i];
	l = 0, r = n;
	while (l <= r) {
		m = (l + r) >> 1;
		for (int i = 1; i <= n; ++i) b[i] = a[i] + m * i;
		sort(b + 1, b + n + 1);
		LL tot = 0, cnt = 0;
		for (int i = 1; i <= n && cnt != m; ++i)
			if (tot + b[i] <= S) tot += b[i], ++cnt;
		if (cnt >= m) ans1 = m, ans2 = tot, l = m + 1;
		else r = m - 1;
	}

	cout << ans1 << ' ' << ans2 << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}