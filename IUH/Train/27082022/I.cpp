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

int n;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
	
	cin >> n;
	int ans = 0;
	int N = n; 
	while (N) ans += N % 10 ? (n % (N % 10) == 0) : 0, N /= 10;
	cout << ans << '\n';
    
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}