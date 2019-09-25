#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool isSafe(int i, int j, vector<vector<char>> g){
    return i>=0 && j>=0 && i<g.size() && j<g.size() && g[i][j]=='0';
}

void dfs(int i, int j, vector<vector<char>> &g, char c){
    g[i][j]=c;
    if(c=='W')
        c='B';
    else
        c='W';
    if(isSafe(i-2, j-1, g)){
        dfs(i-2, j-1, g, c);
    }
    if(isSafe(i-2, j+1, g)){
        dfs(i-2, j+1, g, c);
    }
    if(isSafe(i+2, j-1, g)){
        dfs(i+2, j-1, g, c);
    }
    if(isSafe(i+2, j+1, g)){
        dfs(i+2, j+1, g, c);
    }
    if(isSafe(i-1, j-2, g)){
        dfs(i-1, j-2, g, c);
    }
    if(isSafe(i+1, j-2, g)){
        dfs(i+1, j-2, g, c);
    }
    if(isSafe(i-1, j+2, g)){
        dfs(i-1, j+2, g, c);
    }
    if(isSafe(i+1, j+2, g)){
        dfs(i+1, j+2, g, c);
    }
}

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<vector<char>> g(n, vector<char> (n, '0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='0')
                dfs(i, j, g, 'W');
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }
}