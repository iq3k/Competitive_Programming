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
 
const int N = 11;

int r, c;
char a[N][N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) cin >> a[i][j];    

    int ans = 0;
    for (int i = 0; i < r; ++i) {
        bool ok = false;
        for (int j = 0; j < c; ++j) ok |= a[i][j] == 'S';
        if (!ok) {
            for (int j = 0; j < c; ++j) ans += a[i][j] == '.', a[i][j] = ',';
        }
    }

    for (int i = 0; i < c; ++i) {
        bool ok = false;
        for (int j = 0; j < r; ++j) ok |= a[j][i] == 'S';
        if (!ok) {
            for (int j = 0; j < c; ++j) ans += a[j][i] == '.', a[j][i] = ',';
        }
    }

    cout << ans << '\n';
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}