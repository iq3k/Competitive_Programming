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


 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    int n; cin >> n;
    vector<pair<LL, LL>> a(n);
    for (auto& [x, y]: a) cin >> x >> y;
	LL x1 = 0, x2 = 0, rem1 = 0, rem2 = 0;
	LL sumV = 0;
// a(n) = a(n)
// t(n) = t(n)
// x(n) = x(n-1) + v(n-1)*t + (a(n)*t(n)^2)/2
// v(n) = v(n-1) + a(n)*t(n) 
	for (int i = 0; i < n; ++i) {
		x1 = (x1) + (2LL * sumV * a[i].se) + (a[i].fi * a[i].se * a[i].se);
		sumV = sumV + a[i].fi * a[i].se;
		// debug(x1, sumV);
	}
	// debug(x1);
	// debug(sumV, x1);
    sort(all(a));
	sumV = 0;
	for (int i = n - 1; i >= 0; --i) {
		x2 = (x2) + (2LL * sumV * a[i].se) + (a[i].fi * a[i].se * a[i].se);
		sumV = sumV + a[i].fi * a[i].se;
		// debug(x2, sumV);
	}
	// debug(x2);
	
	// debug(sumV, x2);
	cout << fixed << setprecision(1) <<	1.0 * abs(x1 / 2 - x2 / 2) << '\n';
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}