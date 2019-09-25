#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;
#define f first
#define s second
int ot = 300;//offset to avoid negative index in array
vector<int> xr = {-2,-1,-2,-1,1,2,2,1};
vector<int> yc = {1,2,-1,-2,-2,-1,1,2};
int bfs(int x, int y){
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(1000, vector<bool> (1000, 0));
    q.push({0,0});
    vis[0+ot][0+ot]=1;
    int l=0;
    int nc=0;
    while(!q.empty()){
        nc=q.size();
        while(nc>0){
            pair<int, int> t=q.front();
            q.pop();
            nc--;
            if(t.f==x && t.s==y)
                    return l;
            for(int i=0;i<8;i++){
                int a=t.f+xr[i];
                int b=t.s+yc[i];
                // cout<<a<<" "<<b<<endl;
                if(a>=-300 && b>= -300 && a<=300 && b<=300 && vis[a+ot][b+ot]==0){
                    vis[a+ot][b+ot]=1;
                    q.push({a, b});
                }
            }
        }
            l++;
    }
    return -1;
}

int minKnightMoves(int x, int y) {
    return bfs(x, y);
}
int main(){
fast;
freopen("i.txt", "r", stdin);
freopen("o.txt", "w", stdout);
int x,y;
cin>>x>>y;
cout<<minKnightMoves(x,y)<<endl;
}