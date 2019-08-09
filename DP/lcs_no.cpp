#include <iostream>
#include<string>
#include<vector>
using namespace std;

void lcs(string a,string b,int n, int m){
    int r = m+1;
    int c = n+1;
    vector<vector<int>> dp(r,vector<int> (c,0));
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(a[j-1]==b[i-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[r-1][c-1]<<endl;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        lcs(a,b,n,m);
    }
}