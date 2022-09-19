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
 
const int N = 111, M = 5555, MOD = 1e9 + 7;

int n, m, k, a[N][N];

vector<vector<int>> binpow(int& n, int& m, int k) {
	if (k == 1) {
		vector<vector<int>> ret(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) ret[i][j] = a[i][j];
		return ret;	
	}
	auto ret = binpow(n, m, k / 2);
	vector<vector<int>> t(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				t[i][j] = (t[i][j] + (1LL * ret[i][k] * ret[k][j]) % MOD) % MOD;
			}
		}
	}
	if (k % 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ret[i][j] = 0;
				for (int k = 0; k < n; ++k) {
					ret[i][j] = (ret[i][j] + (1LL * t[i][k] * a[k][j]) % MOD) % MOD;
				}
			}
		}
		return ret;
	}

	return t;
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int t1, t2; cin >> t1 >> t2;
		--t1, --t2;
		a[t1][t2] = 1; a[t2][t1] = 1;
	} 
	auto ans = binpow(n, m, k);
	cout << ans[0][0] << '\n';

    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}