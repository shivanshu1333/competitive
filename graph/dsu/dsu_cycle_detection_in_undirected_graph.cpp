#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

//pseudo code
/*
for each unvisited edge in (u,v) in edge set E{
    if(find(u)==find(v)){
        //cycle detected
    }
    else{
        union(x,y);//u belongs to x and v belongs to y
    }
}
*/

// vector<int> p;
// p[i] in p is parent of and i is ith node;

// int find(vector<int> &pa, int i){
//     if(pa[i]==-1)
//         return i;
//     return find(pa, pa[i]);
// }
// void unio(vector<int> &pa, int x, int y){
//     int xp = find(pa, x);
//     int yp = find(pa, y);
//     pa[xp]=yp;
// }

int find(vector<int> &pa ,int i){
    while(pa[i] != i){
        pa[i] = pa[pa[i]]; 
        i = pa[i]; 
    }
return i;
}

void unio(vector<int> &pa, vector<int> &size , int A, int B){
    int root_A = find(pa, A);
    int root_B = find(pa, B);
    if(size[root_A] < size[root_B ]){
        pa[root_A] = pa[root_B];
        size[root_B] += size[root_A];
    }
    else{
        pa[root_B] = pa[root_A];
        size[root_A] += size[root_B];
    }
}

bool processEdge(vector<int> &pa, vector<int> &size, vector<vector<int>> &edge, int V, int E){
    for(int i=0;i<E;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        if(find(pa, u)==find(pa, v))
            continue;
        else
            unio(pa, size, u, v);
    }
    return 0;
}

int main() {
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    // int t;
    // cin>>t;
    // while(t--){
        int V,E;
        cin>>V>>E;
        vector<vector<int>> edge(E);
        int u,v;
        for(int i=0;i<E;i++){
            cin>>u>>v;
            edge[i]={u,v};
        }
        vector<int> pa(V);
        for(int i=0;i<V;i++) pa[i]=i;
        vector<int> size(V,1);
        processEdge(pa, size, edge, V, E);
        for(int i=0;i<V;i++){
            cout<<size[i]<<" ";
        }
        // if(processEdge(pa, size, edge, V, E))
        //     cout<<"1"<<endl;
        // else
        //     cout<<"0"<<endl;
        // }
}