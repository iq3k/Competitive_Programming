bool millerTest(ll n, ll d){
    ll a = random(2, n-2);
    ll x = (ll)binpow(a, d, n);
    // cout<<x<<" "<<d<<"\n";
    if(x == 1 || x == n-1)return true;
    while(d != n-1){
        x = x*x%n;
        d *= 2;
        // cout<<x<<" "<<d<<"\n";
        if(x == 1)return false;
        if(x == n-1)return true;
    }
    return false;
}

bool isPrime(ll n){
    if(n == 1 || n == 4)
        return false;
    if(n <= 3)return true;
    ll d = n-1;
    while(d % 2 == 0)
        d /= 2;
    ll r = log2((n-1)/d);
    // cout<<d<<" "<<r<<"\n"; 
    for(int i=0; i<10; i++){
        if(!millerTest(n, d))
            return false;
    }
    return true;
}