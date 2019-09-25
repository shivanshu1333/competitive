#include<algorithm>
#include <iostream>
#include<vector>
// #include<queue>
// #include<string>
#include <iomanip>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(int v, int p, long long cost, vvi &a, vector<long long> &c, vector<long long> &up){
   c[v] = cost+up[v];
   for(auto u: a[v]){
       if(u==p){cout<<"u"<<u<<endl; continue;}
       dfs(u, v, c[v], a, c, up);
   } 
   return;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi a(n+1);
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<long long> up(n+1, 0);
    for(int i=0;i<m;i++){
        long long x, y;
        cin>>x>>y;
        up[x] +=y;
    }

    vector<long long> c(n+1, 0);

    dfs(1, -1, 0, a, c, up); 
    for(int i=1;i<n+1;i++){
        cout<<c[i]<<" ";
    }

}