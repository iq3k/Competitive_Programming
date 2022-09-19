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
 
const int N = 1e4 + 11;

LL n, idx[N], f[N];
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n;
    vector<vector<int>> a(n, vector<int> (3, 0)); 
    for (int i = 0; i < n; ++i) cin >> a[i][1] >> a[i][0], a[i][2] = i;
    sort(all(a));
    for (int i = 0; i < n; ++i) idx[a[i][2]] = i;
    f[0] = a[0][1];
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        f[i] = f[i - 1] + a[i][1];
        if (f[i] > a[i][0]) ok = false;
    }
    if (!ok) {
        cout << "*\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = idx[i] - 1; j >= 0; --j) {
            if (f[j] + a[j + 1][1] <= a[j][0]) {
                idx[a[j + 1][2]]--;
                idx[a[j][2]]++;
                f[j] += a[j + 1][1];
                f[j + 1] -= a[j + 1][1];
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << idx[i] + 1 << ' ';
    cout << '\n';
    
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}