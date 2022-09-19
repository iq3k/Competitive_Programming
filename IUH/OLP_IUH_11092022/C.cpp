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
string s; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> n >> s;
    bool ok = true;
    auto t = s;
    reverse(all(t));
    int X = 0, DX = 0, DD = 0;
    while (sz(t)) {
        if (t.back() == 'X') ++X, t.pop_back();
        else {
            if (sz(t) == 1) {
                ok = false;
                break;
            }
            else {
                t.pop_back();
                if (t.back() == 'D') ++DD;
                else ++DX;
                t.pop_back();
            }
        }
    }
    
    if (!ok) {
        cout << "-1\n";
    } else {
        cout << DX << ' ' << DD << ' ' << X << '\n';
    }
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}