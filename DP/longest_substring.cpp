#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string LCS(string a, string b, int n, int m){
    int maxlen = 0;
    int endingIndex = n;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>maxlen){
                    maxlen=dp[i][j];
                    endingIndex=i;
                }
            }
        }
    }
    return a.substr(endingIndex-maxlen, maxlen);
}

int main(){
    string a="ABC", b="BABA";
    int n=a.length(), m=b.length();
    cout<<LCS(a, b, n, m)<<endl;
}