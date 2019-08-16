#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

long long minPartition(vector<int> &v, int tar, long long sum){
    vector<vector<bool>> dp(v.size()+1, vector<bool> (tar+1,0));
    for(int i=0;i<dp.size();i++)
        dp[i][0] = 1;
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<=tar;j++){
            if((j-v[i-1])<0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
        }
    }
    for(int i=tar;i>=0;i--){
        if(dp[v.size()][i]==1)
            return sum - 2*i;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        long long sum = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];;
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        int ans = minPartition(v,sum/2,sum);
        cout<<ans<<endl;
    }
    return 0;
}