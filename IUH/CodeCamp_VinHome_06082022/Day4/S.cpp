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

string s[N]; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
	for (int i = 0; i < 6; ++i) cin >> s[i]; 
	bool ok = false;
	for (int i = 1; i < 6; ++i) ok |= s[0][0] == s[i][0];
	for (int i = 1; i < 6; ++i) ok |= s[0][1] == s[i][1];

	cout << (ok ? "YES" : "NO") << '\n';

    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}