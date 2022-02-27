#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef long long ll;
ll dp[51][51][51];
int n;

//rr 0, 1, 0
//rd 0, 1, 1
//dr 1, 0, 0
//dd 1, 0, 1

ll gc(vvi &g, int x1, int y1, int x2){
    int y2 = x1+y1-x2;
    if(x1>=n || x2>=n || y1>=n || y2>=n || g[x1][y1]==-1 || g[x2][y2]==-1) return -10000;
    else if(x1==n-1 || x2==n-1) return g[x1][y1];
    else if(dp[x1][y1][x2]!=INT_MIN) return dp[x1][y1][x2];
    else{
        ll gv = g[x1][y1];
        if(x1!=x2) gv+=g[x2][y2];
        gv += max( max (max ( gc(g, x1, y1+1, x2), gc(g, x1, y1+1, x2+1) ), gc(g, x1+1, y1, x2) ), gc(g, x1+1, y1, x2+1));
        dp[x1][y1][x2]=gv;
    }
    return dp[x1][y1][x2];
}


int main(){
    vvi g = {
            {0, 1, -1},
            {1, 0, -1},
            {1, 1,  1}
            };
    n = g.size();
    for(int i=0;i<51;i++)
        for(int j=0;j<51;j++)
            for(int k=0;k<51;k++)
                dp[i][j][k]=INT_MIN;
    ll ans = gc(g, 0, 0, 0);
    if(ans<0) ans = 0;
    cout<<ans<<endl;
}