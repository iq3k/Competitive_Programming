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

int n; 
 
signed main() {
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n;
	int l = 1, r = n;
	while (l < r) {
		int m = (l + r) >> 1;
		int v1, v2;
		cout << "? " << m << endl;
		cin >> v1;
		cout << "? " << (m + 1) << endl;
		cin >> v2;
		if (v1 > v2) l = m + 1;
		else r = m;
	} 

	cout << "! " << l << endl;

	cout << "! " << l << endl;
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}