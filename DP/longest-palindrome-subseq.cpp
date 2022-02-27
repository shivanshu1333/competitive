#include<iostream>
#include<string>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int lPSubseq(string s) {
    int n=s.length();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    string t=s;
    reverse(t.begin(), t.end());
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int l=n, r=n;
    string ans="";
    while(l>0 && r>0){
        if(s[l-1]==t[r-1]){
            ans+=s[l-1];
            l--;
            r--;
        }
        else{
            if(dp[l-1][r]==dp[l][r])
                l--;
            else
                r--;
        }
    }
    cout<<ans<<endl;
    return dp[n][n];
}
//Memo
int lp(string a, int l, int r, vector<vector<int>> &dp){
    if(l>r) return 0;
    if(l==r) return 1;
    if(dp[l][r]!=-1) return dp[l][r];
    if(a[l]==a[r]){
        dp[l][r] = 2+lp(a, l+1, r-1, dp);;
        return dp[l][r];
    }
    else{
        dp[l][r] = max(lp(a, l+1, r, dp), lp(a, l, r-1, dp));
        return dp[l][r];
    }
}

int main(){
    string a="ABBDCACB";
    vector<vector<int>> dp(a.size(), vector<int> (a.size(), -1));
    cout<<lp(a, 0, 0, dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}