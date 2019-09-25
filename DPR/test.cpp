#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include <iomanip> //to know type.
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int a,b;
    cout<<q<<endl;
    vector<vector<bool>> g(n+1,vector<bool> (n+1,0));   
    for(int i=1;i<n;i++){
        cin>>a>>b;
        g[a][b]=1;
        for(int i=1;i<a;i++){
            if(g[i][a]==1)
                g[i][b]=1;
        }
    }
    vector<long long> cost(n+1,0);
    int ii;
    long long t;
    for(int x=0;x<q;x++){
        cin>>ii>>t;
        cost[ii] += t;
    }

    // for(int i=1;i<=n;i++)
    //     cout<<cost[i]<<" ";
    vector<long long> cc(n+1,0);
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(g[i][j]==1){
                cc[i] += cost[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        cc[i] += cost[i];
    }

    for(int j=1;j<=n;j++){
            cout<<cc[j]<<" ";
        // cout<<endl;
    }
    
}