#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int cap){
    vector<vector<int>> dp(wt.size()+1, vector<int> (cap+1,0));
    for(int i=1;i<=wt.size();i++){
        for(int j=1;j<=cap;j++){
            if((j-wt[i-1])>=0){
                dp[i][j] = max(dp[i-1][j],(val[i-1]+dp[i-1][j-wt[i-1]]))    ;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[wt.size()][cap];
}

// int knap(int N, int W , vector<int> &v, vector<int> &wt)
// {
//     int i,j,knaps[N+1][W+1];
//     for(i=0;i<N+1;i++)
//         for(j=0;j<W+1;j++)
//         {
//             if(i==0 || j==0)
//                 knaps[i][j]=0;
//             else if(j<wt[i-1])
//                 knaps[i][j]=knaps[i-1][j];
//             else
//             {
//                 knaps[i][j]=max(v[i-1]+knaps[i-1][j-wt[i-1]],knaps[i-1][j]);
//             }
//         }
//     return knaps[N][W];  
// }

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