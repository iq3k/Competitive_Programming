vector<int> z_algo(string s, int n) {
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (z[i-l] < r-i+1){
            z[i] = z[i-l];
        }else {
            r = max(r, i);
            while (s[r-i] == s[r]){
                r += 1;
            }
            z[i] = r - i;
            r--;
            l = i;
        }
    }

    return z;
}