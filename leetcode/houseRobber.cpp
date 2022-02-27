#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int> &v, int l){
    if(l<0)
        return 0;
    return max(v[l]+rob(v,l-2),v[l-1]+rob(v, l-3));
}

int robDP(vector<int> &v){
    if(v.size()==1)
        return v[0];
    if(v.size()==2)
        return max(v[0], v[1]);
    if(v.size()==3)
        return max(v[0]+v[2],v[1]);    
    vector<int> dp(v.size(),0);
    dp[0]=v[0];
    dp[1]=max(v[0], v[1]);
    dp[2]=max(v[0]+v[2],v[1]);
    // dp[3]=max(v[3]+dp[1],v[2]+dp[0]);
    for(int i=3;i<v.size();i++){
        dp[i] = max(v[i]+dp[i-2], v[i-1]+dp[i-3]);
    }
    return dp[v.size()-1];
}

int main(){
    vector<int> v = {100,1,1,100};
    int ans = robDP(v);
    cout<<ans<<endl;
}