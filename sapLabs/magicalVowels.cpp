#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define a 0
#define e 1
#define i 2
#define o 3
#define u 4

int lsvowel(string &s){
    int sz = s.size();
    vi dp(5,0);
    bool isa=0, ise=0, isi=0, iso=0, isu=0;
    for(int j=0;j<sz;j++){
        if(s[j]=='a'){
            dp[a]++;
            isa=1;
        }
        if(s[j]=='e' && isa){
            dp[e] = max(dp[a]+1, dp[e]+1);
            ise=1;
        }
        if(s[j]=='i' && ise){
            dp[i] = max(dp[e]+1, dp[i]+1);
            isi=1;
        }
        if(s[j]=='o' && isi){
            dp[o] = max(dp[i]+1, dp[o]+1);
            iso=1;
        }
        if(s[j]=='u' && iso){
            dp[u] = max(dp[o]+1, dp[u]+1);
            isu=1;
        }
    }
    if(isa && ise && isi && iso && isu) return dp[u];
    else return 0;
}

int main(){
    string s;
    cin>>s;
    cout<<lsvowel(s)<<endl;
}