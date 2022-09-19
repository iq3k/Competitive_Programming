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

int tc; 

float calArea(float x1, float y1, float x2, float y2, float x3, float y3) {
    // return (x1*y2 - x2*y2 + x1*y1 - x2*y1) / 2 + (x3*y1 - x1*y1 + x3*y3 - x1*y3) / 2 - (x3*y2 - x2*y2 + x3*y3 - x2*y3) / 2;
    return fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();
 
    cin >> tc;
    while (tc--) {
        float x1, y1, x2, y2, x3, y3, xp, yp; 
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cin >> xp >> yp;
        bool ok1 = ((xp - x1) * (y2 - y1)) == ((yp - y1) * (x2 - x1));
        bool ok2 = ((xp - x2) * (y3 - y2)) == ((yp - y2) * (x3 - x2));
        bool ok3 = ((xp - x3) * (y1 - y3)) == ((yp - y3) * (x1 - x3));

        ok1 &= (fabs(max(x1, x2) - xp) <= 1e-6 and fabs(min(x1,x2) - xp) <= 1e-6);
        ok2 &= (fabs(max(x2, x3) - xp) <= 1e-6 and fabs(min(x2,x3) - xp) <= 1e-6);
        ok3 &= (fabs(max(x3, x1) - xp) <= 1e-6 and fabs(min(x3,x1) - xp) <= 1e-6);
        // debug(ok1, ok2, ok3);


        float tot = calArea(x1, y1, x2, y2, x3, y3);

        // debug(ok1, ok2, ok3);
        if (ok1 || ok2 || ok3) {
            // debug(tot);
            float l = 0, r = 1;
            // x1x2
            while (fabs(l - r) > 1e-6) {
                float mid = (l + r) / 2;
                float xpNew = x1 + (x2 - x1) * mid; 
                float ypNew = y1 + (y2 - y1) * mid;
                float cal = calArea(x1, y1, xp, yp, xpNew, ypNew) * 2;
                // debug(l, x1, y1, xp, yp, xpNew, ypNew);
                // debug(cal);
                if (cal > tot) {
                    r = mid;
                }
                else l = mid;
            }
            if (l != 0) {
                // debug(l);
                cout << fixed << setprecision(6) << x1 + (x2 - x1) * l << ' ' << y1 + (y2 - y1) * l << '\n';
                // cout << "x1x2\n";
                continue;
            }

            l = 0, r = 1;
            // x2x3
            while (fabs(l - r) > 1e-6) {
                float mid = (l + r) / 2;
                float xpNew = x2 + (x3 - x2) * mid; 
                float ypNew = y2 + (y3 - y2) * mid;
                float cal = calArea(x2, y2, xp, yp, xpNew, ypNew) * 2;
                if (cal > tot) {
                    r = mid;
                }
                else l = mid;
            }
            if (l != 0) {
                cout << fixed << setprecision(6) << x2 + (x3 - x2) * l << ' ' << y2 + (y3 - y2) * l << '\n';
                // cout << "x2x3\n";
                continue;
            }

            l = 0, r = 1;
            // x3x1
            while (fabs(l - r) > 1e-6) {
                float mid = (l + r) / 2;
                float xpNew = x3 + (x1 - x3) * mid; 
                float ypNew = y3 + (y1 - y3) * mid;
                float cal = calArea(x3, y3, xp, yp, xpNew, ypNew) * 2;
                if (cal > tot) {
                    r = mid;
                }
                else l = mid;
            }
            if (l != 0) {
                cout << fixed << setprecision(6) << x3 + (x1 - x3) * l << ' ' << y3 + (y1 - y3) * l << '\n';
                // cout << "x3x1\n";
                continue;
            }

        } else {
            cout << -1 << '\n';
        }
    }
 
 
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << float (end - start) / float (CLOCKS_PER_SEC) << '\n';
    return 0;
}