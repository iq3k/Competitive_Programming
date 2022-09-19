void manacher_algo(string s){
    int n = s.length();
    // center: center position
    // r: center right postion
    int center = 1, r = 2;
    vector<int> lps(n+5, 0);
    lps[1] = 1;
    // cr: current right
    for(int cr=2; cr<n; cr++){
        
        // cl: current left
        int cl = 2*center-cr;
        // khoang cach
        int d = r - cr;
        if(lps[cl] < d){
            lps[cr] = lps[cl];
        }else if(s[cr] != '|'){
            // tam la 1 ky tu
            int e = (2*d+1)/2;
            lps[cr] = min(lps[cl], e);
            while(1){
                
                int l = cr - lps[cr] - 1;
                int r = cr + lps[cr] + 1;
                if(l >= 0 && r < n && (s[l] == '|' || s[l] == s[r])){
                    lps[cr]++;
                }else break;
            }
        }else{
            // tam la 1 ky tu |
            int e = (2*d+1)/2;
            lps[cr] = min(lps[cl], e);
            while(1){
                
                int l = cr - lps[cr] - 1;
                int r = cr + lps[cr] + 1;
                if(l >= 0 && r < n && (s[l] == '|' || s[l] == s[r])){
                    lps[cr]+=2;
                }else break;
            }
        }
        // neu phan mo rong vuot qua r cua center
        if(cr + lps[cr] >= r){
            center = cr;
            r = cr+lps[cr];
        }
    }
    int nmax = 0, vt;
    for(int i=0; i<n; i++){
        if(nmax < lps[i]){
            nmax = lps[i];
            vt = i;
        }
    }
    cout<<nmax<<"\n";
    for(int i=vt-nmax; i<vt+nmax; i++)
        if(s[i] != '|')cout<<s[i];
}

string s = "|";
for(int i=0; i<n; i++){
    s += a[i];
    s += '|';
}
manacher_algo(s);