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

int tc; 
 
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
    	int n, k; cin >> n >> k;
    	int a[n];
    	for (int i = 0; i < n; ++i) cin >> a[i];
    	if (k + k < n) {
    		cout << "NO\n";
    	} else {
    		map<int, int> ma;
    		bool ok = true;
    		for (int i = 0; i < n; ++i) if (++ma[a[i]] > 2) ok = false;
    		cout << (ok ? "YES\n" : "NO\n");
    	}
    }
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}