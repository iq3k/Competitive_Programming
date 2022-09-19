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
#define int LL
const int N = 5e5 + 11;

LL fen1[N], fen2[N], n, q, a[N];

 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
	cin >> n >> q; 
	for (int i = 1; i <= n; ++i) cin >> a[i];    
	for (int i = 0; i < q; ++i) {
		int nQuery; cin >> nQuery;
		map<LL, LL> ma;
		for (int j = 0; j < nQuery; ++j) {
			int t0, t1, t2; cin >> t0 >> t1 >> t2;
			ma[t0] += t2;
			ma[t1 + 1] -= t2;
		}	
		LL tot = 0, valueBef = 0, indexBef = 0;
		for (auto [k, v] : ma) 
			tot += valueBef * (k - indexBef), valueBef += v, indexBef = k;
		LL parLeft = (tot + 1) / 2, parRight = (tot + 2) / 2, ansLeft = -1, ansRight = -1;
		tot = 0, valueBef = 0, indexBef = 0;
		for (auto [k, v] : ma) {
			LL t = valueBef * (k - indexBef);
			if (parLeft > tot && parLeft <= tot + t) ansLeft = indexBef + (parLeft - tot - 1) / valueBef;
			if (parRight > tot && parRight <= tot + t) ansRight = indexBef + (parRight - tot - 1) / valueBef;
			tot += valueBef * (k - indexBef), valueBef += v, indexBef = k;
		}
		// debug(ansLeft, ansRight);
		cout << fixed << setprecision(1) << 1.0 * (a[ansLeft] + a[ansRight]) / 2 << '\n';
	}
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}