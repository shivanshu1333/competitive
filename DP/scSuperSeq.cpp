#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//memo
// int scs(string x, string y, vector<vector<int>> &dp, int n, int m){
//     if(n==0 || m==0){
//         if(dp[n][m]!=-1) return dp[n][m];
//         dp[n][m] = abs(n-m);
//         return dp[n][m];
//     }
//     if(dp[n][m]!=-1) return dp[n][m];
//     if(x[n-1]==y[m-1]){
//         dp[n][m]=1+scs(x, y, dp, n-1, m-1);
//         return dp[n][m];
//     } 
//     dp[n][m]=1+min(scs(x, y, dp, n-1, m), scs(x, y, dp, n, m-1));
//     return dp[n][m];
// }  
//bottom up
int scs(string x, string y, vector<vector<int>> &dp, int n, int m){

    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int j=0;j<=m;j++)
        dp[0][j]=j;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]);
        }
    }
    int l=n, r=m;
    string an="";
    while(l>0 && r>0){
        if(x[l-1]==y[r-1]){
            an+=x[l-1];
            l--;
            r--;
        }
        else{
            if(dp[l-1][r]==dp[l][r]){
                an+=x[l-1];
                l--;
            }
            else{
                an+=x[r-1];
                r--;
            }
        }
    }
    if(r==0 && l!=0){
        for(int i=l-1;i>=0;i--)
            an+=x[i];
    }
    else if(l==0 && r!=0){
        for(int i=r-1;i>=0;i--){
            an+=y[i];
        }
    }
    reverse(an.begin(), an.end());
    cout<<an<<endl;
    return dp[n][m];
}

int main(){
    string x, y;
    x="ABCBDAB";
    y="BDCABA";
    int n=x.length(), m=y.length();
    vector<vector<int>> dp(x.length()+1, vector<int> (y.length()+1, 0));
    cout<<scs(x, y, dp, n, m)<<endl;
}