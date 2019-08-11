#include <iostream>
#include<vector>
using namespace std;

int stairDist(int n){
    if(n==1 || n==2)
        return n;
    int dp[n+1];
    dp[0]=1;dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    return dp[n];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int ans = stairDist(n);
	    cout<<ans<<endl;
	}
	return 0;
}