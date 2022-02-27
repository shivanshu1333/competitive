#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>
using namespace std;

int knap(vector<int> &v, vector<int> &w, int T){
    vector<vector<int>> dp(v.size()+1, vector<int> (T+1, 0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(j>=w[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[v.size()][T]; 
}

//Memo 
int knap(vector<int> &v, vector<int> &w, int T, int in, vector<vector<int>> &dp){
    if(T<=0 || in==v.size()){
        return 0;
    }
    if(dp[in][T]!=-1) return dp[in][T];
        int take = (T-w[in])>=0 ? v[in]+knap(v, w, T-w[in], in+1, dp) : 0;
        int donottake = knap(v,w,T,in+1, dp);
    dp[in][T]=max(take, donottake);
    return dp[in][T];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n,W;
        cin>>n>>W;
        vector<int> wt(n);
        vector<int> val(n);
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        int ans = knapsack(wt,val,W);
        cout<<ans<<endl;
	}
	return 0;
}