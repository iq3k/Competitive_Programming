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
 
const int N = 1e5 + 11;

int n, a[N], idx, mi;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n;
    mi = 1e9 + 5;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mi = min(mi, a[i]);
    } 
    idx = -1;
    for (int i = 0; i < n; ++i)
        if (a[i] == mi && idx == -1) idx = i;
        else if (a[i] == mi && idx != -1) idx = n;
    if (idx == n) cout << "Still Rozdil\n";
    else cout << idx << '\n';
    
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}