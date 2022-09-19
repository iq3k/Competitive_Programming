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
    	int n, m; cin >> n >> m;
    	string s;
    	int a[n + 5][m + 5];
    	for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < m; ++j) a[i][j] = (s[j] == '^' ? 1 : 0);    		
    	}
    	if (n == 1 || m == 1) {
    		bool ok = true;
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < m; ++j) ok &= a[i][j] == 0;
    		if (ok) {
    			cout << "Possible\n";
    			for (int i = 0; i < n; ++i) {
    				for (int j = 0; j < m; ++j) 
    					cout << ".";
    				cout << '\n';
    			}
    		} else {
    			cout << "Impossible\n";
    		}
    	} else {
    		bool ok = true;
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < m; ++j) ok &= a[i][j] == 0;
    		cout << "Possible\n";
    		for (int i = 0; i < n; ++i) {
    			for (int j = 0; j < m; ++j) cout << "^";
    			cout << '\n';
    		}
    	}
    }
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}