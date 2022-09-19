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
 
const LL N = 1e18 + 11;

int n; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n;
    vector<vector<LL>> a(n, vector<LL>(3));
    for (int i = 0; i < n; ++i) cin >> a[i][0];
    string s; cin >> s;
	for (int i = 0; i < n; ++i) a[i][1] = s[i] - '0';
	cin >> s;
	for (int i = 0; i < n; ++i) a[i][2] = s[i] - '0';
    sort(all(a));

	a.pb({N, 0, 0});

	LL ans = 1e18, sum = 0, Sum = 0;
	for (int i = 0; i <= n; ++i) if (a[i][1] == 1) sum += a[i][0];
	Sum = sum;
	// debug(sum); cout << '\n';
	for (int i = 0; i <= n; ++i) {
		LL t = 0;
		sum = Sum;
		for (int j = n; j >= i + 1; --j) {
			if (a[j][1] == 1) sum -= a[j][0], t += sum;
		}
		// debug(t);

		for (int j = i; j >= 0; --j) {
			if (a[j][1] == 1 && a[j][2] == 0) sum -= a[j][0], t += sum;
		}
		// debug(t);

		for (int j = 0; j <= n; ++j) {
			if (a[j][1] == 0 && a[j][2] == 1) sum += a[j][0], t += sum;
		}
		// debug(t);

		for (int j = i + 1; j <= n; ++j) {
			if (a[j][1] == 1 && a[j][2] == 1) sum += a[j][0], t += sum;
		}
		// debug(t);
		// debug("-------------------------------");
		ans = min(ans, t);
	}

 	cout << ans << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}