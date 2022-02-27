vector<int> calZ(string s){
    int n=s.length();
    vector<int> z(n);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        while((i+z[i])<n && s[z[i]] == s[i+z[i]]) ++z[i];
        if((i+z[i]-1)>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}
// if(i+z[i]==n && n%i==0) s.substr(0, i)=repeating string;
void lps(string s, vector<int> &lps){
    int len=0;
    int i=1;
    int n=s.length();
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0) len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}