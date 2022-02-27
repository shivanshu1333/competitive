#include<iostream>
#include<vector>
#include<climits>
// #include<map>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>
// #include <fstream>
using namespace std;

vector<int> shortestDistanceColor(vector<int>& c, vector<vector<int>>& q) {
    int l = c.size();
    vector<int> ans;
    vector<vector<int>> dp(l, vector<int> (4,100000));
    dp[0][c[0]]=0;
    // cout<<dp[0][1]<<endl;
    for(int i=1;i<l;i++){
        dp[i][c[i]]=0;
        // cout<<c[i-1]<<" "<<dp[i-1][c[i-1]]+1<<" ";
        dp[i][1] = min(dp[i][1], dp[i-1][1]+1);
        dp[i][2] = min(dp[i][2], dp[i-1][2]+1);
        dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
        // cout<<"dp["<<i<<"] - "<<dp[i][1]<<" - "<<dp[i][2]<<" - "<<dp[i][3]<<endl;
    }
    // dp[l-1][c[l-1]] = 0;
    for(int i=l-2;i>=0;i--){
        dp[i][1] = min(dp[i][1], dp[i+1][1]+1);
        dp[i][2] = min(dp[i][2], dp[i+1][2]+1);
        dp[i][3] = min(dp[i][3], dp[i+1][3]+1);
        // dp[i][c[i+1]] = min(dp[i][c[i+1]], dp[i+1][c[i+1]]+1);
    }
    for(int i=0;i<q.size();i++){
        if(dp[q[i][0]][q[i][1]]==100000)
            ans.push_back(-1);
        else
            ans.push_back(dp[q[i][0]][q[i][1]]);
    }
    return ans;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> c = {1,2};
    vector<vector<int>> q = {{0,3}};
    vector<int> ans = shortestDistanceColor(c, q);
    for(int i=0;i<ans.size();i++){
        // if(ans[i]==100000)
        //     cout<<-1<<" ";
        // else
            cout<<ans[i]<<" ";
    }
}