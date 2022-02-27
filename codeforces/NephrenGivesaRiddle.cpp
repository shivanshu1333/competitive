#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";

char rec(int n, ll k, vector<ll> &dp){
    if(k>dp[n]) return '.';
    if(n==0) return s[k-1];
    string p1 = "What are you doing while sending \"";
    string p2 =  "\"? Are you busy? Will you send \"";
    if(k<=p1.length()) return p1[k-1];
    if(k<=p1.length()+dp[n-1]) return rec(n-1, k-p1.length(), dp);
    if(k<=p1.length()+dp[n-1]+p2.length()) return p2[k-p1.length()-dp[n-1]-1];
    if(k<=p1.length()+2*dp[n-1]+p2.length()) return rec(n-1, k-p1.length()-dp[n-1]-p2.length(), dp);
    return s1[k-2*dp[n-1]-1];
}

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    vector<ll> dp(100001);
    dp[0]=s.length();
    for(auto i=1;i<=100000;i++)
        dp[i] = 2*dp[i-1]+ (ll)s1.length();
    int q;
    cin>>q;
    while(q--){
        int n;
        ll k;
        cin>>n>>k;
        cout<<rec(n, k, dp);
    }    
}