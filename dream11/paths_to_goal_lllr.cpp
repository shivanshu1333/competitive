#include<bits/stdc++.h>
using namespace std;
int dp[101][100][2];
int solve(string st, int in, int fl, int s, int d, int n){
    if(s > n || s < 0)
        return 0;
    int len = st.length();
    if(in >= len)
        return 0;
    if(dp[in][s][fl]!=-1) return dp[in][s][fl];
    int res = 0;
    if( (st[in] == 'l' && fl == 0 ) || ( st[in] == 'r' && fl) ){
        int f = 1;
        if(st[in] == 'l')
            f = -1;
        res = solve(st, in + 1, fl, s + f, d, n) + solve(st, in + 1, 1 - fl, s + f, d, n);
        if(s + f == d)
            res++;
    }
    else{
        res = solve(st, in + 1, flag, s, d, n);
    }
    dp[in][s][fl] = res;
    return res;
}
int main(){
    string st;
    cin >> st;
    int len = st.length();
    int n;
    cin >> n;
    int s, d;
    cin >> s >> d;
    memset(dp, -1, sizeof(dp));
    int res = solve(st, 0 , 0, s, d, n) + solve(st, 0, 1, s, d, n);
    cout << res << endl;
}