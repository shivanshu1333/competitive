#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//555 pqr -> ppp, pq, qp, r
int noRepChar(int dig){
    if(dig == 7 || dig == 9) return 4;
    return 3;
}

int q(string s){
    int len = s.length();
    vector<int> dp(len, 0);
    dp[0]=1;
    for(int i=1;i<len;i++){
        int pl = noRepChar(s[i]-'0')-1;
        for(int j=i;j>=0;j--){
            if(i-pl>j) break;
            if(s[i]==s[j]){
                if(j-1>-1) dp[i]+=dp[j-1];
                else dp[i]+=1;
            }
            else break;
        }
    }
    for(int i=0;i<len;i++) cout<<dp[i]<<" ";
    cout<<endl;
    return dp[len-1];
}

int main(){
    string s;
    cin>>s;
    cout<<q(s);
}
