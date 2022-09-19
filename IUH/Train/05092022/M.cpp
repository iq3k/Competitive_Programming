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
 
const int N = 1e5 + 11;

int tc;
vector<int> sieve[N], f(N), gt(N);
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    for (int i = 2; i < N; ++i) {
    	if (sz(sieve[i]) == 0) {
    		for (int j = i + i; j < N; j += i) {
    			if (j % i == 0) {
    				int cnt = 0, t = j;
    				while (t % i == 0) ++cnt, t /= i;
    				sieve[j].pb(cnt);
    			}
    		}
    	}
    }
    for (int i = 2; i < N; ++i) {
    	int numDiv = 1;
    	for (auto j : sieve[i]) numDiv = numDiv * (j + 1);
    	f[i] = f[i - 1] + max(1LL, numDiv - 1);
    }
    const int M = 1e9 + 7;
    gt[0] = 1;
    gt[1] = 1;
    gt[2] = 1;
    gt[3] = 1;
    for (int i = 4; i < N; ++i) gt[i] = (gt[i - 1] * (i - 2)) % M;
    // for (int i = 1; i <= 10; ++i) cout << f[i] << ' '; cout << '\n';
    // debug(f[N - 1]);
	cin >> tc;
	while (tc--) {
		LL n; cin >> n;		
		cout << (((1LL * f[n] * ((n * (n - 1) / 2) % M)) % M) * gt[n] % M) % M<< '\n';
		// debug(f[n]);
	} 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}