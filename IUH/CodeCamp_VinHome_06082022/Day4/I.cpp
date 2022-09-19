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
 
const int N = 15;

string s[N];
int f[N][N][N];
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    for (int i = 1; i <= 10; ++i) cin >> s[i], s[i] = " " + s[i]; 
    bool ok = false;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            f[0][i][j] = s[i][j] == 'X' ? f[0][i][j - 1] + 1 : 0;
        }
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 10; j >= 1; --j) {
            f[1][i][j] = s[i][j] == 'X' ? f[1][i][j + 1] + 1 : 0;
        }
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            f[2][j][i] = s[j][i] == 'X' ? f[2][j - 1][i] + 1 : 0;
        }
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 10; j >= 1; --j) {
            f[3][j][i] = s[j][i] == 'X' ? f[3][j + 1][i] + 1 : 0;
        }
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            f[4][i][j] = s[i][j] == 'X' ? f[4][i - 1][j - 1] + 1 : 0;
        }
    }
    for (int i = 10; i >= 1; --i) {
        for (int j = 10; j >= 1; --j) {
            f[5][i][j] = s[i][j] == 'X' ? f[5][i + 1][j + 1] + 1 : 0;
        }
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 10; j >= 1; --j) {
            f[6][i][j] = s[i][j] == 'X' ? f[6][i - 1][j + 1] + 1 : 0;
        }
    }
    for (int i = 10; i >= 1; --i) {
        for (int j = 1; j <= 10; ++j) {
            f[7][i][j] = s[i][j] == 'X' ? f[7][i + 1][j - 1] + 1 : 0;
        }
    }

    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            if (s[i][j] == '.') {
                if (f[0][i][j - 1] + f[1][i][j + 1] >= 4 ||
                    f[2][i - 1][j] + f[3][i + 1][j] >= 4 ||
                    f[4][i - 1][j - 1] + f[5][i + 1][j + 1] >= 4 ||
                    f[6][i + 1][j - 1] + f[7][i - 1][j + 1] >= 4) ok = true;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}