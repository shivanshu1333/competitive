#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define pb push_back

int bfs(vi &g){
    queue<int> q;
    q.push(1);
    int nc;
    int l=0;
    while(!q.empty()){
        nc = q.size();
        while(nc>0){
            int p = q.front();
            q.pop();
            if(p==30) return l;
            nc--;
            for(int i=(p+1);i<=(p+6);i++){
                if(g[i]!=-1)
                    q.push(g[i]);
                else
                    q.push(i);
            }
        }
        l++;
    }
    return l;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vi v(31, -1);
        int uu,vv;
        for(int i=0;i<n;i++){
            cin>>uu>>vv;
            v[uu]=vv;
        }
        cout<<bfs(v)<<endl;
    }
}
