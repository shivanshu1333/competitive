#include<iostream>
#include<vector>
// #include<climits>
#include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>
// #include<algorithm>

using namespace std;

int lis(vector<long long int> &dp){
        int ans = 0, anchor = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (i > 0 && dp[i-1] > dp[i]) anchor = i;
            ans = max(ans, i - anchor + 1);
        }
        return ans-1;
}

int main(){
    int N;
    cin>>N;
    vector<long long int> dp(N,1);
    for(int i=N-1;i>=0;i--)
        cin>>dp[i];
    cout<<lis(dp)<<endl;
    
}