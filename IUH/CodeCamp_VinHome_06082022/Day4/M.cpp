/*-----------------------------------

------------------------------------*/
#include<bits/stdc++.h>
 
using namespace std;
using LL = long long;
#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(a) int(a.size())
void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
    cout << H << ' ';
    debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
 
const int N = 1e2 + 11;

int n, a[N], suma, sumb; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n - 1; i >= 0; --i) a[i] == 200 ? sumb += 200 : suma += 100; 
    if ((sumb / 200 % 2 && suma >= 200 && suma % 200 == 0) || (sumb / 200 % 2 == 0 && suma % 200 == 0)) cout << "YES\n";
    else cout << "NO\n";
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}