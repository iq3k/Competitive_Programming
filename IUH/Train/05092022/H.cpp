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
const int M = 1e9 + 7;

long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;
 
  while (k) {
    if (k % 2) {
      res = (res * cur) % p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;
 
  while (u <= temp) {
    degree_num += temp / u;
    u *= p;
  }
  return degree_num;
}
 
long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n, p) - get_degree(n - k, p);
  int den_degree = get_degree(k, p);
 
  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n - k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * ti) % p;
  }
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * degree(ti, p-2, p)) % p;
  }
  return res;
}

int gt[N], tc; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
	
	gt[1] = 1;
	gt[2] = 2;
	for (int i = 3; i < N; ++i) gt[i] = (gt[i - 1] + gt[i - 2] + 1) % M;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << gt[n] << '\n';
	} 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}