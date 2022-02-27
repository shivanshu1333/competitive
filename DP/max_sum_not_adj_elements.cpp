#include<bits/stdc++.h>
#define ll unsigned long long
#define mem(a, b) memset(a, b, sizeof(a))
#define F(i,s,e) for(auto i=s;i<e;i++)
#define pi acos(-1)
#define v vector
#define ss size()
#define l length()
#define f first
#define s second
using namespace std;

int ms(v<int> &a, int i, v<int> &dp){
    if(i>=a.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i]=max((a[i]+ms(a, i+2, dp)), ms(a, i+1, dp));
    return dp[i];
        
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        v<int> a(n, 0);
        F(i,0,n) cin>>a[i];
        v<int> dp(a.size(), -1);
        cout<<ms(a, 0, dp);
    }
}