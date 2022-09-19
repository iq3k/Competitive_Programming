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
 
const int NN = 1e5 + 11;

int W, H, N;
set<vector<int>> st[4]; 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> W >> H; 
    cin >> N;
    auto where = [](int x, int y) -> pair<int, int> {
        if (x == 0) return mp(0, y);
        if (y == 0) return mp(1, x);
        if (x == W) return mp(2, y);
        if (y == H) return mp(3, x); 
        return mp(-1, -1);
    };
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        auto a1 = where(x1, y1), a2 = where(x2, y2);
        if (a1.fi != -1 && a2.fi != -1) {
            st[a1.fi].insert({a1.se, x1, y1, x2, y2});
            st[a2.fi].insert({a2.se, x1, y1, x2, y2});
        }
    }

    stack<int> s;
    map<vector<int>, int> ma;
    int cntLabel = 1;
    bool ok = true;
    // cout << "0-----------\n";
    for (auto it = rbegin(st[0]); it != rend(st[0]); ++it) {
        auto v = *it;
        // for (auto i : *it) cout << i << ' '; cout << '\n';

        if (ma.find({v[1], v[2], v[3], v[4]}) != ma.end()) {
            if (s.top() == ma[{v[1], v[2], v[3], v[4]}]) {
                s.pop();
            } else {
                ok = false;
            }
        } else {
            s.push(cntLabel);
            ma[{v[1], v[2], v[3], v[4]}] = cntLabel++;
        }
    }
    // cout << "1-----------\n";

    for (auto it = begin(st[1]); it != end(st[1]); ++it) {
        auto v = *it;
        // for (auto i : *it) cout << i << ' '; cout << '\n';

        if (ma.find({v[1], v[2], v[3], v[4]}) != ma.end()) {
            if (s.top() == ma[{v[1], v[2], v[3], v[4]}]) {
                s.pop();
            } else {
                ok = false;
            }
        } else {
            s.push(cntLabel);

            ma[{v[1], v[2], v[3], v[4]}] = cntLabel++;
        }
    }
    // cout << "2-----------\n";

    for (auto it = begin(st[2]); it != end(st[2]); ++it) {
        auto v = *it;
        // for (auto i : *it) cout << i << ' '; cout << '\n';

        if (ma.find({v[1], v[2], v[3], v[4]}) != ma.end()) {
            if (s.top() == ma[{v[1], v[2], v[3], v[4]}]) {
                s.pop();
            } else {
                ok = false;
            }
        } else {
            s.push(cntLabel);

            ma[{v[1], v[2], v[3], v[4]}] = cntLabel++;
        }
    }
    // cout << s.size() << '\n';
    // cout << "3-----------\n";

    for (auto it = rbegin(st[3]); it != rend(st[3]); ++it) {
        auto v = *it;
        // for (auto i : *it) cout << i << ' '; cout << '\n';

        if (ma.find({v[1], v[2], v[3], v[4]}) != ma.end()) {
            if (s.top() == ma[{v[1], v[2], v[3], v[4]}]) {
                s.pop();
            } else {
                ok = false;
            }
        } else {
            s.push(cntLabel);

            ma[{v[1], v[2], v[3], v[4]}] = cntLabel++;
        }
    }
        // cout << "st[0]: "; for (auto i : st[0]) for (auto j : i) cout << j << ' '; cout << '\n';
        // cout << "st[1]: "; for (auto i : st[1]) for (auto j : i) cout << j << ' '; cout << '\n';
        // cout << "st[2]: "; for (auto i : st[2]) for (auto j : i) cout << j << ' '; cout << '\n';
        // cout << "st[3]: "; for (auto i : st[3]) for (auto j : i) cout << j << ' '; cout << '\n';

        cout << (ok ? 'Y' : 'N') << '\n';
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}