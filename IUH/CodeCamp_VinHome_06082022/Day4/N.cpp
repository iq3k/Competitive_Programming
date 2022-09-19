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

int h, m, ans;
char c; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> h >> c >> m;
    int tot = h * 60 + m;
    auto check = [] (int v) {
        int a = ((v / 60) % 24) % 10, b = ((v / 60) % 24) / 10;
        int c = (v % 60) % 10, d = (v % 60) / 10;
        return b == c && a == d;
    };
    for (; ; ++tot, ++ans) if (check(tot)) break;

    cout << ans << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}