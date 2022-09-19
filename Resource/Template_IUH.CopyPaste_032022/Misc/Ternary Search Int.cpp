ll TernarySearchI(ll l, ll r){
  while(l < r){
    ll m = (l+r)>>1;
    if (f(m) < f(m+1))
      r = m;
    else
      l = m+1;
  }
  return l;
}

