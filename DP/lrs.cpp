#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;

int lrs(string X, int m, int n, vector<vector<int>> &dp){
    if(m==0||n==0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(X[m-1]==X[n-1] && m!=n){
        dp[m][n] = 1+lrs(X, m-1, n-1, dp);
        return dp[m][n];
    }
    dp[m][n] = max(lrs(X, m-1, n, dp), lrs(X, m, n-1, dp));
    return dp[m][n];

}

int lrsbu(string x, vector<vector<int>> &dp){
    int n=x.length(), m=x.length();
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(x[i-1]==x[j-1] && i!=j)
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int l=n, r=m;
    string an="";
    while(l>0 && r>0){
        if(x[l-1]==x[r-1] && l!=r){
            an+=x[l-1];
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
    reverse(an.begin(), an.end());
    cout<<an<<endl;
    return dp[m][n];
}

int main(){
	string X = "ATACTCGGA";
	int m = X.length();
    vector<vector<int>> dp(m+1, vector<int> (m+1, 0));
    // cout<<lrs(X, m, m, dp)<<endl;
    cout<<lrsbu(X, dp)<<endl;
}