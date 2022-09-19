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

LL n[3], p[3], rub, l, r, m, cnt[3];
string s; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
   	cin >> s;
   	cin >> n[0] >> n[1] >> n[2];
   	cin >> p[0] >> p[1] >> p[2];
   	cin >> rub;

   	for (auto i : s)
   		if (i == 'B') ++cnt[0];
   		else if (i == 'S') ++cnt[1];
   		else ++cnt[2];

   	auto check = [] (LL m) {
   		LL tot = 0;
   		for (int i = 0; i < 3; ++i) tot += max(0ll, ((m * cnt[i]) - n[i]) * p[i]);
   		return tot <= rub;
   	};

   	l = 1, r = 1e12;
   	while (l < r) {
   		m = (l + r) >> 1;
   		if (check(m)) l = m + 1;
   		else r = m;
   	}
	cout << l - 1 << '\n';  
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}