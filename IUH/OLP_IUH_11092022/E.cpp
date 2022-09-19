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
 
const int N = 1e6 + 11;
const int M = 1e9 + 7;

LL sieve[N], cntPrime[N], n, k, m;

int binpow(LL base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    int ret = binpow(base, exponent / 2);
    ret = 1LL * ret * ret % m;
    if (exponent % 2) ret = 1LL * ret * base % m;
    return ret;
} 

 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n >> k >> m;
    
    for (int i = 2; i < N; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j < N; j += i) {
                sieve[j] = i;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        int t = i;
        while (t > 1) {
            cntPrime[sieve[t]]++;
            t /= sieve[t];
        }
    }
    for (int i = 2; i <= k; ++i) {
        int t = i;
        while (t > 1) {
            cntPrime[sieve[t]]--;
            t /= sieve[t];
        }
    }
    for (int i = 2; i <= n - k; ++i) {
        int t = i;
        while (t > 1) {
            cntPrime[sieve[t]]--;
            t /= sieve[t];
        }
    }
    int ans = 1;
    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < cntPrime[i]; ++j) ans = (1LL * ans * i) % m;
    }
    
    cout << ans << '\n';

    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}