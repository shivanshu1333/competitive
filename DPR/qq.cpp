#include<algorithm>
#include <iostream>
#include<vector>
#include<string>
#include <iomanip>
#include <queue> 
using namespace std;

int main(){
    int n,Q;
    cin>>n>>Q;

    vector<vector<int>> adj(n+1);

    for(int i=1;i<n;i++){
        int p,c;
        cin>>p>>c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    vector<long long> cost(n+1,0);

    for(int i=0;i<Q;i++){
        int v,c;
        cin>>v>>c;
        cost[v] += c;
    }

    queue <int> q;

    q.push(1);
    vector<bool> vis(n+1,0);
    vis[1] = 1;
    while(!q.empty()){
        int nc = q.size();
        
        while(nc>0){
            int pa = q.front();
            q.pop();
            
            nc--;
            long long pc = cost[pa];
            for(int i=0;i<adj[pa].size();i++){
                    if(!vis[adj[pa][i]]){   
                        vis[adj[pa][i]]=1;             
                    q.push(adj[pa][i]);
                    cost[adj[pa][i]] += pc;
                }
            }
        }
    }

    for(int i=1;i<n+1;i++)
        cout<<cost[i]<<" ";
    cout<<endl;
}