#include <iostream>
#include<string>
#include<vector>
using namespace std;

int min3(int a, int b, int c){
    return min(min(a,b),c);
}

int editDist(string a, string b, int n, int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
        dp[i][0]=i;
    for(int j=0;j<m+1;j++)
        dp[0][j]=j;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]!=b[j-1])
                dp[i][j] =1+min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[n][m];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    int ans = editDist(a,b,n,m);
	    cout<<ans<<endl;
	}
	return 0;
}

// int main(){
//     string a = "sunday";
//     string b = "saturday";
//     int ans = editDist(a,b,a.length(),b.length());
//     cout<<ans<<endl;
// }