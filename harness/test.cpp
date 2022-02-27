#include <bits/stdc++.h>
using namespace std;

int minWindow(string a){
    int n=a.length();
    char dp[256];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0;i<n;i++){
        dp[a[i]]++;
    }
    
    int l=0, r=n-1;
    
    while(l<n){
        if(dp[a[l]]>=2) {
            dp[a[l]]--;
            l++;
        }
        else break;
    }
    while(r>l){
        if(dp[a[r]]>=2) {
            dp[a[r]]--;
            r--;
        }
        else break;
    }
    return r-l+1;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        string a;
        cin>>a;
        cout<<minWindow(a)<<endl;
    }
}