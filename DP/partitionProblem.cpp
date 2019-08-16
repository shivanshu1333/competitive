#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

bool partition(vector<int> &v, int tar){
    vector<vector<bool>> dp(v.size()+1,vector<bool> (tar+1,0));
    for(int i=0;i<dp.size();i++)
        dp[i][0]=1;
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<=tar;j++){
            if((j-v[i])<0)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
            }
        }
    }
    return dp[v.size()][tar];
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
        if(sum%2!=0){ cout<<"NO"<<endl;}
        else if(partition(v,sum/2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}