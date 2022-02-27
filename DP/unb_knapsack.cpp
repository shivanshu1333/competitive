#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//Gives you ordered pair, 2-D dp required
int q(int i, vector<int> &v, vector<int> &wt, int w, vector<vector<int>> &m){
    if(i==v.size() || w<=0) return 0;
    if(m[i][w]!=-1) return m[i][w];
    if(wt[i]>w)
        m[i][w]=q(i+1,v, wt, w, m);
    else
        m[i][w] = max(v[i]+q(i, v, wt, w-wt[i], m),  q(i+1,v, wt, w, m));
    return m[i][w];
}
//Gives you unordered pair, 1-D dp required
int q(vector<int> &v, vector<int> &wt, int w, vector<int> &m){
    if(w<=0) return 0;
    if(m[w]!=-1) return m[w];
    int an=0;
    
    for(int i=0;i<v.size();i++){
        if(wt[i]<=w)
            an = max(an, v[i]+q(v, wt, w-wt[i], m));
    }
    m[w]=an;
    return m[w];
}
//Bottom up
int q(vector<int> &v, vector<int> &wt, int w){
    vector<vector<int>> dp(v.size()+1, vector<int> (w+1, 0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(wt[i-1]<=j)
                dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i][j-wt[i-1]]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[v.size()][w];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        vector<int> v(n), wt(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        vector<vector<int>> m(n, vector<int> (w+1, -1));
        cout<<q(0, v, wt, w, m)<<endl;
    }
}