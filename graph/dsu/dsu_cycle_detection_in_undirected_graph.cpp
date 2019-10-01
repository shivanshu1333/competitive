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

int find(vector<int> &pa, int i){
    if(pa[i]==-1)
        return i;
    return find(pa, pa[i]);
}
void unio(vector<int> &pa, int x, int y){
    int xp = find(pa, x);
    int yp = find(pa, y);
    pa[xp]=yp;
}

bool processEdge(vector<int> &pa, vector<vector<int>> &edge, int V, int E){
    for(int i=0;i<E;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        if(find(pa, u)==find(pa, v))
            return 1;
        else
            unio(pa, u, v);
    }
    return 0;
}

int main() {
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<vector<int>> edge(E);
        vector<int> pa(V, -1);
        if(processEdge(pa, edge, V, E))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
        }
}