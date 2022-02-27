#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int diff(string X, string Y, vector<vector<int>> &dp, string &an){
    int n=X.length(), m=Y.length();
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(X[i-1]==Y[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int l=n, r=m;
    while(l>0 && r>0){
        if(X[l-1]==Y[r-1]){
            an+=X[l-1];
            l--;
            r--;
        }
        else{
            if(dp[l][r-1]==dp[l][r]){
                an+=Y[r-1];
                r--;
                an+='+';
            }
            else{
                an+=X[l-1];
                l--;
                an+='-';
            }
        }
    }
    reverse(an.begin(), an.end());
    return dp[n][m];
}

int main(){
	string X = "ABCDFGHJQZ";
	string Y = "ABCDEFGIJKRXYZ";
    vector<vector<int>> dp(X.size()+1, vector<int> (Y.size()+1, 0));
    string an="";
    cout<<diff(X, Y, dp, an)<<endl;
    cout<<an<<endl;
}