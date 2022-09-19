// theo euclid mở rộng
int gcd_extend(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcd_extend(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b) * y1;
    return gcd;
}

int modulo_inverse_euclidean(int n, int m) {
    int x, y;
    if (gcd_extend(n, m, x, y) != 1) return -1; // not exist
    return (x % m  + m) % m; // vì x có thể âm 
}
// mũ nhanh
void binPow(ll &a, ll n, ll b, ll mod){
    if(n <= 1)return;
    binPow(a, n/2, b, mod);
    a = a*a;
    a %= mod;
    if(n % 2)a *= b;
    a %= mod;
}
// m là số nguyên tố
ll nghichDaoModulo(ll a, ll mod){
    binPow(a, mod-2, a, mod);
    return a;
}
void multi(ll mod, ll n){
    ll inv[n+5];
    inv[1] = 1;
    for(ll i = 2; i <= n; ++i){
        inv[i] = mod - (mod/i) * inv[mod%i] % mod;
        cout<<inv[i]<<" ";
    }
}