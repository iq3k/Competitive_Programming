void kmp_algo(string a, string b, vector<int> pre){
    
    vector<int> kmp(lena, 0);
    int j =0;
    for(int i=0; i<lena; i++){
        // cout<<i<<" "<<j<<" ";
        while(j >= 0){
            if(a[i] == b[j]){
                j++;
                break;
            }else{
                if(j == 0)break;
                j = pre[j-1];
            }
        }
        kmp[i] = j;
        if(kmp[i] == lenb){
            cout<<i-lenb+2<<" ";
        }
        if(j >= lenb)j = pre[j-1];
    }
    
}

void preProcess(string s, vector<int> &pre){
    int j = 0;
    for(int i=1; i<lenb; i++){
        
        while(j >= 0){
            if(s[i] == s[j]){
                pre[i] = ++j;
                break;
            }else{
                if(j == 0)break;
                j = pre[j-1];
            }
        }
    }
    // for(int i=0; i<n; i++)cout<<pre[i]<<" ";
}