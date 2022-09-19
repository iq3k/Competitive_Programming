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
 
const int N = 1e3 + 11;

int n;
string s[N], ans[N]; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> ans[i];
    auto solve = [&] {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j)
                if (ans[i][j] == 'O' && ans[i][j + 1] == 'O') return ans[i][j] = '+', ans[i][j + 1] = '+', 1;
        return 0;
    }; 

    if (solve()) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) cout << ans[i][j];
            cout << '\n';
        }
    } else cout << "NO\n";
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}