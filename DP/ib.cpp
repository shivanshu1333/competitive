#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>
using namespace std;

void solve(const vector<int> &A, const vector<int> &wt, const vector<int> &cost) {
    int W = *max_element(A.begin(),A.end());
    cout<<W<<endl;
    vector<int> dp(W+1,16);
    dp[0]=0;

    for(int i=0;i<wt.size();i++){
        for(int j=1;j<=W;i++){
            if((j-wt[i])>=0){
                dp[j] = min(dp[j],cost[i]+dp[j-wt[i]]);
                // cout<<dp[j]<<" ";
            }
            // cout<<endl;
            
        }
    }
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans += dp[A[i]];
    }
    cout<<ans<<endl;
}
int main(){
    vector<int> v = {4,6};
    vector<int> b = {1,3};
    vector<int> c = {5,3};
    solve(v,b,c);
}