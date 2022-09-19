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

 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 	
 	int tc; cin >> tc;
    while (tc--) {
    	int n; cin >> n;
	    vector<int> a(n);
	    for (int i = 0; i < n; ++i) a[i] = i + 1;
	    int tot = 0;
	    do {
	    	for (int i = 0; i < n; ++i) {
	    		for (int j = 0; j < i; ++j) if (a[i] % a[j] == 0) ++tot;
	    	}
	    } while (next_permutation(all(a)));

	    cout << tot << '\n';
	}
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}

/*

0
1
6
24
50
120
189


0
1
6
48
300
2880
22680











*/