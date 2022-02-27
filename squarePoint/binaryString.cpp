// leetcode Count Binary Substrings
//substrings that have the same number of 0's and 1's
#define pb push_back
int countBinarySubstrings(string s) {
    vector<int> v;
    int l=0,r=0;
    while(r<s.length()){
        if(s[l]==s[r])
            r++;
        else{
            v.pb(r-l);
            l=r;
        }
    }
    v.pb(r-l);
    int ans=0;
    for(int i=1;i<v.size();i++){
        ans+=min(v[i], v[i-1]);
    }
    return ans;
}