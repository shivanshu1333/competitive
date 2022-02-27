#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ff first
#define ss second
using namespace std;

int main() {
    vector<int> dp(95, 0);
    dp[19] = 94;
    for(int i=20;i<=94;i++){
        dp[i] = i*i- dp[i-1];
    }
    cout<<(dp[94]%100)<<endl;
}