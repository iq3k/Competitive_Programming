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

#define ll LL

const int base = 1e9 + 3;
const ll MOD = 1000000007;
const ll maxn = 1e6 + 11;
 

ll POW[maxn], hashT[maxn], tc, n, k;
vector<LL> a(maxn), b(maxn), c(maxn); 
// int a[N], b[N], c[N];


ll getHashT(int i,int j) {
    return (1LL * hashT[j] - 1LL * hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

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
        cin >> n >> k;
        // vector<LL> a(n), b(n), c;
        // for (auto& i : a) cin >> i;
        // for (auto& i : b) cin >> i;
        // for (auto i : a) c.pb(i);
        // for (auto i : a) c.pb(i);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        for (int i = 0; i < n; ++i) c[i] = a[i];
        for (int i = n; i < 2 * n; ++i) c[i] = a[i - n];
        
        POW[0] = 1;

        // Precalculate base^i
        for (int i = 1; i <= 2 * n; i++)
            POW[i] = (1LL * POW[i - 1] * base) % MOD;

        // Calculate hash value of T[1..i]
        for (int i = 1; i <= 2 * n; i++)
            hashT[i] = (1LL * hashT[i - 1] * base + c[i - 1]) % MOD;

        // Calculate hash value of P
        ll hashP=0;
        for (int i = 1; i <= n; i++)
            hashP = (1LL * hashP * base + b[i - 1]) % MOD;

        bool ok = false;
        // Finding substrings of T equal to string P
        // debug(hashP);
        // for (int i = 1; i <= 2 * n; ++i) cout << hashT[i] << ' '; cout << '\n';
        // return cout << "ahhaha", 0;
        int min_idx = 1e9, max_idx = -1;
        for (int i = 1; i <= n; i++)
            if (hashP == getHashT(i, i + n - 1)) ok = true, min_idx = min(min_idx, i), max_idx = max(max_idx, i);

        --min_idx, --max_idx;
        // return debug(ok), 0;
        if (ok)
            if (n == 2) 
                if (a[0] == a[1]) {
                    cout << "YES";
                }
                else if (min_idx == 0) {
                    if (k % 2 == 0) cout << "YES";
                    else cout << "NO";
                } else {
                    if (k % 2 == 1) cout << "YES";
                    else cout << "NO";
                } 
            else if ((max_idx && k) || (min_idx == 0 && k != 1)) cout << "YES";
            else cout << "NO";
        else cout << "NO";
        cout << '\n';
    }    
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}