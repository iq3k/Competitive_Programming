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
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> tc;
    while (tc--) {
    	int p, q; cin >> p >> q;
        int gcd = __gcd(p, q);
        p /= gcd;
        q /= gcd;
        int S = p + 2 * q;
        int sqS = sqrt(S);
        // debug(S, sqS);
    	if (sqS * sqS == S) {
            int delta = (sqS * sqS) - (4 * q);
            int sqdelta = sqrt(delta);
            int x1 = (sqS + sqdelta) / 2;
            int x2 = (sqS - sqdelta) / 2;
            // debug(delta, sqdelta);
            if (sqdelta * sqdelta == delta) {
                cout << x1 << ' ' << x2 << '\n';
            }
            else cout << "0 0\n";
        } else cout << "0 0\n";
    }


 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}