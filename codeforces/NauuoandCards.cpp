#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool isSafe(){

}

int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int r,c;
    cin>>r>>c;
    vector<vector<int>> g(r, vector<int> (c, INT_MAX));
    char c;
    pair<int,int> start, end;
    for(int i=0;<c;i++){
        for(int j=0;j<r;j++){
            cin>>c;
            if(c=='S'){
                g[i][j]=0;
                start={i,j};
            }
            else if(c=='T')
                end = {i,j};
            else if(c=='*')
                g[i][j]=-1;
        }
    }
    if(bfs(start, end, g))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}